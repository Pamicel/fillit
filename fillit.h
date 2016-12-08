/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:56:09 by apissier          #+#    #+#             */
/*   Updated: 2016/12/08 17:28:08 by apissier         ###   ########.fr       */
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
char		*ft_realloc(char *ptr, size_t size);
void		ft_putstr(char const *s);
size_t		ft_strlen(const char *s);

#endif
