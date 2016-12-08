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
#include <stdio.h>


// // // // // // // // //

/*
** n_char returns the nb of occurences of c in t
*/

static int		n_char(char *t, char c)
{
	int n;

	n = 0;
	while (*t)
		n += c == *(t++);
	return (n);
}

/*
** valid_shape Can only be used with a valid grid with a valid nbr of '#'s
*/

static	int		valid_shape(char *t)
{
	int i;
	int total;
	int n;

	n = 0;
	total = 0;
	i = 0;
	while (i < 20)
	{
    n = 0;
		if (t[i] == '#')
		{
			n += (i <= 14 ? t[i + 5] == '#' : 0) + \
				(i >= 5 ? t[i - 5] == '#' : 0) + \
				(i >= 1 ? t[i - 1] == '#' : 0) + \
				(i <= 18 ? t[i + 1] == '#' : 0);
			if (n == 0)
				return (0);
		}
		i++;
		total += n;
	}
	return (total);
}

/*
** Tells if a tetromino is valid or not
*/
int				ft_isvalid(char *t)
{
	return ( \
			ft_strlen(t) == 20		&& \
			t[4] ==		'\n'		&& \
			t[9] ==		'\n'		&& \
			t[14] ==	'\n'		&& \
			t[19] ==	'\n'		&& \
			n_char(t, '\n') == 4	&& \
			n_char(t, '#')	== 4	&& \
			valid_shape(t)	>= 6	);
}

// // // // // // // // // // // //


char		**ft_read_file(char *str);

int ft_compare(char **s, char **t, int size)
{
	int ret = 1;

	while (--size)
	{
		ret &= !ft_strcmp(t[size], s[size]);
		// printf("t[size] = \n%s\ns[size] = \n%s\n", t[size], s[size]);
		// printf("\n");
	}
	return (ret);
}

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
		i = ft_compare((s = ft_read_file(argv[1])), t, 7);
		printf("%s\n", (i ? "\e[32mYES\e[0m" : "\e[41mNO\e[0m"));
		for (int n = 0; n < 7; n++)
			printf("tetromino s[%d]\n%s\nft_isvalid ? %s\n", n, s[n], (ft_isvalid(s[n])? "\e[32mVALID\e[0m" : "\e[41mINVALID\e[0m"));
	}
	return (0);
}
