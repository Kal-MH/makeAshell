/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 00:16:58 by napark            #+#    #+#             */
/*   Updated: 2021/12/17 21:09:09 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_UTILS_H
# define EXPANDER_UTILS_H


int		check_for_heredoc(t_par_tok *par_toks[]);
int		wait_for_heredoc(t_par_tok *par_tok, t_exp_tok *exp_tok);
int		handle_redir(t_par_tok *par_tok, t_exp_tok *exp_tok, int pipe_type);
int		handle_pipes(t_exp_tok *exp_tok, int pipe_type);
int		set_pipe_type(t_par_tok **par_toks, int i);

#endif