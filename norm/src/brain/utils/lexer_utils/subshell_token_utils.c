/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subshell_token_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 01:44:37 by napark            #+#    #+#             */
/*   Updated: 2021/12/30 00:02:20 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer_utils.h"

bool	token_is_subshell(char *token)
{
	if (token[0] == '(' || ft_strchr(token, ')') != NULL)
		return (true);
	return (false);
}

int	get_subshell_count(char *tokens[], int i)
{
	int	count;
	int	opened_brackets;

	count = 0;
	opened_brackets = 0;
	while (tokens[i])
	{
		if (ft_strchr(tokens[i], '('))
		{
			opened_brackets++;
			count++;
		}
		else if (ft_strchr(tokens[i], ')'))
		{
			opened_brackets--;
			count++;
		}
		if (opened_brackets == 0)
			break ;
		i++;
	}
	return (count);
}

int	jump_to_end_of_subshell(char *tokens[], int i)
{
	int	subshell_count;

	subshell_count = get_subshell_count(tokens, i);
	while (tokens[i] && subshell_count)
	{
		if (token_is_subshell(tokens[i]))
			subshell_count--;
		i++;
	}
	return (i);
}

char	*get_end_of_subshell(char *tokens[], int *i, char *sub_tok)
{
	char	*tmp;
	int		sub_len;

	sub_len = ft_strrchr(tokens[*i], ')') - tokens [*i];
	tmp = ft_substr(tokens[*i], 0, sub_len + 1);
	sub_tok = ft_append(&sub_tok, tmp);
	free(tmp);
	tmp = tokens[*i];
	tokens[*i] = ft_substr(tmp, sub_len + 1, ft_strlen(tokens[*i]));
	free(tmp);
	return (sub_tok);
}
