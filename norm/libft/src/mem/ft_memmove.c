/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 00:18:19 by napark            #+#    #+#             */
/*   Updated: 2021/12/30 00:18:19 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	const char	*src_buf;
	char		*dst_buf;

	if (dst > src)
	{
		src_buf = src + n - 1;
		dst_buf = dst + n - 1;
	}
	else
		return (ft_memcpy(dst, (void *)src, n));
	while (n > 0)
	{
		*dst_buf = *src_buf;
		dst_buf--;
		src_buf--;
		n--;
	}
	return (dst);
}
