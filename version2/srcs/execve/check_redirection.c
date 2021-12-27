/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkal <mkal@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 06:10:12 by mkal              #+#    #+#             */
/*   Updated: 2021/12/27 15:21:45 by mkal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	heredoc_loop(int *pip, char *eof)
{
	char	*buf;

	while (1)
	{
		buf = readline("heredoc> ");
		if (buf == NULL)
		{
			if (close(pip[1]) != 0)
			{
				close(pip[0]);
				return (0);
			}
			return (1);
		}
		if (ft_strcmp(buf, eof) == 0)
			break ;
		write(pip[1], buf, ft_strlen(buf));
		write(pip[1], "\n", 1);
		free(buf);
	}
	free(buf);
	return (1);
}

static void	set_heredoc(t_cmd *cmd, char *eof)
{
	char	*heredoc_eof;
	int		pip[2];

	if (!eof)
	{
		cmd->fd_in = -1;
		return ;
	}
	heredoc_eof = ft_strdup(eof);
	if (pipe(pip) == -1 || heredoc_eof == NULL)
	{
		cmd->fd_in = -1;
		free(heredoc_eof);
		return ;
	}
	cmd->fd_in = pip[0];
	if (!heredoc_loop(pip, heredoc_eof))
	{
		cmd->fd_in = -1;
		free(heredoc_eof);
		return ;
	}
	if (close(pip[1]) != 0)
	{
		close(pip[0]);
		cmd->fd_in = -1;
		free(heredoc_eof);
		return ;
	}
	free(heredoc_eof);
}

static void	check_redirection_loop(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd->av[i])
	{
		if (cmd->av[i][0] == '>')
		{
			if (cmd->av[i][1] == '>')
				cmd->fd_out = open(cmd->av[i + 1], O_WRONLY
						| O_APPEND | O_CREAT, 0644);
			else
				cmd->fd_out = open(cmd->av[i + 1], O_WRONLY
						| O_TRUNC | O_CREAT, 0644);
		}
		if (cmd->av[i][0] == '<')
		{
			if (cmd->av[i][1] == '<')
				set_heredoc(cmd, cmd->av[i + 1]);
			else
				cmd->fd_in = open(cmd->av[i + 1], O_RDONLY);
		}
		i++;
	}
}

int	check_redirection(t_cmd *cmd)
{
	cmd->fd_in = 0;
	cmd->fd_out = 1;
	check_redirection_loop(cmd);
	if (cmd->fd_out == -1 || cmd->fd_in == -1)
		return (0);
	renewal_cmd(cmd);
	return (1);
}
