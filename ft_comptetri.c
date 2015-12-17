/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comptetri.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 16:10:15 by jleu              #+#    #+#             */
/*   Updated: 2015/12/13 16:42:20 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int ft_rectetriisequ(char *one, char *two, int pos1, int pos2)
{
	int size;

	size = 1;
	if(one[pos1] == '#' && two[pos2] == '#')
	{
		one[pos1] = '.';
		two[pos2] = '.';
		if(one[pos1 + 1] == '#' && two[pos2 + 1] == '#')
			size += ft_rectetriisequ(one, two, pos1 + 1, pos2 + 2);
		if ((pos1 + 1) % 21 < 15 && (pos2 + 1) % 21 < 15 && one[pos1 + 5] == '#' && two[pos2 + 5] == '#')
			size += ft_rectetriisequ(one, two, pos1 + 5, pos2 + 5);
		if (pos1 > 0 && pos2 > 0 && one[pos1 - 1] == '#' && two[pos2 - 1] == '#')
			size += ft_rectetriisequ(one, two, pos1 - 1, pos2 - 1);
		return size;
	}
	return (0);
}

int	ft_comptetri(char *p, int elem1, int elem2)
{
	char *one;
	char *two;
	int equal;
	int cpt1;
	int cpt2;

	one = ft_strdup(p + (elem1 - 1) * 21);
	two = ft_strdup(p + (elem2 - 1) * 21);
	cpt1 = 0;
	cpt2 = 0;
	while (one[cpt1] != '#')
		cpt1++;
	while (two[cpt2] != '#')
		cpt2++;
	equal = ft_rectetriisequ(one, two, cpt1, cpt2);
	free(one);
	free(two);
	return (equal == 4);
}
