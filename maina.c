/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 16:44:53 by apissier          #+#    #+#             */
/*   Updated: 2016/12/08 14:07:32 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 600

int			main(int argc, char **argv)
{
	char	**str;
	if (argc != 2)
		ft_putstr("Error()");
	else
		str = ft_read_file(argv[1]);

  return (0);
}
