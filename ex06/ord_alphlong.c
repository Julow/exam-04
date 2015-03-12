/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ord_alphlong.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 10:09:36 by exam              #+#    #+#             */
/*   Updated: 2015/03/11 10:53:59 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ord_alphlong.h"
#include <stddef.h>
#include <unistd.h>

int				main(int argc, char **argv)
{
	t_ord			ord;

	ord = (t_ord){NULL, 0, 0};
	if (argc == 2)
	{
		split_words(&ord, argv[1]);
		if (ord.word_count > 0 && ord.max_len > 0)
		{
			sort(&ord, &alphacmp);
			print_ord(&ord);
			return (0);
		}
	}
	write(1, "\n", 1);
	return (0);
}
