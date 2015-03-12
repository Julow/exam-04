/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_island.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 09:32:50 by exam              #+#    #+#             */
/*   Updated: 2015/03/11 09:42:36 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "island.h"

static void		track_island(t_island *island, int i, char n)
{
	if (island->map[i] == CHAR_ISLAND)
	{
		island->map[i] = n;
		if (i > 0)
			track_island(island, i - 1, n);
		if (i > island->line_len)
			track_island(island, i - island->line_len - 1, n);
		if ((i + island->line_len) < island->map_len)
			track_island(island, i + island->line_len + 1, n);
		if (i < island->map_len)
			track_island(island, i + 1, n);
	}
}

int				count_island(t_island *island)
{
	int				i;
	char			n;

	i = -1;
	n = '0';
	while (++i < island->map_len)
		if (island->map[i] == CHAR_ISLAND)
		{
			if (n > '9')
				return (0);
			track_island(island, i, n);
			n++;
		}
	return (1);
}
