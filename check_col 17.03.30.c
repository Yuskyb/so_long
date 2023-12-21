/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_col.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:59:01 by yususato          #+#    #+#             */
/*   Updated: 2023/12/11 16:17:10 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	col_y(t_map *game, int x, int y)
{
	if (game->str[y][x] != '1' && game->str[y][x] != 'X' &&
	game->str[y][x] != 'E')
	{
		if (game->str[y][x] != 'd')
		{
			return (1);
		}
	}
	return (0);
}

int	col_x(t_map *game, int x, int y)
{
	if (game->str[y][x] != '1' && game->str[y][x] != 'X' &&
	game->str[y][x] != 'E')
	{
		if (game->str[y][x] != 'd')
		{
			return (1);
		}
	}
	return (0);
}

int	end_col(t_move *move, t_map *game, int x, int y)
{
	if (game->str[y][x] == 'P')
	{
		move->col_move_flag = 1;
		return (1);
	}
	return (0);
}

void	col_depth(t_map *game, t_move *move)
{
	if (col_explore_up(game, move) == 1)
		return ;
	if (col_explore_down(game, move) == 1)
		return ;
	if (col_explore_left(game, move) == 1)
		return ;
	if (col_explore_right(game, move) == 1)
		return ;
}
