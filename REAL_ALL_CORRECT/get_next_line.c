/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:03:05 by apyykone          #+#    #+#             */
/*   Updated: 2023/11/17 14:55:05 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_file(int fd, char *s_buffer)
{
	char	buffer[BUFFER_SIZE + 1];
	int		bytes_read;

	bytes_read = 0;
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		s_buffer = join_free(s_buffer, buffer);
		if (!s_buffer)
			return (NULL);
		if (find_nl(buffer) != -1)
			break ;
	}
	return (s_buffer);
}

static char	*next_spot(char *tmp)
{
	ssize_t	i;
	char	*new_tmp;

	if (((tmp) == 0 && tmp[1] == 0) || find_nl(tmp) == -1)
	{
		free(tmp);
		tmp = 0;
		return (NULL);
	}
	new_tmp = (char *)malloc(slen(tmp) - find_nl(tmp) + 1);
	i = -1;
	if (new_tmp)
	{
		while (tmp[++i] && tmp[find_nl(tmp) + i + 1])
			new_tmp[i] = tmp[find_nl(tmp) + i + 1];
		new_tmp[i] = '\0';
	}
	if (i == 0)
	{
		free(new_tmp);
		new_tmp = 0;
	}
	free(tmp);
	tmp = 0;
	return (new_tmp);
}

static char	*get_line(char **s_buff)
{
	char		*next_line;
	ssize_t		i;
	ssize_t		s_i;
	size_t		size;
	char		*temp;

	i = -1;
	size = 0;
	temp = *s_buff;
	while (temp[++i] != '\n' && temp[i])
		size++;
	next_line = (char *)malloc(size + (temp[size] == '\n') + 1);
	if (next_line)
	{
		s_i = -1;
		if (find_nl(temp) == -1)
			while (temp[++s_i])
				next_line[s_i] = temp[s_i];
		else
			while (temp[++s_i] && s_i <= find_nl(temp))
				next_line[s_i] = temp[s_i];
		next_line[s_i] = '\0';
	}
	*s_buff = next_spot(*s_buff);
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char	*s_buffer;
	char		*next_line;

	if ((fd < 0 || BUFFER_SIZE <= 0))
		return (NULL);
	if (read(fd, 0, 0) < 0)
	{
		if (s_buffer)
			free(s_buffer);
		s_buffer = 0;
		return (NULL);
	}
	s_buffer = read_file(fd, s_buffer);
	if (!s_buffer)
		return (NULL);
	next_line = get_line(&s_buffer);
	if (!next_line && s_buffer)
	{
		free(s_buffer);
		s_buffer = 0;
	}
	return (next_line);
}
