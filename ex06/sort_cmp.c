/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_cmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 10:27:08 by exam              #+#    #+#             */
/*   Updated: 2015/03/11 10:37:01 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ord_alphlong.h"

int				alphacmp(const char *s1, const char *s2)
{
	int				i;

	i = 0;
	while (LOWER(s1[i]) == LOWER(s2[i]) && s2[i] != '\0')
		i++;
	if (LOWER(s1[i] != LOWER(s2[i])))
		return (LOWER(s1[i]) - LOWER(s2[i]));
	return (0);
}

int				longcmp(const char *s1, const char *s2)
{
	int				i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}
