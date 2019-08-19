/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_over.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 10:36:14 by rengelbr          #+#    #+#             */
/*   Updated: 2019/07/25 13:14:27 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_int_over(const char *str)
{
	long	res;
	int		neg;

	res = 0;
	neg = 1;
	while (ft_iswhitespace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		(*str == '-') ? (neg = -1) : 1;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		res = res * 10 + (*str - '0');
		if (neg == 1)
			if (res > 2147483647)
				return (1);
		str++;
	}
	res *= neg;
	if (res < -2147483648)
		return (1);
	return (0);
}
