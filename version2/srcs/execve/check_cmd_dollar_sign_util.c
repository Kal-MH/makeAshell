/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd_dollar_sign_util.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkal <mkal@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 16:15:47 by mkal              #+#    #+#             */
/*   Updated: 2021/12/29 17:59:18 by mkal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_dollar_key_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$' || str[i] == '\''
			|| str[i] == ' ')
			break ;
		i++;
	}
	return (i);
}

static char	*get_env_value_condition(char *cmd, int *i, int *len_ptr)
{
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
		*len_ptr = check_dollar_key_len(&cmd[*i + 1]);
	}
	return (key);
}

static char	*get_env_value_condition_ret(char *cmd, int *i, int *len_ptr)
{
	int		len;
	char	*key;

	len = 0;
	key = 0;
	len = check_key_len(&cmd[*i + 1], 1);
	key = ft_substr(&cmd[*i + 1], 0, len);
	*len_ptr = len;
	return (key);
}

char	*get_env_value(char *cmd, int *i, int *b_onset)
{
	int		len;
	char	*key;
	char	*value;

	len = 0;
	value = 0;
	key = 0;
	if (*i > 0 && cmd[*i - 1] == '\\')
	{
		*b_onset = 1;
		*i = *i - 1;
	}
	else if (cmd[*i + 1])
	{
		if (!ft_strncmp(&cmd[*i + 1], "?", 1))
			key = get_env_value_condition_ret(cmd, i, &len);
		else
			key = get_env_value_condition(cmd, i, &len);
		if (key[0] == '?')
			value = insert_return_value(key);
		else
			value = ft_strdup(find_env_val(g_state.env_head, key));
		free(key);
	}
	return (changed_str(cmd, *i, *i + len, value));
}
