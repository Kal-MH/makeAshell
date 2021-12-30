/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 00:21:55 by napark            #+#    #+#             */
/*   Updated: 2021/12/30 00:21:58 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strclen(char *str, char c)
{
	int	len;

	len = 0;
	while (str && str[len] && str[len] != c)
		len++;
	return (len);
}
