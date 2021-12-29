/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkal <mkal@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 19:55:03 by mkal              #+#    #+#             */
/*   Updated: 2021/12/29 17:43:49 by mkal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	tokenizer(int i, int count)
{
	int		type;

	if (!g_state.input2)
		return ;
	type = 42;
	tokenizer_loop(i, count, type);
	check_token_error(&g_state);
}

int	make_token(t_state *state, int count, int i, int type)
{
	char	*token_str;
	int		j;

	if (!ft_calloc(count + 1, sizeof(char), (void *)&token_str))
		exit(1);
	j = 0;
	while (j < count)
		token_str[j++] = state->input2[i++];
	token_str[j] = '\0';
	add_token_back(&state->token_head, token_str, type);
	free(token_str);
	return (i);
}

void	add_token_back(t_token **head, char *str, int type)
{
	t_token	*token;
	int		token_type;
	int		cur_type;
	int		has_space;

	str = trim_str(str, type);
	has_space = FALSE;
	if (*head == NULL)
	{
		token_type = check_syntax_error(ERROR_NULL, type, has_space);
		*head = create_token(str, token_type);
	}
	else
	{
		token = *head;
		while (token->next)
			token = token->next;
		cur_type = find_cur_type(head, &has_space);
		token_type = check_syntax_error(cur_type, type, has_space);
		token->next = create_token(str, token_type);
	}
}

char	*trim_str(char *str, int type)
{
	int	i;

	if (type == SINGLE || type == DOUBLE)
		str[ft_strlen(str) - 1] = '\0';
	else if (type == BACKSLASH
		&& (str[1] == '\\' || !is_operator(str, 1)))
	{
		i = 0;
		str[i] = str[i + 1];
		str[i + 1] = '\0';
	}
	return (str);
}

int	find_cur_type(t_token **head, int *has_space)
{
	t_token	*token;
	int		type;

	token = *head;
	type = token->type;
	while (token)
	{
		if (token->type != SPACE)
		{
			type = token->type;
			*has_space = FALSE;
		}
		else
			*has_space = TRUE;
		token = token->next;
	}
	return (type);
}
