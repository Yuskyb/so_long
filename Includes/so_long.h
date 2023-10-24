/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:35:41 by yususato          #+#    #+#             */
/*   Updated: 2023/10/24 16:20:26 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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

typedef	struct s_map{
	int	height;
	int	width;
} t_map;

 #endif