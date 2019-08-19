/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 10:07:36 by rengelbr          #+#    #+#             */
/*   Updated: 2019/05/30 10:07:37 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *tmp;

	tmp = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (tmp == NULL)
		return (NULL);
	else
		return (ft_strcpy(tmp, s1));
}
