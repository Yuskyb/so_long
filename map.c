/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 22:26:45 by yususato          #+#    #+#             */
/*   Updated: 2023/10/31 15:59:43 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"
#include	"mlx.h"

void	map_read(char *map, t_map *game)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	game->height = 0;
	game->width = ft_strlen(line) - 1;
	game->str_line = ft_strdup_new(line);
	while (line)
	{
		game->height++;
		line = get_next_line(fd);
		if (line)
			game->str_line = ft_strjoin_new(game->str_line, line);
	}
	close(fd);
	printf("%s\n", game->str_line);
}

void	setting_img(t_mlx *mlx, t_img *img, t_map *game)
{
	int	hei;
	int	wid;

	hei = 0;
	while (hei < game->height)
	{
		wid = 0;
		while (hei < game->width)
		{
			if (game->str_line[hei * game->width + wid] == '1')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_ptr, img->wall, wid * 64, hei * 64);
			else if (game->str_line[hei * game->width + wid] == 'C')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_ptr, img->chest, wid * 64, hei * 64);
			else if (game->str_line[hei * game->width + wid] == 'P')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_ptr, img->chara, wid * 64, hei * 64);
			else if (game->str_line[hei * game->width + wid] == 'E')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_ptr, img->rune, wid * 64, hei * 64);
			else
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_ptr, img->land, wid * 64, hei * 64);
			wid++;
		}
	hei++;
	}
}
