/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 22:26:45 by yususato          #+#    #+#             */
/*   Updated: 2023/10/24 19:39:23 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long"

void	map_read(char *filename, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);	
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

void	setting_img(t_game game)
{
	int	hei;
	int	wid;

	hei = 0;
	while (hei < game->width)
	{
		if (game->str_line[hei * game->width + wid] == '1')
			mlt_put_image_to_window(game->mlx, game->win, game->img->wall, wid * 64, hei * 64);
		else if (game->str_line[hei * game->width + wid] == '1')
			mlt_put_image_to_window(game->mlx, game->win, game->img->chest, wid * 64, hei * 64);
		else if (game->str_line[hei * game->width + wid] == '1')
			mlt_put_image_to_window(game->mlx, game->win, game->img->chara, wid * 64, hei * 64);
		else if (game->str_line[hei * game->width + wid] == '1')
			mlt_put_image_to_window(game->mlx, game->win, game->img->rune, wid * 64, hei * 64);
		else
			mlt_put_image_to_window(game->mlx, game->win,game->img->land,wid * 64, hei * 64);
		wid++;
	}
	hei++;
}
