/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_util2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkal <mkal@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:03:10 by mkal              #+#    #+#             */
/*   Updated: 2021/12/27 20:07:55 by mkal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	execve_stdout(t_cmd *cmd)
{
	int	n;
	char	buf[10];

	n = 0;
	while (1)
	{
		n = read(cmd->fd_in, buf, 10);
		if (n <= 0)
			break ;
		write(1, buf, n);
	}
}

static void	execve_stdin(t_cmd *cmd)
{
	int	n;
	char	buf[10];

	n = 0;
	while (1)
	{
		n = read(0, buf, 9);
		if (n <= 0)
			break ;
		buf[n] = 0;
		write(cmd->fd_out, buf, n);
	}
}

void	execve_std(t_cmd *cmd)
{
	if (cmd->fd_in > 0)
		execve_stdout(cmd);
	else if (cmd->fd_out > 1)
		execve_stdin(cmd);
}
