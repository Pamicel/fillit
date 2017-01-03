/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 17:10:22 by apissier          #+#    #+#             */
/*   Updated: 2016/12/14 17:35:26 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int      n_char(char *t, char c)
{
    int n;

    n = 0;
    while (*t)
        n += (c == *(t++));
    return (n);
}

/*
** valid_shape Can only be used with a valid grid with a valid nbr of '#'s
*/

static int      valid_shape(char *tetro)
{
    int i;
    int total;
    int n;

    n = 0;
    total = 0;
    i = 0;
    while (i < 20)
    {
        n = 0;
        if (tetro[i] == '#')
        {
            n += (i <= 14 ? tetro[i + 5] == '#' : 0) + \
                (i >= 5 ? tetro[i - 5] == '#' : 0) + \
                (i >= 1 ? tetro[i - 1] == '#' : 0) + \
                (i <= 18 ? tetro[i + 1] == '#' : 0);
            if (n == 0)
                return (0);
        }
        i++;
        total += n;
    }
    return (total);
}

int             ft_isvalid(char *tetro)
{
    return (*tetro && \
            ft_strlen(tetro) == 20 && \
            tetro[4] == '\n' && \
            tetro[9] == '\n' && \
            tetro[14] == '\n' && \
            tetro[19] == '\n' && \
            n_char(tetro, '\n') == 4 && \
            n_char(tetro, '#') == 4 && \
            valid_shape(tetro) >= 6);
}
