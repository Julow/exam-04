/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ord_alphlong.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 10:10:09 by exam              #+#    #+#             */
/*   Updated: 2015/03/11 11:14:24 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ORD_ALPHLONG_H
# define ORD_ALPHLONG_H

typedef struct	s_ord
{
	char			**words;
	int				word_count;
	int				max_len;
}				t_ord;

# define LOWER(c)		(((c) >= 'A' && (c) <= 'Z') ? (c) + 32 : (c))

void			split_words(t_ord *ord, char *str);

int				alphacmp(const char *s1, const char *s2);
void			sort(t_ord *ord, int (*f)(const char *s1, const char *s2));

void			print_ord(t_ord *ord);

#endif
