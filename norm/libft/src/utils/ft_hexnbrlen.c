/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexnbrlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 00:24:57 by napark            #+#    #+#             */
/*   Updated: 2021/12/30 00:24:57 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hexnbrlen(unsigned long long nbr)
{
	int	count;

	if (nbr == 0)
		return (1);
	count = 0;
	while (nbr != 0)
	{
		nbr /= 16;
		count++;
	}
	return (count);
}
