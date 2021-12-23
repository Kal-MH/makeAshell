/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:20:05 by napark            #+#    #+#             */
/*   Updated: 2021/12/12 15:20:08 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*p;

	i = ft_strlen(s);
	p = NULL;
	while (i >= 0)
	{
		if (s[i] == (char)c)
		{
			p = &s[i];
			return ((char *)p);
		}
		i--;
	}
	return ((char *)p);
}
