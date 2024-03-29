/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkal <mkal@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 06:10:12 by mkal              #+#    #+#             */
/*   Updated: 2021/12/27 20:03:02 by mkal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_pipe(t_cmd *cmd)
{
	if (cmd->type == PIPE_TYPE
		|| (cmd->next != 0 && cmd->next->type == PIPE_TYPE))
	{
		if (cmd->type != PIPE_TYPE)
			dup2(cmd->pip[1], 1);
		else if (cmd->next == 0 || cmd->type == COLON_TYPE)
			dup2(cmd->prev->pip[0], 0);
		else
		{
			dup2(cmd->prev->pip[0], 0);
			dup2(cmd->pip[1], 1);
		}
	}
}

char	**make_new_cmd(t_cmd *cmd, int cnt, char **new)
{
	int	i;
	int	j;

	if (!ft_calloc(cnt + 1, sizeof(char *), (void **)&new))
		exit(1);
	i = 0;
	j = 0;
	while (cmd->ac > i)
	{
		if (cmd->av[i][0] == '<' || cmd->av[i][0] == '>')
			i++;
		else
		{
			new[j] = ft_strdup(cmd->av[i]);
			if (!new[j])
				exit(1);
			j++;
		}
		i++;
	}
	new[cnt] = 0;
	return (new);
}

void	renewal_cmd(t_cmd *cmd)
{
	char	**new;
	int		cnt;
	int		i;

	i = 0;
	cnt = 0;
	while (cmd->ac > i)
	{
		if (cmd->av[i][0] == '<' || cmd->av[i][0] == '>')
			cnt++;
		i++;
	}
	if (cnt == 0)
		return ;
	cnt = cmd->ac - (cnt * 2);
	new = 0;
	new = make_new_cmd(cmd, cnt, new);
	free_2d(cmd->av);
	cmd->av = new;
	cmd->ac = cnt;
}

void	execute_error(t_state *s, t_cmd *cmd, int type)
{
	if (type == EXECVE_ERR)
	{
		printf("bash: %s: %s\n", cmd->av[0], strerror(errno));
		if (errno == 13)
			exit(126);
		else if (errno == 2)
			exit(127);
		exit(1);
	}
	else if (type == NOT_FOUND || type == NO_F_OR_D)
	{
		if (!find_env(s->env_head, "PATH"))
			type = 4;
		if (type == 2)
			printf("bash: %s: command not found\n", cmd->av[0]);
		else if (type == 4)
			printf("bash: %s: No such file or directory\n", cmd->av[0]);
		s->ret = 127;
	}
	else if (type == IS_DIR)
	{
		printf("bash: %s: is a directory\n", cmd->av[0]);
		s->ret = 126;
	}
}
