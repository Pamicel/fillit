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

struct		s_pieces
{
	char			*all_codes[16*3];
	unsigned short	all_pieces[16][4];

	all_code = "3003040034034040403030204444000030034430004400044";
	all_pieces = {	{16384, 57344, 0, 0}, \
					{16384, 49152, 16384, 0}, \
					{57344, 16384, 0, 0}, \
					{32768, 49152, 32768, 0}, \
					{32768, 49152, 16384, 0}, \
					{49152, 24576, 0, 0}, \
					{16384, 49152, 32768, 0}, \
					{24576, 49152, 0, 0}, \
					{32768, 32768, 32768, 32768}, \
					{61440, 0, 0, 0}, \
					{49152, 49152, 0, 0}, \
					{49152, 32768, 32768, 0}, \
					{16384, 16384, 49152, 0}, \
					{57344, 8192, 0, 0}, \
					{32768, 57344, 0, 0}, \
					{49152, 16384, 16384, 0} };
}

char		**ft_read_file(char *str);
int			ft_isvalid(char *t);
char		*ft_realloc(char *str, size_t size);
void		ft_putstr(char const *s);
size_t		ft_strlen(const char *s);
void		*ft_memalloc(size_t size);
char		*ft_code(char *str);
void		*ft_memset(void *s, int c, size_t n);
char		*ft_strnew(size_t size);
char		*ft_strncpy(char *dest, const char *src, size_t n);

#endif
