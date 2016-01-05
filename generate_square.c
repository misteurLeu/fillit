/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 12:21:53 by jleu              #+#    #+#             */
/*   Updated: 2016/01/05 12:31:35 by mfleuria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*gen_square(size_t size)
{
	char	*sqr;
	size_t	nbrcases;
	size_t	cpt;

	if (size == 0)
		return (NULL);
	nbrcases = (size + 1) * size + 1;
	if ((sqr = (char*)malloc(sizeof(char*) * nbrcases)))
	{
		cpt = 0;
		nbrcases--;
		sqr[nbrcases] = '\0';
		while (--nbrcases > 0)
		{
			if ((nbrcases + 1) % (size + 1) != 0)
				sqr[nbrcases] = '.';
			else
				sqr[nbrcases] = '\n';
		}
		sqr[0] = '.';
	}
	return (sqr);
}
