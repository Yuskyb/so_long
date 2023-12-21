/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:09:42 by yususato          #+#    #+#             */
/*   Updated: 2023/12/08 13:37:51 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	draw_wall(t_mlx *mlx, t_img *img, int wid, int hei)
{
	mlx_put_image_to_window(mlx->m_ptr, mlx->w_ptr,
		img->wall, wid * 50, hei * 50);
}

void	draw_chest(t_mlx *mlx, t_img *img, int wid, int hei)
{
	mlx_put_image_to_window(mlx->m_ptr, mlx->w_ptr,
		img->chest, wid * 50, hei * 50);
}

void	draw_chara(t_mlx *mlx, t_img *img, int wid, int hei)
{
	mlx_put_image_to_window(mlx->m_ptr, mlx->w_ptr,
		img->chara, wid * 50, hei * 50);
}

void	draw_rune(t_mlx *mlx, t_img *img, int wid, int hei)
{
	mlx_put_image_to_window(mlx->m_ptr, mlx->w_ptr,
		img->rune, wid * 50, hei * 50);
}

void	draw_land(t_mlx *mlx, t_img *img, int wid, int hei)
{
	mlx_put_image_to_window(mlx->m_ptr, mlx->w_ptr,
		img->land, wid * 50, hei * 50);
}
