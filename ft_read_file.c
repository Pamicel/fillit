/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 12:12:37 by apissier          #+#    #+#             */
/*   Updated: 2016/12/08 12:59:09 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_split_tetriminos(char *str)
{
	int		i;

	i = 20;
	while (str[i])
	{
		if (str[i] == '\n')
			str[i] = '@';
		i = i + 21;
    }
	return (str);
}

char		**ft_read_file(char *str)
{
    int		fd;
    int		ret;
    char	**s;
    int		i;
    char	buf[BUF_SIZE + 1];

	i = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		ft_putstr("open() error");
	ret = read(fd, buf,BUF_SIZE);
	ft_split_tetriminos(buf);
	s =ft_strsplit(buf, '@');
	if (close(fd) == -1)
		ft_putstr("open() error");
	return (s);
}
