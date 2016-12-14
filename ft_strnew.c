/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:24:23 by apissier          #+#    #+#             */
/*   Updated: 2016/12/11 13:57:46 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*ft_strnew(size_t size)
{
	char	*new;
	size_t	i;

	i = 0;
	new = malloc(size + 1);
	if (new == NULL)
		return (NULL);
	while (i < size)
	{
		new[i] = 0;
		i++;
	}
	new[i] = '\0';
	return (new);
}
