/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamicel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:00:51 by pamicel           #+#    #+#             */
/*   Updated: 2016/11/13 14:38:33 by pamicel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	char	*str;
	void	*ptr;

	ptr = malloc(size);
	if (ptr)
	{
		str = (char*)ptr;
		while (size-- && str)
			*(str++) = 0;
	}
	return (ptr);
}
