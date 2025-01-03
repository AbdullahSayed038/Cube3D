/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsayed <abdsayed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:25:00 by abdsayed          #+#    #+#             */
/*   Updated: 2024/07/01 15:25:02 by abdsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	char	*a;

	if (!b)
		return (perror("memset: sending null"), NULL);
	a = (char *)b;
	while (n > 0)
	{
		a[n - 1] = (char)c;
		n--;
	}
	return (b);
}
