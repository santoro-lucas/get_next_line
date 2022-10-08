/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusantor <lusantor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 13:04:20 by lusantor          #+#    #+#             */
/*   Updated: 2022/10/08 15:44:45 by lusantor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

// ssize_t	read(int fd, void *buf, size_t count)
// reads count bytes from fd pointed file into *buf

char *get_next_line (int fd)
{
	int		bufa_sai;
	char	*bufa;

	bufa_sai = 2048;
	bufa = malloc(bufa_sai);
	read(fd, bufa, bufa_sai);
	return (bufa);
}

#include <fcntl.h>
#include <stdio.h>
int	main(void)
{	
	printf("%i\n", open("lulala.txt", O_RDONLY));
	printf("%s\n", get_next_line(3));
	return (0);
}