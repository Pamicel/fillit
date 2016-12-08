/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamicel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 11:19:12 by pamicel           #+#    #+#             */
/*   Updated: 2016/11/16 11:37:20 by pamicel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *first_elem;

	if (!lst)
		return (NULL);
	if (!(new = f(lst)))
		return (NULL);
	first_elem = new;
	while (lst->next)
	{
		lst = lst->next;
		if ((new->next = f(lst)))
			new = new->next;
		else
			break ;
	}
	return (first_elem);
}
