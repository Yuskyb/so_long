/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:42:32 by yususato          #+#    #+#             */
/*   Updated: 2023/10/31 18:50:29 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	param_init(t_param *param)
{
	param->x = 3;
	param->y = 4;
}

int	key_press(int key_code, t_param *param)
{
	static int	a;

	a = 0;
	if (key_code == KEY_W)
		param->y++;
	else if (key_code == KEY_A)
		param->y--;
	else if (key_code == KEY_D)
		param->x--;
	else if (key_code == KEY_ESC)
		param->x++;
	printf("x:%d, y:%d\n", param->x, param->y);
	return (0);
}

int	main(int ac, char **av)
{
	t_img	img;
	t_mlx	mlx;
	t_param	param;
	t_map	game;

	param_init(&param);
	if (ac <= 1)
		error();
	mlx.mlx_ptr = mlx_init();
	map_read(av[1], &game);
	setting_img(&mlx, &img, &game);
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 500, 500, "my_mlx");
	img.land = mlx_xpm_file_to_image(mlx.mlx_ptr, "./images/land.xpm", &img.width, &img.height);
	img.wall = mlx_xpm_file_to_image(mlx.mlx_ptr, "./images/wall.xpm", &img.width, &img.height);
	img.chara = mlx_xpm_file_to_image(mlx.mlx_ptr, "./images/chara.xpm", &img.width, &img.height);
	img.chest = mlx_xpm_file_to_image(mlx.mlx_ptr, "./images/chest.xpm", &img.width, &img.height);
	img.chest_open = mlx_xpm_file_to_image(mlx.mlx_ptr, "./images/chest_open.xpm", &img.width, &img.height);
	img.rune = mlx_xpm_file_to_image(mlx.mlx_ptr, "./images/rune.xpm", &img.width, &img.height);
	img.rune_light = mlx_xpm_file_to_image(mlx.mlx_ptr, "./images/rune_light.xpm", &img.width, &img.height);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, img.land , 0, 0);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, img.wall , 64, 0);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, img.chara , 128, 0);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, img.chest , 192, 64);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, img.chest_open , 0, 64);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, img.rune , 64, 64);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, img.rune_light , 128, 64);
	mlx_hook(mlx.win_ptr, X_EVENT_KEY_RELEASE, 0, &key_press, &param);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
