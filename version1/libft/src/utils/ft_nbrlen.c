/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:21:27 by napark            #+#    #+#             */
/*   Updated: 2021/12/12 15:21:27 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbrlen(long nbr)
{
	int	count;

	if (nbr == 0)
		return (1);
	count = 0;
	while (nbr != 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}
