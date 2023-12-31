/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumurata <sumurata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 22:00:30 by sumurata          #+#    #+#             */
/*   Updated: 2023/12/27 18:12:33 by sumurata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*next;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	next = ft_readline(fd, next);
	if (!next)
		return (NULL);
}

static char	*ft_readline(int fd, static char *next)
{
	char	*tmp;
	int		re;

	re = 1;
	// tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	// if (!tmp)
	//	return (NULL);
	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char *));
	while (!ft_strchr(next, '\n') && re != 0)
	{
		re = read(fd, tmp, BUFFER_SIZE);
		if (re == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[re] = '\0';
		next = ft_strjoin(next, tmp);
	}
	free(tmp);
	return (next);
}

char	*ft_getline(static char *next)
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

char	*ft_changenext(static char *next)
{
	int		len;
	int		i;
	int		a;
	char	*str;

	i = 0;
	c = 0;
	while (next[i] != '\0' && next[i] != '\n')
		i++;
	if (!next[i])
	{
		free(next);
		return (NULL);
	}
	while (next[len] != '\0')
		len++;
	str = ft_calloc(len - i + 1, sizeof(char *));
	i += 1;
	while (next[i])
		str[c++] = next[i++];
	str[c] = '\0';
	free(next);
	return (str);
}
