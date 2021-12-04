/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 12:15:33 by napark            #+#    #+#             */
/*   Updated: 2021/12/04 12:22:45 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//error처리를 위한 시그널 처리

#include "minishell.h"

void    none_ctrl(void)
{
    ft_putchar_fd("error", 1);
    exit(1);
}