/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:03:12 by apyykone          #+#    #+#             */
/*   Updated: 2023/11/09 16:03:13 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 20
# if BUFFER_SIZE > 9223372036854775806
# undef BUFFER_SIZE
# define BUFFER_SIZE 0
#endif 
# endif
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

// CORE
char    *get_next_line(int fd);

// UTILS
char    *ft_strjoinni(char *first, char *last);
size_t  ft_strlenni(char *s);
int     ft_check_nl(char *read_buffer);
char	*ft_strchrri(const char *s, int c);
#endif