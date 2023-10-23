/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 22:26:45 by yususato          #+#    #+#             */
/*   Updated: 2023/10/23 22:45:54 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	map_read(char *filename, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	game->hei = 0;
	game->wid = ft_strlen(line) - 1;
	game->str_line = ft_strdup(line);
	while (line)
	{
		game_>hei++;
		line = get_next_line(fd);
		if (line)
			game->str_line = ft_strjoin(game->str_line, line);
	}
	close(fd);
	printf("%s\n", game->str_line);
}