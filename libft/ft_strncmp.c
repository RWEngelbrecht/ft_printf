/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 10:08:09 by rengelbr          #+#    #+#             */
/*   Updated: 2019/06/06 18:41:28 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0 && *s1 && s2 && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}
	if (n)
	{
		if ((unsigned char)*s1 - (unsigned char)*s2 < 0)
			return (-1);
		if ((unsigned char)*s1 - (unsigned char)*s2 > 0)
			return (1);
	}
	return (0);
}
