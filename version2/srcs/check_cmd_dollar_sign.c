/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd_dollar_sign.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkal <mkal@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 16:15:47 by mkal              #+#    #+#             */
/*   Updated: 2021/12/24 00:45:59 by mkal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env_value(char *cmd, int *i)
{
	int		len;
	char	*key;
	char	*value;
	char	*temp;

	len = 0;
	value = 0;
	if (*i > 0 && cmd[*i - 1] == '\\')
		*i = *i - 1;
	else if (cmd[*i + 1])
	{
		len = check_key_len(&cmd[*i + 1], FALSE);
		key = ft_substr(&cmd[*i + 1], 0, len);
		if (!ft_strcmp(key, "?"))
		{
			temp = ft_itoa(g_state.ret);
			value = ft_strdup(temp);
			free(temp);
		}
		else
			value = ft_strdup(find_env_val(g_state.env_head, key));
	}
	return (changed_str(cmd, *i, *i + len, value));
}

static void	check_cmd_dollar_sign_loop(t_cmd *cmd, int i)
{
	int		j;
	char	*buf;

	j = 0;
	while (cmd->av[i][j])
	{
		if (cmd->av[i][j] == '$')
		{
			buf = get_env_value(cmd->av[i], &j);
			free(cmd->av[i]);
			if (buf)
			{
				cmd->av[i] = ft_strdup(buf);
				free(buf);
			}
		}
		j++;
	}
}

void	check_cmd_dollar_sign(t_cmd *cmd)
{
	int		i;
	char	*buf;

	i = 0;
	while (cmd->av[i])
	{
		if (cmd->av[i][0] == '\'')
		{
			buf = ft_strdup(&cmd->av[i][1]);
			free(cmd->av[i]);
			cmd->av[i] = ft_strdup(buf);
			free(buf);
		}
		else
			check_cmd_dollar_sign_loop(cmd, i);
		i++;
	}
}
