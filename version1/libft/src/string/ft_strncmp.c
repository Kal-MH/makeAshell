/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:19:46 by napark            #+#    #+#             */
/*   Updated: 2021/12/12 15:19:48 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*buf1;
	const unsigned char	*buf2;

	buf1 = (const unsigned char *)s1;
	buf2 = (const unsigned char *)s2;
	if (*buf1 != *buf2 && n > 0)
		return (*buf1 - *buf2);
	while ((*buf1 || *buf2) && n > 0)
	{
		if (*buf1 != *buf2)
			return (*buf1 - *buf2);
		buf1++;
		buf2++;
		n--;
	}
	return (0);
}
