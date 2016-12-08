/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:56:59 by apissier          #+#    #+#             */
/*   Updated: 2016/12/08 17:27:28 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_putstr(const char *s)
{
	int		i;

	i = 0;
	if (s == NULL)
		return ;
	write(1, s, ft_strlen(s));
}