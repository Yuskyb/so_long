/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:55:50 by yususato          #+#    #+#             */
/*   Updated: 2023/12/21 11:02:10 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	ft_exit(void)
{
	ft_printf("Error\n");
	exit(1);
}

void	ft_exit_close(int fd)
{
	close(fd);
	ft_printf("Error\n");
	exit(1);
}

void	exit_game(t_map *game)
{
	mlx_destroy_window(game->mlx.m_ptr, game->mlx.w_ptr);
	free(game->str_line);
	exit(0);
}

void	clear_game(t_map *game)
{
	game->walk_cnt++;
	setting_img(&game->mlx, &game->img, game);
	ft_printf("Clear!!");
	mlx_destroy_window(game->mlx.m_ptr, game->mlx.w_ptr);
	free(game->str_line);
	exit(0);
}
