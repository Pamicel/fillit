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

//
// static void setup(unsigned short **all_pieces)
// {
// 	all_pieces = (**unsigned short)ft_memalloc(16 * sizeof(*unsigned short));
// 	all_pieces[0] = ft_memcpy()
// }

static unsigned short		*ft_code_to_bin(char *str)
{
	char						*all_codes;
	int 						i;
	unsigned short	*piece;
	unsigned short 	*all_pieces;

	all_codes = "300304003403404040303020444000030034430004400044440200002";
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
	i = 0;
	while (ft_strncmp(str, &(all_codes[i * 3]), 3))
		i++;
	if ((piece = (unsigned short*)ft_memalloc(4 * sizeof(unsigned short))))
	 	ft_memcpy(piece, &(all_pieces[i * 4]), 4 * sizeof(unsigned short));
	return (piece);
}

/*
** ints[0]	indice dans str
** ints[1]	charactere a ajouter a code
** ints[2]  indice dans code
*/


unsigned short						*ft_code(char *str)
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
	write(1, code, 3);
	write(1, "\n", 1);
	unsigned short	*piece = ft_code_to_bin(code);
	for (int i = 0; i < 4; i++)
	{
		printf("%hu,\t", piece[i]);
	}
	return (0);
	//return (ft_code_to_bin(code));
}
//
// int main()
// {
// 	char 						*str = "..#.\n###.\n....\n....\n";
// 	unsigned short	*piece = ft_code(str);
// 	printf("\n");
// 	return 0;
// }
//


/*

. # # .

0 1 1 0  0 0 0 0  0 0 0 0  0 0 0 0


7
16
16 - 7 = 9
tetro += 2**9

0 0 0 0  0 0 1 0  0 0 0 0  0 0 0 0

s_numbers
{
	char *all_my_numbers = "abcd";
	int 	numbers[6];
	numbers[0] = 34;
	numbers[1] = 256;
	numbers[2] = 9;
	numbers[3] = 10;
}

s_numbers.numbers[1]

while(i++ < 4)
	if (compare_le_char(code, s_numbers.all_my_numbers[i]))
		return (s_numbers.numbers[i]);

char *all_possible_codes = "404000123123123123123123120";
short **all_possible_pieces = piece0;

codes[3]
i = 0
while (i < 15 * 3)
{
	if (0 == ft_strncmp(codes[12], &(all_possible_codes[i]), 3))
		break ;
	i += 3;
}
return pieces[i / 3]

short pieces[16][4];
pieces[0] = {	0b1100000000000000, 0b1100000000000000,
							0b0000000000000000, 0b0000000000000000}
pieces[1] = {}

str			tetro
				0				1			0
				0				2			1
				0				4			2
				0				8			3
				0				16		4
				0				32		5
				0				64		6
				0				128		7
				0				256   8
				0				512		9
				0				1024  10
				0				2048  11
.		3		0				4096  12
#		2		0				8192  13
#		1		0				16384 14
.		0		0				32768 15

str[1] == '#' -> vrai
tetro =

if str[i] == '#'
	tetro += 2**(15 - i)

1 0 0 0
*/
