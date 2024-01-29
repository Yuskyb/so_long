/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:15:58 by yususato          #+#    #+#             */
/*   Updated: 2023/12/15 15:05:19 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

int	press_key(int key_code, t_map *game)
{
	if (key_code == KEY_ESC)
		exit_game(game);
	else if (key_code == KEY_W)
		move_w(game);
	else if (key_code == KEY_A)
		move_a(game);
	else if (key_code == KEY_S)
		move_s(game);
	else if (key_code == KEY_D)
		move_d(game);
	return (0);
}

void	move_w(t_map *g)
{
	size_t	i;

	i = 0;
	while (i++ < ft_strlen(g->str_line))
	{
		if (g->str_line[i] == 'P')
			break ;
	}
	if (g->str_line[i - g->width] == 'C')
		g->col_cnt++;
	if (g->str_line[i - g->width] == 'E' && g->all_col == g->col_cnt)
	{
		g->str_line[i] = 0;
		g->str_line[i - g->width] = 'P';
		clear_game(g);
	}
	else if (g->str_line[i - g->width] != '1'
		&& g->str_line[i - g->width] != 'E')
	{
		g->str_line[i] = '0';
		g->str_line[i - g->width] = 'P';
		g->walk_cnt++;
		ft_printf("%d\n", g->walk_cnt);
		setting_img(&g->mlx, &g->img, g);
	}
}

void	move_s(t_map *g)
{
	size_t	i;

	i = 0;
	while (i++ < ft_strlen(g->str_line))
	{
		if (g->str_line[i] == 'P')
			break ;
	}
	if (g->str_line[i + g->width] == 'C')
		g->col_cnt++;
	if (g->str_line[i + g->width] == 'E' && g->all_col == g->col_cnt)
	{
		g->str_line[i] = 0;
		g->str_line[i + g->width] = 'P';
		clear_game(g);
	}	
	else if (g->str_line[i + g->width] != '1'
		&& g->str_line[i + g->width] != 'E')
	{
		g->str_line[i] = '0';
		g->str_line[i + g->width] = 'P';
		g->walk_cnt++;
		ft_printf("%d\n", g->walk_cnt);
		setting_img(&g->mlx, &g->img, g);
	}
}

void	move_a(t_map *g)
{
	size_t	i;

	i = 0;
	while (i++ < ft_strlen(g->str_line))
	{
		if (g->str_line[i] == 'P')
			break ;
	}
	if (g->str_line[i - 1] == 'C')
		g->col_cnt++;
	if (g->str_line[i - 1] == 'E' && g->all_col == g->col_cnt)
	{
		g->str_line[i] = 0;
		g->str_line[i - 1] = 'P';
		clear_game(g);
	}	
	else if (g->str_line[i - 1] != '1' && g->str_line[i - 1] != 'E')
	{
		g->str_line[i] = '0';
		g->str_line[i - 1] = 'P';
		g->walk_cnt++;
		ft_printf("%d\n", g->walk_cnt);
		setting_img(&g->mlx, &g->img, g);
	}
}

void	move_d(t_map *g)
{
	size_t	i;

	i = 0;
	while (i++ < ft_strlen(g->str_line))
	{
		if (g->str_line[i] == 'P')
			break ;
	}
	if (g->str_line[i + 1] == 'C')
		g->col_cnt++;
	if (g->str_line[i + 1] == 'E' && g->all_col == g->col_cnt)
	{
		g->str_line[i] = 0;
		g->str_line[i + 1] = 'P';
		clear_game(g);
	}	
	else if (g->str_line[i + 1] != '1' && g->str_line[i + 1] != 'E')
	{
		g->str_line[i] = '0';
		g->str_line[i + 1] = 'P';
		g->walk_cnt++;
		ft_printf("%d\n", g->walk_cnt);
		setting_img(&g->mlx, &g->img, g);
	}
}
