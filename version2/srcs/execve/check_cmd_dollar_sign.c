/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd_dollar_sign.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkal <mkal@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 16:15:47 by mkal              #+#    #+#             */
/*   Updated: 2021/12/29 23:15:20 by mkal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	dollar_sign_loop_single(t_cmd *cmd, int i, int j)
{
	j += 2;
	while (cmd->av[i][j] && cmd->av[i][j] != '|')
		j++;
	return (j);
}

static void	check_cmd_dollar_sign_loop(t_cmd *cmd, int i)
{
	int		j;
	int		b_onset;
	char	*buf;

	j = 0;
	while (cmd->av[i][j])
	{
		b_onset = 0;
		if (cmd->av[i][j] == ';' && cmd->av[i][j + 1]
			&& cmd->av[i][j + 1] == '|')
			j = dollar_sign_loop_single(cmd, i, j);
		/*{
			j += 2;
			while (cmd->av[i][j] && cmd->av[i][j] != '|')
				j++;
		}*/
		else if (cmd->av[i][j] == '$')
		{
			buf = get_env_value(cmd->av[i], &j, &b_onset);
			free(cmd->av[i]);
			if (buf)
			{
				cmd->av[i] = ft_strdup(buf);
				free(buf);
			}
			if (cmd->av[i][j] && cmd->av[i][j] == '$' && !b_onset)
				j--;
		}
		j++;
	}
}

void	check_cmd_dollar_sign(t_cmd *cmd)
{
	int		i;

	i = 0;
	while (cmd->av[i])
	{
		check_cmd_dollar_sign_loop(cmd, i);
		i++;
	}
	if (!ft_strcmp(cmd->av[0], "echo"))
	{
		remove_single(cmd);
		//remove_back_one_line(cmd);
	}
}
