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
// fd inválido
// arquivo vazio
// 

int	gnl_check(int fd)
{
	if (fd < 0)
		return (0);
	else
		return (1);
}

char	*get_next_line(int fd)
{
	char		*next_line;
	static char	buffer[BUFFER_SIZE];
	int			line_len;
	char		*temp;

	if (!gnl_check(fd))
		return (NULL);
	line_len = 1;
	next_line = NULL;
	while (!gnl_strchr(next_line, '\n'))
	{
		temp = next_line;
		if (*buffer == '\0' && read(fd, buffer, BUFFER_SIZE) == 0)
		{
			free(temp);
			break ;
		}
		line_len += gnl_strlen(buffer);
		next_line = malloc(line_len);
		gnl_strlcpy(next_line, temp, line_len);
		gnl_strlcat(next_line, buffer, line_len);
		free(temp);
		buffer_realign(buffer, BUFFER_SIZE);
	}
	return (next_line);
}
