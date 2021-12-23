/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 11:27:54 by napark            #+#    #+#             */
/*   Updated: 2021/12/04 12:33:02 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./lib/libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/resource.h>
# include <sys/time.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <dirent.h>
# include <termios.h>
# include <termcap.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>

extern int  g_status;

typedef enum e_pipe {PIPE, INPUT, DOCUMENT, OUTPUT, APPEND} t_pipe;

typedef struct s_cmd
{
    char            **word;
    int             p_type;
    char            quote;
    t_list          *environ;
    int             cmd_num;
    char            **path;
    pid_t           pid;
    struct s_cmd    *next;
    struct s_cmd    *prev;
}t_cmd;

t_list  *pre_process(char **envp);

#endif