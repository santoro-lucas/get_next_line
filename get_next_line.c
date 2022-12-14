/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusantor <lusantor@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 13:04:20 by lusantor          #+#    #+#             */
/*   Updated: 2022/10/21 17:54:41 by lusantor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// ssize_t	read(int fd, void *buf, size_t count)
// > reads count bytes from fd pointed file into *buf
#include <stdio.h>

char	*get_next_line(int fd)
{
	char		*next_line;
	static char	*buffer;
	int			line_len;
	int			was_read;

	next_line = malloc(4096);
	if (!buffer)
		buffer = malloc(BUFFER_SIZE);
	while (!gnl_strchr(buffer, '\n'))
	{
		gnl_strlcat(next_line, buffer, line_len);
		was_read = read(fd, buffer, BUFFER_SIZE);
		line_len = gnl_strlen(next_line) + gnl_strlen(buffer) + 1;
	}
	line_len = gnl_strlen(next_line) + gnl_strlen(buffer) + 1;
	gnl_strlcat(next_line, buffer, line_len);
	gnl_strlcpy(buffer, gnl_strchr(buffer, '\n') + 1, BUFFER_SIZE);
	if (was_read < BUFFER_SIZE) // Melhorar esta condição
	{
		free(buffer);
		printf("freed buffer");
	}
	return (next_line);
}
