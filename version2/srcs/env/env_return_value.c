/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_return_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkal <mkal@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:06:29 by mkal              #+#    #+#             */
/*   Updated: 2021/12/27 20:20:21 by mkal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*insert_return_value(char *key)
{
	char	*temp;
	char	*value;
	char	*result;

	temp = ft_itoa(g_state.ret);
	value = ft_strdup(&key[1]);
	result = ft_strjoin(temp, value);
	free(temp);
	free(value);
	return (result);
}

char	*change_return_value(char *key)
{
	char	*temp;

	(void)key;
	temp = ft_itoa(g_state.ret);
	return (temp);
}
