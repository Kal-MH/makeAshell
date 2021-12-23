/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 01:25:06 by napark            #+#    #+#             */
/*   Updated: 2021/12/04 12:31:33 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int g_status;
//상ㅐ 표를 위한 전역 변수
int main(int argc, char *argv[], char **envp)
{
    static int  ret;
    char        *str;
    t_cmd       *cmd;
    t_list      *l_env;

    if (argc > 1 || argv == NULL)
        return (1);
    l_env = pre_process(envp);

    while (!ret)
    {
        str = readline("Minishell> ");
        if (str == NULL)
            none_ctrl();
        cmd = (t_cmd *)malloc(sizeof(t_cmd));
        init_data(cmd, l_env);
        //if (parsing(&cmd, l_env, str))


    }
}
