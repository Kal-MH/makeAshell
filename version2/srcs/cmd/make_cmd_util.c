/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cmd_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkal <mkal@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 13:42:16 by mkal              #+#    #+#             */
/*   Updated: 2021/12/28 15:48:38 by mkal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	make_cmd_condition(t_token *start, char **av, int *i)
{
	if ((start->type >= LEFT && start->type <= DOUBLERIGHT && av[*i]))
		(*i)++;
	else if ((!ft_strcmp(av[*i], "<") || !ft_strcmp(av[*i], ">")) && av[*i])
		(*i)++;
	else if ((!ft_strcmp(av[*i], "<<") || !ft_strcmp(av[*i], ">>")) && av[*i])
		(*i)++;
	else if (start->type == DOUBLE || start->type == COMMON)
		check_backslash_and_env(&g_state, start);
}
