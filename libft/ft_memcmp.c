/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamicel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:36:13 by pamicel           #+#    #+#             */
/*   Updated: 2016/11/15 15:14:47 by pamicel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*uc1;
	unsigned char	*uc2;
	int				res;
	size_t			i;

	i = 0;
	uc1 = (unsigned char*)s1;
	uc2 = (unsigned char*)s2;
	if (n == 0)
		return (0);
	if (s1 != s2)
		while (uc1[i] == uc2[i] && (i + 1) < n)
			i++;
	res = uc1[i] - uc2[i];
	return (res);
}
