/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:11:32 by napark            #+#    #+#             */
/*   Updated: 2021/12/12 16:14:23 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    handle_signal(int signal)
{
    if (signal == SIGQUIT)
        return ;
    if (signal == SIGINT)
    {
        ft_printf("\nminishell$");
    }
}