/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 10:32:48 by exam              #+#    #+#             */
/*   Updated: 2015/03/11 11:13:34 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ord_alphlong.h"

void			sort(t_ord *ord, int (*f)(const char *s1, const char *s2))
{
	int				i;
	char			*tmp;

	i = 0;
	while (++i < ord->word_count)
	{
		if (f(ord->words[i - 1], ord->words[i]) > 0)
		{
			tmp = ord->words[i - 1];
			ord->words[i - 1] = ord->words[i];
			ord->words[i] = tmp;
			if (i > 1)
				i--;
			if (i > 1)
				i--;
		}
	}
}
