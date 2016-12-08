/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 14:06:33 by apissier          #+#    #+#             */
/*   Updated: 2016/12/08 14:09:49 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int         ft_isvalid(char *str)
{
  int i;
  int tetri;
  int point;

  i = 0;
  tetri = 0;
  point = 0;
  while (i < 20)
	{
    if (str[i] == '#')
			tetri++;
    if (str[i] == '.')
			point++;
		if (str[i] != '#' || str[i] != '.' || str[i] != '\n')
			return (0);
	}
  if (tetri == 4 && point == 12)
		return (1);
  else
		return (0);
}

int         ft_connection(char *str)
{
    int i;
    int tetri;

    i = 0;
    tetri = 0;
    while (i < 20)
    {
      if (str[i] == '#')
    	{
        if ((i + 1) < 20 && str[i + 1] == '#')
  				tetri++;
        if ((i - 1) >= 0 && str[i - 1] == '#')
  				tetri++;
        if ((i + 5) < 20 && str[i + 5] == '#')
  				tetri++;
        if ((i - 5) >= 0 && str[i - 5] == '#')
  				tetri++;
  		}
      i++;
    }
    if (tetri == 6 || tetri == 8)
		  return (1);
    return (0);
}
