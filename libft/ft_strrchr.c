/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamicel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:24:36 by pamicel           #+#    #+#             */
/*   Updated: 2016/11/11 13:34:35 by pamicel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	size_t	len;

	len = ft_strlen(s);
	i = (int)len;
	if (!c)
		return ((char*)s + len);
	while (s[i] != (char)c && i >= 0)
		i--;
	return (i != -1 ? (char*)s + i : NULL);
}
