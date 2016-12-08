/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamicel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:41:17 by pamicel           #+#    #+#             */
/*   Updated: 2016/11/15 20:48:53 by pamicel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *str;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (NULL);
	if (!len)
		return ("");
	str = ft_strnew(len);
	if (str)
		ft_strncpy(str, s + start, len);
	return (str);
}
