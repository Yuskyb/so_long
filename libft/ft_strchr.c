/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:07:20 by yususato          #+#    #+#             */
/*   Updated: 2023/10/24 18:17:01 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}


int main()
{
    const char *str = "Hello, World!";
    char ch = 'W';

    char *result = ft_strchr(str, ch);
    
    if (result != NULL) {
        printf("Character found: %s\n", result);
    } else {
        printf("Character not found\n");
    }

    return 0;
}