/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusantor <lusantor@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:22:00 by lusantor          #+#    #+#             */
/*   Updated: 2022/11/21 21:52:24 by lusantor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*gnl_alloc(int size)
{
	char	*ptr;
	int		offset;

	offset = 0;
	ptr = malloc(size);
	while (size--)
	{
		*(ptr + offset++) = 0;
	}
	return (ptr);
}

size_t	gnl_append(char *dst, const char *src, size_t size)
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
	while (size-- > 1)
		*dst++ = *src++;
	*dst = '\0';
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

char	*gnl_strchr(const char *str, int chr)
{
	if (str == NULL)
		return (NULL);
	while ((*str != (char) chr) && (*str != '\0'))
		str++;
	if (*str == (char) chr)
		return ((char *) str);
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

//gnl_read(char *buffer)
//{
//	if (*buffer == '\0')
//		byte_count = read(fd, buffer, BUFFER_SIZE);
//	if (byte_count = 0)
//	{
//		free(last_line);
//		break
//	}
//}