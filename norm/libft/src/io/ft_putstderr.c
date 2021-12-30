/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstderr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 00:16:04 by napark            #+#    #+#             */
/*   Updated: 2021/12/30 00:16:05 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	putstderr(char *error_message)
{
	write(2, error_message, ft_strlen(error_message));
	exit(EXIT_FAILURE);
	return (EXIT_FAILURE);
}
