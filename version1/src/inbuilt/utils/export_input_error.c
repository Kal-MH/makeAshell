/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_input_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 00:09:32 by napark            #+#    #+#             */
/*   Updated: 2021/12/14 00:09:44 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	export_error_loop(char **var, char **argv)
{
	int	j;

	j = 0;
	while ((*var)[j] != '\0')
	{
		if (ft_isalnum((*var)[j]) == 0 && (*var)[j] != '_')
		{
			ft_putstr_fd("export: ", STDERR_FILENO);
			ft_putstr_fd(argv[1], STDERR_FILENO);
			ft_putstr_fd(": not a valid identifier\n", STDERR_FILENO);
			ft_free_str(var);
			return (EXIT_FAILURE);
		}
		j++;
	}
	return (EXIT_SUCCESS);
}

/*
checks the input of export for errors and prints the corresponding message
*/
int	export_input_error(char **argv)
{
	char	**split;
	char	*var;
	int		i;

	i = 1;
	var = NULL;
	while (argv && argv[i])
	{
		split = ft_split(argv[i], '=');
		if (split == NULL)
			return (EXIT_FAILURE);
		var = ft_strdup(split[0]);
		ft_free_str_array(&split);
		if (var == NULL)
			return (EXIT_FAILURE);
		if (export_error_loop(&var, argv) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		i++;
		ft_free_str(&var);
	}
	return (EXIT_SUCCESS);
}
