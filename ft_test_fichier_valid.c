/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_fichier_valid.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleuria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 05:02:58 by mfleuria          #+#    #+#             */
/*   Updated: 2016/01/05 02:03:15 by mfleuria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		rec_valid_bloc(char *t, int c)
{
	int			size;

	size = 1;
	if (t[c] == '#')
	{
		t[c] = '.';
		if (t[c + 1] == '#')
			size += rec_valid_bloc(t, c + 1);
		if (c < 14 && t[c + 5] == '#')
			size += rec_valid_bloc(t, c + 5);
		if (c % 5 != 0 && t[c - 1] == '#')
			size += rec_valid_bloc(t, c - 1);
		if (c > 4 && t[c - 5] == '#')
			size += rec_valid_bloc(t, c - 5);
		return (size);
	}
	return (0);
}

static int		ft_test_fichier(char *tab)
{
	int			cmp_block;
	int			cmp;

	cmp_block = 0;
	cmp = 0;
	while (tab[cmp])
	{
		while ((cmp + 1) % 5 != 0)
		{
			if (rec_valid_bloc(tab, cmp) == 4)
				cmp_block = 4;
			else if (cmp < 20 && tab[cmp] != '.')
				return (0);
			cmp++;
		}
		if (cmp < 21 && tab[cmp] != '\n')
			return (0);
		cmp++;
		if ((cmp == 20) && (tab[cmp + 1]) != '\0')
			return (0);
	}
	if (((tab[cmp] == '\0') && (cmp_block == 4)))
		return (1);
	return (0);
}

static int		ft_desoler(char *tab)
{
	free(tab);
	return (1);
}

/*
**fd		= tab[0]
**ret		= tab[1]
**cmp		= tab[2]
**endfile 	= tab[3]
*/

int				ft_fichier_valid(char *file_name)
{
	int			tab[4];
	char		*buf;

	buf = NULL;
	tab[1] = 0;
	tab[2] = 0;
	tab[3] = 0;
	buf = (char*)malloc(sizeof(char) * BUF_SIZE);
	if (((tab[0] = open(file_name, O_RDONLY)) == -1))
		return (0);
	while ((tab[1] = read(tab[0], buf, BUF_SIZE)))
	{
		if (tab[1] == BUF_SIZE - 1)
			tab[3] = 1;
		buf[BUF_SIZE] = '\0';
		if (ft_test_fichier(buf) == 0 && ft_desoler(buf))
			return (0);
		tab[2] += tab[1];
	}
	free(buf);
	if (tab[2] >= 546 || close(tab[0]) == -1 || tab[3] == 0)
		return (0);
	return (tab[2]);
}
