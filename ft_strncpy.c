/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 19:34:25 by apissier          #+#    #+#             */
/*   Updated: 2016/12/11 13:57:58 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while ((i < n) && src[i])
	{
		if (dest[i] == '\0')
			return (&dest[i]);
		dest[i] = src[i];
		i++;
	}
	while (i < n)
		dest[i++] = '\0';
	return (dest);
}
