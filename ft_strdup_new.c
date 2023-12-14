/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 13:02:33 by yususato          #+#    #+#             */
/*   Updated: 2023/12/13 17:36:58 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

char	*ft_strdup_new(char *src)
{
	int		i;
	int		count;
	char	*new;

	i = 0;
	count = 0;
	while (src[i] != '\0')
	{
		count++;
		i++;
	}
	new = (char *)malloc(sizeof(char) * (count + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\n')
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	free(src);
	return (new);
}
