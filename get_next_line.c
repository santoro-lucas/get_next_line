/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusantor <lusantor@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 13:04:20 by lusantor          #+#    #+#             */
/*   Updated: 2022/10/19 21:16:33 by lusantor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// ssize_t	read(int fd, void *buf, size_t count)
// > reads count bytes from fd pointed file into *buf

//char	*get_next_line(int fd)
//{
//	char		*next_line;
//	char		*next_next
//	char		*buffer;
//	int			line_len;
//
//	next_line = malloc(4096);
//	buffer = malloc(BUFFER_SIZE + 1);
//	if (*next_line == 0)
//		read(fd, buffer, BUFFER_SIZE);
//	gnl_strlcpy(next_line, buffer, gnl_strlen(buffer) + 1);
//	while (!gnl_strchr(buffer, '\n'))
//	{
//		read(fd, buffer, BUFFER_SIZE);
//		line_len = gnl_strlen(next_line) + gnl_strlen(buffer) + 1;
//		gnl_strlcat(next_line, buffer, line_len);
//	}
//	next_next = gnl_strchr(next_line, '\n');
//	if (gnl_strchr(buffer, '\0'))
//		free(buffer);
//	return (next_line);
//}

// V2
char	*get_next_line(int fd)
{
	char		*next_line;
	char		*buffer;
	int			line_len;

	next_line = malloc(4096);
	buffer = malloc(BUFFER_SIZE + 1);
	while (!gnl_strchr(buffer, '\n'))
	{
		gnl_strlcat(next_line, buffer, line_len);
		read(fd, buffer, BUFFER_SIZE);
		line_len = gnl_strlen(next_line) + gnl_strlen(buffer) + 1;
	}
	free(buffer);
	return (next_line);
}
