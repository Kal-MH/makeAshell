/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:16:26 by napark            #+#    #+#             */
/*   Updated: 2021/12/12 15:16:27 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_chrcount(const char *str, char ch)
{
	int	count;

	count = 0;
	while (str && *str)
	{
		if (*str == ch)
			count++;
		str++;
	}
	return (count);
}
