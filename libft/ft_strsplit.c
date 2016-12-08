/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamicel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:47:38 by pamicel           #+#    #+#             */
/*   Updated: 2016/11/16 14:50:39 by pamicel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_n_words(char const *str, char separator)
{
	int n_words;

	n_words = 0;
	while (*str)
	{
		while (*str == separator)
			str++;
		n_words += (*str != 0);
		while (*str && *str != separator)
			str++;
	}
	return (n_words);
}

static void		ft_fill_tab(char **tab, char const *str, int n_words, char sep)
{
	char	*ptr_start;
	char	*ptr_end;
	int		index;

	ptr_start = (char*)str;
	ptr_end = (char*)str;
	index = 0;
	while (index < n_words)
	{
		while (*ptr_start == sep)
			ptr_start++;
		ptr_end = ptr_start;
		while (*ptr_end && *ptr_end != sep)
			ptr_end++;
		tab[index++] = ft_strsub(ptr_start, 0, ptr_end - ptr_start);
		ptr_start = ptr_end;
	}
}

char			**ft_strsplit(char const *str, char separator)
{
	int		n_words;
	char	**word_tab;

	if (!str)
		return (NULL);
	n_words = ft_n_words(str, separator);
	if ((word_tab = ft_memalloc(sizeof(char*) * n_words + 1)) == NULL)
		return (NULL);
	ft_fill_tab(word_tab, str, n_words, separator);
	word_tab[n_words] = NULL;
	return (word_tab);
}
