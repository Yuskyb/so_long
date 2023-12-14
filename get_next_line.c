/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:09:56 by yususato          #+#    #+#             */
/*   Updated: 2023/12/14 14:40:28 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

char	*fr_strjoin_free_temp(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

char	*ft_left_line(char *buffer)
{
	size_t	i;
	size_t	j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = (char *)ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	if (!line)
	{
		free(buffer);
		return (line);
	}
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

char	*ft_got_line(char *buffer)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = (char *)ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*ka_read_file(int fd, char *one_fd_line)
{
	char	*buffer;
	long	byte_read;

	buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[byte_read] = '\0';
		one_fd_line = fr_strjoin_free_temp(one_fd_line, buffer);
		if (ft_strchr(one_fd_line, '\n'))
			break ;
	}
	free(buffer);
	return (one_fd_line);
}

char	*get_next_line(int fd)
{
	static char	*many_fd[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	many_fd[fd] = ka_read_file(fd, many_fd[fd]);
	if (!many_fd[fd])
		return (NULL);
	line = ft_got_line(many_fd[fd]);
	many_fd[fd] = ft_left_line(many_fd[fd]);
	return (line);
}

// char	*line_next(char *buffer, char *line)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	*tmp;

// 	i = 0;
// 	j = 0;
// 	while (buffer[i] && buffer[i] != '\n')
// 		i++;
// 	if (!buffer[i])
// 	{
// 		free(buffer);
// 		return (NULL);
// 	}
// 	tmp = (char *)ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
// 	if (!tmp)
// 	{
// 		free(buffer);
// 		return (line);
// 	}
// 	i++;
// 	while (buffer[i])
// 		tmp[j++] = buffer[i++];
// 		// printf("buffer333 yade~%s\n",buffer);
// 	free(buffer);
// 	// ft_exit();
// 	return (tmp);
// }

// char	*output(char *buffer)
// {
// 	char	*line;
// 	size_t	i;

// 	i = 0;
// 	if (!buffer[i])
// 		return (NULL);
// 	while (buffer[i] && buffer[i] != '\n')
// 		i++;
// 	line = ft_calloc(i + 2, sizeof(char));
// 	if (!line)
// 	{
// 		free(buffer);
// 		return (NULL);
// 	}
// 	i = 0;
// 	while (buffer[i] && buffer[i] != '\n')
// 	{
// 		line[i] = buffer[i];
// 		i++;
// 	}
// 	if (buffer[i] != '\0' && buffer[i] == '\n')
// 		line[i] = '\n';
// 	return (line);
// }

// char	*unit(char *buffer, char *buf)
// {
// 	char	*temp;

// 	temp = ft_strjoin(buffer, buf);
// 	// free(buffer);
// 	return (temp);
// }

// char	*read_file(int fd, char *buffer, int *flag)
// {
// 	int		byte_size;
// 	char	*buf;

// 	byte_size = 1;
// 	buf = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
// 	if (!buf)
// 		ft_exit();
// 	printf("buf yade~!!!!!!!!%s\n",buf);
// 	while (byte_size > 0)
// 	{
// 		byte_size = read(fd, buf, BUFFER_SIZE);
// 		if (byte_size == -1)
// 		{
// 			*flag = 0;
// 			free(buf);
// 			buf = NULL;
// 			return (NULL);
// 		}
// 		buf[byte_size] = '\0';
// 		buffer = unit(buffer, buf);
// 		if (ft_strchr(buffer, '\n'))
// 			break ;
// 	}
// 	if (buf)
// 	{
// 		printf("buf yade~%s\n",buf);
// 		printf("~%p\n",buf);
// 		// free(buf);
// 		buf = NULL;
// 	}
// 	printf("buffer yade~%s\n",buffer);
// 	return (buffer);
// }

// char	*get_next_line(int fd)
// {
// 	static char	*buffer;
// 	char		*line;
// 	int			flag;

// 	flag = 1;
// 	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
// 		ft_exit();
// 	buffer = read_file(fd, buffer, &flag);
// 	if (flag == 0)
// 	{
// 		free(buffer);
// 		return (NULL);
// 	}
// 	if (!buffer)
// 		return (NULL);
// 	line = output(buffer);
// 	buffer = line_next(buffer, line);
// 	return (line);
// }
