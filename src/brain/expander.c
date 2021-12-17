/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 00:03:47 by napark            #+#    #+#             */
/*   Updated: 2021/12/18 00:57:08 by mkal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "brain.h"
#include "expander_utils.h"

static int	repinterprete_env_vars(t_par_tok *par_toks[], t_exp_tok *exp_toks[])
{
	int	i;
	int	j;

	i = 0;
	while (par_toks[i] && exp_toks[i] && par_toks[i]->type == std)
	{
		j = 0;
		while (exp_toks[i]->cmd[j])
		{
			exp_toks[i]->cmd[j] = interprete_env_var(exp_toks[i]->cmd[j]);
			if (exp_toks[i]->cmd[j] == NULL)
				return (EXIT_FAILURE);
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

static int	handle_tokens(t_exp_tok *exp_toks[], t_par_tok *par_toks[])
{
	int	i;
	int	pipe_type;

	i = 0;
	while (exp_toks[i] && par_toks[i])
	{
		pipe_type = set_pipe_type(par_toks, i);
		if (par_toks[i]->type == and || par_toks[i]->type == or)
		{
			if ((par_toks[i]->type == and && get_err_code() != EXIT_SUCCESS) \
			|| (par_toks[i]->type == or && get_err_code() == EXIT_SUCCESS))
			{
				set_err_code(EXIT_FAILURE);
				return (EXIT_SUCCESS);
			}
			if (repinterprete_env_vars(&par_toks[i + 1],
					&exp_toks[i + 1]) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
		else if (par_toks[i]->type == subshell)
			set_err_code(handle_subshell(exp_toks[i]->cmd[0]));
		else if (is_redir_expander(par_toks[i]))
			set_err_code(handle_redir(par_toks[i], exp_toks[i], pipe_type));
		else
			set_err_code(executor(exp_toks[i]));
		i++;
	}
	return (EXIT_SUCCESS);
}

int	expander(t_par_tok *par_toks[])
{
	t_exp_tok	**exp_toks;

	if (get_tokens_expander(par_toks) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	exp_toks = get_exp_toks();
	return (free_exp_toks(exp_toks, handle_tokens(exp_toks, par_toks)));
}
