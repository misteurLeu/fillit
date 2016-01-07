/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_square.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 18:16:15 by jleu              #+#    #+#             */
/*   Updated: 2016/01/07 18:16:22 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_gen_square(size_t size)
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
