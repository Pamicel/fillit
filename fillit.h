/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:56:09 by apissier          #+#    #+#             */
/*   Updated: 2016/12/09 10:53:30 by apissier         ###   ########.fr       */
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

char		**ft_read_file(char *str);
int			ft_isvalid(char *t);
char		*ft_realloc(void *ptr, size_t cur_size, size_t new_size);
void		ft_putstr(char const *s);
size_t		ft_strlen(const char *s);
void        *ft_memalloc(size_t size);
char        *ft_code(char *str);

#endif
