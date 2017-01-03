/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 15:56:30 by apissier          #+#    #+#             */
/*   Updated: 2016/12/14 18:10:57 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
// // //
#include <stdio.h>
// // //

#define BUFF_SIZE 21

static unsigned short **ft_create_map(void)
{
	unsigned short **map;

	map =	ft_memalloc(sizeof(unsigned short) * 16);
	return (map);
}

static unsigned short *ft_create_pieces(void)
{
	unsigned short	*all_pieces;

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
** ft_read_file :
** ints[0] fd
** ints[1] nbr of codes ( <=> tetrominos )
*/

unsigned short		**ft_read_file(char *str, unsigned short *all_pieces, int *n)
{
	int							ints[2];
	ssize_t						ret;
	char						buf[BUFF_SIZE + 1];
	unsigned short		**tetros;

	tetros = ft_memalloc(sizeof(unsigned short) * 26);
	ints[1] = 0;
	if ((ints[0] = open(str, O_RDONLY)) == -1)
		ft_putstr("open() error\n");
	while (1)
	{
		if ((ret = read(ints[0], buf, BUFF_SIZE)) <= 0)
			break ;
		buf[BUFF_SIZE - 1] = '\0';
		if (ft_isvalid(buf))
			tetros[(*n)++] = ft_code(buf, all_pieces);
		else
			return (NULL);
	}
	if (close(ints[0]) == -1)
		ft_putstr("close() error\n");
	return (tetros);
}

int main(int ac, char **av)
{
	unsigned short 	*all_pieces;
	unsigned short 	**tetros;
	unsigned short	**map;
	int				n;
	int				size;

	tetros = NULL;
	n = 0;
	if (ac > 1)
	{
		if ((all_pieces = ft_create_pieces()))
		{
			tetros = ft_read_file(av[1], all_pieces, &n);
			free(all_pieces);
		}
		// Votre code ici
		if (!tetros)
		{
			ft_putstr("La grille est invalide\n");
			return (0);
		}
		else
			map = ft_create_map();
		size = ft_fillit((t_tro*)tetros, n);
		ft_print_result((t_tro*)tetros, n, size);
		if (tetros)
		{
			while (n--)
				free(tetros[n]);
			free(tetros);
		}
	}
	else
		ft_putstr("\e[42mUSAGE\e[0m\n");
	return (0);
}
