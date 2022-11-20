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

int	gnl_check(int fd)
{
	if (fd < 0 || read(fd, 0, 0) < 0)
		return (0);
	else
		return (1);
}

// ssize_t	read(int fd, void *buf, size_t count)
// > reads count bytes from fd pointed file into *buf

char	*get_next_line(int fd)
{
	char		*next_line;
	static char	buffer[BUFFER_SIZE + 1];
	int			line_len;
	char		*temp_line;

	if (!gnl_check(fd))
		return (NULL);
	line_len = 1;
	next_line = NULL;
	while (!gnl_strchr(next_line, '\n'))
	{
		temp_line = next_line;
		if (*buffer == '\0' && read(fd, buffer, BUFFER_SIZE) == 0)
		{
			free(temp_line);
			break ;
		}
		line_len += gnl_len(buffer);
		next_line = malloc(line_len);
		gnl_strlcpy(next_line, temp_line, line_len);
		free(temp_line);
		gnl_strlcat(next_line, buffer, line_len);
		buffer_realign(buffer);
	}
	return (next_line);
}
