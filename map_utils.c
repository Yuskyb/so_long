/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:35:22 by yususato          #+#    #+#             */
/*   Updated: 2023/12/21 11:07:59 by yususato         ###   ########.fr       */
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
		if (game->str_line[x] != '1'
			|| game->str_line[(game->height - 1) * game->width + x] != '1')
			ft_exit();
		x++;
	}
	while (y < game->height)
	{
		if (game->str_line[y * game->width] != '1'
			|| game->str_line[(game->width - 1) + (game->width * y)] != '1')
			ft_exit();
		y++;
	}
}

void	serch_p(t_map *game, t_stack *node)
{
	int	i;

	i = 0;
	while (game->str_line[i])
	{
		if (game->str_line[i] == 'P')
			break ;
		i++;
	}
	node->x = i % game->width;
	node->y = i / game->width;
	game->top = 0;
	game->xi = node->x;
	game->yi = node->y;
	return ;
}

bool	check_end(t_map *game, t_stack *cur)
{
	if (game->str_line[cur->x + (game->width * cur->y)] == 'E')
	{
		return (true);
	}
	return (false);
}

bool	check(t_map *game)
{
	if (game->str_line[game->xi + (game->yi * game->width)] != '1')
	{
		return (true);
	}
	return (false);
}
