/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:35:41 by yususato          #+#    #+#             */
/*   Updated: 2023/10/31 18:52:55 by yususato         ###   ########.fr       */
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
# include	"mlx.h"

#define	X_EVENT_KEY_PRESS 2
#define	X_EVENT_KEY_RELEASE 3
#define	KEY_ESC 53
#define	KEY_W 13
#define	KEY_A 0
#define	KEY_S 1
#define	KEY_D 2

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 5

# endif

typedef	struct s_param{
	int	x;
	int	y;
} t_param;

typedef	struct s_mlx{
	void	*mlx_ptr;
	void	*win_ptr;
} t_mlx;

typedef	struct s_img{
	void	*land;
	void	*wall;
	void	*chara;
	void	*chest;
	void	*chest_open;
	void	*rune;
	void	*rune_light;
	int		width;
	int		height;
} t_img;

typedef	struct s_map{
	t_mlx	mlx;
	t_img	img;
	int	height;
	int	width;
	char	*str_line;
	char	col_cnt;
	char	all_col;
} t_map;

void	map_read(char *map, t_map *game);
void	setting_img(t_mlx *mlx, t_img *img, t_map *game);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
char	*line_next(char *buffer, char *line);
char	*output(char *buffer);
char	*unit(char *buffer, char *buf);
char	*read_file(int fd, char *buffer, int *flag);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
char	*line_next(char *buffer, char *line);
char	*output(char *buffer);
char	*unit(char *buffer, char *buf);
char	*read_file(int fd, char *buffer, int *flag);
char	*get_next_line(int fd);
char	*ft_strdup_new(const char *src);
char	*ft_strjoin_new(char const *s1, char const *s2);
void	error(void);
int		key_press(int key_code, t_param *param);
void	param_init(t_param *param);

 #endif