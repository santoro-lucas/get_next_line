/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusantor <lusantor@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 13:04:20 by lusantor          #+#    #+#             */
/*   Updated: 2022/11/21 23:58:26 by lusantor         ###   ########.fr       */
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

char	*get_next_line(int fd)
{
	char		*next_line;
	char		*previous_line;
	static char	buffer[BUFFER_SIZE + 1];
	int			line_len;

	if (!gnl_check(fd))
		return (NULL);
	line_len = 1;
	next_line = NULL;
	while (!gnl_strchr(next_line, '\n'))
	{
		if (*buffer == '\0' && read(fd, buffer, BUFFER_SIZE) == 0)
			break ;
		previous_line = next_line;
		line_len += gnl_len(buffer);
		next_line = gnl_alloc(line_len);
		gnl_append(next_line, previous_line, line_len);
		gnl_append(next_line, buffer, line_len);
		free(previous_line);
		gnl_realign(buffer);
	}
	return (next_line);
}
