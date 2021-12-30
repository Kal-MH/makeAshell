/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 00:23:14 by napark            #+#    #+#             */
/*   Updated: 2021/12/30 00:23:14 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strnstr(const char *s, const char *to_find, size_t n)
{
	int	i;

	if (s == NULL && to_find == NULL)
		return (NULL);
	if (ft_strlen(to_find) == 0)
		return ((char *)s);
	i = 0;
	while (*s && n > 0)
	{
		if (*s == *to_find)
		{
			i = 0;
			while (n > 0 && s[i] == to_find[i] && s[i])
			{
				i++;
				n--;
			}
			if (i == ft_strlen(to_find))
				return ((char *)s);
			n += i;
		}
		s++;
		n--;
	}
	return (0);
}
