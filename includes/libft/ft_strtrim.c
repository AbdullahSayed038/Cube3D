/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NOTDONEft_strtrim.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsayed <abdsayed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:19:14 by abdsayed          #+#    #+#             */
/*   Updated: 2024/07/01 14:19:17 by abdsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = 0;
	i = 0;
	if (!s1 || !set)
		return (perror("strtrim: sending null"), NULL);
	if (s1 != 0 && set != 0)
	{
		j = ft_strlen(s1);
		while (s1[i] && ft_strchr(set, s1[i]))
			i++;
		while (s1[j - 1] && ft_strchr(set, s1[j - 1]) && j > i)
			j--;
		str = (char *)malloc(sizeof(char) * (j - i + 1));
		if (str)
			ft_strlcpy(str, (char *)s1 + i, j - i + 1);
	}
	return (str);
}