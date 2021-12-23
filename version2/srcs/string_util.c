/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkal <mkal@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 00:21:00 by mkal              #+#    #+#             */
/*   Updated: 2021/12/24 00:59:20 by mkal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

char	*ft_strcjoin(char *str, char c)
{
	char	*ret;
	int		i;

	if (!str)
	{
		if (!ft_calloc(2, sizeof(char), (void *)&ret))
			exit(1);
		ret[0] = c;
		ret[1] = '\0';
	}
	else
	{
		if (!ft_calloc(ft_strlen(str) + 2, sizeof(char), (void *)&ret))
			exit(1);
		i = -1;
		while (str[++i])
			ret[i] = str[i];
		ret[i] = c;
		ret[i + 1] = '\0';
		free(str);
	}
	return (ret);
}

void	print_save_char(t_state *s, char c)
{
	s->input = ft_strcjoin(s->input, c);
	write(1, &c, 1);
}

char	*delete_last_char(char *str)
{
	char	*tmp;
	int		len;
	int		i;

	if (str == 0)
		return (0);
	len = ft_strlen(str);
	if (!ft_calloc(len, sizeof(char), (void *)&tmp))
		exit(1);
	i = 0;
	while (str[i + 1])
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[len - 1] = '\0';
	free(str);
	if (ft_strlen(tmp) == 0)
	{
		free(tmp);
		tmp = 0;
	}
	str = tmp;
	return (str);
}

void	print_mini(void)
{
	int		fd;
	char	*line;

	fd = open("jordy.txt", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	free(line);
}
