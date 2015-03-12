/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_island.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 09:25:13 by exam              #+#    #+#             */
/*   Updated: 2015/03/11 10:02:27 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "island.h"

int				check_island(t_island *island)
{
	int				i;
	int				last_line;

	while (island->map[island->line_len] != '\n'
			&& island->map[island->line_len] != '\0')
		island->line_len++;
	if (island->line_len > MAX_LINE_LEN || island->line_len <= 0)
		return (0);
	i = -1;
	last_line = 0;
	while (++i < island->map_len)
	{
		if (island->map[i] == '\n')
		{
			if ((i - last_line) != island->line_len)
				return (0);
			last_line = i + 1;
		}
		else if (island->map[i] != CHAR_VOID && island->map[i] != CHAR_ISLAND)
			return (0);
	}
	if (i != last_line && (i - last_line) != island->line_len)
		return (0);
	return (1);
}
