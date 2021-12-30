/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 00:23:26 by napark            #+#    #+#             */
/*   Updated: 2021/12/30 00:23:30 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strset(char *str, char *set)
{
	int	i;

	i = 0;
	while (str && *str)
	{
		i = 0;
		while (set && set[i])
		{
			if (*str == set[i])
				return (str);
			i++;
		}
		str++;
	}
	return (NULL);
}
