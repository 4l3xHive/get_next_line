/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:03:20 by apyykone          #+#    #+#             */
/*   Updated: 2023/11/09 16:03:22 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t  ft_strlenni(char *s)
{
    size_t len;

    len = 0;
    if (s != NULL)
    {
        while (s[len])
            len++;
    }
    return (len);
}

char *ft_strjoinni(char *first, char *last)
{
    char    *answ;
    size_t  total_len;
    size_t  j;
    size_t  i;

    if (!first || !last)
        return (NULL);
    i = 0;
    j = 0;
    total_len = ft_strlenni(first) + ft_strlenni(last);
    answ = (char *)malloc(sizeof(char) * (total_len + 1));
    if (!answ)
        return (NULL);
    while (first[j])
        answ[i++] = first[j++];
    j = 0;
    while (last[j])
        answ[i++] = last[j++];
    answ[i] = '\0';
    return (answ);
}


int ft_check_nl(char *read_buffer)
{
    size_t i;

    i = 0;
    if (!read_buffer)
        return (0);
    while (read_buffer[i])
    {
        if (read_buffer[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}

char	*ft_strchrri(const char *s, int c)
{
	char	*ret;
	char	ch;

	ret = (char *)s;
	ch = (char)c;
	while (*ret)
	{
		if (*ret == ch)
			return (ret);
		ret++;
	}
	if (ch == '\0')
		return (ret);
	return (NULL);
}




char    *ft_strduppi(char *s)
{
    char    *ret;

    ret = (char *)malloc(sizeof(char) * ft_strlenni(s) + 1);
    if (!ret)
        return (NULL);

    while (*s)
        *ret++ = *s++;
    *ret = '\0';
    return (ret);
}
