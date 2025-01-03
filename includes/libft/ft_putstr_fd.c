/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsayed <abdsayed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 13:38:59 by abdsayed          #+#    #+#             */
/*   Updated: 2024/07/02 13:39:07 by abdsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(const char *const s, int fd)
{
	if (!s)
		return (perror("putstr_fd: sending null"));
	if (write(fd, s, ft_strlen(s)) < 0)
		perror("putstr_fd: write error");
}
