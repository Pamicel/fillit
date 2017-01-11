/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:56:09 by apissier          #+#    #+#             */
/*   Updated: 2017/01/10 15:58:53 by pamicel          ###   ########.fr       */
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
# define TETRO_SIZE 6
#define BUFF_SIZE 21

typedef unsigned short  t_tro[TETRO_SIZE];
typedef unsigned short  t_map[16];

int FD;

int		ft_is_out_under(int y, t_tro tetro, int index);
int	    ft_read_file(char *str, unsigned short *all_tetros, int *n,\
	 t_tro tetros[26]);
int		ft_get_tetro(char *str, unsigned short *all_tetros, t_tro tetro);
int		ft_solve(t_tro tetros[26], t_map map, int ind[5]);
int		ft_fillit(t_tro tetros[26], int n_tetros);
void	ft_print_result(t_tro tetros[26], int n_tetros, int size);
int		ft_print_tetro_on_map(t_tro tetro, int shift, t_map map, int index);
int		ft_move_tetro(t_tro tetro, int *shift, int *index, int size);

#endif
