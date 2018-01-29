/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetramino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:14:00 by vkovsh            #+#    #+#             */
/*   Updated: 2017/11/28 15:13:21 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetramino.h"
#include "libft.h"
#define MAX(x, y) ((x > y) ? x : y)

static int	is_neighbour(int a1, int a2, int b1, int b2)
{
	if ((!(a1 - b1) && (a2 - b2 == 1 || a2 - b2 == -1)) ||
			(!(a2 - b2) && (a1 - b1 == 1 || a1 - b1 == -1)))
		return (1);
	return (0);
}

static int	is_brick(char *t)
{
	if (is_neighbour(t[0], t[1], t[2], t[3]) +
		is_neighbour(t[0], t[1], t[4], t[5]) +
		is_neighbour(t[0], t[1], t[6], t[7]) +
		is_neighbour(t[2], t[3], t[0], t[1]) +
		is_neighbour(t[2], t[3], t[4], t[5]) +
		is_neighbour(t[2], t[3], t[6], t[7]) +
		is_neighbour(t[4], t[5], t[0], t[1]) +
		is_neighbour(t[4], t[5], t[2], t[3]) +
		is_neighbour(t[4], t[5], t[6], t[7]) +
		is_neighbour(t[6], t[7], t[0], t[1]) +
		is_neighbour(t[6], t[7], t[2], t[3]) +
		is_neighbour(t[6], t[7], t[4], t[5]) >= 6)
		return (1);
	return (0);
}

static void	init_value(char *t, char view)
{
	totopleft(t);
	t[8] = MAX(MAX(t[0], t[2]), MAX(t[4], t[6])) + 1;
	t[9] = MAX(MAX(t[1], t[3]), MAX(t[5], t[7])) + 1;
	t[10] = view;
}

static char	*form_tetra(char *tetra, char view)
{
	int		i;
	int		k;
	char	*t;
	int		point;

	point = 0;
	if (!(t = ft_strnew(11)))
		force_error(BAD_ALLOC);
	k = -1;
	i = 0;
	while (++k < 16)
		if (tetra[k] == '#')
			if (++point && i <= 7)
			{
				t[i++] = k % 4;
				t[i++] = k / 4;
			}
	if (point != 4)
		return (NULL);
	if (is_brick(t))
	{
		init_value(t, view);
		return (t);
	}
	return (NULL);
}

char		**ft_tetramino(const char *filename, int *tetras)
{
	char	**fs;
	char	*sequence;
	int		size;
	int		i;
	char	view;

	sequence = ft_readfile(filename);
	if ((size = (size_t)(ft_strlen(sequence) / 16)) > 26)
		force_error(BAD_SIZE);
	if (!(fs = (char **)ft_memalloc(sizeof(char *) * size)))
		force_error(BAD_ALLOC);
	i = 0;
	view = 'A';
	while (i++ < size)
		if (!(fs[i - 1] = form_tetra(sequence + (i - 1) * 16, view++)))
			force_error(BAD_BRICK);
	*tetras = size;
	return (fs);
}
