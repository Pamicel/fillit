/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamicel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 14:42:14 by pamicel           #+#    #+#             */
/*   Updated: 2016/11/11 16:06:56 by pamicel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	if (!(*s1 && *s2) || n == 1 || *s1 != *s2)
		return ((unsigned char)*s1 - (unsigned char)*s2);
	else
		return (ft_strncmp(s1 + 1, s2 + 1, n - 1));
}
