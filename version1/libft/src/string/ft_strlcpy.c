/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:19:27 by napark            #+#    #+#             */
/*   Updated: 2021/12/12 15:19:29 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static size_t	ft_get_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	if (dst == NULL || src == NULL)
		return (-1);
	i = 0;
	if (n == 0)
		return (ft_get_strlen(src));
	while (n - 1 > 0 && src[i])
	{
		dst[i] = src[i];
		i++;
		n--;
	}
	dst[i] = 0;
	return (ft_get_strlen(src));
}
