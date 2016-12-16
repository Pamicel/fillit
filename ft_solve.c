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

/* fonctions */

unsigned short	ft_put_bits(unsigned short *tetro, unsigned short *map, int x)
{
	int			t;
	int			m;

	t = 0;
	m = 0;
	while (map)
	{ 
		if (tetro[i]^map[m] == tetro[i])
		{
			m++;
            i++;
		}
		while (tetro[i]^map[m] != tetro[i] && ft_column_max(tetro, x))
			tetro >> 1;
	}
}

static int       ft_column_max(unsigned short *tetro, int x)
{
  unsigned short modula;
  int i;

  i = 0;
  modula = 0b1000000000000000 >> (x - 1);

  while (i < 3)
    if (tetro[i++] % modula != 0)
      return (0);
  return (1)
}

int ft_place(unsigned short *mappy, unsigned short **tetro, int x, int y)
{
  >>
  V
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
