/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:04:54 by napark            #+#    #+#             */
/*   Updated: 2021/12/14 00:16:40 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_VAR_UTILS_H
# define ENV_VAR_UTILS_H

/* TRANSPORT OF ENV_VARIABLES */
typedef struct s_env
{
	char	**envp;
	char	**env_var;
	char	*pwd;
	char	*oldpwd;
}			t_env;

// ENV VAR UTILS
t_env	*init_envv(char **envp);
void	free_envv(t_env *envv);
int		reinit_env_var(t_env *envv, char **argv);
char	*get_env_var_value(t_env *envv, char *var);

// GETTER / SETTER
void	set_envv(t_env *envv);
t_env	*get_envv(void);
char	**get_env_var(void);

#endif