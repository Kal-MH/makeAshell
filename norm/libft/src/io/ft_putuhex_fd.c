/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuhex_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 00:16:25 by napark            #+#    #+#             */
/*   Updated: 2021/12/30 00:16:26 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putuhex_fd(int fd, unsigned long long nbr)
{
	char	*hex;
	int		printed_chars;

	hex = ft_htoa(nbr, 1);
	if (hex == NULL)
		return (0);
	printed_chars = ft_putstr_fd(fd, hex);
	free(hex);
	return (printed_chars);
}
