/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 21:28:42 by napark            #+#    #+#             */
/*   Updated: 2021/12/24 01:03:47 by mkal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_export(t_env *env_head)
{
	char	**env_list;
	t_env	*env;
	int		len;
	int		i;

	env = env_head;
	len = check_env_length(env_head);
	if (!ft_calloc(len + 1, sizeof(char *), (void **)&env_list))
		exit(1);
	env_list[len] = 0;
	i = 0;
	while (env)
	{
		env_list[i] = make_env_string(env->key,
				env->value, env->has_equal);
		env = env->next;
		i++;
	}
	sorted_list(env_list, len);
	i = 0;
	while (i < len)
		printf("declare -x %s\n", env_list[i++]);
	free_2d(env_list);
}

void	print_one_export(t_env *head, char *key)
{
	t_env	*env;

	env = find_env(head, key);
	if (env)
		printf("%s\n", env->value);
}

void	update_env(t_env *head, char *key, char *value, int has_equal)
{
	t_env	*env;

	env = find_env(head, key);
	if (env == NULL)
		add_env_back(&head, key, value, has_equal);
	else
	{
		if (env->value)
		{
			free(env->value);
			if (value)
				env->value = ft_strdup(value);
			else
				env->value = 0;
		}
		else
		{
			if (value)
				env->value = ft_strdup(value);
		}
		env->has_equal = has_equal;
	}
}
