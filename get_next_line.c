/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusantor <lusantor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 13:04:20 by lusantor          #+#    #+#             */
/*   Updated: 2022/10/08 19:15:38 by lusantor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

// ssize_t	read(int fd, void *buf, size_t count)
// > reads count bytes from fd pointed file into *buf

char *get_next_line (int fd)
{
	char		*bufa;

	bufa = malloc(BUFFER_SIZE);
	read(fd, bufa, BUFFER_SIZE);
	return (bufa);
}

#include <fcntl.h>
#include <stdio.h>
int	main(void)
{
	int	file_no;

	file_no = open("lulala.txt", O_RDONLY);
	printf("call 1:\n%s\n\n", get_next_line(file_no));
	printf("call 2:\n%s\n\n", get_next_line(file_no));
	printf("call 3:\n%s\n\n", get_next_line(file_no));
	printf("call 4:\n%s\n\n", get_next_line(file_no));
	printf("call 5:\n%s\n\n", get_next_line(file_no));
	printf("call 6:\n%s\n\n", get_next_line(file_no));
	printf("call 7:\n%s\n\n", get_next_line(file_no));
	return (0);
}