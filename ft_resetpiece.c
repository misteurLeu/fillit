/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resetpiece.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 18:14:02 by jleu              #+#    #+#             */
/*   Updated: 2016/01/07 18:14:06 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_resetpiece(char *p)
{
	while (*p)
	{
		if (*p == 'A')
			*p = '#';
		p++;
	}
}
