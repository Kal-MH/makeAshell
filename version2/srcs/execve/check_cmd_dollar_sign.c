/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd_dollar_sign.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkal <mkal@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 16:15:47 by mkal              #+#    #+#             */
/*   Updated: 2021/12/29 00:43:19 by mkal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_env_value_condition(char *cmd, int *i, int *len_ptr)
{
	//int	len;
	char	*key;
	t_env	*head;

	key = 0;
	*len_ptr = 0;
	head = g_state.env_head;
	while (head)
	{
		if (!ft_strncmp(head->key, &cmd[*i + 1], ft_strlen(head->key)))
		{
			*len_ptr = ft_strlen(head->key);
			key = ft_substr(&cmd[*i + 1], 0, *len_ptr);
			break ;
		}
		head = head->next;
	}
	if (key == 0)
	{
		key = ft_strdup("");
		*len_ptr = check_key_len(&cmd[*i + 1], 0);
	}
	return (key);
}

static char	*get_env_value_condition_ret(char *cmd, int *i, int *len_ptr)
{
	int	len;
	char	*key;

	len = 0;
	key = 0;
	len = check_key_len(&cmd[*i + 1], 1);
	key = ft_substr(&cmd[*i + 1], 0, len);
	*len_ptr = len;
	return (key);
}

char	*get_env_value(char *cmd, int *i)
{
	int		len;
	char	*key;
	char	*value;
	//t_env	*head;

	len = 0;
	value = 0;
	key = 0;
	if (*i > 0 && cmd[*i - 1] == '\\')
		*i = *i - 1;
	else if (cmd[*i + 1])
	{
		if (!ft_strncmp(&cmd[*i + 1], "?", 1))
			key = get_env_value_condition_ret(cmd, i, &len);
		/*{
			len = check_key_len(&cmd[*i + 1], 1);
			key = ft_substr(&cmd[*i + 1], 0, len);
		}*/
		else
			key = get_env_value_condition(cmd, i, &len);
		/*if (!ft_strncmp(&cmd[*i + 1], "?", 1))
		{
			len = check_key_len(&cmd[*i + 1], 1);
			key = ft_substr(&cmd[*i + 1], 0, len);
		}
		else
		{
			head = g_state.env_head;
			while (head)
			{
				if (!ft_strncmp(head->key, &cmd[*i + 1], ft_strlen(head->key)))
				{
					len = ft_strlen(head->key);
					key = ft_substr(&cmd[*i + 1], 0, len);
					break ;
				}
				head = head->next;
			}
		}*/
		if (key[0] == '?')
			value = insert_return_value(key);
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
	int		single_i;
	char	*buf;
	char	*tmp;

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
