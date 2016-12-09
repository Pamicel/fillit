/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 15:56:30 by apissier          #+#    #+#             */
/*   Updated: 2016/12/09 13:47:09 by pamicel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#define BUFF_SIZE 21

/*
** ft_read_file :
** i[0] fd
** i[1] nbr of char read
** i[2] counter
*/

char        **ft_read_file(char *str)
{
	int		i[3];
//	int     fd;
//	int     ret;
	char    **s;
//	int     i;
	char    buf[BUFF_SIZE + 1];

	i[2] = 0;
	s = NULL;
	i[0] = open(str, O_RDONLY);
	if (i[0] == -1)
		ft_putstr("open() error");
	while (1)
	{
		i[1] = read(i[1], buf, BUFF_SIZE);
		if (i[1] == 0)
			break ;
		buf[i[1] - 1] = '\0';
		if (ft_isvalid(buf))
		{
			ft_realloc(s, BUFF_SIZE, ++i[2]);
			s[i[2]] = ft_code(buf);
		}
	}
	if (close(i[2]) == -1)
		ft_putstr("open() error");
	return (s);
}
