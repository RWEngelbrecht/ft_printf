/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 13:48:36 by rengelbr          #+#    #+#             */
/*   Updated: 2019/08/29 14:47:02 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int		print_char(va_list ap)
{
	unsigned int	arg;
	int				ret;

	ret = 1;
	arg = va_arg(ap, int);
	ft_putchar(arg);

	return (ret);
}

int		print_string(va_list ap)
{
	const char	*str;
	int			ret;

	str = va_arg(ap, char*);
	ret = ft_strlen(str);
	ft_putstr_fd(str, 1);

	return (ret);
}

int		print_int_var(va_list ap, char * var)
{
	short	sh;
	int		ret;
	int		arg;

	sh = 0;
	ret = 0;
	if (ft_strcmp(var, "h"))
	{
		sh = (short)va_arg(ap, int);
		ret = ft_intlen((int)sh);
		ft_putnbr((int)sh);
	}
	// else if (ft_strcmp(var, "hh"))
	// {

	// }
	else
	{
		arg = va_arg(ap, int);
		ret += ft_intlen((int)arg);
		ft_putnbr((int)arg);
	}

	return (ret);
}

void	print_
