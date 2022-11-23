/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusantor <lusantor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 13:04:20 by lusantor          #+#    #+#             */
/*   Updated: 2022/11/23 00:28:28 by lusantor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	gnl_check(int fd)
{
	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (0);
	else
		return (1);
}

char	*get_next_line(int fd)
{
	char		*next_line;
	char		*previous_line;
	static char	buffer[256][BUFFER_SIZE + 1];
	int			line_len;

	if (!gnl_check(fd))
		return (NULL);
	line_len = 1;
	next_line = NULL;
	while (!gnl_strchr(next_line, '\n'))
	{
		if (*buffer[fd] == '\0' && read(fd, buffer[fd], BUFFER_SIZE) == 0)
			break ;
		previous_line = next_line;
		line_len += gnl_len(buffer[fd]);
		next_line = gnl_alloc(line_len);
		gnl_append(next_line, previous_line, line_len);
		gnl_append(next_line, buffer[fd], line_len);
		free(previous_line);
		gnl_realign(buffer[fd]);
	}
	return (next_line);
}
