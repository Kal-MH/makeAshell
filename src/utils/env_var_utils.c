/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:18:25 by napark            #+#    #+#             */
/*   Updated: 2021/12/15 00:46:31 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "env_var_utils.h"

t_env   *init_envv(char **envp)
{
    t_env   *envv;
    
    envv = ft_calloc(1, sizeof(t_env));//홤경변수 초기화 메모리 할당
    if (envv != NULL && envp != NULL && *envp != NULL)
    {
        envv->envp = envp;
        envv->env_var = ft_str_arr_dup(envp);
        envv->pwd = get_env_var_value(envv, "PWD");
		envv->oldpwd = get_env_var_value(envv, "OLDPWD");
		if (envv->env_var != NULL && envv->pwd != NULL && envv->oldpwd != NULL)
			return (envv);
    }
    return (NULL);
}