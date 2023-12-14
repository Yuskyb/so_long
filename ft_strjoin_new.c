/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 13:02:22 by yususato          #+#    #+#             */
/*   Updated: 2023/12/14 16:19:31 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin_new(char *s1, char *s2, t_map *game)
{
	char	*new;
	size_t	len1;
	size_t	len2;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!new)
		return (NULL);
	ft_strlcpy(new, s1, len1 + 1);
	ft_strlcpy(new + len1, s2, len2 + 1);
	if (ft_strchr(new, '\n'))
		new[len1 + len2 - 1] = '\0';
	else
		game->flag = 1;
	return (new);
}
