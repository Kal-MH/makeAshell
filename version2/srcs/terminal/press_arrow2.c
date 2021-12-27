/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_arrow2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkal <mkal@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 17:17:23 by mkal              #+#    #+#             */
/*   Updated: 2021/12/24 00:50:06 by mkal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	putchar_tc(int tc)
{
	write(1, &tc, 1);
	return (0);
}

void	move_cursor_left(void)
{
	int	col;
	int	row;

	set_cursor(&col, &row);
	if (col == 0)
		return ;
	--(col);
	tputs(tgoto(g_state.t.cm, col, row), 1, putchar_tc);
}

void	move_cursor_right(void)
{
	int	col;
	int	row;

	set_cursor(&col, &row);
	++(col);
	tputs(tgoto(g_state.t.cm, col, row), 1, putchar_tc);
}
