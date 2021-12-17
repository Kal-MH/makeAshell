/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 00:14:03 by napark            #+#    #+#             */
/*   Updated: 2021/12/14 00:14:12 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pwd(void)
{
	char	*cwd;

	cwd = NULL;
	cwd = getcwd(cwd, 0);
	if (cwd == NULL)
	{
		perror("Error");
		return (EXIT_FAILURE);
	}
	else if (ft_printf("%s\n", cwd) != ft_strlen(cwd) + 1)
	{
		ft_free_str(&cwd);
		perror("\nError: printf failed");
		return (EXIT_FAILURE);
	}
	ft_free_str(&cwd);
	return (EXIT_SUCCESS);
}
