/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusantor <lusantor@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:22:00 by lusantor          #+#    #+#             */
/*   Updated: 2022/10/20 20:09:46 by lusantor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_size;

	if (!src || !dst)
		return (0);
	src_size = gnl_len(src);
	if (size == 0)
		return (src_size);
	while (size-- > 1)
		*dst++ = *src++;
	*dst = '\0';
	return (src_size);
}

size_t	gnl_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_size;
	size_t	src_size;

	if (!src || !dst)
		return (0);
	dst_size = gnl_len(dst);
	src_size = gnl_len(src);
	if (size <= dst_size)
		return (size + src_size);
	dst += dst_size;
	size -= dst_size;
	gnl_strlcpy(dst, src, size);
	return (dst_size + src_size);
}

size_t	gnl_len(const char *str)
{
	int	len;

	len = 0;
	while (*str != '\0')
	{
		if (*str == '\n')
			return (len + 1);
		str++;
		len++;
	}
	return (len);
}

char	*gnl_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while ((*s != (char) c) && (*s != '\0'))
		s++;
	if (*s == (char) c)
		return ((char *) s);
	else
		return (NULL);
}

void	buffer_realign(char *buf)
{
	char	*tmp;
	int		len;
	int		i;

	tmp = buf;
	len = 0;
	i = 0;
	while (*(tmp + len))
			len ++;
	while (*tmp && *tmp != '\n')
			tmp ++;
	if (*tmp == '\n')
			tmp ++;
	while (tmp != (buf + len))
			buf[i++] = *tmp++;
	while (i <= len)
			buf[i++] = '\0';
}
