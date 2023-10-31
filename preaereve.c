
int	main(void)
{
	t_mlx	*mlx_ptr;
	t_mlx	*win_ptr;
	t_img *img;
	t_img *img2;
	t_img *img3;
	t_img *img4;
	t_img *img5;
	t_img *img6;
	t_img *img7;
	int img_width;
	int img_height;
	t_param	param;
	t_map *game;

	game = NULL;
	param_init(&param);
	mlx_ptr = mlx_init();
	map_read("maps/map.txt", game);
	win_ptr = mlx_new_window(mlx, 500, 500, "my_mlx");
	img = mlx_xpm_file_to_image(mlx, "./images/land.xpm", &img_width, &img_height);
	img2 = mlx_xpm_file_to_image(mlx, "./images/wall.xpm", &img_width, &img_height);
	img3 = mlx_xpm_file_to_image(mlx, "./images/chara.xpm", &img_width, &img_height);
	img4 = mlx_xpm_file_to_image(mlx, "./images/chest.xpm", &img_width, &img_height);
	img5 = mlx_xpm_file_to_image(mlx, "./images/chest_open.xpm", &img_width, &img_height);
	img6 = mlx_xpm_file_to_image(mlx, "./images/rune.xpm", &img_width, &img_height);
	img7 = mlx_xpm_file_to_image(mlx, "./images/rune_light.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_put_image_to_window(mlx, win, img2, 64, 0);
	mlx_put_image_to_window(mlx, win, img3, 128, 0);
	mlx_put_image_to_window(mlx, win, img4, 192, 64);
	mlx_put_image_to_window(mlx, win, img5, 0, 64);
	mlx_put_image_to_window(mlx, win, img6, 64, 64);
	mlx_put_image_to_window(mlx, win, img7, 128, 64);
	mlx_hook(win, X_EVENT_KEY_RELEASE, 0, &key_press, &param);
	mlx_loop(mlx);
	return (0);
}
