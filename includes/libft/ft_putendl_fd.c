/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsayed <abdsayed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 13:42:09 by abdsayed          #+#    #+#             */
/*   Updated: 2024/07/02 13:43:04 by abdsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(const char *const s, int fd)
{
	if (!s)
		return (perror("putendl_fd: sending null"));
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
