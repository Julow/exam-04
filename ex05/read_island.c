/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_island.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 09:14:28 by exam              #+#    #+#             */
/*   Updated: 2015/03/11 09:51:42 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "island.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

static int		concat_island(t_island *island, const char *cat, int len)
{
	char			*tmp;
	int				i;
	int				i2;

	tmp = island->map;
	if ((island->map = malloc(1 + island->map_len + len)) == NULL)
		return (0);
	i = 0;
	if (tmp != NULL)
	{
		while (tmp[i] != '\0')
		{
			island->map[i] = tmp[i];
			i++;
		}
		free(tmp);
	}
	i2 = -1;
	while (++i2 < len)
		island->map[i + i2] = cat[i2];
	island->map[i + i2] = '\0';
	island->map_len += len;
	return (1);
}

int				read_island(t_island *island, const char *file)
{
	int				fd;
	char			buff[BUFF_SIZE];
	int				len;

	if ((fd = open(file, O_RDONLY)) < 0)
		return (0);
	while ((len = read(fd, buff, BUFF_SIZE)) > 0)
		if (!concat_island(island, buff, len))
			return (0);
	return (1);
}
