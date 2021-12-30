/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 00:18:01 by napark            #+#    #+#             */
/*   Updated: 2021/12/30 00:18:02 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*buf;

	buf = s;
	while (n > 0)
	{
		if (*buf == (unsigned char)c)
			return ((void *)buf);
		buf++;
		n--;
	}
	return (NULL);
}
