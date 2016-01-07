/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 15:26:11 by jleu              #+#    #+#             */
/*   Updated: 2016/01/07 14:56:25 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

# define BUF_SIZE 21
# define NB_TEST_MAX 1500000000

int		ft_fichier_valid(char *file_name);
char	*gen_square(size_t size);
size_t	get_sqrsize(size_t file_size);
int		ft_removepiece(char *tab, int nb);
int		ft_setpiece(char *q[2], size_t num, size_t ss);
char	*ft_getpieces(size_t size_file, char *filename);
int		ft_backtrack(char *q[2], size_t size[2]);
int		ft_comptetri(char *p, int elem1, int elem2);
void	ft_resetpiece(char *p);

#endif
