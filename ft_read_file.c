/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 15:56:30 by apissier          #+#    #+#             */
/*   Updated: 2016/12/09 13:36:09 by pamicel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#define BUFF_SIZE 21

char        **ft_read_file(char *str)
{
    int     fd;
    int     ret;
    char    **s;
    int     i;
    char    buf[BUFF_SIZE + 1];

    i = 0;
	s = NULL;
    fd = open(str, O_RDONLY);
    if (fd == -1)
        ft_putstr("open() error");
	while (1)
	{
		ret = read(fd, buf,BUFF_SIZE);
		if (ret == 0)
			break ;
		buf[ret - 1] = '\0';
		if (ft_isvalid(buf))
		{
			ft_realloc(s, BUFF_SIZE, ++i);
			s[i] = ft_code(buf);
		}
	}
	if (close(fd) == -1)
		ft_putstr("open() error");
	return (s);
}
