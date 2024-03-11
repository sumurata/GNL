/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumurata <sumurata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 22:00:57 by sumurata          #+#    #+#             */
/*   Updated: 2024/03/06 13:34:22 by sumurata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (c == '\0')
		return ((char *)&str[ft_strlen(str)]);
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
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

char	*ft_joinnext(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*result;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = (char *)malloc(len1 + len2 + 1);
	if (result == NULL)
		return (NULL);
	ft_memcpy(result, (char *)s1, len1);
	ft_memcpy(result + len1, (char *)s2, len2 + 1);
	if (s1)
		free(s1);
	return (result);
}
