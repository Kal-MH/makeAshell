/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkal <mkal@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:19:23 by mkal              #+#    #+#             */
/*   Updated: 2021/11/18 17:14:18 by mkal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int main(void)
{
	int fd;
	char *line;

	//-------libft get_next_line test --------
	fd = open("./test", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		printf("%s(%zu)", line, ft_strlen(line));
		free(line);
	}
	free(line);
	close(fd);
	return (0);
}
