/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:03:20 by apyykone          #+#    #+#             */
/*   Updated: 2023/11/16 20:20:17 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t slen(char *s)
{
    size_t len;

    len = 0;
    while (s[len])
        len++;
    return (len);
}

char *join_free(char *tmp, char *bf)
{
    char *join;
    ssize_t ti;

    if (!tmp)
    {
        tmp = (char *)malloc(1);
        if (!tmp)
            return (NULL);
        tmp[0] = '\0';
    }
    if (!bf)
        return (tmp);
    join = (char *)malloc((slen(tmp) + slen(bf) + 1));
    if (join)
    {
        ti = -1;
        while (tmp[++ti])
            join[ti] = tmp[ti];
        while (*bf)
            join[ti++] = *bf++;
        join[ti] = '\0';
    }
    if (tmp)
        free(tmp);
    tmp = 0;
    return (join);
}

ssize_t find_nl(char *str)
{
    ssize_t idx;

    idx = 0;
    while (str[idx])
    {
        if (str[idx] == '\n')
            return (idx);
        idx++;
    }
    return (-1);
}
