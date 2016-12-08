/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamicel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 10:21:07 by pamicel           #+#    #+#             */
/*   Updated: 2016/11/16 10:59:19 by pamicel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	if (!alst)
		return ;
	if (*alst)
	{
		del((*alst)->content, (*alst)->content_size);
		ft_lstdel(&((*alst)->next), del);
		free(*alst);
		*alst = NULL;
	}
}
