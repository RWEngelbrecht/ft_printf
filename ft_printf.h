/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 13:56:00 by rengelbr          #+#    #+#             */
/*   Updated: 2019/09/02 15:44:46 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include <stdarg.h>
#include <string.h>

int		print_char(va_list ap);
int		print_string(va_list ap);
int		print_int_var(va_list ap, char * var);
int		print_octal_var(va_list ap, char * var);
int		print_hex_mem(va_list ap);
int		print_unsigned_decimal(va_list ap);
int		print_hex(va_list ap);

void	print_memory(const void *addr, size_t size);

#endif
