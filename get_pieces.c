/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pieces.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 14:05:40 by jleu              #+#    #+#             */
/*   Updated: 2015/12/09 18:43:32 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*get_pieces(char *file_name, size_t size_file)
{
	char *pieces;
	int fd;

	if(!(pieces = (char*)malloc(sizeof(char) * size_file)))
		return (NULL);
	if(!(fd = open(file_name, O_RDONLY)))
		return (NULL);
	pieces[size_file] = '\0';
	return (pieces);
}
