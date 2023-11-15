/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:03:05 by apyykone          #+#    #+#             */
/*   Updated: 2023/11/13 13:40:42 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char *ft_cat_free(char *s_buffer, char *read_buffer)
{
	char *joined;

	joined = NULL;
	joined = ft_strjoinni(s_buffer, read_buffer);
	if (s_buffer)
		free(s_buffer);
	return (joined);
}

// Finds eof or newline
static char *ft_next_spot(char *buffer)
{
	size_t i;
	size_t j;
	size_t line_size;
	char *newline;

	i = 0;
	j = 0;
	newline = NULL;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		if (buffer)
			free(buffer);
		return (NULL);
	}

	line_size = ft_strlenni(buffer) - i + 1;
	newline = malloc(line_size * sizeof(char) + 1);
	if (!newline)
		return (NULL);
	i++;
	while (buffer[i])
		newline[j++] = buffer[i++];
	newline[j] = '\0';
	if (buffer)
		free(buffer);
	return (newline);
}

static char *ft_getline(char *s_buffer)
{
	char *line;
	size_t i;

	i = 0;
	if (!s_buffer[i])
		return (NULL);
	while (s_buffer[i] && s_buffer[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	line[i + 1] = '\0';
	i = 0;
	while (s_buffer[i] && s_buffer[i] != '\n')
	{
		line[i] = s_buffer[i];
		i++;
	}
	if (s_buffer[i] && s_buffer[i] == '\n')
	{
		line[i++] = '\n';
	}
	else
	{
		line[i] = '\0';
	}
	return (line);
}

static char *ft_read_file(int fd, char *s_buffer)
{
	char *read_buffer;
	ssize_t bytes_read;

	read_buffer = NULL;
	bytes_read = 1;
	if (!s_buffer)
	{
		s_buffer = malloc(1);
		if (!s_buffer)
			return (NULL);
		s_buffer[0] = '\0';
	}
	read_buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!read_buffer)
	{
		free(s_buffer);
		return (NULL);
	}
	while (bytes_read > 0)
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(s_buffer);
			free(read_buffer);
			return (NULL);
		}
		read_buffer[bytes_read] = '\0';
		if (bytes_read > 0)
		{
			read_buffer[bytes_read] = '\0';
			s_buffer = ft_cat_free(s_buffer, read_buffer);
			if (!s_buffer)
				return (NULL);
			if (ft_check_nl(read_buffer))
				break;
		}
	}
	free(read_buffer);
	return (s_buffer);
}
#include <string.h>
char *get_next_line(int fd)
{
	static char *buffer;
	char *line;

	if ((fd < 0 || BUFFER_SIZE <= 0))
		return (NULL);
	if (read(fd, 0, 0) < 0)
	{
		free(buffer);
		buffer = 0;
		return (NULL);
	}

	line = NULL;

	buffer = ft_read_file(fd, buffer);

	if (!buffer)
		return (NULL);
	line = ft_getline(buffer);
	if (!line)
	{
		if (buffer)
		{
			free(buffer);
			buffer = NULL;
		}
		return (NULL);
	}
	buffer = ft_next_spot(buffer);
	return (line);
}
/*
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int fd;
	char *line;

	// Open a file with one character
	fd = open("1char.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return 1;
	}
	line = get_next_line(fd);
	printf("Line: %s\n", line);
	// Close the file descriptor
	close(fd);

	return 0;
}
*/