/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 11:52:26 by rengelbr          #+#    #+#             */
/*   Updated: 2019/09/05 14:00:14 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void    print_byte(unsigned char c)
{
    char c_1;
    char c_16;

    c_16 = '0';
    while (c >= 16)
    {
        if (c_16 == '9')
            c_16 = 'a';
        else
            c_16++;
        c -= 16;
    }
    c_1 = '0';
    while (c > 0)
    {
        if (c_1 == '9')
            c_1 = 'a';
        else
            c_1++;
        c--;
    }
	write(1, &c_16, 1);
	write(1, &c_1, 1);
}

void    print_line_hex(unsigned char *s, int len)
{
    int i;

    i = len - 1;
    while (i >= 0)
    {
        print_byte(s[i]);
        i--;
    }
}

void	print_memory(const void *addr, size_t size)
{
    unsigned char *arr;
    int i;

    arr = (unsigned char *)addr;
    i = 0;
    while (i + 6 < (int)size)
    {
        print_line_hex(&(arr[i]), 6);
        write(1, "\n", 1);
        i += 6;
    }
    print_line_hex(&(arr[i]), (int)size - i);
}
