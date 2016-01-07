/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtrack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 20:11:22 by jleu              #+#    #+#             */
/*   Updated: 2016/01/05 16:04:54 by mfleuria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int			endbt(char *values, size_t nb_p)
{
	int				isnull;

	isnull = 1;
	while (nb_p > 0 && isnull)
	{
		isnull = (values[nb_p - 1] < 0);
		nb_p--;
	}
	return (isnull);
}

/*
**		nb_p 	= s[0]
**		sqr_s	= s[1]
*/

/*
**		sqr		= q[0]
**		p		= q[1]
*/

static int			ft_rec_backtrack(char *values, char *q[2], size_t s[2])
{
	size_t			cpt;
	static size_t	end = 0;
	size_t			lasttetri;

	cpt = 0;
	while (cpt < s[0] && end < NB_TEST_MAX)
	{
		while (cpt < s[0] && values[cpt] < 0)
			cpt++;
		if (cpt < s[0] && ft_setpiece(q, cpt + 1, s[1]))
		{
			values[cpt] = -values[cpt];
			if (ft_rec_backtrack(values, q, s) == 0 &&
					ft_removepiece(q[0], cpt + 1))
				values[cpt] = -values[cpt];
			else
				return (end < NB_TEST_MAX ? 1 : -1);
		}
		lasttetri = cpt++;
		while (cpt < s[0] && (values[cpt] < 0 ||
				values[cpt] == values[lasttetri]))
			cpt++;
		end++;
	}
	return (end >= NB_TEST_MAX ? -1 : endbt(values, s[0]));
}

static char			*type_pieces(char *p, size_t nb_p)
{
	char			*types;
	int				cpt;
	int				cpt2;
	int				cpt3;

	if (!(types = (char*)malloc(sizeof(char) * nb_p)))
		return (0);
	cpt2 = 0;
	cpt3 = 0;
	while ((size_t)cpt2 < nb_p)
	{
		cpt = 0;
		while (cpt < cpt2 && !ft_comptetri(p, cpt + 1, cpt2 + 1))
			cpt++;
		if (cpt == cpt2)
		{
			cpt3++;
			types[cpt2] = cpt3;
		}
		else
			types[cpt2] = cpt + 1;
		cpt2++;
	}
	return (types);
}

/*
**		nb_p 	= size[0]
**		sqr_s	= size[1]
*/

/*
**		sqr		= q[0]
**		p		= q[1]
*/

int					ft_backtrack(char *q[2], size_t size[2])
{
	char			*tab1;
	int				success;

	if (!(tab1 = type_pieces(q[1], size[0])))
		return (0);
	success = ft_rec_backtrack(tab1, q, size);
	free(tab1);
	if (success == -1)
	{
		q[1][0] = '0';
		return (1);
	}
	return (success);
}
