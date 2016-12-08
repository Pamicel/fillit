/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamicel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:54:35 by pamicel           #+#    #+#             */
/*   Updated: 2016/11/16 14:51:20 by pamicel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_blank(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char		*ft_strtrim(char const *s)
{
	size_t			len;
	unsigned int	start;

	start = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (len == 0)
		return (ft_strnew(1));
	if (!(is_blank(s[start]) || is_blank(s[len - 1])))
		return (ft_strdup(s));
	while (is_blank(s[start]))
		start++;
	if (start == len)
		return (ft_strnew(1));
	len--;
	while (is_blank(s[len]))
		len--;
	return (ft_strsub(s, start, len - start + 1));
}
