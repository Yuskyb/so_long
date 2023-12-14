/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:55:50 by yususato          #+#    #+#             */
/*   Updated: 2023/12/13 16:57:32 by yususato         ###   ########.fr       */
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
	int	i;

	i = 0;
	while (game->str[i])
	{
		free(game->str[i]);
		i++;
	}
	i = 0;
	free(game->str_line);
	mlx_destroy_window(game->mlx.m_ptr, game->mlx.w_ptr);
	free(game->str);
	exit(0);
}

void	clear_game(t_map *game)
{
	int	i;

	i = 0;
	game->walk_cnt++;
	setting_img(&game->mlx, &game->img, game);
	ft_printf("Clear!!");
	mlx_destroy_window(game->mlx.m_ptr, game->mlx.w_ptr);
	while (game->str[i])
	{
		free(game->str[i]);
		i++;
	}
	free(game->str);
	exit(0);
}
