/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsayed <abdsayed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:19:58 by abdsayed          #+#    #+#             */
/*   Updated: 2024/07/01 14:20:01 by abdsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	if (!s)
		return (perror("bzero: sending null"));
	if ((size_t)s + n < n || (size_t)s + n < (size_t)s)
		return(perror("bzero: crazy count"));
	while (n--)
		*(unsigned char *)s++ = 0;
}
