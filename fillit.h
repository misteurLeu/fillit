/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 15:26:11 by jleu              #+#    #+#             */
/*   Updated: 2015/12/12 22:25:42 by jleu             ###   ########.fr       */
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

int		ft_fichier_valid(char *file_name);
char	*gen_square(size_t size);
size_t	get_sqrsize(size_t file_size);
int		ft_removepiece(char *tab, int nb);
int		ft_setpiece(char *piece, char *sqr, size_t num, size_t ss);
char	*ft_getpieces(size_t size_file, char *filename);
int		ft_backtrack(char *sqr, char *p, size_t sqr_s, size_t nb_p);
int		ft_chrintri(int *tab, int i, size_t endtab);
void	ft_swap_int(int **dst, int **src, int pos_dst, int pos_src);
int	ft_comptetri(char *p, int elem1, int elem2);

#endif
