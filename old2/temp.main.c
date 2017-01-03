#include <stdio.h>
#include <stdlib.h>
typedef unsigned short t_tro[6];
typedef unsigned short t_map[16];
#include "libft.h"

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


    ///////////////////////////
   ////////   DEBUG   ////////
  ///////////////////////////

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

int main()
{
	unsigned short tetro[] = {0b1000000000000000, 0b1000000000000000, 0b1000000000000000, 0b1000000000000000};
	unsigned short map[] = {0b0000000000000000, 0b0000000000000000, 0b0000000000000000, 0b0000000000000000,\
													0b0000000000000000, 0b0000000000000000, 0b0000000000000000, 0b0000000000000000,\
													0b0000000000000000, 0b0000000000000000, 0b0000000000000000, 0b0000000000000000,\
		 											0b0000000000000000, 0b0000000000000000, 0b0000000000000000, 0b0000000000000000};
	int shift = 0;
	int index = 0;
	int size = 5;

	do {
		printf("index = %d\n", index);
		printf("shift = %d\n", shift);
		printf("print_at(tetro, %d, map, %d);\n", shift, index);
		print_at(tetro, shift, map, index);
    ft_erase_tetro_from_map(tetro, shift, map, index);
	} while (ft_move_tetro(tetro, &shift, &index, size));
}
// // // // // // // // // // // // // // // // // //
