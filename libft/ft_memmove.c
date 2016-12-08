/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamicel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 10:56:13 by pamicel           #+#    #+#             */
/*   Updated: 2016/11/12 19:57:00 by pamicel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void *ret;

	ret = dst;
	if (dst < src)
		while (len-- > 0)
			*(char*)dst++ = *(char*)src++;
	else
		while (len-- > 0)
			((char*)dst)[len] = ((char*)src)[len];
	return (ret);
}
