/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pipe_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 01:41:43 by napark            #+#    #+#             */
/*   Updated: 2021/12/29 23:59:48 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "brain.h"
#include "expander_utils.h"

int	set_pipe_type(t_par_tok **par_toks, int i)
{
	int	pipe_type;

	pipe_type = -1;
	if (par_toks[i]->redir_type[is_pipe] == false)
		return (pipe_type);
	else if (i > 0)
	{
		if (par_toks[i - 1]->redir_type[is_pipe]
			&& par_toks[i]->redir_type[is_pipe] && (par_toks[i + 1] == NULL
				|| par_toks[i + 1]->redir_type[is_pipe] == false))
			pipe_type = 0;
		else if (par_toks[i - 1]->redir_type[is_pipe] == false
			&& par_toks[i]->redir_type[is_pipe] && par_toks[i + 1] != NULL
			&& par_toks[i + 1]->redir_type[is_pipe])
			pipe_type = 1;
		else if (par_toks[i - 1]->redir_type[is_pipe]
			&& par_toks[i]->redir_type[is_pipe] && par_toks[i + 1] != NULL
			&& par_toks[i + 1]->redir_type[is_pipe])
			pipe_type = 2;
	}
	else if (par_toks[i]->redir_type[is_pipe] && par_toks[i + 1] != NULL
		&& par_toks[i + 1]->redir_type[is_pipe])
		pipe_type = 1;
	return (pipe_type);
}
