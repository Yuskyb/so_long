/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   explore.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:58:43 by yususato          #+#    #+#             */
/*   Updated: 2023/12/11 16:18:54 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

int	explore_up(t_map *game, t_move *move)
{
	int	a;
	int	b;

	a = move->x;
	b = move->y - 1;
	if (check_y(game, a, b))
	{
		check_c(move, game, a, b);
		move->y = b;
		if (check_end(move, game, a, b) == 1)
			return (1);
		game->str[b][a] = 'd';
		depth(game, move);
	}
	return (0);
}

int	explore_down(t_map *game, t_move *move)
{
	int	a;
	int	b;

	a = move->x;
	b = move->y + 1;
	if (check_y(game, a, b))
	{
		check_c(move, game, a, b);
		move->y = b;
		if (check_end(move, game, a, b) == 1)
			return (1);
		game->str[b][a] = 'd';
		depth(game, move);
	}
	return (0);
}

int	explore_left(t_map *game, t_move *move)
{
	int	a;
	int	b;

	a = move->x - 1;
	b = move->y;
	if (check_x(game, a, b))
	{
		check_c(move, game, a, b);
		move->x = a;
		if (check_end(move, game, a, b) == 1)
			return (1);
		game->str[b][a] = 'd';
		depth(game, move);
	}
	return (0);
}

int	explore_right(t_map *game, t_move *move)
{
	int	a;
	int	b;

	a = move->x + 1;
	b = move->y;
	if (check_x(game, a, b))
	{
		check_c(move, game, a, b);
		move->x = a;
		if (check_end(move, game, a, b) == 1)
			return (1);
		game->str[b][a] = 'd';
		depth(game, move);
	}
	return (0);
}

void	depth(t_map *game, t_move *move)
{
	if (explore_up(game, move) == 1)
		return ;
	if (explore_down(game, move) == 1)
		return ;
	if (explore_left(game, move) == 1)
		return ;
	if (explore_right(game, move) == 1)
		return ;
}
