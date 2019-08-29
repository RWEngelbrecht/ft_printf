/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 15:17:59 by rengelbr          #+#    #+#             */
/*   Updated: 2019/08/29 09:09:54 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		neg;

	i = 0;
	neg = 0;
	if (!(str = ft_strnew(ft_intlen(n) + 1)))
		return (NULL);
	if (n <= -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		str[i++] = '0';
	if (n < 0 && (n = -n))
		neg = 1;
	while (n > 0)
	{
		str[i++] = n % 10 + '0';
		n /= 10;
	}
	if (neg == 1)
		str[i++] = '-';
	str[i] = '\0';
	ft_strrev(str);
	return (str);
}
