/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 13:56:00 by rengelbr          #+#    #+#             */
/*   Updated: 2019/08/30 08:46:36 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include <stdarg.h>

int		print_char(va_list ap);
int		print_string(va_list ap);
int		print_int_var(va_list ap, char * var);
int		print_octal_var(va_list ap, char * var);

#endif
