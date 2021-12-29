/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:18:36 by napark            #+#    #+#             */
/*   Updated: 2021/12/12 15:18:41 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/* returns the value of the difference found in two strings, 0 if equal */
int	ft_strcmp(const char *s1, const char *s2)
{
	const unsigned char	*buf1;
	const unsigned char	*buf2;

	buf1 = (const unsigned char *)s1;
	buf2 = (const unsigned char *)s2;
	if (*buf1 != *buf2)
		return (*buf1 - *buf2);
	while (*buf1 && *buf2)
	{
		if (*buf1 != *buf2)
			return (*buf1 - *buf2);
		buf1++;
		buf2++;
	}
	if (*buf1 == '\0' && *buf2 != '\0')
		return (0 - *buf2);
	else if (*buf2 == '\0' && *buf1 != '\0')
		return (*buf1);
	return (0);
}
