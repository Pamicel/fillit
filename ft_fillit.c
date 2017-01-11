/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamicel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 16:39:41 by pamicel           #+#    #+#             */
/*   Updated: 2016/12/16 17:11:59 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static unsigned short	*ft_generate_tetros(void)
{
	unsigned short		*all_pieces;

	all_pieces = (unsigned short*)ft_memalloc(sizeof(unsigned short) * 19 * 4);
	if (!all_pieces)
		return (NULL);
	ft_memcpy(all_pieces,\
		(unsigned short[19 * 4]){16384, 57344, 0, 0, 16384, 49152, 16384, 0, \
		57344, 16384, 0, 0, 32768, 49152, 32768, 0, 32768, 49152, 16384, 0, \
		49152, 24576, 0, 0, 16384, 49152, 32768, 0, 24576, 49152, 0, 0, \
		32768, 32768, 32768, 32768, 61440, 0, 0, 0, 49152, 49152, 0, 0, \
		49152, 32768, 32768, 0, 16384, 16384, 49152, 0, 57344, 8192, 0, 0, \
		32768, 57344, 0, 0, 49152, 16384, 16384, 0, 32768, 32768, 49152, 0,\
		8192, 57344, 0, 0, 57344, 32768, 0, 0},\
		sizeof(unsigned short) * 19 * 4);
	return (all_pieces);
}

/*
** Thank you Wikipedia for this bioutifoul ft_sqrt()
*/

static int				ft_sqrt(int num)
{
	int					res;
	int					bit;

	res = 0;
	bit = 1 << 30;
	while (bit > num)
		bit >>= 2;
	while (bit != 0)
	{
		if (num >= res + bit)
		{
			num -= res + bit;
			res = (res >> 1) + bit;
		}
		else
			res >>= 1;
		bit >>= 2;
	}
	return (res);
}

/*
** 		arguments to ft_solve
** ind[4] : square size (aka y or x in some functions)
** ind[3] : line index (from which the placement is done) in map
** ind[2] : shift value for the tetromino
** ind[1] : current tetromino (index in the list of tetros)
** ind[0] : number of tetrominos (length of the list of tetros)
*/

int						ft_fillit(t_tro tetros[26], int n_tetros)
{
	t_map				map;
	int					ind[5];

	ft_memset(map, 0, sizeof(unsigned short) * 16);
	ind[4] = ft_sqrt(n_tetros);
	ind[4] *= 2;
	ind[3] = 0;
	ind[2] = 0;
	ind[1] = 0;
	ind[0] = n_tetros;
	while (!ft_solve(tetros, map, ind))
	{
		ind[4]++;
		ind[3] = 0;
		ind[2] = 0;
		ind[1] = 0;
	}
	return (ind[4]);
}

int						main(int ac, char **av)
{
	unsigned short		*all_tetros;
	t_tro				tetros[26];
	int					n;
	int					size;

	// // // //
	FD = open("chemin.txt", O_RDWR);
	// // // //
	n = 0;
	if (ac > 1)
	{
		if ((all_tetros = ft_generate_tetros()))
		{
			if (!ft_read_file(av[1], all_tetros, &n, tetros))
				ft_putstr("Error : grid is invalid\n");
			free(all_tetros);
		}
		if (!n)
			return (0);
		size = ft_fillit(tetros, n);
		while (ft_is_out_under(size, tetros[0], 0))
			size++;
		ft_print_result(tetros, n, size);
	}
	else
		ft_putstr("usage : ./fillit <text_file>\n");
	return (0);
}
