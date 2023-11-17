/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:41:22 by fsantama          #+#    #+#             */
/*   Updated: 2023/02/27 17:01:27 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_get_new_line(char *read_line)
{
	int		i;
	int		j;
	char	*str;

	j = 0;
	i = 0;
	while (read_line[i] && read_line[i] != '\n')
		i++;
	if (!read_line[i])
	{
		free(read_line);
		return (0);
	}
	str = malloc(sizeof(char) * (ft_strlen(read_line) - i + 1));
	if (!str)
		return (0);
	i++;
	while (read_line[i])
		str[j++] = read_line[i++];
	str[j] = 0;
	free(read_line);
	return (str);
}

char	*ft_get_line(char *read_line)
{
	int		i;
	char	*str;

	i = 0;
	if (!read_line[i])
		return (0);
	while (read_line[i] && read_line[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (0);
	i = 0;
	while (read_line[i] && read_line[i] != '\n')
	{
		str[i] = read_line[i];
		i++;
	}
	if (read_line[i] == '\n')
	{
		str[i] = '\n';
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_read_line(int fd, char *read_line)
{
	char			*buff;
	int				read_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (0);
	read_bytes = 1;
	while (!ft_strchr(read_line, '\n') && read_bytes)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			free(read_line);
			return (0);
		}
		buff[read_bytes] = '\0';
		read_line = ft_strjoin(read_line, buff);
	}
	free(buff);
	return (read_line);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*read_line[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	read_line[fd] = ft_read_line(fd, read_line[fd]);
	if (!read_line[fd])
		return (NULL);
	line = ft_get_line(read_line[fd]);
	read_line[fd] = ft_get_new_line(read_line[fd]);
	return (line);
}
