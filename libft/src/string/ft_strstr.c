/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:20:20 by napark            #+#    #+#             */
/*   Updated: 2021/12/12 15:20:20 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s, const char *to_find)
{
	int	i;

	if (ft_strlen(to_find) == 0)
		return ((char *)s);
	i = 0;
	while (s && *s)
	{
		if (*s == *to_find)
		{
			i = 0;
			while (s[i] == to_find[i] && s[i])
				i++;
			if (i == ft_strlen(to_find))
				return ((char *)s);
		}
		s++;
	}
	return (0);
}
