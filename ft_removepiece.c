/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_removepiece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 18:13:01 by jleu              #+#    #+#             */
/*   Updated: 2016/01/07 18:13:10 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_removepiece(char *tab, int nb)
{
	int		i;
	int		nb_block;

	nb_block = 0;
	i = -1;
	nb = nb + 'A' - 1;
	while (tab[++i])
	{
		if (tab[i] == (char)nb)
		{
			nb_block++;
			tab[i] = '.';
		}
	}
	if (nb_block == 4)
		return (1);
	if (nb_block < 4)
		return (-1);
	if (nb_block > 4)
		return (-2);
	return (-5);
}
