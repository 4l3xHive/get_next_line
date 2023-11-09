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

char    *read_file(int fd, )
{
    char    *buffer;
    ssize_t  bytes_read;

    bytes_read = 0;;
    while (bytes_read > 0)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read < 0)
            break; 
    }

}








char    *get_next_line(int fd)
{
    static char *buffer;

    if (!fd || !BUFFER_SIZE || !read(fd, 0, 0))
        return (NULL);
    buffer = read_file(fd);

    


}


int main(int ac, char **av)
{
    int fd = open(av[1], O_RDONLY);
    char *line = get_next_line(fd);
    write(1, line, len(line));
    return 0;
}