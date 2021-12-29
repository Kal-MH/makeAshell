/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_sub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 00:03:47 by napark            #+#    #+#             */
/*   Updated: 2021/12/29 14:33:37 by mkal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "brain.h"
#include "expander_utils.h"

int	free_exp_toks(t_exp_tok *exp_toks[], int exit_status)
{
	int	i;

	i = 0;
	while (exp_toks[i])
	{
		ft_free_str_array(&exp_toks[i]->cmd);
		free(exp_toks[i]);
		i++;
	}
	free(exp_toks);
	reset_exp_toks();
	return (exit_status);
}

size_t	get_tok_size(t_par_tok *par_toks[])
{
	size_t	size;

	size = 0;
	while (par_toks[size])
		size++;
	return (size);
}

static int	init(t_exp_tok **exp_tok)
{
	*exp_tok = malloc(sizeof(**exp_tok));
	if (*exp_tok == NULL)
		return (EXIT_FAILURE);
	(*exp_tok)->cmd = NULL;
	(*exp_tok)->in = 0;
	(*exp_tok)->out = 1;
	return (EXIT_SUCCESS);
}

int	get_tokens_expander(t_par_tok *par_toks[])
{
	t_exp_tok	**exp_toks;
	int			i;

	exp_toks = ft_calloc(get_tok_size(par_toks) + 1, sizeof(*exp_toks));
	if (exp_toks == NULL)
		return (EXIT_FAILURE);
	set_exp_toks(exp_toks);
	i = 0;
	while (par_toks[i])
	{
		if (init(&exp_toks[i]) == EXIT_FAILURE)
			return (free_exp_toks(exp_toks, EXIT_FAILURE));
		if (par_toks[i]->cmd)
		{
			exp_toks[i]->cmd = ft_str_arr_dup(par_toks[i]->cmd);
			if (exp_toks[i]->cmd == NULL)
				return (free_exp_toks(exp_toks, EXIT_FAILURE));
		}
		if (par_toks[i]->redir_type[is_in_heredoc])
			if (wait_for_heredoc(par_toks[i], exp_toks[i]) == EXIT_FAILURE)
				return (free_exp_toks(exp_toks, EXIT_FAILURE));
		i++;
	}
	return (EXIT_SUCCESS);
}

char	*get_subshell_cmd(char *cmd)
{
	char	*subshell_cmd;
	int		cmd_len;
	int		i;
	int		j;

	cmd_len = ft_strlen(cmd);
	subshell_cmd = ft_calloc(cmd_len + 1, sizeof(*subshell_cmd));
	if (subshell_cmd == NULL)
		return (NULL);
	i = 1;
	j = 0;
	while (i < cmd_len - 2)
	{
		subshell_cmd[j] = cmd[i];
		i++;
		j++;
	}
	return (subshell_cmd);
}
