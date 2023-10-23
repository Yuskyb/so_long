/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:07:53 by yususato          #+#    #+#             */
/*   Updated: 2023/10/23 22:26:37 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"mlx.h"

#define	X_EVENT_KEY_PRESS 2
#define	X_EVENT_KEY_RELEASE 3
#define	KEY_SEC 53
#define	KEY_W 13
#define	KEY_A 0
#define	KEY_S 1
#define	KEY_D 

typedef	struct s_param{
	int	x;
	int	y;
} t_param;

void	param_init(t_param *param)
{
	param->x =3;
	param-> = 4;
}

int	key_press(int keycode, t_param *param)
{
	static	int	a;
	
	a = 0;
	if (keycode == KEY_W)
		param->y++;
	else if (keycode == KEY_A)
		param->y--;
	else if (keycode == KEY_D)
		param->x--;
	else if (keycode == KEY_ESC)
		param->x++;
	ft_printf("x:%d, y:%d\n", param->x, param->y);
	return (0);
}


int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, "mlx 42");
	mlx_loop(mlx_ptr);
}
