/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   island.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 09:06:46 by exam              #+#    #+#             */
/*   Updated: 2015/03/11 10:01:50 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISLAND_H
# define ISLAND_H

typedef struct	s_island
{
	char			*map;
	int				map_len;
	int				line_len;
	int				island_count;
}				t_island;

# define BUFF_SIZE		5

# define MAX_LINE_LEN	1024

# define CHAR_VOID		'.'
# define CHAR_ISLAND	'X'

int				read_island(t_island *island, const char *file);
int				check_island(t_island *island);

int				count_island(t_island *island);

#endif
