/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:07:53 by yususato          #+#    #+#             */
/*   Updated: 2023/10/24 19:39:09 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"mlx.h"
#include	"so_long"

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
