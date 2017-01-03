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


static unsigned short		*ft_code_to_bin(char *str, unsigned short *all_pieces)
{
	char						*all_codes;
	int 						i;
	unsigned short	*piece;

	all_codes = "300304003403404040303020444000030034430004400044440200002";
	i = 0;
	while (ft_strncmp(str, &(all_codes[i * 3]), 3))
		i++;
	if ((piece = (unsigned short*)ft_memalloc(5 * sizeof(unsigned short))))
	 	ft_memcpy(piece, &(all_pieces[i * 4]), 4 * sizeof(unsigned short));
	return (piece);
}

/*
** ints[0]	indice dans str
** ints[1]	charactere a ajouter a code
** ints[2]  indice dans code
*/

unsigned short						*ft_code(char *str, unsigned short *all_pieces)
{
	int ints[3];
	char	*code;

	ft_memset(ints, 0, sizeof(int) * 3);
	if (!(code = (char *)malloc(sizeof(char) * 4)))
		return (0);
	while (str[ints[0]] != '#')
		ints[0]++;
	while (ints[2] < 3)
	{
		while (str[++ints[0]] == '#')
			code[ints[2]++] = 0 + '0';
		ints[1] = 0;
		while (str[ints[0]] && str[ints[0]] != '#')
		{
			ints[1]++;
			ints[0]++;
		}
		code[ints[2]++] = (char)ints[1] + '0';
	}
	return (ft_code_to_bin(code, all_pieces));
}
