/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 22:26:45 by yususato          #+#    #+#             */
/*   Updated: 2023/12/14 16:19:39 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"
#include	"mlx.h"

char    *ft_temp_sj(t_map *game, char *line)
{
    char    *tmp;


    tmp = ft_strjoin_new(game->str_line, line, game);
    if (game->str_line)
        free (game->str_line);
    if (!tmp)
    {
        if (line)
            free(line);
        return (NULL);
    }
    return (tmp);
}

void	map_read(char *map, t_map *game)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL || ft_strchr(line, '1') == NULL)
		ft_exit_close(fd);
	game->width = ft_strlen(line) - 1;
	game->str_line = ft_strdup_new(line);
	char *nl = game->str_line;
;	while (nl)
	{	
		game->height++;
		nl = get_next_line(fd);
		if (nl)
			game->str_line = ft_temp_sj(game,nl);
		else if (nl != NULL && game->width != ft_strlen(nl) - 1)
			ft_exit_close(fd);
		free(nl);
	}
	close(fd);
	free(game->str_line);
	if (game->width > 50 || game->height > 28)
		ft_exit();
	if (game->flag == 0)
		ft_exit();
}

void	setting_img(t_mlx *mlx, t_img *img, t_map *game)
{
	size_t	hei;
	size_t	wid;

	hei = 0;
	while (hei < game->height)
	{
		wid = 0;
		while (wid < game->width)
		{
			if (game->str_line[hei * game->width + wid] == '1')
				draw_wall(mlx, img, wid, hei);
			else if (game->str_line[hei * game->width + wid] == 'C')
				draw_chest(mlx, img, wid, hei);
			else if (game->str_line[hei * game->width + wid] == 'P')
				draw_chara(mlx, img, wid, hei);
			else if (game->str_line[hei * game->width + wid] == 'E')
				draw_rune(mlx, img, wid, hei);
			else
				draw_land(mlx, img, wid, hei);
			wid++;
		}
	hei++;
	}
}
