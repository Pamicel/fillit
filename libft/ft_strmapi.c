/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamicel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:26:46 by pamicel           #+#    #+#             */
/*   Updated: 2016/11/15 14:30:17 by pamicel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;

	i = -1;
	if (!s)
		return (NULL);
	str = ft_strnew(ft_strlen(s));
	if (str)
	{
		while (s[++i])
			str[i] = f(i, s[i]);
		str[i] = 0;
	}
	return (str);
}
