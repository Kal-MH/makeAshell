/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:09:04 by napark            #+#    #+#             */
/*   Updated: 2021/12/17 21:37:15 by mkal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "brain.h"
#include "env_var_utils.h"

static int	exit_routine(void *to_free, int exit_status)
{
	clear_history();
	free(to_free);
	free_envv(get_envv());
	return (exit_status);
}

static int	routine(void)
{
	char	*buf;
	int		exit_code;

	while (true)
	{
		buf = readline("minishell$ ");
		if (ft_strlen(buf) > 0)
			add_history(buf);
		if (buf == NULL || ft_strcmp(buf, "exit") == 0)
		{
			printf("exit\n");
			return (exit_routine((void *)buf, EXIT_CTRL_D));
		}
		exit_code = lexer(buf);
		if (exit_code == EXIT_FAILURE)
			return (exit_routine((void *)buf, EXIT_FAILURE));
		if (exit_code == EXIT_CTRL_D)
		{
			printf("exit\n");
			return (exit_routine((void *)buf, EXIT_CTRL_D));
		}
		free(buf);
	}
	return (exit_routine((void *)buf, EXIT_FAILURE));
}

static int	handle_flags(int argc, char *argv[])
{
	int	exit_code;

	if (argc != 3 || ft_strcmp(argv[1], "-c") != 0)
	{
		ft_putstr_fd("Usage: ./minishell [Flag] \"[Command]\"\n", STDERR_FILENO);
		ft_putstr_fd("\t-c\tExecute Command without promot\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	exit_code = lexer(argv[2]);
	free_envv(get_envv());
	return (exit_code);
}

static void	handle_signals(void)
{
	signal(SIGINT, handle_signal);
	signal(SIGQUIT, handle_signal);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_env	*envv;

	handle_signals();
	envv = init_envv(envp);
	if (envv == NULL)
		return (EXIT_FAILURE);
	set_envp(envp);
	set_envv(envv);
	if (argc != 1)
		return (handle_flags(argc, argv));
	if (routine() == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
