/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 17:26:54 by apissier          #+#    #+#             */
/*   Updated: 2016/12/08 17:27:12 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char        *ft_realloc(char *ptr, size_t size)
{
    char    *new;
    int     i;

    new = ptr;
    ptr = NULL;
    free(ptr);
    i = 0;
    if (!(ptr = (char*)malloc(sizeof(size))))
        return (NULL);
    while (new[i] && i < (int)size)
    {
        ptr[i] = new[i];
        i++;
    }
    new = NULL;
    free(new);
    return (ptr);
}
