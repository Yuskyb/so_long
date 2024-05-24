/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:35:41 by yususato          #+#    #+#             */
/*   Updated: 2023/12/21 12:21:02 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# include <limits.h>
# include <fcntl.h>
# include	"../mlx/mlx.h"
# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include <stdbool.h>

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE 3
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define LAND "./textures/land.xpm"
# define WALL "./textures/wall.xpm"
# define CHA "./textures/chara.xpm"
# define CHE "./textures/chest.xpm"
# define RUNE "./textures/rune.xpm"
# define RUNL "./textures/rune_l.xpm"

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 100

# endif

# define MAX_SIZE 1500

typedef struct s_stack{
	int	x;
	int	y;
}	t_stack;

typedef struct s_mlx{
	void	*m_ptr;
	void	*w_ptr;
}	t_mlx;

typedef struct s_img{
	void	*land;
	void	*wall;
	void	*chara;
	void	*chest;
	void	*chest_open;
	void	*rune;
	void	*runl;
	int		width;
	int		height;
}	t_img;

typedef struct s_map{
	t_mlx	mlx;
	t_img	img;
	size_t	height;
	size_t	width;
	char	*str_line;
	char	col_cnt;
	char	all_col;
	int		walk_cnt;
	int		flag;
	int		top;
	int		now_col;
	int		xi;
	int		yi;
}	t_map;

void	map_read(char *map, t_map *game);
void	setting_img(t_mlx *mlx, t_img *img, t_map *game);
char	*line_next(char *buffer, char *line);
char	*output(char *buffer);
char	*unit(char *buffer, char *buf);
char	*get_next_line(int fd);
char	*ft_strdup_new(char *src);
char	*ft_strjoin_new(char *s1, char *s2, t_map *game);
void	ft_exit(void);
void	game_init(t_map *param);
void	ber_check(int ac, char *av);
int		press_key(int key_code, t_map *game);
void	move_w(t_map *g);
void	move_a(t_map *g);
void	move_s(t_map *g);
void	move_d(t_map *g);
void	exit_game(t_map *game);
void	clear_game(t_map *game);
void	wall_check(t_map *game);
void	ft_exit_close(int fd);
void	draw_wall(t_mlx *mlx, t_img *img, int wid, int hei);
void	draw_chest(t_mlx *mlx, t_img *img, int wid, int hei);
void	draw_chara(t_mlx *mlx, t_img *img, int wid, int hei);
void	draw_rune(t_mlx *mlx, t_img *img, int wid, int hei);
void	draw_land(t_mlx *mlx, t_img *img, int wid, int hei);
void	check_map(t_map *game);
bool	pass_find(t_map *game, t_stack *stack, bool *visited);
void	ft_free(t_map *game);
void	can_pass(t_map *game, t_stack *stack, bool *visited);
bool	check_end(t_map *game, t_stack *cur);
void	serch_p(t_map *game, t_stack *node);
void	serch_c(t_map *game, t_stack *node);
bool	check_p(t_map *game, t_stack *cur);
bool	check_c(t_map *game);
bool	col_find(t_map *game, t_stack *stack, bool visited[]);
void	col_check(t_map *game);
void	map_count(t_map *game);
bool	check(t_map *game);

#endif