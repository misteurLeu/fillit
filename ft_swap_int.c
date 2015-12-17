/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleuria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 15:29:53 by mfleuria          #+#    #+#             */
/*   Updated: 2015/12/12 15:57:52 by mfleuria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_swap_int(int **dst, int **src, int pos_dst, int pos_src)
{
	int		save;

	save = *src[pos_src];
	*src[pos_src] = *dst[pos_dst];
	*dst[pos_dst] = save;
}
