/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusantor <lusantor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 14:52:25 by lusantor          #+#    #+#             */
/*   Updated: 2022/10/15 16:40:58 by lusantor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int	test_file;
	int	i;
	char *line;

	i = 1;
	test_file = open("text.txt", O_RDONLY);
	while (i < 6)
	{
		line = get_next_line(test_file);
		printf("%s <<< line %i: \n", line, i++);	
	}
	free(line);
	return (0);
}
