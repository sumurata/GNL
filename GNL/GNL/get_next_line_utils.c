/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumurata <sumurata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 22:00:57 by sumurata          #+#    #+#             */
/*   Updated: 2024/02/19 17:33:59 by sumurata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//size_t	ft_strlen(const char *str)
//{
//	size_t	len;

//	len = 0;
//	while (str[len] != '\0')
//		len++;
//	return (len);
//}

char	*ft_strchr(const char *str, int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	while (1)
	{
		if (*str == uc)
			return ((char *)str);
		if (*str == '\0')
			return (NULL);
		str++;
	}
}

void	*ft_memcpy(void *buf1, const void *buf2, size_t n)
{
	char		*b1;
	const char	*b2;
	size_t		i;

	b1 = buf1;
	b2 = buf2;
	i = 0;
	if (b1 == NULL && b2 == NULL)
		return (NULL);
	while (i < n)
	{
		b1[i] = b2[i];
		i++;
	}
	return (buf1);
}

//char	*ft_strjoin(char const *s1, char const *s2)
//{
//	size_t	len1;
//	size_t	len2;
//	char	*result;

//	if (s1 == NULL || s2 == NULL)
//		return (NULL);
//	len1 = ft_strlen(s1);
//	len2 = ft_strlen(s2);
//	result = (char *)malloc(len1 + len2 + 1);
//	if (result == NULL)
//		return (NULL);
//	ft_memcpy(result, (char *)s1, len1);
//	ft_memcpy(result + len1, (char *)s2, len2 + 1);
//	return (result);
//}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*result;

	len1 = 0;
	len2 = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	while (s1[len1] != '\0')
		len1++;
	while (s2[len2] != '\0')
		len2++;
	result = (char *)malloc(len1 + len2 + 1);
	if (result == NULL)
		return (NULL);
	ft_memcpy(result, (char *)s1, len1);
	ft_memcpy(result + len1, (char *)s2, len2 + 1);
	return (result);
}

void	*ft_memset(void *buf, int value, size_t len)
{
	unsigned char	*b;
	size_t			i;

	b = buf;
	i = 0;
	while (i < len)
	{
		b[i] = (unsigned char)value;
		i++;
	}
	return (buf);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	totalsize;
	void	*ptr;

	totalsize = 0;
	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	if (size < (SIZE_MAX / count))
	{
		totalsize = count * size;
		ptr = malloc(totalsize);
		if (ptr == NULL)
			return (NULL);
		ft_memset(ptr, 0, totalsize);
	}
	else
		return (NULL);
	return (ptr);
}
