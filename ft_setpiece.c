/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setpiece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 18:14:20 by jleu              #+#    #+#             */
/*   Updated: 2016/01/07 18:14:31 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	s		= q[0]
**	p		= q[1]
*/

static int		ft_cansetpiece(char *q[2], size_t pp, size_t ps, size_t ss)
{
	int			size;

	size = 1;
	if (q[1][pp] == '#' && q[0][ps] == '.')
	{
		q[1][pp] = 'A';
		if (q[1][pp + 1] == '#' && q[0][ps + 1] == '.')
			size += ft_cansetpiece(q, pp + 1, ps + 1, ss);
		if ((pp + 1) % 21 < 15 && ps < ss * ss && q[1][pp + 5] == '#'
				&& q[0][ps] == '.')
			size += ft_cansetpiece(q, pp + 5, ps + ss + 1, ss);
		if (pp > 0 && q[1][pp - 1] == '#' && ps > 0 && q[0][ps - 1] == '.')
			size += ft_cansetpiece(q, pp - 1, ps - 1, ss);
		return (size);
	}
	return (0);
}

/*
**	s	= q[0]
**	p	= q[1]
*/

static void		ft_set_p(char *q[2], size_t pp, size_t ps, size_t ss)
{
	if (q[1][pp] == '#' && q[0][ps] == '.')
	{
		q[1][pp] = '.';
		q[0][ps] = '#';
		if (q[1][pp + 1] == '#')
			ft_set_p(q, pp + 1, ps + 1, ss);
		if ((pp + 1) % 21 < 15 && q[1][pp + 5] == '#')
			ft_set_p(q, pp + 5, ps + ss + 1, ss);
		if (pp > 0 && q[1][pp - 1] == '#')
			ft_set_p(q, pp - 1, ps - 1, ss);
		q[1][pp] = '#';
	}
}

static void		ft_setletter(char *s, size_t l)
{
	while (*s)
	{
		if (*s == '#')
			*s = (l - 1) + 'A';
		s++;
	}
}

/*
**	cptp = cpt[0]
**	cpts = cpt[1]
*/

/*
**	sqr		= q[0]
**	piece	= q[1]
*/

int				ft_setpiece(char *q[2], size_t num, size_t ss)
{
	size_t		cpt[2];

	if (!q[1] || !q[0] || num > 26)
		return (0);
	cpt[0] = (num - 1) * 21;
	cpt[1] = 0;
	while (q[1][cpt[0]] != '#')
		cpt[0]++;
	while (q[0][cpt[1]] && q[0][cpt[1]] != '.')
		cpt[1]++;
	while (q[0][cpt[1] + 4])
	{
		if (ft_cansetpiece(q, cpt[0], cpt[1], ss) == 4)
		{
			ft_resetpiece(q[1]);
			ft_set_p(q, cpt[0], cpt[1], ss);
			ft_setletter(q[0], num);
			return (1);
		}
		ft_resetpiece(q[1]);
		cpt[1]++;
		while (q[0][cpt[1]] && q[0][cpt[1]] != '.')
			cpt[1]++;
	}
	return (0);
}
