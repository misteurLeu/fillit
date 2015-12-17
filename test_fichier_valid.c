/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fichier_valid.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleuria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 05:02:58 by mfleuria          #+#    #+#             */
/*   Updated: 2015/12/09 21:29:31 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int rec_valid_bloc(char *t, int c)
{
	int size;

	size = 1;
	if (t[c] == '#')
	{
		t[c] = '.';
		if (t[c + 1] == '#')
			size += rec_valid_bloc(t, c + 1);
		if (c < 14 && t[c + 5] == '#')
			size += rec_valid_bloc(t, c + 5);
		if (c % 5 != 0 && t[c - 1] == '#')
			size += rec_valid_bloc(t, c - 1);
		if (c > 4 && t[c - 5] == '#')
			size += rec_valid_bloc(t, c - 5);
		return (size);
	}
	return (0);
}

static int	ft_test_fichier(char *tab)
{
	int		cmp_block;
	int		cmp;

	cmp_block = 0;
	cmp = 0;
	while (tab[cmp])
	{
		while ((cmp + 1) % 5 != 0)
		{
			if (rec_valid_bloc(tab, cmp) == 4)
				cmp_block = 4;
			else if(cmp < 20 && tab[cmp] != '.')
				return (0);
			cmp++;
		}
		if (cmp < 21 && tab[cmp] != '\n')
			return (0);
		cmp++;
		if ((cmp == 20) && (tab[cmp + 1]) != '\0')
			return (0);
	}
	if (((tab[cmp] == '\0') && (cmp_block == 4)))
		return (1);
	return (0);
}

int			ft_fichier_valid(char *file_name)
{
	int		fd;
	int		ret;
	int		cmp;
	int 	endfile;
	char	*buf;

	buf = NULL;
	ret = 0;
	cmp = 0;
	endfile = 0;
	buf = (char*)malloc(sizeof(char) * BUF_SIZE);
	if (((fd = open(file_name, O_RDONLY)) == -1))
		return (0);
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		if (ret == BUF_SIZE - 1)
			endfile = 1;
		buf[BUF_SIZE] = '\0';
		if (ft_test_fichier(buf) == 0)
		{
			free(buf);
			return (0);
		}
		cmp += ret;
	}
	free(buf);
	if (cmp >= 546 || close(fd) == -1 || endfile == 0)
		return (0);
	return (cmp);
}
