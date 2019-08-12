/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 10:48:24 by rengelbr          #+#    #+#             */
/*   Updated: 2019/08/11 09:23:29 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

/*
//stdarh.h Declares va_list type
		Function must declare object type va_list
//defines macros:
void va_start(va_list ap, last); //last: last param of which funct knows type
//must be called first, inits ap, can be passed to va_arg
//	for each arg that needs to be processed
//	each call must accompanied by va_end
type va_arg(va_list ap, type); //ap: va_list inited by va_start
//Processes args?				//type: type name
//modifies ap so next call returns next arg
void va_copy(va_list dest, va_list src);

void va_end(va_list ap);
//signals there are no more args, invalidates ap
*/

int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (((unsigned char)*s1 - (unsigned char)*s2) < 0)
		return (-1);
	if (((unsigned char)*s1 - (unsigned char)*s2) > 0)
		return (1);
	return (0);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if ((char)c == '\0')
		return ((char*)(s + i));
	return (NULL);
}

void	ft_putstr(char const *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
}

/*
Produces output according to format param.
The format str specifies how subsequent args, or args accessed via cariable-length arsument faciliteis of stdarg(3), are converted for output.
The format str can consist of 0 or more directives: Can be non-% chars, which is displayed unchanged on stdout.
The format str can be 1 or multiple conversion specifications, each results in using 0 or more subsequent args. These are introduced with '%' preceding it.
It writes its output to stdout.

*/

#include <stdio.h>
int		ft_printf(const char *format, ...)
{
	va_list ap;
	char *str;
	char *con;

	va_start(ap, format);
	con = ft_strchr(format, '%');
	if (con == NULL)
		ft_putstr(format);
	else if ()
	{
		/*
		NEED FUNCTION TO FIND %s, %c, %p
		*/
			str = va_arg(ap, char*);
		while (*str)
		{
			write(1, str, 1);
			str++;
		}
		free(str);
		ft_printf(format + 2);
	}
	else if (*format != '%')
	{
		while (*format)
		{
			write(1, format, 1);
			format++;
		}
	}
	va_end(ap);
	return (0);
}

int main()
{
	char *str = "now print this\n";
	char *str1 = "now print this\n";

	ft_printf("%s %s", str, str1);
	ft_printf("\n");
	return (0);
}
