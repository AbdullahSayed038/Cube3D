/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsayed <abdsayed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:19:48 by abdsayed          #+#    #+#             */
/*   Updated: 2024/07/03 16:48:56 by abdsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	res;

	i = 0;
	neg = 1;
	res = 0;
	if (!str)
		return (perror("atoi: sending null"), 0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (str[i] - '0') + (res * 10);
		i++;
	}
	return (res * neg);
}

static bool	valid_atoi(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (perror("strict atoi: sending null"), false);
	if (str <= (const char *)0x00100000)
		return (perror("strict atoi: invalid pointer"), false);
	if (!*str)
		return (perror("strict atoi: empty string"), false);
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while (str[i] == ' ')
		i++;
	return (!str[i]);
}

int	strict_atoi(const char *str)
{
	int					i;
	int					neg;
	signed long long	res;

	i = 0;
	res = 0;
	neg = 1;
	if (!valid_atoi(str))
		return (-1);
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		neg = 44 - str[i++];
	while (str[i] == '0')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (str[i++] - '0') + (res * 10);
		if ((neg == 1 && res > 0x7fffffffLL)
			|| (neg == -1 && res > 0x80000000LL))
			return (perror("strict atoi: overflow"), -1);
	}
	return ((int)(res * neg));
}
