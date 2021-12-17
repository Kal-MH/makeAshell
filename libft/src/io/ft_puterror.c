/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:13:01 by napark            #+#    #+#             */
/*   Updated: 2021/12/12 15:13:02 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puterror(char *message)
{
	ft_printf("%s\n", message);
	exit(EXIT_FAILURE);
	return (EXIT_FAILURE);
}
