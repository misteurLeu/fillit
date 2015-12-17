/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sqrsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 12:43:36 by jleu              #+#    #+#             */
/*   Updated: 2015/12/09 13:48:48 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t	get_sqrsize(size_t file_size)
{
	size_t nbrpiece;
	size_t sqr;

	if (file_size >= 20)
	{
		sqr = 1;
		nbrpiece = (file_size + 1) / 21;
		while (sqr * sqr < nbrpiece * 4)
			sqr++;
		return (sqr);
	}
	else
		return (0);
}
