/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahasna <ahasna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 16:20:03 by abdsayed          #+#    #+#             */
/*   Updated: 2024/10/16 18:34:13 by ahasna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (i);
}

static char	*split_line(char *line, char *str)
{
	size_t	i;
	char	*res;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
	{
		free(line);
		return (NULL);
	}
	ft_strcpy(str, line + i);
	res[i] = '\0';
	while (i-- > 0)
		res[i] = line[i];
	free (line);
	return (res);
}

static char	*ft_strappend(char *s1, char *s2)
{
	char	*str;

	str = ft_strjoin(s1, s2);
	free(s1);
	if (!str)
		return (NULL);
	return (str);
}

static char	*make_line(int fd, char *prev)
{
	ssize_t	bytes;
	char	*res;
	char	*buff;

	bytes = 1;
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	res = ft_strdup(prev);
	while (res != NULL && bytes != 0 && !ft_strchr(res, '\n'))
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(res);
			free(buff);
			return (NULL);
		}
		buff[bytes] = '\0';
		res = ft_strappend(res, buff);
	}
	free(buff);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	prev[BUFFER_SIZE + 1U];
	char		*line;

	if (BUFFER_SIZE <= 0 || BUFFER_SIZE >= 2147483647)
		return (NULL);
	line = make_line(fd, prev);
	if (line && line[0] != '\0')
		line = split_line(line, prev);
	else if (!line)
		prev[0] = '\0';
	else if (line)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
