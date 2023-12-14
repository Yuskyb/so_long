/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:12:04 by yususato          #+#    #+#             */
/*   Updated: 2023/12/11 16:14:31 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_y(t_map *game, int x, int y)
{
	if (game->str[y][x] != '1' && game->str[y][x] != 'P')
	{
		if (game->str[y][x] != 'd')
		{
			return (1);
		}
	}
	return (0);
}

int	check_end(t_move *move, t_map *game, int x, int y)
{
	if (game->str[y][x] == 'C')
		move->col_flag++;
	if (game->str[y][x] == 'E')
	{
		move->flag = 1;
		return (1);
	}
	return (0);
}

int	check_x(t_map *game, int x, int y)
{
	if (game->str[y][x] != '1' && game->str[y][x] != 'P')
	{
		if (game->str[y][x] != 'd')
		{
			return (1);
		}
	}
	return (0);
}

void	check_c(t_move *move, t_map *game, int x, int y)
{
	if (game->str[y][x] == 'C')
		move->col_flag++;
}
