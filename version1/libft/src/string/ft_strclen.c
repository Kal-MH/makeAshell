/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:18:31 by napark            #+#    #+#             */
/*   Updated: 2021/12/12 15:18:31 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
will measure the length of str until first occurance of c or end of string
*/
int	ft_strclen(char *str, char c)
{
	int	len;

	len = 0;
	while (str && str[len] && str[len] != c)
		len++;
	return (len);
}
