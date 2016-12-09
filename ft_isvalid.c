/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 17:10:22 by apissier          #+#    #+#             */
/*   Updated: 2016/12/08 17:11:23 by apissier         ###   ########.fr       */
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

static  int     valid_shape(char *t)
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
        if (t[i] == '#')
        {
            n += (i <= 14 ? t[i + 5] == '#' : 0) + \
                (i >= 5 ? t[i - 5] == '#' : 0) + \
                (i >= 1 ? t[i - 1] == '#' : 0) + \
                (i <= 18 ? t[i + 1] == '#' : 0);
            if (n == 0)
                return (0);
        }
        i++;
        total += n;
    }
    return (total);
}

/*
** Tells if a tetromino is valid or not
*/
int             ft_isvalid(char *t)
{
    return ( \
		ft_strlen(t) == 20      && \
            t[4] ==     '\n'        && \
            t[9] ==     '\n'        && \
            t[14] ==    '\n'        && \
            t[19] ==    '\n'        && \
		n_char(t, '\n') == 4    && \
		n_char(t, '#')  == 4    && \
		valid_shape(t)  >= 6    );
}
