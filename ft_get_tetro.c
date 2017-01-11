/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_tetro.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 17:48:18 by apissier          #+#    #+#             */
/*   Updated: 2016/12/09 15:44:00 by pamicel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_make_code(char *code, char *str, int i_str)
{
	int		i_code;
	char	c;

	i_code = 0;
	while (i_code < 3)
	{
		while (str[++i_str] == '#')
			code[i_code++] = 0 + '0';
		c = 0;
		while (str[i_str] && str[i_str] != '#')
		{
			c++;
			i_str++;
		}
		code[i_code++] = c + '0';
	}
}

static void	ft_code_to_bin(char *str, unsigned short *all_tetros, t_tro tetro)
{
	char	*all_codes;
	int 	i;

	all_codes = "300304003403404040303020444000030034430004400044440200002";
	i = 0;
	while (ft_strncmp(str, &(all_codes[i * 3]), 3))
		i++;
	ft_memcpy(tetro, &(all_tetros[i * 4]), 4 * sizeof(unsigned short));
}

int			ft_get_tetro(char *str, unsigned short *all_tetros, t_tro tetro)
{
	int 	i_str;
	char	*code;

	i_str = 0;
	if (!(code = ft_strnew(3)))
		return (0);
	while (str[i_str] != '#')
		i_str++;
	ft_make_code(code, str, i_str);
	ft_code_to_bin(code, all_tetros, tetro);
	free(code);
	return (1);
}
