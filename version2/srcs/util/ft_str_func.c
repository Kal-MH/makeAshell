/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkal <mkal@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 00:20:02 by mkal              #+#    #+#             */
/*   Updated: 2021/12/29 17:44:11 by mkal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strchr_index(char *str, int c)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == (char) c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_strhas(char *str, char *set)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (!ft_strncmp(&str[i], set, ft_strlen(set)))
			return (i);
		i++;
	}
	return (-1);
}
