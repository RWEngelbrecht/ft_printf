/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 13:53:02 by rengelbr          #+#    #+#             */
/*   Updated: 2019/06/07 10:31:10 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	str = ft_strnew(len);
	if (!str || !s)
		return (NULL);
	i = 0;
	s = s + start;
	if (s)
	{
		while (i < len)
		{
			str[i] = s[i];
			i++;
		}
		str[i] = '\0';
	}
	else
		return (0);
	return (str);
}
