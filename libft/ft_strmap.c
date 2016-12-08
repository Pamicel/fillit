/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamicel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:11:13 by pamicel           #+#    #+#             */
/*   Updated: 2016/11/15 14:29:42 by pamicel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
			str[i] = f(s[i]);
		str[i] = 0;
	}
	return (str);
}
