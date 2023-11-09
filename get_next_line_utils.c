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

int len(char *s)
{
    int len = 0;
    while (s[len])
    {
        len++;
    }
    return (len);
}

char    *get_next_line(int fd)
{
    if (!fd || !BUFFER_SIZE)
        return (NULL);
    ssize_t  bytes_read;
    static  char buffer[BUFFER_SIZE];
    bytes_read = 0;;
    while (TRUE)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read < 0)
            break; 
    }

}


int main(int ac, char **av)
{
    int fd = open("test/test1", O_RDONLY);
    char *line = get_next_line(fd);
    write(1, line, len(line));
    return 0;
}