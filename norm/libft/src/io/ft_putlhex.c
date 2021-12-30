/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlhex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 00:15:18 by napark            #+#    #+#             */
/*   Updated: 2021/12/30 00:15:19 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putlhex(unsigned long long nbr)
{
	char	*hex;
	int		printed_chars;

	hex = ft_htoa(nbr, 0);
	if (hex == NULL)
		return (0);
	printed_chars = ft_putstr(hex);
	free(hex);
	return (printed_chars);
}
