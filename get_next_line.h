/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusantor <lusantor@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:45:24 by lusantor          #+#    #+#             */
/*   Updated: 2022/11/21 21:36:01 by lusantor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

/* ************************************************************************** */
/* SEÇÃO DE INCLUDES QUE TEM QUE APAGAR                                       */
/* ************************************************************************** */
# include <fcntl.h>
# include <stdio.h>
/* ************************************************************************** */

void	buffer_realign(char *str);
void	*gnl_alloc(int size);
size_t	gnl_append(char *dst, const char *src, size_t size);
int		gnl_check(int fd);
size_t	gnl_len(const char *str);
char	*get_next_line(int fd);
char	*gnl_strchr(const char *s, int c);

#endif