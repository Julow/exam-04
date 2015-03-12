/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 09:05:28 by exam              #+#    #+#             */
/*   Updated: 2015/03/11 10:02:59 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "island.h"
#include <unistd.h>
#include <stdlib.h>

static void		print_island(t_island *island)
{
	write(1, island->map, island->map_len);
	if (island->map[island->map_len - 1] != '\n')
		write(1, "\n", 1);
}

int				main(int argc, char **argv)
{
	t_island		island;

	island = (t_island){NULL, 0, 0, 0};
	if (argc > 1 && read_island(&island, argv[1]) && check_island(&island)
			&& count_island(&island))
		print_island(&island);
	else
		write(1, "\n", 1);
	if (island.map != NULL)
		free(island.map);
	return (0);
}
