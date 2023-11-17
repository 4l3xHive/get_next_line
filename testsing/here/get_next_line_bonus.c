/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:37:13 by jcheel-n          #+#    #+#             */
/*   Updated: 2022/05/04 15:55:15 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

static char	*returnstring(char	*recovery)
{
	char	*line;
	int		i;

	i = 0;
	if (recovery)
	{
		while (recovery && recovery[i] != '\n')
			i++;
		line = ft_substr(recovery, 0, i + 1, 0);
		return (line);
	}
	return (NULL);
}

static char	*staticret(char	*recovery)
{
	size_t	i;

	i = 0;
	if (ft_strchr(recovery, '\n'))
		while (recovery && recovery[i] != '\n')
			i++;
	if (!recovery[i + 1])
	{
		free(recovery);
		return (NULL);
	}
	recovery = ft_substr(recovery, i + 1, ft_strlen(recovery) - i, 1);
	return (recovery);
}

static char	*reader(int fd, char *recovery)
{
	int		ret;
	char	*buf;

	ret = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	buf[0] = '\0';
	while (ret > 0 && !ft_strchr(buf, '\n'))
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret > 0)
		{
			buf[ret] = '\0';
			recovery = ft_strjoin(recovery, buf);
		}
	}
	free(buf);
	if (ret < 0)
	{	
		free(recovery);
		return (NULL);
	}	
	return (recovery);
}

char	*get_next_line(int fd)
{
	static char		*recovery[256];
	char			*line;

	if (fd < 0 || fd > 255 || !BUFFER_SIZE)
		return (NULL);
	if (!recovery[fd] || !ft_strchr(recovery[fd], '\n'))
		recovery[fd] = reader(fd, recovery[fd]);
	if (recovery[fd] == NULL)
		return (NULL);
	if (ft_strchr(recovery[fd], '\n'))
	{
		line = returnstring(recovery[fd]);
		recovery[fd] = staticret(recovery[fd]);
		return (line);
	}
	line = recovery[fd];
	recovery[fd] = NULL;
	return (line);
}
