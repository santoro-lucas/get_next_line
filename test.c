/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusantor <lusantor@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 14:52:25 by lusantor          #+#    #+#             */
/*   Updated: 2022/10/20 22:57:47 by lusantor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "gnl/get_next_line.h"

int	main(void)
{
	int		test_file;
	int		i;
	char	*line;

	i = 1;
	test_file = open("text.txt", O_RDONLY);
	while (i <= 5)
	{
		line = NULL;
		line = get_next_line(test_file);
		printf("line %i: %s", i++, line);
	}
	// free(line);
	return (0);
}
