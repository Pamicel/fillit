/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 10:48:25 by apissier          #+#    #+#             */
/*   Updated: 2016/12/09 15:19:35 by pamicel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
// // //
#include <stdio.h>
// // //

char	*ft_realloc(char *str, size_t size)
{
	char	*new;

	if (str && ft_strlen(str) < size)
	{
		if (!(new = ft_strnew(size)))
			break ;
		ft_strncpy(new, str, ft_strlen(str));
		free(str);
		str = new;
	}
	return (str);
}
