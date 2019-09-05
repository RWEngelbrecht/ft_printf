/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 13:00:11 by rengelbr          #+#    #+#             */
/*   Updated: 2019/09/05 12:14:30 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void convert(char *ret, int len, int num, int base)
{
	char	*base_str = "0123456789ABCDEF";

	ret[len] = '\0';
	while (num)
	{
		ret[--len] = base_str[num % base];
		num /= base;
	}
}

char	*ft_itoa_base(int value, int base)
{
//	char	*base_str = "0123456789ABCDEF";
	char	*ret;
	long	num;
	int		len;

	len = 0;
	if (value == 0)
		return ("0");
	if (value == -2147483648 && base == 10)
		return ("-2147483648");
	num = value;
	len = ft_intlen(num, base) - 1;
	if (value < 0)
	{
		if (base == 10)
			len++;
		num *= -1;
	}
	ret = (char*)malloc(sizeof(char) * len/*+ 1*/);
	convert(ret, len, num, base);
	if (value < 0 && base == 10)
		ret[0] = '-';
	return (ret);
}
