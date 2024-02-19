/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumurata <sumurata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:21:33 by sumurata          #+#    #+#             */
/*   Updated: 2024/02/19 17:49:40 by sumurata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1

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

char	*ft_readline(int fd, char *next)
{
	char	*tmp;
	int		re;

	re = 1;
	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (!ft_strchr(next, '\n') && re != 0)
	{
		re = read(fd, tmp, BUFFER_SIZE);
		if (re == -1)
		{
			free(tmp);
			return (NULL);
		}
		next = ft_strjoin(next, tmp);
	}
	free(tmp);
	return (next);
}

char	*ft_getline(char *next)
{
	int		i;
	char	*ret;

	i = 0;
	if (!next[i])
		return (NULL);
	while (next[i] != '\0' && next[i] != '\n')
		i++;
	ret = ft_calloc(i + 2, sizeof(char *));
	i = 0;
	while (next[i] != '\0' && next[i] != '\n')
	{
		ret[i] = next[i];
		i++;
	}
	if (next[i] == '\n')
	{
		ret[i] = '\n';
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

int	main(void)
{
	int			fd;
	static char	*next;
	char		*line;

	next = "\0";
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("open");
		return (1);
	}
	line = ft_readline(fd, next);
	printf("%s\n", line);
	free(line);
	line = ft_readline(fd, next);
	if (close(fd) == -1)
	{
		perror("close");
		return (1);
	}
	return (0);
}
