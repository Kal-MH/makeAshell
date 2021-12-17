/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 00:03:10 by napark            #+#    #+#             */
/*   Updated: 2021/12/18 00:37:46 by mkal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "brain.h"
#include "env_var_utils.h"

static int	execute_inbuilt(char *cmd[])
{
	if (ft_strcmp(cmd[0], "echo") == 0)
		return (echo(cmd));
	if (ft_strcmp(cmd[0], "export") == 0)
		return (export(cmd));
	if (ft_strcmp(cmd[0], "env") == 0)
		return (env(cmd));
	if (ft_strcmp(cmd[0], "cd") == 0)
		return (cd(cmd));
	if (ft_strcmp(cmd[0], "unset") == 0)
		return (unset(cmd));
	if (ft_strcmp(cmd[0], "pwd") == 0)
		return (pwd());
	if (ft_strcmp(cmd[0], "exit") == 0)
		return (exit_inbuilt(cmd));
	return (EXIT_FAILURE);
}

/**
 * @brief  This is stolen from somewhere, idk from where
 * @note   i have no clue how or why this is working
 * @param  *exp_tok:
 * @retval the exit status of the inbuilt function
 */
static int	handle_inbuilt_redir(t_exp_tok *exp_tok)
{
	int	exit_status;
	int	s;

	if (exp_tok->in != STDIN_FILENO)
		dup2(exp_tok->in, STDIN_FILENO);
	if (exp_tok->out != STDOUT_FILENO)
	{
		s = dup(STDOUT_FILENO);
		dup2(exp_tok->out, STDOUT_FILENO);
	}
	exit_status = execute_inbuilt(exp_tok->cmd);
	if (exp_tok->in != STDIN_FILENO)
	{
		close(exp_tok->in);
		dup2(0, exp_tok->in);
	}
	if (exp_tok->out != STDOUT_FILENO)
	{
		dup2(s, STDOUT_FILENO);
		close(s);
	}
	return (exit_status);
}

static char	*get_clean_cmd(char *cmd)
{
	char	*cleaned;
	int		cmd_len;
	int		i;
	int		j;

	cmd_len = ft_strlen(cmd);
	if (cmd[0] != '\'' && cmd[0] != '\"')
		return (cmd);
	if (cmd[cmd_len - 1] != cmd[0])
		return (cmd);
	cleaned = ft_calloc(ft_strlen(cmd) + 1, sizeof(*cleaned));
	if (cleaned == NULL)
	{
		free(cmd);
		return (NULL);
	}
	i = 1;
	j = 0;
	while (i < cmd_len - 1)
		cleaned[j++] = cmd[i++];
	free(cmd);
	return (cleaned);
}

static int	clean_exp_tok_cmds(t_exp_tok *exp_tok)
{
	int		i;

	i = 0;
	while (exp_tok->cmd[i])
	{
		exp_tok->cmd[i] = get_clean_cmd(exp_tok->cmd[i]);
		if (exp_tok->cmd[i] == NULL)
		{
			ft_free_split(exp_tok->cmd);
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	executor(t_exp_tok *exp_tok)
{
	int		exit_status;
	char	*abs_cmd_path;

	if (clean_exp_tok_cmds(exp_tok) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (is_inbuilt(exp_tok->cmd[0]))
		return (handle_inbuilt_redir(exp_tok));
	abs_cmd_path = NULL;
	if (!is_valid_cmd(exp_tok->cmd[0], &abs_cmd_path))
	{
		ft_putstr_fd(exp_tok->cmd[0], STDERR_FILENO);
		ft_putstr_fd(": command not found\n", STDERR_FILENO);
		return (EXIT_CMD_NOT_FOUND);
	}
	exit_status = execute_cmd(exp_tok, abs_cmd_path);
	free(abs_cmd_path);
	return (exit_status);
}
