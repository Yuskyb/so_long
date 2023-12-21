/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:11:46 by yususato          #+#    #+#             */
/*   Updated: 2023/12/14 18:07:38 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	game_set(t_map *game)
{
	size_t	i;
	size_t	j;
	size_t	a;

	i = 0;
	j = 0;
	a = 0;
	while (game->str_line[i])
	{
		game->str[a][j] = game->str_line[i];
		j++;
		if (j == game->width)
		{
			j = 0;
			a++;
		}
		i++;
	}
	return ;
}

void	str_change(t_map *game)
{
	size_t	y;

	y = 0;
	game->str = (char **)ft_calloc(sizeof(char *), (game->height + 1));
	while (y < game->height)
	{
		game->str[y] = (char *)ft_calloc((game->width + 1), sizeof(char));
		y++;
	}
	game_set(game);
	return ;
}

void	ft_free(t_map *game)
{
	int	i;

	i = 0;
	while (game->str[i])
	{
		free(game->str[i]);
		i++;
	}
	free(game->str);
}

void	col_check(t_map *game, t_move *move, int hei, int wid)
{
	int		i;

	i = 0;
	while (game->str_line[i])
	{
		if (game->str_line[i] == 'C')
		{
			hei = i / game->width;
			wid = i % game->width;
			game->str[hei][wid] = 'X';
			col_init(move, hei, wid);
			col_depth(game, move);
			if (move->col_move_flag == 0)
				ft_exit();
			move->col_move_flag = 0;
			game->str[hei][wid] = 'C';
		}
		i++;
	}
	ft_free(game);
}

void	search(t_map *game, int col)
{
	int			i;
	int			hei;
	int			wid;
	t_move		move;

	i = 0;
	while (!(game->str_line[i] == 'P'))
		i++;
	hei = i / game->width;
	wid = i % game->width;
	move_init(&move, hei, wid, col);
	str_change(game);
	wall_check(game);
	line_check(game);
	col_check(game, &move, hei, wid);
	str_change(game);
	depth(game, &move);
	ft_free(game);
	if (move.flag == 0)
		ft_exit();
}
