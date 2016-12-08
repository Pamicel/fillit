/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamicel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 19:20:00 by pamicel           #+#    #+#             */
/*   Updated: 2016/11/15 14:28:29 by pamicel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_strclr(char *s)
{
	size_t	len;
	void	*ptr;

	ptr = (void*)s;
	len = (s ? ft_strlen(s) : 0);
	if (s)
		ft_bzero(ptr, len);
}
