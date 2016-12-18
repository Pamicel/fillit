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

static int       ft_is_left_of(int x, unsigned short *tetro, int shift)
{
	unsigned short	modula;
	int							i;

	i = 0;
	modula = 0b1000000000000000 >> (x - 1);

	while (i < 3)
		if (tetro[i++] >> shift % modula != 0)
			return (0);
	return (1);
}

static void				ft_print_tetro_on_map(unsigned short *tetro_ptr, unsigned short *map_ptr)
{
	map_ptr[0] |= tetro_ptr[0];
	if (tetro_ptr[1])
	{
		map_ptr[1] |= tetro_ptr[1];
		if (tetro_ptr[2])
		{
			map_ptr[2] |= tetro_ptr[2];
			if (tetro_ptr[3])
				map_ptr[3] |= tetro_ptr[3];
		}
	}
}

static void				ft_erase_tetro_from_map(unsigned short *tetro_ptr, unsigned short *map_ptr)
{
	map_ptr[0] ^= tetro_ptr[0];
	if (tetro_ptr[1])
	{
		map_ptr[1] ^= tetro_ptr[1];
		if (tetro_ptr[2])
		{
			map_ptr[2] ^= tetro_ptr[2];
			if (tetro_ptr[3])
				map_ptr[3] ^= tetro_ptr[3];
		}
	}
}

// // // // // DEBUG PRINT & ERASE // // // // //
// #include <stdio.h>
// static char *bigger_mother_fucker(char *str, int n_digits)
// {
// 	char *new;
// 	int n = ft_strlen(str);
// 	if (n < n_digits)
// 	{
// 		new = ft_strnew(n_digits);
// 		ft_strcpy(&(new[n_digits - n]), str);
// 		for (int i = 0; i < n_digits - n; i++)
// 		{
// 			new[i] = '0';
// 		}
// 		return (new);
// 	}
// 	return (str);
// }
//
// static void print(unsigned short *us)
// {
// 	for(int i = 0; i < 4; i++)
// 	{
// 		printf("%s\n", bigger_mother_fucker(ft_itoa_base(us[i], 2), 16));
// 	}
// }
//
// int main()
// {
// 	unsigned short tetro[] = {0b0000000000110000, 0b0000000000110000, 0b0000000000000000, 0b0000000000000000};
// 	unsigned short map[] = {0b0100000000000000, 0b0100000000000000, 0b0100000000000000, 0b0100000000000000};
//
// 	printf("tetro = \n");
// 	print(tetro);
// 	printf("map = \n");
// 	print(map);
// 	printf("ft_print_tetro_on_map(tetro, map);\n");
// 	ft_print_tetro_on_map(tetro, map);
// 	printf("tetro = \n");
// 	print(tetro);
// 	printf("map = \n");
// 	print(map);
// 	printf("ft_erase_tetro_from_map(tetro, map);\n");
// 	ft_erase_tetro_from_map(tetro, map);
// 	printf("tetro = \n");
// 	print(tetro);
// 	printf("map = \n");
// 	print(map);
// 	return 0;
// }
// // // // // // // // // // // // // // // // //


static int			ft_is_above(int y, unsigned short *map)
{
	return (map[y - 1] != 0);
}

/*
**
**
*/

static int	ft_collision(unsigned short *tetro, unsigned short *map)
{
	int i;
	int ret;

	ret = 1;
	i = 0;
	while (i < 4)
		ret &= tetro[i] & map[i];
	return (ret);
}

// static int	ft_put_bits(unsigned short *tetro, unsigned short *map)
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

int ft_place(unsigned short *mappy, unsigned short *tetro, int[2] square, int[2] shifts)
{
	//		>>
	if (ft_is_
	//		V
	ft_place (mappy, tetro++, x, y);
}

int ft_solve(unsigned short mappy[16], unsigned short **tetros, int x, int y)
{
  unsigned short  map[16]
  int             i;

  i = -1;
  while (++i < 16)
    map[i] = mappy[i];
  if (ft_place(map, tetro, x, y))
    return (x, y);
  ft_solve(map, tetro, x + 1, y + 1);
}











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


*/

/*

     x    0 1 2 3 4 5 6 7 8'9'A B C D E F

tetro :

i

0         0 0 0 0 0 0 0 0 1'1'0 0 0 0 0 0
1         0 0 0 0 0 0 0 0 1'0'0 0 0 0 0 0
2         0 0 0 0 0 0 0 0 1'0'0 0 0 0 0 0
3         0 0 0 0 0 0 0 0 0'0'0 0 0 0 0 0

%         0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0
*/
