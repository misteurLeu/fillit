/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 17:04:57 by jleu              #+#    #+#             */
/*   Updated: 2015/12/12 22:48:58 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	size_t	size_file;
	size_t	sqr_size;
	char	*sqr;
	char *pieces;

	if (argc == 2)
	{
		size_file = ft_fichier_valid(argv[1]);
		if (size_file == 0)
		{
			ft_putendl("error");
			return (0);
		}
		sqr_size = get_sqrsize(size_file);
		sqr = gen_square(sqr_size);
		pieces = ft_getpieces(size_file, argv[1]);
		while(!ft_backtrack(sqr, pieces, sqr_size, (size_file + 1) / 21))
		{
			sqr_size++;
			free(sqr);
			sqr = gen_square(sqr_size);
		}
		if (pieces[0] != '0')
			ft_putstr(sqr);
		else
			ft_putendl("error");
		free(sqr);
		free(pieces);
		return (0);
	}
	ft_putendl("error");
	return (0);
}
