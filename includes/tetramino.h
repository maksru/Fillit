/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetramino.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 14:37:36 by vkovsh            #+#    #+#             */
/*   Updated: 2017/11/28 16:04:25 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRAMINO_H
# define TETRAMINO_H
# include "error.h"
# define T_SIZE 11

char	*ft_readfile(const char *filename);
char	**ft_tetramino(const char *filename, int *tetras);
char	*solve(char **tetramino, int tetras);
char	*fresh_square(int width);
void	x_iter(char *s, int iter);
void	y_iter(char *s, int iter);
int		set_value(char *out, char *t, int wd);
int		reset_value(char *out, char *t, int wd);
int		check_position(char *t, char *out, int wd);
void	toleft(char *t);
void	totopleft(char *t);
int		init_width(char **t, int nbr);
#endif
