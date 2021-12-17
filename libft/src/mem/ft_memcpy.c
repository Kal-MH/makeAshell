/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:15:27 by napark            #+#    #+#             */
/*   Updated: 2021/12/12 15:15:27 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	char	*src_buf;
	char	*dst_buf;

	if (dst == NULL && src == NULL)
		return (NULL);
	src_buf = src;
	dst_buf = dst;
	while (n > 0)
	{
		*dst_buf = *src_buf;
		dst_buf++;
		src_buf++;
		n--;
	}
	return (dst);
}
