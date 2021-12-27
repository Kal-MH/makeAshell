/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cmd_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkal <mkal@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 13:42:16 by mkal              #+#    #+#             */
/*   Updated: 2021/12/27 18:20:02 by mkal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	make_cmd_loop(t_token *start, char **av, int *i)
{
	if ((start->type >= LEFT && start->type <= DOUBLERIGHT && av[*i]))
		(*i)++;
	else if (!ft_strcmp(av[*i], "<") || !ft_strcmp(av[*i], ">"))
		(*i)++;
	else if (!ft_strcmp(av[*i], "<<") || !ft_strcmp(av[*i], ">>"))
		(*i)++;
	else if (start->type == DOUBLE || start->type == COMMON)
		check_backslash_and_env(&g_state, start);
}
