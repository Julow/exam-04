/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 10:42:23 by exam              #+#    #+#             */
/*   Updated: 2015/03/11 11:04:53 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ord_alphlong.h"
#include <unistd.h>
#include <stdlib.h>

static int		ft_strlen(const char *str)
{
	int				len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

static int		print_len(t_ord *ord, int len)
{
	int				i;
	int				first;

	first = 1;
	i = -1;
	while (++i < ord->word_count)
	{
		if (ord->words[i] == NULL)
			continue ;
		if (ft_strlen(ord->words[i]) == len)
		{
			if (first == 0)
				write(1, " ", 1);
			write(1, ord->words[i], len);
			free(ord->words[i]);
			ord->words[i] = NULL;
			first = 0;
		}
	}
	return (!first);
}

void			print_ord(t_ord *ord)
{
	int				len;

	len = 0;
	while (++len <= ord->max_len)
	{
		if (print_len(ord, len))
			write(1, "\n", 1);
	}
	free(ord->words);
}
