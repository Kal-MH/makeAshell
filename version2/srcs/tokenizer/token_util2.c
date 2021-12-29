/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_util2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkal <mkal@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:41:40 by mkal              #+#    #+#             */
/*   Updated: 2021/12/29 17:43:30 by mkal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_operator_two(char *c, int i)
{
	if (c[i] == ';')
		return (SEMICOLON);
	else if (c[i] == '|')
		return (PIPE);
	else if (c[i] == ' ')
		return (SPACE);
	else if (c[i] == '\\')
		return (BACKSLASH);
	else if (c[i] == '$')
		return (DOLLAR);
	return (COMMON);
}

static int	handle_dollar_sign(int *count, int i)
{
	*count = check_key_len(&g_state.input2[i + 1], 1);
	count++;
	return (COMMON);
}

void	tokenizer_loop(int i, int count, int type)
{
	while (g_state.input2[i])
	{
		count = 1;
		type = is_operator(g_state.input2, i);
		if (!type)
			count = get_len(g_state.input2, i);
		else if (type == DOUBLERIGHT || type == BACKSLASH || type == DOUBLELEFT)
			count = 2;
		else if (type == DOLLAR)
		{
			type = handle_dollar_sign(&count, i);
		}
		else if (type == SINGLE || type == DOUBLE)
		{
			count = find_end(&g_state, type, ++i);
			if (!count)
			{
				i = make_token(&g_state, 1, i - 1, ERROR_QUOTE);
				break ;
			}
		}
		i = make_token(&g_state, count, i, type);
	}
}
