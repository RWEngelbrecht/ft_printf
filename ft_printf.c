/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 10:48:24 by rengelbr          #+#    #+#             */
/*   Updated: 2019/09/05 14:03:37 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

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
	int				ret;
//	void			*ptr;
//	const char		*str;
	char			*trav;
	short			sh;

	va_start(ap, format);
	trav = (char*)format;
	arg = 0;
	ret = 0;
	sh = 0;
	while (*trav != '\0')
	{
		while (*trav != '%' && *trav != '\0')
		{
			ft_putchar(*trav);
			trav++;
			ret++;
		}
		if (*trav == '%')
		{
			trav++;
			//Fetch + execute conversions
	/*
	c:	The int argument is converted to an unsigned char, and the
		resulting character is written.
		If the l (ell) modifier is used, the wint_t argument shall be
		converted to a wchar_t, and the (potentially multi-byte) sequence
		representing the single wide character is written, including any
		shift sequences.  If a shift sequence is used, the shift state is
		also restored to the original state after the character.
	*/
			if (*trav == 'c')
				ret += print_char(ap);
	/*
	s:	The char * argument is expected to be a pointer to an array of
		character type (pointer to a string).  Characters from the array
		are written up to (but not including) a terminating NUL charac-
		ter; if a precision is specified, no more than the number speci-
		fied are written.  If a precision is given, no null character
		need be present; if the precision is not specified, or is greater
		than the size of the array, the array must contain a terminating
		NUL character.
	*/
			else if (*trav == 's')
				ret += print_string(ap);
	/*
	p	The void * pointer argument is printed in hexadecimal (as if by `%#x' 		or `%#lx').
	*/
			else if (*trav == 'p')
				ret += print_hex_mem(ap);
	/*
	diouxX	The int (or appropriate variant) argument is converted to signed
			decimal (d and i), unsigned octal (o), unsigned decimal (u), or
			unsigned hexadecimal (x and X) notation.  The letters ``abcdef''
			are used for x conversions; the letters ``ABCDEF'' are used for X
			conversions.The precision, if any, gives the minimum number of
			digits that must appear; if the converted value requires fewer
			digits, it is padded on the left with zeros.
	*/
			else if (*trav == 'd' || *trav == 'i')
				ret += print_int_var(ap, "");
			else if (*trav == 'o')
				ret += print_octal_var(ap, "");
			else if (*trav == 'u')
				ret += print_unsigned_var(ap, "");
			else if (*trav == 'x')
				ret += print_hex_small(ap);
			else if (*trav == 'X')
				ret += print_hex_large(ap);
			else if (*trav == 'h')
			{
				trav++;
				if (*trav == 'd' || *trav == 'i')
					ret += print_int_var(ap, "h");
				else if (*trav == 'o')
					ret += print_octal_var(ap, "h");
				else if (*trav == 'u')
					ret += print_unsigned_var(ap, "h");
			}
			trav++;
		}
	}
	va_end(ap);

/*
ft_printf must return the number of chars printed
*/

	return (ret);
}

int main()
{
	char *str = "print this";
	char c1 = 'A';
//	void *ptr = &c1;
	unsigned char c2 = 'u';
	char *str1 = "ffffffff";
	int nbr;
	unsigned short sh = 32767;
	//void *ptr;

//	ft_putstr(str);
	nbr = ft_printf("%c %c, also %s and %s\n", c1, c2, str, str1);
	ft_printf("ft_mem address == %p\n", (void*)&c1);
//	ptr = &nbr;
	ft_printf("ft_d == %d\n", nbr);
	ft_printf("ft_i == %i\n", nbr);
	ft_printf("ft_o == %o\n", c1);
	ft_printf("ft_u == %u\n", c1);
	ft_printf("ft_x == %x\n", 545434562);
	ft_printf("ft_X == %X\n", 545434562);
	ft_printf("ft_hu == %hu\n", sh);
	printf("hu: %hu\n", sh);
	printf("u: %u\n", c1);

//	printf("ft_itoa_base == %s\n", wtf);
//	printf("mem address == %p\n", (void*)&c1);

	return (0);
}
