/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_code.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 17:48:18 by apissier          #+#    #+#             */
/*   Updated: 2016/12/09 15:44:00 by pamicel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "fillit.h"

char		*ft_code(char *str) // char *codes)
{
	int		i;
	char	j;
	int		k;
	char	*code;

	i = 0;
	j = 0;
	k = 0;
	if (!(code = (char *)malloc(sizeof(char) * 3)))
		return (0);
	while (str[i] != '#')
		i++;
	while (k < 3)
	{
		while (str[++i] == '#')
			code[k++] = 0;
		j = 0;
		while (str[i] && str[i] != '#')
		{
			j++;
			i++;
		}
		code[k++] = j;
	}
	return (code);
}
