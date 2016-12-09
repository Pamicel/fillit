/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 16:44:53 by apissier          #+#    #+#             */
/*   Updated: 2016/12/09 15:15:30 by pamicel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// // //
#include <stdio.h>
// // //
#include "fillit.h"

int			main(int argc, char **argv)
{
	char **s;
	int n;

	if (argc != 2)
		ft_putstr("Error()");
	else
	{
		n = 0;
		printf("test ft_read_file\n");
		s = ft_read_file(argv[1]);
		printf("%s\n", s[0]);
		printf("%s\n", (s ? "\e[32mYES\e[0m" : "\e[41mNO\e[0m"));
		for (int n = 0; n < 7; n++)
			printf("tetromino s[%d]\n%s\nft_isvalid ? %s\n", n, s[n], (ft_isvalid(s[n])? "\e[32mVALID\e[0m" : "\e[41mINVALID\e[0m"));
	}
	return (0);
}
