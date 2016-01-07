/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comptetri.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 16:10:15 by jleu              #+#    #+#             */
/*   Updated: 2016/01/05 12:16:05 by mfleuria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_rectetriisequ(char *p, int pos1, int pos2)
{
	int		size;

	size = 1;
	if (p[pos1] == '#' && p[pos2] == '#')
	{
		p[pos1] = 'A';
		p[pos2] = 'A';
		if (p[pos1 + 1] == '#' && p[pos2 + 1] == '#')
			size += ft_rectetriisequ(p, pos1 + 1, pos2 + 1);
		if ((pos1 + 1) % 21 < 15 && (pos2 + 1) % 21 < 15
		&& p[pos1 + 5] == '#' && p[pos2 + 5] == '#')
			size += ft_rectetriisequ(p, pos1 + 5, pos2 + 5);
		if (pos1 > 0 && pos2 > 0 && p[pos1 - 1] == '#'
		&& p[pos2 - 1] == '#')
			size += ft_rectetriisequ(p, pos1 - 1, pos2 - 1);
		return (size);
	}
	return (0);
}

int			ft_comptetri(char *p, int elem1, int elem2)
{
	int		equal;
	int		cpt1;
	int		cpt2;

	cpt1 = (elem1 - 1) * 21;
	cpt2 = (elem2 - 1) * 21;
	while (p[cpt1] != '#')
		cpt1++;
	while (p[cpt2] != '#')
		cpt2++;
	equal = (ft_rectetriisequ(p, cpt1, cpt2) == 4);
	ft_resetpiece(p);
	return (equal);
}
