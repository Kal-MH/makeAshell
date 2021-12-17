/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 00:12:22 by napark            #+#    #+#             */
/*   Updated: 2021/12/14 00:12:32 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	echo(char **args)
{
	bool	print_newline;

	print_newline = true;
	if (ft_strncmp(*args, "echo", ft_strlen(*args)) != 0)
		return (EXIT_FAILURE);
	args++;
	if (*args && ft_strncmp(*args, "-n", ft_strlen("-n") + 1) == 0)
	{
		print_newline = false;
		args++;
	}
	while (*args)
	{
		if (printf("%s", *args) != ft_strlen(*args))
			return (EXIT_FAILURE);
		if (*(args + 1) != NULL)
			if (printf(" ") != ft_strlen(" "))
				return (EXIT_FAILURE);
		args++;
	}
	if (print_newline)
		if (printf("\n") != ft_strlen("\n"))
			return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
