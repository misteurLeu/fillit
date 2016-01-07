/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 18:09:32 by jleu              #+#    #+#             */
/*   Updated: 2016/01/07 18:18:36 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**		size_file	= size[0]
**		sqr_size	= size[1]
*/

/*
**		sqr			= q[0]
**		pieces		= q[1]
*/

int			main(int argc, char **argv)
{
	size_t	size[2];
	char	*q[2];

	if (((size[0] = ft_fichier_valid(argv[1])) == 0 || argc != 2)
			&& write(1, "error\n", 7))
		return (0);
	size[1] = ft_get_sqrsize(size[0]);
	q[0] = ft_gen_square(size[1]);
	q[1] = ft_getpieces(size[0], argv[1]);
	size[0] = (size[0] + 1) / 21;
	while (!ft_backtrack(q, size))
	{
		size[1]++;
		free(q[0]);
		q[0] = ft_gen_square(size[1]);
	}
	if (q[1][0] != '0')
		ft_putstr(q[0]);
	else
		ft_putendl("error");
	free(q[0]);
	free(q[1]);
	return (0);
}
