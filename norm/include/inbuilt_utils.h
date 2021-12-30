/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inbuilt_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 00:17:15 by napark            #+#    #+#             */
/*   Updated: 2021/12/29 23:51:33 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INBUILT_UTILS_H
# define INBUILT_UTILS_H

# include "env_var_utils.h"

/* TRANSPORT OF VARIABLES OF EXPORT */
typedef struct s_export
{
	int		i;
	int		j;
	char	*var;
}			t_export;

/* INBUILD_UTILS */
int		export_only(t_env *envv);
int		export_input_error(char **argv);
int		export_special(t_env *envv, t_export *exp);
int		export_wd(t_env *envv, t_export *exp, char **argv);

#endif
