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

char	*ft_realloc(char *ptr, size_t size)
{
	char	*tmp;
	int 	i;

	tmp = ptr;
	free(ptr);
	i = 0;
	if (!(ptr = ft_strnew(size)))
		return (NULL);
	while(tmp[i])
	{
		ptr[i] = tmp[i];
		i++;
	}
	free(tmp);
	return (ptr);
}
