/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamicel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 20:09:52 by pamicel           #+#    #+#             */
/*   Updated: 2016/11/13 11:37:25 by pamicel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		n;
	size_t	len;

	len = ft_strlen(dst);
	len = (size <= len ? size + ft_strlen(src) : len + ft_strlen(src));
	n = (int)size;
	while (*dst)
	{
		dst++;
		n--;
	}
	while (*src && n > 1)
	{
		*dst++ = *src++;
		n--;
	}
	if (!(n <= 0))
		*dst = 0;
	return (len);
}
