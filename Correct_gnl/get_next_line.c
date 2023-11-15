/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daehlee <daehlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:56:28 by daehlee           #+#    #+#             */
/*   Updated: 2023/11/15 19:41:54 by daehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read(int fd, char *tmp)
{
	char	bf[BUFFER_SIZE + 1];
	int		read_cnt;

	read_cnt = 0;
	while (1)
	{
		read_cnt = read(fd, bf, BUFFER_SIZE);
		if (read_cnt < 0)
			return (NULL);
		else if (read_cnt == 0)
			break ;
		bf[read_cnt] = '\0';
		if (ent(bf) == -1)
			tmp = join(tmp, bf);
		else
		{
			tmp = join(tmp, bf);
			break ;
		}
	}
	return (tmp);
}

static char	*new_tmp(char *tmp)
{
	ssize_t	i;
	char	*new_tmp;

	if (((tmp) == 0 && tmp[1] == 0) || ent(tmp) == -1)
	{
		free(tmp);
		tmp = 0;
		return (NULL);
	}
	new_tmp = (char *)malloc(len(tmp) - ent(tmp) + 1);
	i = -1;
	if (new_tmp)
	{
		while (tmp[++i] && tmp[ent(tmp) + i + 1])
			new_tmp[i] = tmp[ent(tmp) + i + 1];
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

static char	*nextline(char **tmp)
{
	char	*next_line;
	ssize_t	i;
	ssize_t	ti;
	ssize_t	size;

	i = -1;
	size = 0;
	while ((*tmp)[++i] != '\n' && (*tmp)[i])
		size++;
	next_line = (char *)malloc(size + ((*tmp)[size] == '\n') + 1);
	if (next_line)
	{
		ti = -1;
		if (ent(*tmp) == -1)
			while ((*tmp)[++ti])
				next_line[ti] = (*tmp)[ti];
		else
			while ((*tmp)[++ti] && ti <= ent(*tmp))
				next_line[ti] = (*tmp)[ti];
		next_line[ti] = '\0';
	}
	*tmp = new_tmp(*tmp);
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char	*tmp;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, 0, 0) < 0)
	{
		free(tmp);
		tmp = 0;
		return (NULL);
	}
	tmp = ft_read(fd, tmp);
	if (!tmp)
	{
		free(tmp);
		tmp = 0;
		return (NULL);
	}
	next_line = nextline(&tmp);
	if (!next_line && tmp)
	{
		free (tmp);
		tmp = 0;
	}
	return (next_line);
}
