/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamicel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 19:54:08 by pamicel           #+#    #+#             */
/*   Updated: 2016/11/13 12:06:22 by pamicel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_put_positive_nbr(int n)
{
	if (n >= 10)
		ft_put_positive_nbr(n / 10);
	ft_putchar('0' + n % 10);
}

void			ft_putnbr(int n)
{
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else if (n < 0)
	{
		n = -n;
		ft_putchar('-');
		ft_put_positive_nbr(n);
	}
	else
		ft_put_positive_nbr(n);
}
