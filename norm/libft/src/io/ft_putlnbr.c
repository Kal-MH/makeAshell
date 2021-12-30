/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 00:15:32 by napark            #+#    #+#             */
/*   Updated: 2021/12/30 00:15:32 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putlnbr(long nbr)
{
	int		printed_chars;
	char	*s;

	s = ft_itoa(nbr);
	if (s == NULL)
		return (0);
	printed_chars = ft_putstr(s);
	free(s);
	s = NULL;
	return (printed_chars);
}
