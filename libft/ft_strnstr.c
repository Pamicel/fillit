/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamicel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:35:03 by pamicel           #+#    #+#             */
/*   Updated: 2016/11/15 22:15:25 by pamicel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		i;
	size_t	little_len;

	if (!*little)
		return ((char*)big);
	little_len = ft_strlen(little);
	while (len >= little_len && (i = ft_strncmp(big, little, little_len)))
	{
		if (!*big)
			break ;
		big++;
		len--;
	}
	return ((*big && len >= little_len) ? (char*)big : 0);
}
