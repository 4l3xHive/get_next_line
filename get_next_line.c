/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:03:05 by apyykone          #+#    #+#             */
/*   Updated: 2023/11/09 16:03:07 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char *ft_cat_free(char *s_buffer, char *read_buffer)
{
    char    *joined;

    joined = ft_strjoinni(s_buffer, read_buffer);
    free(read_buffer);
    return(joined);
}

static char	*ft_next_spot(char *buffer)
{
	int		i;
	int		j;
	char	*line;
    size_t  line_size;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
    line_size = ft_strlenni(buffer) - i + 1;
	line = malloc(line_size * sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

static char	*ft_getline(char *s_buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!s_buffer[i])
		return (NULL);

	while (s_buffer[i] && s_buffer[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
    if (!line){
        return (NULL);
    }
    line[i + 2] = '\0';
	i = 0;
	while (s_buffer[i] && s_buffer[i] != '\n')
	{
		line[i] = s_buffer[i];
		i++;
	}
	if (s_buffer[i] && s_buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

static char    *ft_read_file(int fd, char *s_buffer)
{
    char    *read_buffer;
    ssize_t  bytes_read;

    if (!s_buffer)
        s_buffer = malloc(1);
    read_buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
    if (!read_buffer)
        return (NULL);
    bytes_read = 1;
    while (bytes_read > 0)
    {
        bytes_read = read(fd, read_buffer, BUFFER_SIZE);
        if (bytes_read == -1)
        {
            free(read_buffer);
            return (NULL);
        }
        read_buffer[bytes_read] = '\0';
        s_buffer = ft_cat_free(s_buffer, read_buffer);
        if (!s_buffer)
            return (NULL);
        if (ft_check_nl(read_buffer))
            break;
    }
    free(read_buffer);
    return (s_buffer);
}

char    *get_next_line(int fd)
{
    static char *buffer;
    char        *line;

    if (!fd || !BUFFER_SIZE || read(fd, 0, 0) < 0)
        return (NULL);
    buffer = ft_read_file(fd, buffer);
    line = ft_getline(buffer);
    buffer = ft_next_spot(buffer);
    return (line);
}


int main(int ac, char **av)
{
    (void)ac;
    int fd = open(av[1], O_RDONLY);
    char *line = get_next_line(fd);
    (void)line;
   write(1, line, ft_strlenni(line));
    return 0;
}