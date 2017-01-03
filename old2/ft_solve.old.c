/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamicel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 16:39:41 by pamicel           #+#    #+#             */
/*   Updated: 2016/12/16 17:11:59 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
typedef unsigned short t_tro[6];
typedef unsigned short t_map[16];

// // // // // // // // //
#include <stdio.h>
// // // // // // // // //

// - imprimer indice et shift dans la 5eme ligne
// - faire la fonction mere

// 😎  TESTEY
int				ft_is_out_under(int y, t_tro tetro, int index)
{
	if (tetro[3])
		return ((y - index - 4) < 0);
	else if (tetro[2])
		return ((y - index - 3) < 0);
	else if (tetro[1])
		return ((y - index - 2) < 0);
	return ((y - index - 1) < 0);
}

// 😎  TESTEY
int				ft_is_out_right(int x, t_tro tetro, int shift)
{
	unsigned short	modula;
	int				i;

	i = 0;
	modula = 0b1000000000000000 >> (x - 1);
	while (i < 3)
		if (modula == 1)
		{
			if ((tetro[i++] >> (shift - 1) & 1))
				return (1);
		}
		else
			if ((tetro[i++] >> shift) % modula != 0)
				return (1);
	return (0);
}

// 😎  TESTEY
int				ft_can_print(t_tro tetro, int shift, t_map map, int index)
{
	int 		ret;

	ret = 0;
	ret = ret || (tetro[0] >> shift) & map[index];
	if (tetro[1])
	{
		ret = ret || (tetro[1] >> shift) & map[1 + index];
		if (tetro[2])
		{
			ret = ret || (tetro[2] >> shift) & map[2 + index];
			if (tetro[3])
				ret = ret || (tetro[3] >> shift) & map[3 + index];
		}
	}
	return (!ret);
}

// 😎  TESTEY
int				ft_print_tetro_on_map(t_tro tetro, int shift, t_map map, int index)
{
	if (ft_can_print(tetro, shift, map, index))
	{
		map[0 + index] |= tetro[0] >> shift;
		if (tetro[1])
		{
			map[1 + index] |= tetro[1] >> shift;
			if (tetro[2])
			{
				map[2 + index] |= tetro[2] >> shift;
				if (tetro[3])
					map[3 + index] |= tetro[3] >> shift;
			}
		}
		tetro[4] = (unsigned short) shift;
		tetro[5] = (unsigned short) index;
		return (1);
	}
	return (0);
}

// 😎  TESTEY
void			ft_erase_tetro_from_map(t_tro tetro, int shift, t_map map, int index)
{
	map[0 + index] ^= tetro[0] >> shift;
	if (tetro[1])
	{
		map[1 + index] ^= tetro[1] >> shift;
		if (tetro[2])
		{
			map[2 + index] ^= tetro[2] >> shift;
			if (tetro[3])
				map[3 + index] ^= tetro[3] >> shift;
		}
	}
}

// 😎  TESTEY
int				ft_move_tetro(t_tro tetro, int *shift, int *index, int size)
{
	if (ft_is_out_right(size, tetro, *shift + 1))
	{
		(*index)++;
		*shift = 0;
	}
	else
		(*shift)++;
	if (ft_is_out_under(size, tetro, *index))
		return (0);
	return (1);
}

/*
 ** 		arguments
 ** ind[4] : taille du cote du carre (aussi appelé y ou x)
 ** ind[3] : index de ligne (a partir de laquelle on fait le placement) dans map
 ** ind[2] : shift du tetromino
 ** ind[1] : numero du tetromino actuel (indice dans la liste des tetros)
 ** ind[0] : nombre de tetrominos (longueur de la liste des tetros)
 */
/*
 ** ft_sqrt from Wikipedia
 */

// 😎  TESTEY
static int ft_sqrt(int num)
{
	int res = 0;
	int bit = 1 << 30;

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
	return res;
}

  ////////////////////////////////////////////////////////////////////////////////
 ////////  DEBUG   //////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

static char *bigger_mother_fucker(char *str, int n_digits)
{
	char *new;
	int n = ft_strlen(str);
	if (n < n_digits)
	{
		new = ft_strnew(n_digits);
		ft_strcpy(&(new[n_digits - n]), str);
		for (int i = 0; i < n_digits - n; i++)
			new[i] = '0';
		return (new);
	}
	return (str);
}

static void print(unsigned short *us, int size)
{
	for(int i = 0; i < size; i++)
		printf("%s\n", bigger_mother_fucker(ft_itoa_base(us[i], 2), 16));
}

static void print_at(t_tro tetro, int shift, t_map map, int index)
{
	ft_print_tetro_on_map(tetro, shift, map, index);
	print(map, 16);
}

  ////////////////////////////////////////////////////////////////////////////////
 ////////  DEBUG   //////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////


// 😎  TESTEY
static void 				ft_set_ind_next_tetro(int rec_ind[5], int ind[5])
{
	rec_ind[4] = ind[4];
	rec_ind[3] = 0;
	rec_ind[2] = 0;
	rec_ind[1] = ind[1] + 1;
	rec_ind[0] = ind[0];
}

