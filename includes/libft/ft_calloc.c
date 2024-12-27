/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsayed <abdsayed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:20:11 by abdsayed          #+#    #+#             */
/*   Updated: 2024/07/03 18:46:55 by abdsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nmemtotalsize, size_t size)
{
	void	*ptr;

	if (nmemtotalsize == 0 || size == 0)
		return (perror("calloc: invalid size"), NULL);
	if (nmemtotalsize > SIZE_MAX / size)
		return (perror("calloc: integer overflow"), NULL);
	ptr = malloc(size * nmemtotalsize);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, (nmemtotalsize * size));
	return (ptr);
}
