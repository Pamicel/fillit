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
// - gerer le backtracking et l'initialisation du placement à zero

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
	unsigned short		modula;
	int								i;

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
	int 							ret;

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

// PAS TESTEY
int				ft_move_tetro(t_tro tetro, int *shift, int *index)
{
	if (ft_is_out_right(tetro, *shift, *index))
	{
		*index++;
		*shift = 0;
	}
	else
		*shift++;
	if (ft_is_out_under(tetro, *shift, *index))
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

// PAS TESTEY
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

// PAS TESTEY
int									ft_fillit(t_tro *tetros, int n_tetros)
{
	t_map map;
	int ind[5];

	ind[4] = ft_sqrt(n_tetros);
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

// PAS TESTEY
static void 				ft_set_ind_next_tetro(int rec_ind[5], int ind[5])
{
	rec_ind[4] = ind[4];
	rec_ind[3] = 0;
	rec_ind[2] = 0;
	rec_ind[1] = ind[1] + 1;
	rec_ind[0] = ind[0];
}

// PAS TESTEY
static int					ft_solve(t_tro *tetros, t_map map, int ind[5])
{
	int rec_ind[5];

	if (ind[1] == ind[0])
		return (1);
	while (1)
	{
		while (!ft_can_print(tetros[ind[1]], ind[2], ind[3]))
		{
			if (!ft_move_tetro(tetros[ind[1]], &(ind[2]), &(ind[3])))
				return (0);
		}
		ft_print_tetro_on_map(tetros[ind[1]], ind[2], map, ind[3]);
		ft_set_ind_next_tetro(rec_ind, ind);
		if (ft_solve(tetros, map, rec_ind))
			return (1);
		else
		{
			ft_erase_tetro_from_map(tetros[ind[1]], ind[2], map, ind[3]);
			if (!ft_move_tetro(tetros[ind[1]], &(ind[2]), &(ind[3])))
					return (0);
		}
	}
	return (1);
}

// VERSION PLUS CLAIRE
// static int					ft_solve(t_tro *tetros, t_map map, int ind[5])
// {
// 	int rec_ind[5];
//
// 	if (num_of_tetro == n_tetros)
// 	while (1)
// 	{
// 		while (!ft_can_print(tetro, shift, index))
// 		{
// 			if (!ft_move_tetro(tetro, &shift, &index))
// 				return (0);
// 		}
// 		ft_print_tetro_on_map(tetro, shift, map, index);
//
// 		ft_memcpy(rec_ind, ind, sizeof(int) * 5);
// 		rec_ind[3] = 0;
// 		rec_ind[2] = 0;
// 		rec_ind[1] = ind[1] + 1;
//
// 		if (ft_solve(tetros, map, rec_ind))
// 			return (1);
// 		else
// 		{
// 			ft_erase_tetro_from_map(tetro, shift, map, index);
// 			if (!ft_move_tetro(tetro, &shift, &index))
// 			{
// 				if (ind[1] == 0)
// 				{
// 					ind[2] = 0;
// 					ind[3] = 0;
// 					ind[4]++;
// 					return (ft_solve(tetros, map, ind));
// 				}
// 				return (0);
// 		}
// 	}
// 	return (1);
// }

/*
** 		arguments de ft_solve
** ind[4] : taille du cote du carre (aussi appelé y ou x)
** ind[3] : index de ligne (a partir de laquelle on fait le placement) dans map
** ind[2] : shift du tetromino
** ind[1] : numero du tetromino actuel (indice dans la liste des tetros)
** ind[0] : nombre de tetrominos (longueur de la liste des tetros)
*/

// // 🍀 ! PAS TESTEY
//
// static int					ft_solve(unsigned short **tetros, t_map map, int ind[5])
// {
// 	int temp;
//
// 	if (ind[1] == ind[0])
// 		return (1);
// 	/*ft_shift(tetros[ind[1]], ind[2]);*/
// 	//si quitte le carré par le bas
// 	if (ft_is_out_under(ind[4], tetros[ind[1]], ind[3]))
// 		return (0);
// 	//si quitte le carre par la droite
// 	if (ft_is_out_right(ind[4], tetros[ind[1]], ind[2]))
// 	{
// 		temp = ind[2];
// 		ind[2] = 0;
// 		ind[3]++;
// 		//essaye plus bas avec retour du tetro à zero
// 		if (ft_solve(tetros, map, ind))
// 			return (1);
// 		ind[3]--;
// 		ind[2] = temp;
// 	}
// 	//si le tetro peut se placer
// 	if (ft_can_print(tetros[ind[1]], ind[2], map, ind[3]))
// 	{
// 		ind[1]++;
// 		//essaye tetro suivant
// 		if (!ft_solve(tetros, map, ind))
// 			return (0);
// 		ind[1]--;
// 	}
// 	//sinon enleve le tetro
// 	else
// 	{
// 		ind[2]++;
// 		if (!ft_solve(tetros, map, ind))
// 		{
// 			/*ft_erase_tetro_from_map(tetros[ind[1]], ind[2], map, ind[3]);*/
// 			return (0);
// 		}
// 	}
// 	return (1);
// }
//
// //💩 innutile
// static void 				ft_unshift(t_tro tetro, int shift)
// {
// 	unsigned short 		go_to;
// 	int 							stop;
//
// 	stop = 0;
// 	go_to = 0b1000000000000000 >> shift;
// 	stop ||= tetro[0] & go_to;
// 	stop ||= tetro[1] & go_to;
// 	stop ||= tetro[2] & go_to;
// 	stop ||= tetro[3] & go_to;
// 	while (!stop)
// 	{
// 		stop ||= (tetro[0] <<= 1) & go_to;
// 		stop ||= (tetro[1] <<= 1) & go_to;
// 		stop ||= (tetro[2] <<= 1) & go_to;
// 		stop ||= (tetro[3] <<= 1) & go_to;
// 	}
// }

// //💩 innutile
// static void 				ft_shift(t_tro tetro, int shift)
// {
// 	unsigned short 		go_to;
// 	int 							stop;
//
// 	stop = 0;
// 	go_to = 0b1000000000000000 >> shift;
// 	stop ||= tetro[0] % go_to;
// 	stop ||= tetro[1] % go_to;
// 	stop ||= tetro[2] % go_to;
// 	stop ||= tetro[3] % go_to;
// 	if (stop)
// 		ft_unshift(tetro, shift);
// 	while (!stop)
// 	{
// 		stop ||= (tetro[0] >>= 1) % go_to;
// 		stop ||= (tetro[1] >>= 1) % go_to;
// 		stop ||= (tetro[2] >>= 1) % go_to;
// 		stop ||= (tetro[3] >>= 1) % go_to;
// 	}
// }


// 🎁  Nouveau

/*
** 		ind
**
** ind[4] : taille du cote du carre (aussi appelé y ou x ou size)
** ind[3] : index de ligne (a partir de laquelle on fait le placement) dans map
** ind[2] : shift du tetromino
** ind[1] : numero du tetromino actuel (indice dans la liste des tetros)
** ind[0] : nombre de tetrominos (longueur de la liste des tetros)
*/

// static int ft_fillit(unsigned short **tetros, t_map map, int ind[5], t_data data)
// {
// 	// 1- verifie que le tetro est dans le carré
// 			// si il est en dessous return (0)
// 			// si il est a droite return(ft_fillit avec ind[2] = 0 et ind[3] += 1);
// 	// 2-
// }


	// // // // // // // // // // // //
 // // // //    DEBUG    // // // //
// // // // // // // // // // // //

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
	{
		printf("%s\n", bigger_mother_fucker(ft_itoa_base(us[i], 2), 16));
	}
}

static void print_at(t_tro tetro, int shift, t_map map, int index)
{
	ft_print_tetro_on_map(tetro, shift, map, index);
	print(map, 16);
}


// // // // // // //
// ft_print_tetro_on_map
// ft_erase_tetro_from_map
// ft_is_out_under
// ft_is_out_right
//

// int main()
// {
// 	unsigned short tetro[] = {0b1100000000000000, 0b0100000000000000, 0b0100000000000000, 0b0000000000000000};
// 	unsigned short map[] = {0b0000000000000000, 0b0000000000000000, 0b0000000000000000, 0b0000000000000000,\
// 													0b0000000000000000, 0b0000000000000000, 0b0000000000000000, 0b0000000000000000,\
// 													0b0000000000000000, 0b0000000000000000, 0b0000000000000000, 0b0000000000000000,\
// 		 											0b0000000000000000, 0b0000000000000000, 0b0000000000000000, 0b0000000000000000};
// 	int shift = 0;
// 	int index = 0;
// 	int size = 10;
// 	while (index < 20)
// 	{
// 		printf("index = %d\n", index);
// 		if (ft_is_out_under(size, tetro, index))
// 		{
// 			printf("\e[41mOUT UNDER\e[0m\n");
// 			break;
// 		}
// 		else
// 		{
// 			while(shift < 20)
// 			{
// 				printf("shift = %d\n", shift);
// 				if (ft_is_out_right(size, tetro, shift))
// 				{
// 					printf("\e[41mOUT RIGHT\e[0m\n");
// 					break;
// 				}
// 				else
// 				{
// 					printf("print_at(tetro, %d, map, %d);\n", shift, index);
// 					print_at(tetro, shift, map, index);
// 					ft_erase_tetro_from_map(tetro, shift, map, index);
// 					shift ++;
// 				}
// 			}
// 			shift = 0;
// 			index ++;
// 		}
// 	}
// }

// // // // // // //
// ft_can_print
//

int main()
{
	unsigned short tetro[] = {0b1100000000000000, 0b0100000000000000, 0b0000000000000000, 0b0000000000000000};
	unsigned short map[] = {0b0000000000000000, 0b0000000000000000, 0b0000000000000000, 0b0000000000000000,\
													0b0000000000000000, 0b0000000000000000, 0b0000000000000000, 0b0000000000000000,\
													0b0000000000000000, 0b0000000000000000, 0b0000000000000000, 0b0000000000000000,\
		 											0b0000000000000000, 0b0000000000000000, 0b0000000000000000, 0b0000000000000000};
	int shift = 0;
	int index = 0;
	int size = 5;
	while (index < 20)
	{
		printf("index = %d\n", index);
		if (ft_is_out_under(size, tetro, index))
		{
			printf("\e[41mOUT UNDER\e[0m\n");
		}
		else
		{
			while(shift < 20)
			{
				printf("shift = %d\n", shift);
				if (ft_is_out_right(size, tetro, shift))
					printf("\e[41mOUT RIGHT\e[0m\n");
				else
				{
					printf("print_at(tetro, %d, map, %d);\n", shift, index);
					print_at(tetro, shift, map, index);
				}
				shift++;
			}
			shift = 0;
		}
		index++;
	}
}
// // // // // // // // // // // // // // // // // //

// static int	ft_put_bits(t_tro tetro, t_map map)
// {
// 	int		i;
// 	int		shift;
//
// 	i = 0;
// 	shift = 0;
// 	if (ft_is_left_of(x, tetro, shift))
// 		ft_put_bits(tetro, map, );
// 	{
// 		if (tetro[i] >> shift & map[i] == 0 && i < 4)
//       i++;
// 		else
// 		{
// 			shift++;
// 			i = 0;
// 		}
// 		if (i == 3)
// 		{
// 			map[0] |= tetro[0];
// 			map[1] |= tetro[1];
// 			map[2] |= tetro[2];
// 			map[3] |= tetro[3];
// 			return (1);
// 		}
// 	}
// 	return (0);
// }
//
// int ft_place(t_map mappy, t_tro tetro, int[2] square, int[2] shifts)
// {
// 	//		>>
// 	if (ft_is_
// 	//		V
// 	ft_place (mappy, tetro++, x, y);
// }
//
// int ft_solve(unsigned short mappy[16], unsigned short **tetros, int x, int y)
// {
//   unsigned short  map[16]
//   int             i;
//
//   i = -1;
//   while (++i < 16)
//     map[i] = mappy[i];
//   if (ft_place(map, tetro, x, y))
//     return (x, y);
//   ft_solve(map, tetro, x + 1, y + 1);
// }
//
//

/*

       x    0 1 2 3 4 5 6 7 8'9'A B C D E F

      mappy :                'x'
 y

 0          0 0 0 0 0 0 0 0 0'0'0 0 0 0 0 0
 1          0 0 0 0 0 0 0 0 0'0'0 0 0 0 0 0
 2          0 0 0 0 0 0 0 0 0'0'0 0 0 0 0 0
 3          0 0 0 0 0 0 0 0 0'0'0 0 0 0 0 0
 4          0 0 0 0 0 0 0 0 0'0'0 0 0 0 0 0
 5          0 0 0 0 0 0 0 0 0'0'0 0 0 0 0 0
 6          0 0 0 0 0 0 0 0 0'0'0 0 0 0 0 0
 7          0 0 0 0 0 0 0 0 0'0'0 0 0 0 0 0
'8' 'y'    "0 0 0 0 0 0 0 0 0'0'0 0 0 0 0 0"
 9          0 0 0 0 0 0 0 0 0'0'0 0 0 0 0 0
 A          0 0 0 0 0 0 0 0 0'0'0 0 0 0 0 0
 B          0 0 0 0 0 0 0 0 0'0'0 0 0 0 0 0
 C          0 0 0 0 0 0 0 0 0'0'0 0 0 0 0 0
 D          0 0 0 0 0 0 0 0 0'0'0 0 0 0 0 0
 E          0 0 0 0 0 0 0 0 0'0'0 0 0 0 0 0
 F          0 0 0 0 0 0 0 0 0'0'0 0 0 0 0 0

      mask :
            1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0


     x      0 1 2 3 4 5 6 7 8'9'A B C D E F

tetro :

i

0           0 0 0 0 0 0 0 0 1'1'0 0 0 0 0 0
1           0 0 0 0 0 0 0 0 1'0'0 0 0 0 0 0
2           0 0 0 0 0 0 0 0 1'0'0 0 0 0 0 0
3           0 0 0 0 0 0 0 0 0'0'0 0 0 0 0 0

%           0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0
*/