void						ft_print_on_map(t_tro tetro, char **map, char c)
{
	int i;
	int j;

	i = -1;
	while (++i < 4)
	{
		j = 0;
		if (tetro[i] == 0b1000000000000000)
			map[tetro[5] + i][tetro[4]] = c;
		else if (tetro[i] == 0b0100000000000000)
			map[tetro[5] + i][tetro[4] + 1] = c;
		else if (tetro[i] == 0b0010000000000000)
			map[tetro[5] + i][tetro[4] + 2] = c;
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
}

void						ft_print_result(t_tro *tetros, int n_tetros, int size)
{
	char **map;
	int i;
	int j;

	map = (char**)ft_memalloc(sizeof(char*) * size);
	i = 0;
	while (i < size)
		map[i++] = ft_strnew(size);
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			map[i][j] = '.';
	}
	i = -1;
	while (++i < n_tetros)
		ft_print_on_map(tetros[i], map, 'A' + i);
	i = -1;
	while (++i < size)
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
	}
}

// EN COURS DE TEST
static int					ft_solve(t_tro *tetros, t_map map, int ind[5])
{
	int rec_ind[5];

	// // //
	printf("index = %d\n", ind[3]);
	printf("shift = %d\n", ind[2]);
	printf("n_tetro = %d\n", ind[1]);
	if (ind[1] == ind[0])
		return (1);
	printf("tetro = \n");
	print(tetros[ind[1]], 4);
	printf("map = \n");
	print(map, 16);
	// // //
	while (1)
	{
		while (!ft_print_tetro_on_map(tetros[ind[1]], ind[2], map, ind[3]))
		{
			if (!ft_move_tetro(tetros[ind[1]], &(ind[2]), &(ind[3]), ind[4]))
			{
				printf("TETRO AU BOUT\n");
				return (0);
			}
		}
		ft_set_ind_next_tetro(rec_ind, ind);
		// // // // // //
		printf("\e[32m%d, %d, %d, %d, %d\n\e[0m", ind[0], ind[1], ind[2], ind[3], ind[4]);
		// // // // // //
		if (ft_solve(tetros, map, rec_ind))
		{
			printf("done\n");
			return (1);
		}
		else
		{
			printf("ERASE AND MOVE ROUTINE\n");
			ft_erase_tetro_from_map(tetros[ind[1]], ind[2], map, ind[3]);
			if (!ft_move_tetro(tetros[ind[1]], &(ind[2]), &(ind[3]), ind[4]))
				return (0);
		}
	}
	return (1);
}

// PAS TESTEY
int									ft_fillit(t_tro *tetros, int n_tetros)
{
	t_map map;
	int ind[5];

	ft_memset(map, 0, sizeof(unsigned short) * 16);
	ind[4] = ft_sqrt(n_tetros);
	ind[4] += n_tetros > (ind[4] * ind[4]);
	ind[4] *= 2;
	printf("%d\n", ind[4]);
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

int main()
{
	int ind[5];

	t_tro tetro_0 = {0b1100000000000000, 0b1000000000000000, 0b1000000000000000, 0b0000000000000000, 0b0000000000000000, 0b0000000000000000};
	t_tro tetro_1 = {0b1100000000000000, 0b0100000000000000, 0b0100000000000000, 0b0000000000000000, 0b0000000000000000, 0b0000000000000000};
	t_tro tetro_2 = {0b1100000000000000, 0b0100000000000000, 0b0100000000000000, 0b0000000000000000, 0b0000000000000000, 0b0000000000000000};
	unsigned short map[] = {0b0000000000000000, 0b0000000000000000, 0b0000000000000000, 0b0000000000000000,\
		0b0000000000000000, 0b0000000000000000, 0b0000000000000000, 0b0000000000000000,\
			0b0000000000000000, 0b0000000000000000, 0b0000000000000000, 0b0000000000000000,\
			0b0000000000000000, 0b0000000000000000, 0b0000000000000000, 0b0000000000000000};
	t_tro tetros[3];
	ft_memcpy(tetros[0], tetro_0, sizeof(t_tro));
	ft_memcpy(tetros[1], tetro_1, sizeof(t_tro));
	ft_memcpy(tetros[2], tetro_2, sizeof(t_tro));
	// int shift = 0;
	// int index = 0;
	// int size = 5;

	int n = ft_fillit(tetros, 3);
	ft_print_result(tetros, 3, n);

	// ind[4] = 4;
	// ind[3] = 0;
	// ind[2] = 0;
	// ind[1] = 0;
	// ind[0] = 3;
	//
	// printf("\e[31m");
	// print(map, 16);
	// printf("\e[0m");
	// ft_solve(tetros, map, ind);
	// printf("\e[31m");
	// print(map, 16);
	// printf("\e[0m");
	//
	// for (int i = 0; i < 3; i++)
	// {
	// 	printf("tetros[%d]\n", i);
	// 	printf("x = %d, y = %d\n\n", (int)(tetros[i][4]), (int)(tetros[i][5]));
	// }

	// do {
	// 	printf("index = %d\n", index);
	// 	printf("shift = %d\n", shift);
	// 	printf("print_at(tetro, %d, map, %d);\n", shift, index);
	// 	print_at(tetro, shift, map, index);
	//   ft_erase_tetro_from_map(tetro, shift, map, index);
	// } while (ft_move_tetro(tetro, &shift, &index, size));
}
