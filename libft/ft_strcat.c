/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamicel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 22:07:52 by pamicel           #+#    #+#             */
/*   Updated: 2016/11/10 22:10:30 by pamicel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strcat(char *restrict s1, const char *restrict s2)
{
	size_t i;
	size_t lens1;
	size_t lens2;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	i = 0;
	while (i < lens2)
	{
		s1[i + lens1] = s2[i];
		i++;
	}
	s1[lens1 + lens2] = 0;
	return (s1);
}
