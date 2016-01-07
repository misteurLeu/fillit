/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpieces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 18:12:46 by jleu              #+#    #+#             */
/*   Updated: 2016/01/07 18:12:49 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*ft_getpieces(size_t size_file, char *filename)
{
	char	*pieces;
	int		fd;

	if (!(pieces = (char*)malloc(sizeof(char) * size_file + 1)))
		return (NULL);
	if (!(fd = open(filename, O_RDONLY)))
		return (NULL);
	read(fd, pieces, size_file);
	pieces[size_file] = '\0';
	close(fd);
	return (pieces);
}
