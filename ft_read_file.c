/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 15:56:30 by apissier          #+#    #+#             */
/*   Updated: 2016/12/08 16:51:26 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFF_SIZE 21

char        **ft_read_file(char *str)
{
    int     fd;
    int     ret;
    int    *s;
    int     i;
    char    buf[BUFF_SIZE + 1];

    i = 0;
    fd = open(str, O_RDONLY);
    if (fd == -1)
        ft_putstr("open() error");
	while (1)
	{
		ret = read(fd, buf,BUFF_SIZE);
		if (ret == 0)
			break ;
		if (ft_isvalid(buf))
		{
			ft_realloc(s, ++i);
			s[i] = ft_code(buf);
		}
	}
	if (close(fd) == -1)
		ft_putstr("open() error");
	return (s);
}
