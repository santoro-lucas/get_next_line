/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusantor <lusantor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 13:04:20 by lusantor          #+#    #+#             */
/*   Updated: 2022/10/15 14:43:04 by lusantor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// ssize_t	read(int fd, void *buf, size_t count)
// > reads count bytes from fd pointed file into *buf

char	*get_next_line(int fd)
{
	char	*next_line;
	char	*buffer;
	int		line_len;

	next_line = malloc(1024);
	buffer = malloc(BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	gnl_strlcpy(next_line, buffer, gnl_strlen(buffer) + 1);
	while (!gnl_strchr(buffer, '\n'))
	{
		read(fd, buffer, BUFFER_SIZE);
		line_len = gnl_strlen(next_line) + gnl_strlen(buffer) + 1;
		gnl_strlcat(next_line, buffer, line_len);
	}
	return (next_line);
}

#include <fcntl.h>
#include <stdio.h>
int	main(void)
{
	int	file_no;
	int	i;

	i = 0;
	file_no = open("test_text.txt", O_RDONLY);
	while (printf("%s", get_next_line(file_no)))
		printf(" <<< line %i: \n", ++i);
	return (0);
}
