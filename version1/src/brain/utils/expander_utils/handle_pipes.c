/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pipes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 01:39:48 by napark            #+#    #+#             */
/*   Updated: 2021/12/17 21:56:24 by mkal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "brain.h"
#include "expander_utils.h"

int	handle_pipes(t_exp_tok *exp_tok, int pipe_type)
{
	static int	last_pipe_out;
	int			end[2];

	if (pipe_type == -1)
	{
		if (last_pipe_out != 0 && last_pipe_out != 1)
		{
			close(last_pipe_out);
			ft_putstr_fd("something with pipes went wrong pipe_type=-1\n", 2);
			return (EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	if (pipe_type == 0)
	{
		if (last_pipe_out == 0)
		{
			ft_putstr_fd("something with pipes went wrong pipe_type=0\n", 2);
			return (EXIT_FAILURE);
		}
		if (exp_tok->in == 0)
			exp_tok->in = last_pipe_out;
		else if (last_pipe_out != 0 && last_pipe_out != 1)
			close(last_pipe_out);
		last_pipe_out = 0;
	}
	else if (pipe_type == 1)
	{
		if (pipe(end) != 0)
		{
			perror("ERROR");
			return (EXIT_FAILURE);
		}
		last_pipe_out = end[0];
		if (exp_tok->out == 1)
			exp_tok->out = end[1];
		else
			close(end[1]);
	}
	else if (pipe_type == 2)
	{
		if (last_pipe_out == 0)
		{
			ft_putstr_fd("something with pipes went wrong pipe_type=2\n", 2);
			return (EXIT_FAILURE);
		}
		if (exp_tok->in == 0)
			exp_tok->in = last_pipe_out;
		else if (last_pipe_out != 0 && last_pipe_out != 1)
			close(last_pipe_out);
		last_pipe_out = 0;
		if (pipe(end) != 0)
		{
			perror("ERROR");
			return (EXIT_FAILURE);
		}
		last_pipe_out = end[0];
		if (exp_tok->out == 1)
			exp_tok->out = end[1];
		else
			close(end[1]);
	}
	return (EXIT_SUCCESS);
}
