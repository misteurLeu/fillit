/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setpiece.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 14:12:59 by jleu              #+#    #+#             */
/*   Updated: 2016/01/04 16:03:37 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_cansetpiece(char *p, size_t pp, char *s, size_t ps, size_t ss)
{
	int size;

	size = 1;
	if (p[pp] == '#' && s[ps] == '.')
	{
		p[pp] = 'A';
		if (p[pp + 1] == '#' && s[ps + 1] == '.')
			size += ft_cansetpiece(p, pp + 1, s, ps + 1, ss);
		if ((pp + 1) % 21 < 15 && ps < ss * ss && p[pp + 5] == '#' && s[ps] == '.')
			size += ft_cansetpiece(p, pp + 5, s, ps + ss + 1, ss);
		if (pp > 0 && p[pp - 1] == '#' && ps > 0 && s[ps - 1] == '.')
			size += ft_cansetpiece(p, pp - 1, s, ps - 1, ss);
		return (size);
	}
	return (0);
}

static void	ft_set_p(char *p, size_t pp, char *s, size_t ps, size_t ss)
{
	if (p[pp] == '#' && s[ps] == '.')
	{
		p[pp] = '.';
		s[ps] = '#';
		if (p[pp + 1] == '#')
			ft_set_p(p, pp + 1, s, ps + 1, ss);
		if ((pp + 1) % 21 < 15 && p[pp + 5] == '#')
			ft_set_p(p, pp + 5, s, ps + ss + 1, ss);
		if (pp > 0 && p[pp - 1] == '#')
			ft_set_p(p, pp - 1, s, ps - 1, ss);
		p[pp] = '#';
	}
}

static void ft_setletter(char *s, size_t l)
{
	while (*s)
	{
		if (*s == '#')
			*s = (l - 1) + 'A';
		s++;
	}
}

int	ft_setpiece(char *piece, char *sqr, size_t num, size_t ss)
{
	size_t cptp;
	size_t cpts;

	if (!piece || !sqr || num > 26)
		return 0;
	cptp = (num - 1) * 21;
	cpts = 0;
	while (piece[cptp] != '#')
		cptp++;
	while (sqr[cpts] && sqr[cpts] != '.')
		cpts++;
	while (sqr[cpts + 4])
	{
		if (ft_cansetpiece(piece, cptp, sqr, cpts, ss) == 4)
		{
			ft_resetPiece(piece);
			ft_set_p(piece, cptp, sqr, cpts, ss);
			ft_setletter(sqr, num);
			return(1);
		}
		ft_resetPiece(piece);
		cpts++;
		while (sqr[cpts] && sqr[cpts] != '.')
			cpts++;
	}
	return (0);
}
