/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsayed <abdsayed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 13:14:32 by abdsayed          #+#    #+#             */
/*   Updated: 2024/07/03 18:34:26 by abdsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordlen(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static size_t	ft_countwords(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			s += ft_wordlen(s, c);
		}
		else
			s++;
	}
	return (count);
}

static void	*free_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free((void *)strs);
	return (NULL);
}

char	**ft_split(char const *str, char c)
{
	char	**strs;
	size_t	i;
	size_t	count;

	if (!str)
		return (perror("split: sending null"), (char **) NULL);
	count = ft_countwords(str, c);
	strs = (char **)malloc(sizeof(char *) * (count + 1ULL));
	if (!strs)
		return (NULL);
	strs[count] = NULL;
	i = 0;
	while (*str)
	{
		if (*str != c)
		{
			strs[i] = ft_substr(str, 0, ft_wordlen(str, c));
			if (!strs[i++])
				return ((char **)free_strs(strs));
			str += ft_wordlen(str, c);
		}
		else
			str++;
	}
	return (strs);
}
