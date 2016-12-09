/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 16:44:53 by apissier          #+#    #+#             */
/*   Updated: 2016/12/09 11:32:11 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "fillit.h"

int			main(int argc, char **argv)
{
	char *t[7];
	char **s;
	char *str;
	int i;

	str = "..##\n...#\n...#\n....\n\n##..\n##..\n....\n....\n\n....\n##..\n#...\n#...\n\n....\n##..\n##..\n.#..\n\n##..\n##..\n....\n....\n\n##..\n....\n.##.\n....\n\n#...\n##..\n.#..\n....\n";
	t[0] = "..##\n...#\n...#\n....\n";
	t[1] = "##..\n##..\n....\n....\n";
	t[2] = "....\n##..\n#...\n#...\n";
	t[3] = "....\n##..\n##..\n.#..\n";
	t[4] = "##..\n##..\n....\n....\n";
	t[5] = "##..\n....\n.##.\n....\n";
	t[6] = "#...\n##..\n.#..\n....\n";

	if (argc != 2)

	ft_putstr("Error()");
	else
	{
		printf("test ft_read_file\n");
		printf("%s\n", ft_read_file(argv[1]));
		printf("%s\n", (i ? "\e[32mYES\e[0m" : "\e[41mNO\e[0m"));
		for (int n = 0; n < 7; n++)
			printf("tetromino s[%d]\n%s\nft_isvalid ? %s\n", n, s[n], (ft_isvalid(s[n])? "\e[32mVALID\e[0m" : "\e[41mINVALID\e[0m"));
	}
	return (0);
}
