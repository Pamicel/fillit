/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_result.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamicel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 15:58:14 by pamicel           #+#    #+#             */
/*   Updated: 2017/01/10 15:59:33 by pamicel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_print_line(t_tro tetro, char **map, int i, char c)
{
	int			j;

	j = 0;
	if (tetro[i] == 0b1000000000000000)
		map[tetro[5] + i][tetro[4]] = c;
	else if (tetro[i] == 0b0100000000000000)
		map[tetro[5] + i][tetro[4] + 1] = c;
	else if (tetro[i] == 0b0010000000000000)
		map[tetro[5] + i][tetro[4] + 2] = c;
	else if (tetro[i] == 0b0110000000000000)
		while (j < 2)
			map[tetro[5] + i][tetro[4] + 1 + j++] = c;
	else if (tetro[i] == 0b1100000000000000)
		while (j < 2)
			map[tetro[5] + i][tetro[4] + j++] = c;
	else if (tetro[i] == 0b1110000000000000)
		while (j < 3)
			map[tetro[5] + i][tetro[4] + j++] = c;
	else if (tetro[i] == 0b1111000000000000)
		while (j < 4)
			map[tetro[5] + i][tetro[4] + j++] = c;
}

static void		ft_print_on_map(t_tro tetro, char **map, char c)
{
	int			i;

	i = -1;
	while (++i < 4)
		ft_print_line(tetro, map, i, c);
}
#include <stdio.h>

void			ft_print_result(t_tro tetros[26], int n_tetros, int size)
{
	printf("size = %d\n", size);
	char		**map;
	int			i;
	int			j;

	map = (char**)ft_memalloc(sizeof(char*) * size);
	i = size;
	while (--i >= 0)
		map[i] = ft_strnew(size);
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			map[i][j] = '.';
	}
	i = n_tetros;
	while (--i >= 0)
		ft_print_on_map(tetros[i], map, 'A' + i);
	while (++i < size)
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
	}
}
