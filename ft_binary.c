/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamicel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 15:58:00 by pamicel           #+#    #+#             */
/*   Updated: 2017/01/10 15:58:02 by pamicel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int					ft_is_out_under(int y, t_tro tetro, int index)
{
	if (tetro[3])
		return ((y - index - 4) < 0);
	else if (tetro[2])
		return ((y - index - 3) < 0);
	else if (tetro[1])
		return ((y - index - 2) < 0);
	return ((y - index - 1) < 0);
}

static int			ft_is_out_right(int x, t_tro tetro, int shift)
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

static int			ft_can_print(t_tro tetro, int shift, t_map map, int index)
{
	int 			ret;

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

int					ft_print_tetro_on_map(t_tro tetro, int shift, t_map map, int index)
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

int					ft_move_tetro(t_tro tetro, int *shift, int *index, int size)
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
