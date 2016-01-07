/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_sqrsize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 18:17:37 by jleu              #+#    #+#             */
/*   Updated: 2016/01/07 18:18:02 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t	ft_get_sqrsize(size_t file_size)
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
