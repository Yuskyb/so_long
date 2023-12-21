/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:42:32 by yususato          #+#    #+#             */
/*   Updated: 2023/12/14 20:12:55 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	game_init(t_map *game)
{
	game->height = 0;
	game->width = 0;
	game->str_line = 0;
	game->all_col = 1;
	game->col_cnt = 0;
	game->walk_cnt = 0;
	game->flag = 0;
}

void	ber_check(char *av)
{
	char	*a;

	a = ft_strrchr(av, '.');
	if (a == NULL)
		ft_exit();
	if (ft_strncmp(a, ".ber\0", 5) != 0)
		ft_exit();
}

int	main(int ac, char **av)
{
	t_img	img;
	t_mlx	mlx;
	t_map	game;

	game_init(&game);
	if (ac != 2)
		ft_exit();
	ber_check(av[1]);
	mlx.m_ptr = mlx_init();
	map_read(av[1], &game);
	map_check(&game);
	mlx.w_ptr = mlx_new_window(mlx.m_ptr, 50 * game.width,
			50 * game.height, "my_mlx");
	img.land = mlx_xpm_file_to_image(mlx.m_ptr, LAND, &img.width, &img.height);
	img.wall = mlx_xpm_file_to_image(mlx.m_ptr, WALL, &img.width, &img.height);
	img.chara = mlx_xpm_file_to_image(mlx.m_ptr, CHA, &img.width, &img.height);
	img.chest = mlx_xpm_file_to_image(mlx.m_ptr, CHE, &img.width, &img.height);
	img.rune = mlx_xpm_file_to_image(mlx.m_ptr, RUNE, &img.width, &img.height);
	img.runl = mlx_xpm_file_to_image(mlx.m_ptr, RUNL, &img.width, &img.height);
	game.mlx = mlx;
	game.img = img;
	setting_img(&mlx, &img, &game);
	mlx_hook(mlx.w_ptr, X_EVENT_KEY_RELEASE, 0, &press_key, &game);
	mlx_loop(mlx.m_ptr);
	exit(0);
}

// __attribute__((destructor)) static void destructor()
// {
//     system("leaks -q so_long");
// }