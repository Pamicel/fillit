/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:56:09 by apissier          #+#    #+#             */
/*   Updated: 2016/12/12 15:17:32 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"

unsigned short 		**ft_read_file(char *str, unsigned short *all_pieces, int *n);
int				        ft_isvalid(char *t);
//char			*ft_realloc(char *str, size_t size);
unsigned short		*ft_code(char *str, unsigned short *all_pieces);

#endif


/*

      x    0 1 2 3 4 5 6 7 8'9'A B C D E F
y

0          0 0 0 0 0 0 0 0 0'0'0 0 0 0 0 0
1          0 0 0 0 0 0 0 0 0'0'0 0 0 0 0 0
2          0 0 0 0 0 0 0 0 0'0'0 0 0 0 0 0
3          0 0 0 0 0 0 0 0 0'0'0 0 0 0 0 0
4          0 0 0 0 0 0 0 0 0'0'0 0 0 0 0 0
5          0 0 0 0 0 0 0 0 0'0'0 0 0 0 0 0
6          0 0 0 0 0 0 0 0 0'0'0 0 0 0 0 0
7          0 0 0 0 0 0 0 0 0'0'0 0 0 0 0 0
'8'       "0 0 0 0 0 0 0 0 0'0'0 0 0 0 0 0"
9          0 0 0 0 0 0 0 0 0'0'0 0 0 0 0 0
A          0 0 0 0 0 0 0 0 0'0'0 0 0 0 0 0
B          0 0 0 0 0 0 0 0 0'0'0 0 0 0 0 0
C          0 0 0 0 0 0 0 0 0'0'0 0 0 0 0 0
D          0 0 0 0 0 0 0 0 0'0'0 0 0 0 0 0
E          0 0 0 0 0 0 0 0 0'0'0 0 0 0 0 0
F          0 0 0 0 0 0 0 0 0'0'0 0 0 0 0 0

%          1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

*/
