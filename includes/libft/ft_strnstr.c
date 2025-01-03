/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsayed <abdsayed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:38:52 by abdsayed          #+#    #+#             */
/*   Updated: 2024/07/03 18:28:26 by abdsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;

	if (!haystack || !needle)
		return (perror("strnstr: sending null"), NULL);
	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (i < n && haystack[i] != '\0')
	{
		if (haystack[i] == needle[j])
		{
			while (i + j < n && haystack[i + j] == needle[j])
			{
				if (needle[j + 1] == '\0')
					return ((char *)haystack + i);
				j++;
			}
			j = 0;
		}
		i++;
	}
	return (NULL);
}
