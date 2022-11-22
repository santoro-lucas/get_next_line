/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusantor <lusantor@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:45:24 by lusantor          #+#    #+#             */
/*   Updated: 2022/11/21 23:56:54 by lusantor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
void	*gnl_alloc(int size);
size_t	gnl_append(char *dst, const char *src, size_t size);
int		gnl_check(int fd);
size_t	gnl_len(const char *str);
void	gnl_realign(char *str);
char	*gnl_strchr(const char *s, int c);

#endif