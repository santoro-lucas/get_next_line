/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusantor <lusantor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 13:04:20 by lusantor          #+#    #+#             */
/*   Updated: 2022/10/15 16:23:35 by lusantor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// ssize_t	read(int fd, void *buf, size_t count)
// > reads count bytes from fd pointed file into *buf

char	*get_next_line(int fd)
{
	char		*next_line;
	static char	*buffer;
	int			line_len;

	next_line = malloc(1024);
	buffer = malloc(BUFFER_SIZE + 1);
	read(fd, buffer, BUFFER_SIZE);
	gnl_strlcpy(next_line, buffer, gnl_strlen(buffer) + 1);
	while (!gnl_strchr(buffer, '\n'))
	{
		read(fd, buffer, BUFFER_SIZE);
		line_len = gnl_strlen(next_line) + gnl_strlen(buffer) + 1;
		gnl_strlcat(next_line, buffer, line_len);
	}
	if (gnl_strchr(buffer, '\0'))
		free(buffer);
	return (next_line);
}
