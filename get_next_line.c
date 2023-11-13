/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:03:05 by apyykone          #+#    #+#             */
/*   Updated: 2023/11/11 18:14:57 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*ft_cat_free(char *s_buffer, char *read_buffer)
{
	char	*joined;

	joined = NULL;
	joined = ft_strjoinni(s_buffer, read_buffer);
	if (s_buffer)
		free(s_buffer);
	return (joined);
}

// Finds eof or newline
static char	*ft_next_spot(char *buffer)
{
	size_t		i;
	size_t		j;
	size_t		line_size;
	char		*newline;

	i = 0;
	j = 0;
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
	return (newline);
}

static char	*ft_getline(char *s_buffer)
{
	char	*line;
	size_t	i;

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
		line[i++] = '\n';
	return (line);
}

static char	*ft_read_file(int fd, char *s_buffer)
{
	char		*read_buffer;
	ssize_t		bytes_read;

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
		//printf("len --> %d\n", ft_strlenni(read_buffer));
		if (bytes_read > 0)
		{
			read_buffer[bytes_read] = '\0';
			s_buffer = ft_cat_free(s_buffer, read_buffer);
			if (!s_buffer)
				return (NULL);
			if (ft_check_nl(read_buffer))
				break ;
		}
	}
	free(read_buffer);
	return (s_buffer);
}

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*line;

	line = NULL;
	if ((fd < 0 || BUFFER_SIZE <= 0) || read(fd, 0, 0) < 0)
	{
		if (buffer)
			free(buffer);
		return (NULL);
	}
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


int main(int ac, char **av)
{
    (void)ac;
    int fd = open(av[1], O_RDONLY);
    char *line;

    line = NULL;
     line = get_next_line(fd);
    write(1, line, ft_strlenni(line));




	free(line);
   line = get_next_line(fd);
	 write(1, line, ft_strlenni(line));
	    line = get_next_line(fd);
	 write(1, line, ft_strlenni(line));
	    line = get_next_line(fd);
	 write(1, line, ft_strlenni(line));
    
   // line = get_next_line(fd);
   // write(1, line, ft_strlenni(line));
    
    //line = get_next_line(fd);
   // write(1, line, ft_strlenni(line));
    //line = get_next_line(fd);
   // write(1, line, ft_strlenni(line));
    //free(line);
    close(fd);
    //write(1, line, ft_strlenni(line));
    return 0;
}

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*line;

	line = NULL;
	if ((fd < 0 || BUFFER_SIZE <= 0) || read(fd, 0, 0) < 0)
	{
		if (buffer)
			free(buffer);
		return (NULL);
	}
	buffer = ft_read_file(fd, buffer);
	if (!buffer)
		return (NULL);

	// Check for both newline and end of file
	if (*buffer || buffer[ft_strlenni(buffer)] != '\n')
	{
		line = ft_getline(buffer);
		if (!line)
		{
			free(buffer);
			buffer = NULL;
			return (NULL);
		}
		buffer = ft_next_spot(buffer);
		return (line);
	}
	free(buffer);
	buffer = NULL;
	return (NULL);
}


/*


	title("files/41_no_nl: ")
	fd = open("files/41_no_nl", O_RDWR);
	TEST(gnl(fd, "01234567890123456789012345678901234567890");
		 gnl(fd, NULL);) cout << ENDL; close(fd);

	title("files/41_with_nl: ")
	fd = open("files/41_with_nl", O_RDWR);
	TEST(gnl(fd, "0123456789012345678901234567890123456789\n");
		  gnl(fd, "0");
		 gnl(fd, NULL);) cout << ENDL; close(fd);

	title("files/42_no_nl: ")
	fd = open("files/42_no_nl", O_RDWR);
	TEST( gnl(fd, "012345678901234567890123456789012345678901");
		gnl(fd, NULL);) cout << ENDL; close(fd);

	title("files/42_with_nl: ")
	fd = open("files/42_with_nl", O_RDWR);
	TEST( gnl(fd, "01234567890123456789012345678901234567890\n");
	if (BUFFER_SIZE == 42) {
		 char c = 0; read(fd, &c, 1); check(c == '1'); ++iTest;
	   gnl(fd, NULL);}
	else {
		 gnl(fd, "1");
		 gnl(fd, NULL);})
	iTest = 1; cout << ENDL; close(fd);

	title("files/43_no_nl: ")
	fd = open("files/43_no_nl", O_RDWR);
	TEST(gnl(fd, "0123456789012345678901234567890123456789012");
	 gnl(fd, NULL);) cout << ENDL; close(fd);

	title("files/43_with_nl: ")
	fd = open("files/43_with_nl", O_RDWR);
	TEST(gnl(fd, "012345678901234567890123456789012345678901\n");
		 gnl(fd, "2");
		 gnl(fd, NULL);) cout << ENDL; close(fd);*/
