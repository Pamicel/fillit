/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 10:48:25 by apissier          #+#    #+#             */
/*   Updated: 2016/12/09 10:48:29 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void        *ft_realloc(void *ptr, size_t cur_size, size_t new_size)
{
    void       *new;
    size_t     i;

    if (new_size <= cur_size)
      return (ptr);
    if (!(new = ft_memalloc(new_size)))
      return (NULL);
    i = 0;
    while (i < cur_size)
    {
      ((char*)new)[i] = ((char*)ptr)[i];
      i++;
    }
    free(ptr);
    return (new);
}
