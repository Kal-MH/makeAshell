/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 19:55:03 by mkal              #+#    #+#             */
/*   Updated: 2021/12/27 20:14:34 by mkal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_syntax_error(int cur_type, int next_type, int has_space)
{
	int	type;

	type = next_type;
	if (cur_type == ERROR_NULL && next_type >= PIPE)
	{
		if (next_type == PIPE)
			type = ERROR_PIPE;
	}
	else if ((cur_type >= PIPE || cur_type <= ERROR_PIPE) && next_type >= PIPE)
		type = check_deep_syntax_error(cur_type, next_type, has_space);
	else if (next_type == PIPE && (cur_type == SPACE
			|| ((cur_type >= LEFT && cur_type <= DOUBLERIGHT) && has_space)))
		type = ERROR_PIPE;
	return (type);
}

int	check_deep_syntax_error(int cur_type, int next_type, int has_space)
{
	int	type;

	type = next_type;
	if (cur_type == PIPE || cur_type == ERROR_PIPE)
	{
		if (next_type == PIPE)
			type = ERROR_PIPE2;
		else if (next_type == SEMICOLON)
			type = ERROR_COLON;
		if (has_space)
			type = ERROR_PIPE;
	}
	else if (cur_type == SEMICOLON || cur_type == ERROR_COLON)
	{
		if (next_type == SEMICOLON && !has_space)
			type = ERROR_COLON2;
		else if (next_type == PIPE)
			type = ERROR_PIPE;
	}
	return (type);
}

void	check_token_error(t_state *state)
{
	t_token	*token;
	char	**av;

	token = state->token_head;
	while (token)
	{
		if (token->type <= ERROR_QUOTE)
			return (return_quote_error(state, token));
		else if (token->type >= LEFT && token->type <= DOUBLERIGHT)
		{
			if (!token->next || is_operator_error(token->next->type))
			{
				av = make_empty_av(1);
				add_cmd_back(&g_state.cmd_head, av, ERROR_RDIR);
				free_token(g_state.token_head);
				return ;
			}
		}
		token = token->next;
	}
	parse_cmd(state, 0);
	free_token(g_state.token_head);
}

int	is_operator_error(int type)
{
	if ((type >= LEFT && type <= DOUBLERIGHT)
		|| (type >= PIPE && type <= DOLLAR))
		return (TRUE);
	return (FALSE);
}

void	return_quote_error(t_state *state, t_token *token)
{
	int		type;

	type = token->type;
	if (token->next)
	{
		if (token->next->type <= ERROR_PIPE2)
			type = token->next->type;
	}
	make_cmd(token, 1, type, 0);
	free_token(state->token_head);
}
