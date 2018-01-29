/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:13:15 by vkovsh            #+#    #+#             */
/*   Updated: 2017/11/28 16:02:22 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetramino.h"

static int	next(char *l, char *map, int wd)
{
	while (l[1] <= wd - 1 && l[3] <= wd - 1 && l[5] <= wd - 1 && l[7] <= wd - 1)
	{
		while (l[0] <= wd - 1 && l[2] <= wd - 1 &&
			l[4] <= wd - 1 && l[6] <= wd - 1)
		{
			x_iter(l, 1);
			if (check_position(l, map, wd))
				return (1);
		}
		y_iter(l, 1);
		toleft(l);
		if (check_position(l, map, wd))
			return (1);
	}
	return (0);
}

static void	backtrack(char **t, char **map, int *i, int *wd)
{
	totopleft(t[*i]);
	while ((*i)-- > 0)
	{
		reset_value(*map, t[*i], *wd);
		if (next(t[*i], *map, *wd))
		{
			set_value(*map, t[*i], *wd);
			break ;
		}
		else
		{
			totopleft(t[*i]);
			if (*i == 0)
				*map = fresh_square(++(*wd));
		}
	}
}

char		*solve(char **t, int nbr)
{
	char	*map;
	int		i;
	int		wd;

	wd = init_width(t, nbr);
	map = fresh_square(wd);
	i = 0;
	while (i < nbr)
	{
		while (!check_position(t[i], map, wd))
			if (!next(t[i], map, wd))
				break ;
		if (!check_position(t[i], map, wd))
			backtrack(t, &map, &i, &wd);
		if (i++ >= 0)
			set_value(map, t[i - 1], wd);
	}
	return (map);
}
