/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamicel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 10:43:28 by pamicel           #+#    #+#             */
/*   Updated: 2016/11/13 12:06:36 by pamicel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_put_positive_nbr_fd(int n, int fd)
{
	if (n >= 10)
		ft_put_positive_nbr_fd(n / 10, fd);
	ft_putchar_fd('0' + n % 10, fd);
}

void			ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (n < 0)
	{
		n = -n;
		ft_putchar_fd('-', fd);
		ft_put_positive_nbr_fd(n, fd);
	}
	else
		ft_put_positive_nbr_fd(n, fd);
}
