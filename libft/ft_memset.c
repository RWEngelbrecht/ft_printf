/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 11:10:26 by rengelbr          #+#    #+#             */
/*   Updated: 2019/06/03 13:32:17 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*temp;

	temp = (unsigned char*)b;
	i = 0;
	while (i < n)
		temp[i++] = (unsigned char)c;
	return (b);
}
