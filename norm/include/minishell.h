/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:10:31 by napark            #+#    #+#             */
/*   Updated: 2021/12/29 23:51:56 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <errno.h>
# include <dirent.h>
# include <stdbool.h>
# include <fcntl.h>
# include "error_utils.h"

# define EXIT_SYNTAX_ERROR 258
# define EXIT_CMD_NOT_FOUND 127
# define EXIT_CTRL_D 130

/* INBUILD */
int		echo(char **args);
int		export(char **argv);
int		unset(char **argv);
int		env(char **argv);
int		pwd(void);
int		cd(char **argv);
int		exit_inbuilt(char *args[]);

void	handle_cmd_signals(void);
void	handle_global_signals(void);

#endif
