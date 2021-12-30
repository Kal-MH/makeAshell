/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 00:15:53 by napark            #+#    #+#             */
/*   Updated: 2021/12/30 00:15:54 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr_fd(int fd, void *ptr)
{
	return (ft_putstr_fd(fd, "0x") + \
	ft_putlhex_fd(fd, (unsigned long long)ptr));
}
