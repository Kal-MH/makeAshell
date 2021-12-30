/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strhas.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 00:22:18 by napark            #+#    #+#             */
/*   Updated: 2021/12/30 00:22:22 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strhas(char *str, char *set)
{
	int	i;

	while (str && *str)
	{
		i = 0;
		while (set && set[i])
		{
			if (*str == set[i])
				return (true);
			i++;
		}
		str++;
	}
	return (false);
}
