/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_explore.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:35:08 by yususato          #+#    #+#             */
/*   Updated: 2023/12/11 16:19:26 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	col_explore_up(t_map *game, t_move *move)
{
	int	a;
	int	b;

	a = move->cx;
	b = move->cy - 1;
	if (col_y(game, a, b))
	{
		move->cy = b;
		if (end_col(move, game, a, b) == 1)
			return (1);
		game->str[b][a] = 'd';
		col_depth(game, move);
	}
	return (0);
}

int	col_explore_down(t_map *game, t_move *move)
{
	int	a;
	int	b;

	a = move->cx;
	b = move->cy + 1;
	if (col_y(game, a, b))
	{
		move->cy = b;
		if (end_col(move, game, a, b) == 1)
			return (1);
		game->str[b][a] = 'd';
		col_depth(game, move);
	}
	return (0);
}

int	col_explore_left(t_map *game, t_move *move)
{
	int	a;
	int	b;

	a = move->cx - 1;
	b = move->cy;
	if (col_x(game, a, b))
	{
		move->cx = a;
		if (end_col(move, game, a, b) == 1)
			return (1);
		game->str[b][a] = 'd';
		col_depth(game, move);
	}
	return (0);
}

int	col_explore_right(t_map *game, t_move *move)
{
	int	a;
	int	b;

	a = move->cx + 1;
	b = move->cy;
	if (col_x(game, a, b))
	{
		move->cx = a;
		if (end_col(move, game, a, b) == 1)
			return (1);
		game->str[b][a] = 'd';
		col_depth(game, move);
	}
	return (0);
}
