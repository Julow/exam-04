/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 10:13:48 by exam              #+#    #+#             */
/*   Updated: 2015/03/11 11:15:09 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ord_alphlong.h"
#include <stdlib.h>

static int		ft_isspace(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

static void		count_words(t_ord *ord, const char *str)
{
	while (ft_isspace(*str))
		str++;
	while (*str != '\0')
	{
		ord->word_count++;
		while (!ft_isspace(*str) && *str != '\0')
			str++;
		while (ft_isspace(*str))
			str++;
	}
}

static char		*cut_word(char **dst, char *str, int *max)
{
	int				len;
	int				i;

	while (ft_isspace(*str))
		str++;
	len = 0;
	while (!ft_isspace(str[len]) && str[len] != '\0')
		len++;
	*dst = (char*)malloc(len + 1);
	i = -1;
	while (++i < len)
		(*dst)[i] = str[i];
	(*dst)[len] = '\0';
	if (len > *max)
		*max = len;
	return (str + len);
}

void			split_words(t_ord *ord, char *str)
{
	int				i;

	count_words(ord, str);
	ord->words = (char**)malloc(sizeof(char*) * (ord->word_count + 1));
	i = 0;
	while (i < ord->word_count)
	{
		str = cut_word(ord->words + i, str, &(ord->max_len));
		i++;
	}
	ord->words[i] = NULL;
}
