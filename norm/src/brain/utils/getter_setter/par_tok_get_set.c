/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par_tok_get_set.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 01:39:01 by napark            #+#    #+#             */
/*   Updated: 2021/12/30 00:00:51 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brain.h"
#include "parser_utils.h"
#include "minishell.h"

static t_par_tok	**_get_par_toks(t_par_tok **par_toks, bool reset)
{
	static t_par_tok	**static_par_toks = NULL;

	if (par_toks == NULL && !reset)
		return (static_par_toks);
	if (reset)
	{
		static_par_toks = NULL;
		return (NULL);
	}
	static_par_toks = par_toks;
	return (static_par_toks);
}

t_par_tok	*get_curr_par_tok(void)
{
	t_iter	*iter;

	iter = get_iter();
	if (iter == NULL)
		return (NULL);
	return (get_par_toks()[iter[par]]);
}

t_par_tok	**get_par_toks(void)
{
	return (_get_par_toks(NULL, false));
}

void	set_par_toks(t_par_tok **par_toks)
{
	_get_par_toks(par_toks, false);
}

void	reset_par_toks(void)
{
	_get_par_toks(NULL, true);
}
