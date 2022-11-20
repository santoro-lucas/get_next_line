/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusantor <lusantor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:45:24 by lusantor          #+#    #+#             */
/*   Updated: 2022/10/15 14:49:35 by lusantor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

void	buffer_realign(char *str/*, int size*/);
int		gnl_check(int fd);
void	*gnl_memcpy(void *dest, const void *src, size_t n);
char	*get_next_line(int fd);
size_t	gnl_strlcpy(char *dst, const char *src, size_t size);
size_t	gnl_strlcat(char *dst, const char *src, size_t size);
size_t	gnl_len(const char *str);
char	*gnl_strchr(const char *s, int c);

#endif