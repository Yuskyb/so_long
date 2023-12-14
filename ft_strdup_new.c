/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 13:02:33 by yususato          #+#    #+#             */
/*   Updated: 2023/12/14 20:06:36 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

char	*ft_strdup_new(char *src)
{
	int		i;
	char	*new;

	i = 0;
	if (src == NULL)
		return (NULL);
	new = (char *)malloc(sizeof(char) * ft_strlen(src));
	if (new == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		new[i] = src[i];
		i++;
	}
	if (ft_strchr(new, '\n') && i != 0)
		new[i - 1] = '\0';
	else
		new[i] = '\0';
	return (new);
}
