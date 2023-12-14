/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:35:22 by yususato          #+#    #+#             */
/*   Updated: 2023/12/11 16:20:22 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	wall_check(t_map *game)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (x < game->width)
	{
		if (game->str[0][x] != '1' || game->str[game->height - 1][x] != '1')
			ft_exit();
		x++;
	}
	while (y < game->height)
	{
		if (game->str[y][0] != '1' || game->str[y][game->width - 1] != '1')
			ft_exit();
		y++;
	}
}

void	map_check(t_map *game)
{
	int	i;
	int	dep;
	int	col;
	int	play;

	i = 0;
	dep = 0;
	col = 0;
	play = 0;
	while (game->str_line[i])
	{
		if (game->str_line[i] == 'E')
			dep++;
		else if (game->str_line[i] == 'C')
				col++;
		else if (game->str_line[i] == 'P')
				play++;
		else if (game->str_line[i] != '1' && game->str_line[i] != '0')
			ft_exit();
		i++;
	}
	if (!(dep == 1 && play == 1) || col < 1)
		ft_exit();
	game->all_col = col;
	search(game, col);
}

void	move_init(t_move *move, int hei, int wid, int col)
{
	move->x = wid;
	move->y = hei;
	move->col_flag = 0;
	move->all_flag = col;
	move->end_flag = 0;
	move->flag = 0;
}

void	col_init(t_move *move, int hei, int wid)
{
	move->cx = wid;
	move->cy = hei;
	move->col_move_flag = 0;
}

void	line_check(t_map *game)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (game->str[y])
	{
		while (game->str[y][x])
			x++;
		if (x != game->width)
			ft_exit();
		y++;
	}
}
