/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 10:48:24 by rengelbr          #+#    #+#             */
/*   Updated: 2019/08/19 20:34:01 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

/*
//stdarg.h Declares va_list type
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
	va_list			ap;
	unsigned int	arg;
//	unsigned int	*ptr;
	const char			*str;
	const char		*trav;

	va_start(ap, format);
	trav = format;
	while (*trav)
	{
		while (*trav != '%')
		{
			ft_putchar(*trav);
			trav++;
		}
		if (*trav == '%')
			trav++;
		//Fetch + execute conversions

// c	The int argument is converted to an unsigned char, and the
// resulting character is written.
// If the l (ell) modifier is used, the wint_t argument shall be
// converted to a wchar_t, and the (potentially multi-byte) sequence
// representing the single wide character is written, including any
// shift sequences.  If a shift sequence is used, the shift state is
// also restored to the original state after the character.

		if (*trav == 'c')
		{
			arg = va_arg(ap, int);
			ft_putchar(arg);
		}

//s		The char * argument is expected to be a pointer to an array of
//character type (pointer to a string).  Characters from the array
//are written up to (but not including) a terminating NUL charac-
//ter; if a precision is specified, no more than the number speci-
//fied are written.  If a precision is given, no null character
//need be present; if the precision is not specified, or is greater
//than the size of the array, the array must contain a terminating
//NUL character.

		else if (*trav == 's')
		{
			str = va_arg(ap, char*);
			ft_putstr_fd(str, 1);
		}
//p		The void * pointer argument is printed in hexadecimal (as if by `%#x' or `%#lx').
		// else if (*trav == 'p')
		// {
		// 	ptr = va_arg(ap, void*);
		// 	ft_print
		// }
		else if (*trav == 'd')
		{
			arg = va_arg(ap, int);
			ft_putnbr(arg);
		}
		trav++;
	}
	// else if (*format != '%')
	// {
	// 	while (*format)
	// 	{
	// 		write(1, format, 1);
	// 		format++;
	// 	}
	va_end(ap);
	return (0);
}

int main()
{
	char *str = "print this";
	char *str1 = "now print this";

//	ft_putstr(str);
	ft_printf("%s and %s\n", str, str1);
//	ft_printf("\n");
	return (0);
}
