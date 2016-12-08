/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamicel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 11:36:39 by pamicel           #+#    #+#             */
/*   Updated: 2016/11/15 15:05:12 by pamicel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int i)
{
	char	*str;
	int		n_digits;

	n_digits = ft_log10(i) + 1 + (i < 0);
	str = ft_strnew(n_digits);
	if (str == NULL)
		return (NULL);
	str[0] = (i != 0 ? '-' : '0');
	if (i > 0)
		i = -i;
	while (i)
	{
		str[n_digits-- - 1] = -(i % 10) + '0';
		i /= 10;
	}
	return (str);
}
