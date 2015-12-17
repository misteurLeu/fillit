/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtrack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 20:11:22 by jleu              #+#    #+#             */
/*   Updated: 2015/12/13 16:58:40 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int endbt(char *values, size_t nb_p)
{
	int isnull;

	isnull = 1;
	while (nb_p > 0 && isnull)
	{
		isnull = (values[nb_p - 1] == 0);
		nb_p--;
	}
	return (isnull);
}

static int ft_rec_backtrack(char *values, char *p, char *sqr, size_t nb_p, size_t sqr_s)
{
	int cpt;

	cpt = 0;
	ft_putendl(sqr);
	while (cpt < nb_p)
	{
		while (cpt < nb_p && values[cpt] == 0)
			cpt++;
		if (cpt < nb_p && ft_setpiece(p, sqr, values[cpt], sqr_s))
		{
			values[cpt] = 0;
			if (!ft_rec_backtrack(values, p, sqr, nb_p, sqr_s))
			{
				if (ft_comptetri(p, cpt + 1, cpt + 2))
					return (0);
				ft_removepiece(sqr, cpt + 1);
				values[cpt] = cpt + 1;
			}
			else
				return (1);
		}
		cpt++;
	}
	return (endbt(values, nb_p));
}

int	ft_backtrack(char *sqr, char *p, size_t sqr_s, size_t nb_p)
{
	char *tab1;
	int cpt;

	if (!(tab1 = (char*)malloc(sizeof(char) * nb_p)))
		return (0);
	cpt = 0;
	while (cpt < nb_p )
	{
		tab1[cpt] = cpt + 1;
		cpt++;
	}
	cpt = ft_rec_backtrack(tab1, p, sqr, nb_p, sqr_s);
	free(tab1);
	return (cpt);
}
