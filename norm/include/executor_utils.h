/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 00:19:09 by napark            #+#    #+#             */
/*   Updated: 2021/12/29 00:19:15 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_UTILS_H
# define EXECUTOR_UTILS_H

int		clean_exp_tok_cmds(t_exp_tok *exp_tok);
int		handle_inbuilt_redir(t_exp_tok *exp_tok);
int		execute_inbuilt(t_exp_tok *exp_tok);
bool	is_inbuilt(char *cmd);
int		execute_child(t_exp_tok *exp_tok, char *abs_cmd_path, int status);
int		execute_inbuilt_child(t_exp_tok *exp_tok);
int		execute_inbuilt_reset_fds(t_exp_tok *exp_tok, int saved_fds[2]);

#endif