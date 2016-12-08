/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamicel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 11:19:31 by pamicel           #+#    #+#             */
/*   Updated: 2016/11/11 16:11:02 by pamicel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src, int c,\
					size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (((char*)src)[i] == (char)c)
		{
			((char*)dst)[i] = ((char*)src)[i];
			return (&dst[i + 1]);
		}
		((char*)dst)[i] = ((char*)src)[i];
		i++;
	}
	return (NULL);
}
