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
# define TRUE 1
# define FALSE 0
# define BUFFER_SIZE 20
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# if BUFFER_SIZE > 9223372036854775806
# undef BUFFER_SIZE
# define BUFFER_SIZE 0
#endif 
char    *get_next_line(int fd);


#endif