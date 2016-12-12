/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 15:56:30 by apissier          #+#    #+#             */
/*   Updated: 2016/12/09 14:40:30 by pamicel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
// // //
#include <stdio.h>
// // //

#define BUFF_SIZE 21

/*
** ft_read_file :
** ints[0] fd
** ints[1] nbr of codes ( <=> tetrominos )
*/

char        **ft_read_file(char *str)
{
	int			ints[2];
	ssize_t ret;
	char    **codes;
	char    buf[BUFF_SIZE + 1];

	ints[1] = 0;
	if ((ints[0] = open(str, O_RDONLY)) == -1)
		ft_putstr("open() error");
	while (1)
	{
		if ((ret = read(ints[0], buf, BUFF_SIZE)) <= 0)
			break ;
		buf[ret - 1] = '\0';
		if (ft_isvalid(buf))
		{
			write(1, "\e[44mpas segfault\e[0m\n", 13 + 4 + 5);
			codes = (char**)realloc((void*)codes, ++ints[1]); //ft_realloc(codes, ints[1], ++ints[1]);

			printf("address of codes : %X\n", (int)codes);

			codes[ints[1] - 1] = ft_code(buf);
			printf("buffer : \n%s\n", buf);
			printf("ft_code returns %d%d%d\n", (int)codes[ints[1] - 1][0], (int)codes[ints[1] - 1][1], (int)codes[ints[1] - 1][2]);
		}
		else
			break ;
	}
	if (close(ints[0]) == -1)
		ft_putstr("close() error");
	return (codes);
}
