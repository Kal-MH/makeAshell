/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:20:13 by napark            #+#    #+#             */
/*   Updated: 2021/12/12 15:20:14 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * Returns the first found character of set in str 
 * or NULL if no character of set is found in str 
 */
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
