/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:15:10 by napark            #+#    #+#             */
/*   Updated: 2021/12/12 15:15:11 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	int		full_size;
	char	*buf;

	full_size = size * count;
	buf = malloc(full_size);
	if (buf == NULL)
		return (NULL);
	return (ft_memset((void *)buf, 0, full_size));
}
