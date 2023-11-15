/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daehlee <daehlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 20:16:08 by daehlee           #+#    #+#             */
/*   Updated: 2023/11/12 23:13:54 by daehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	ent(char *str)
{
	ssize_t	idx;

	idx = 0;
	while (str[idx])
	{
		if (str[idx] == '\n')
			return (idx);
		idx++;
	}
	return (-1);
}

ssize_t	len(char *str)
{
	ssize_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*join(char *tmp, char *bf)
{
	char	*join;
	ssize_t	ti;

	if (!tmp)
	{
		tmp = (char *)malloc(1);
		if (!tmp)
			return (NULL);
		tmp[0] = '\0';
	}
	if (!bf)
		return (tmp);
	join = (char *)malloc((len(tmp) + len(bf) + 1));
	if (join)
	{
		ti = -1;
		while (tmp[++ti])
			join[ti] = tmp[ti];
		while (*bf)
			join[ti++] = *bf++;
		join[ti] = '\0';
	}
	free(tmp);
	tmp = 0;
	return (join);
}
