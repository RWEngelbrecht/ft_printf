/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 09:09:38 by rengelbr          #+#    #+#             */
/*   Updated: 2019/09/05 08:52:34 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_intlen(int n, int base)
{
	int		cnt;

	cnt = 1;
	if (n == 0)
		return (1);
	else if (n < 0)
	{
		cnt++;
		while (n /= base)
			cnt++;
	}
	else
	{
		while (n /= base)
			cnt++;
	}
	return (cnt);
}
