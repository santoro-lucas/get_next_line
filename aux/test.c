/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusantor <lusantor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 14:52:25 by lusantor          #+#    #+#             */
/*   Updated: 2022/11/23 00:32:59 by lusantor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

// int	main(void)
// {
// 	int		test_file;
// 	int		test_file2;
// 	int		test_file3;	
// 	char	*line;
// 	int		i;

// 	i = 1;
// 	test_file = open("aux/text.txt", O_RDONLY);
// 	line = NULL;
// 	line = get_next_line(test_file);
// 	printf("line %i: %s", test_file, line);
// 	free(line);
	
// 	test_file2 = open("aux/text2.txt", O_RDONLY);
// 	line = NULL;
// 	line = get_next_line(test_file2);
// 	printf("line %i: %s", test_file2, line);
// 	free(line);
	
// 	test_file3 = open("aux/text3.txt", O_RDONLY);	
// 	line = NULL;
// 	line = get_next_line(test_file3);
// 	printf("line %i: %s", test_file3, line);
// 	free(line);

// 	line = NULL;
// 	line = get_next_line(test_file);
// 	printf("line %i: %s", test_file, line);
// 	free(line);

// 	line = NULL;
// 	line = get_next_line(test_file2);
// 	printf("line %i: %s", test_file2, line);
// 	free(line);
	
// 	line = NULL;
// 	line = get_next_line(test_file3);
// 	printf("line %i: %s", test_file3, line);
// 	free(line);

// 	line = NULL;
// 	line = get_next_line(test_file);
// 	printf("line %i: %s", test_file, line);
// 	free(line);

// 	line = NULL;
// 	line = get_next_line(test_file2);
// 	printf("line %i: %s", test_file2, line);
// 	free(line);
	
// 	line = NULL;
// 	line = get_next_line(test_file3);
// 	printf("line %i: %s", test_file3, line);
// 	free(line);
	
// 	// while (i <= 16)
// 	// {
// 	// 	line = NULL;
// 	// 	line = get_next_line(test_file2);
// 	// 	printf("line %i: %s", i++, line);
// 	// 	free(line);
// 	// }
// 	return (0);
// }

int	main(void)
{
	int		test_file;
	char	*line;
	int		i;

	i = 1;
	test_file = open("aux/text2.txt", O_RDONLY);
	while (i <= 6)
	{
		line = get_next_line(test_file);
		printf("line %i: %s", i++, line);
		free(line);
	}
	return (0);
}
