/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 05:11:32 by napark            #+#    #+#             */
/*   Updated: 2021/12/27 20:06:07 by mkal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_path(t_state *s, t_cmd *cmd, char **envp)
{
	int		status;
	pid_t	pid;

	s->is_fork = 1;
	pid = fork();
	if (pid < 0)
		exit(1);
	if (pid == 0)
	{
		set_pipe(cmd);
		if (cmd->fd_in != 0)
			dup2(cmd->fd_in, 0);
		if (cmd->fd_out != 1)
			dup2(cmd->fd_out, 1);
		if (execve(cmd->av[0], cmd->av, envp) < 0)
			execute_error(s, cmd, 1);
	}
	else
	{
		close(cmd->pip[1]);
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			s->ret = WEXITSTATUS(status);
	}
}

void	execute_cmd2(t_state *s, t_cmd *cmd, char **envp)
{
	int	err;

	if (!check_redirection(cmd))
	{
		s->ret = 1;
		printf("bash: %s\n", strerror(errno));
	}
	else if (cmd->ac == 0)
		execve_std(cmd);
	else if (builtin(s, cmd))
		return ;
	else if (find_command(s, cmd))
		execute_path(s, cmd, envp);
	else if (cmd->av[0][0] == '/')
	{
		if (find_simple_cmd(cmd, &err))
			execute_path(s, cmd, envp);
		else
			execute_error(s, cmd, err);
	}
	else
		execute_error(s, cmd, 2);
	s->is_fork = 0;
}

void	close_fd_dup(t_cmd *cmd, int *stin, int *stout)
{
	if (cmd->prev != 0)
		close(cmd->prev->pip[0]);
	close(cmd->pip[1]);
	if (cmd->next == 0)
		close(cmd->pip[0]);
	if (cmd->fd_in != 0)
		close(cmd->fd_in);
	if (cmd->fd_out != 1)
		close(cmd->fd_out);
	dup2(*stin, 0);
	dup2(*stout, 1);
	close(*stin);
	close(*stout);
}

void	handle_syntax_error(t_state *s, t_cmd *cmd)
{
	if (cmd->type == ERROR_QUOTE)
		printf("error : quote error\n");
	else if (cmd->type == ERROR_PIPE)
		printf("bash: syntax error near unexpected token `|'\n");
	else if (cmd->type == ERROR_COLON)
		printf("bash: syntax error near unexpected token `;'\n");
	else if (cmd->type == ERROR_PIPE2)
		printf("bash: syntax error near unexpected token `||'\n");
	else if (cmd->type == ERROR_COLON2)
		printf("bash: syntax error near unexpected token `;;'\n");
	else if (cmd->type == ERROR_RDIR)
		printf("bash: syntax error near unexpected token `newline'\n");
	s->ret = 1;
}

void	execute(t_state *s, t_cmd *cmd, char **envp)
{
	t_cmd	*cur;
	int		stin;
	int		stout;

	if (!cmd)
		return ;
	if (cmd->type < 0)
		handle_syntax_error(s, cmd);
	else
	{
		cur = cmd;
		while (cur)
		{
			pipe(cur->pip);
			stin = dup(0);
			stout = dup(1);
			execute_cmd2(s, cur, envp);
			close_fd_dup(cur, &stin, &stout);
			cur = cur->next;
		}
	}
	save_history(s);
}
