/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 10:07:54 by rengelbr          #+#    #+#             */
/*   Updated: 2019/05/30 10:07:55 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	d_len;
	size_t	s_len;

	i = ft_strlen(dst);
	j = 0;
	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	if (size < d_len + 1)
		return (s_len + size);
	if (size > d_len + 1)
	{
		while (i < size - 1)
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
	}
	return (d_len + s_len);
}
