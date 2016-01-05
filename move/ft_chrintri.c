/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrintri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 16:01:22 by jleu              #+#    #+#             */
/*   Updated: 2016/01/05 01:15:41 by mfleuria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_chrintri(int *tab, int i, size_t endtab)
{
	if (!tab)
		return (0);
	while (endtab > 0)
	{
		if (tab[endtab] < i && tab[endtab] != 0)
			return (endtab);
		endtab--;
	}
	return (endtab);
}
