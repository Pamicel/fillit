/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamicel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:23:24 by pamicel           #+#    #+#             */
/*   Updated: 2016/11/14 16:09:22 by pamicel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *ret;

	ret = dst;
	while (*src && len)
	{
		*dst++ = *src++;
		len--;
	}
	if (!*src)
		ft_bzero(dst, len);
	return (ret);
}
