/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 09:53:14 by rengelbr          #+#    #+#             */
/*   Updated: 2019/06/10 13:04:11 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*trimd;
	int		i;
	int		j;

	i = 0;
	if (!s)
		return (NULL);
	j = ft_strlen(s) - 1;
	while (s[i] == ' ' || (s[i] >= '\t' && s[i] <= '\r'))
	{
		i++;
		if (s[i] == '\0')
			return (ft_strdup(""));
	}
	while (s[j] == ' ' || (s[j] >= '\t' && s[j] <= '\r'))
		j--;
	trimd = ft_strsub(s, i, (j - i) + 1);
	return (trimd);
}
