/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusantor <lusantor@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 14:52:25 by lusantor          #+#    #+#             */
/*   Updated: 2022/11/21 20:33:04 by lusantor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"

//int	main(void)
//{
//	int		test_file;
//	char	*line;
//	int		i;
//
//	i = 1;
//	test_file = open("aux/text2.txt", O_RDONLY);
//	while (i <= 12)
//	{
//		line = NULL;
//		line = get_next_line(test_file);
//		printf("line %i: %s", i++, line);
//		free(line);
//	}
//	return (0);
//}

int	main(void)
{
	int		test_file;
	char	*line;

	test_file = open("aux/text2.txt", O_RDONLY);
	while ((line = get_next_line(test_file)))
	{
		printf("line: %s", line);
		free(line);
	}
	return (0);
}
