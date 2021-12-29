/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_sub2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 00:03:47 by napark            #+#    #+#             */
/*   Updated: 2021/12/29 14:29:59 by mkal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "brain.h"
#include "expander_utils.h"

int	handle_subshell(char *cmd)
{
	pid_t	pid;
	int		status;
	char	*cutted_cmd;

	pid = fork();
	if (pid < 0)
		return (EXIT_FAILURE);
	if (pid == 0)
	{
		cutted_cmd = get_subshell_cmd(cmd);
		if (cutted_cmd == NULL)
			return (EXIT_FAILURE);
		status = lexer(cutted_cmd);
		free(cutted_cmd);
		exit(get_err_code());
		return (get_err_code());
	}
	waitpid(pid, &status, 0);
	set_err_code(WEXITSTATUS(status));
	return (WEXITSTATUS(status));
}

bool	is_redir(t_par_tok *par_tok)
{
	if (par_tok->redir_type[is_in] || par_tok->redir_type[is_in_heredoc] \
	|| par_tok->redir_type[is_out] || par_tok->redir_type[is_out_append] \
	|| par_tok->redir_type[is_pipe])
		return (true);
	return (false);
}

char		*interprete_env_var(char *lex_tok);
