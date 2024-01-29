/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:01:04 by yususato          #+#    #+#             */
/*   Updated: 2023/12/21 11:08:44 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	serch_c(t_map *game, t_stack *node)
{
	while (game->str_line[game->now_col])
	{
		if (game->str_line[game->now_col] == 'C')
			break ;
		game->now_col++;
	}
	node->x = game->now_col % game->width;
	node->y = game->now_col / game->width;
	game->top = 0;
	game->xi = node->x;
	game->yi = node->y;
	game->col_cnt++;
	if (game->str_line[game->now_col] != '\0')
		game->now_col++;
	return ;
}

bool	check_p(t_map *game, t_stack *cur)
{
	if (game->str_line[cur->x + (game->width * cur->y)] == 'P')
	{
		return (true);
	}
	return (false);
}

bool	check_c(t_map *game)
{
	if (game->str_line[game->xi + (game->yi * game->width)] != '1'
		&& game->str_line[game->xi + (game->yi * game->width)] != 'E')
	{
		return (true);
	}
	return (false);
}
