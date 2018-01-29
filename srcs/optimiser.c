/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimiser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 12:58:23 by vkovsh            #+#    #+#             */
/*   Updated: 2017/11/28 15:23:58 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MAX(x, y) ((x > y) ? x : y)
#define MIN(x, y) ((x < y) ? x : y)
#define ABS(x) ((x < 0) ? -x : x)

static int	ft_sqrt(int nbr)
{
	int		res;

	res = 1;
	while (res * res < nbr)
		res++;
	return (res);
}

static void	init_val(int *min_w, int *min_h, int *max_w, int *max_h)
{
	*min_w = 4;
	*min_h = 4;
	*max_w = 1;
	*max_h = 1;
}

static int	base_width(char **t, int nbr)
{
	if (nbr == 1)
		return (MAX(t[0][8], t[0][9]));
	return (MAX(MAX(t[1][8], t[1][9]), MAX(t[0][8], t[0][9])));
}

int			init_width(char **t, int nbr)
{
	int		min_w;
	int		min_h;
	int		max_w;
	int		max_h;
	int		i;

	if (nbr <= 2)
		return (base_width(t, nbr));
	if (nbr > 16)
	{
		init_val(&min_w, &min_h, &max_w, &max_h);
		i = 0;
		while (i++ < nbr)
		{
			min_w = MIN(min_w, t[i - 1][8]);
			min_h = MIN(min_h, t[i - 1][9]);
			max_w = MAX(max_w, t[i - 1][8]);
			max_h = MAX(max_h, t[i - 1][9]);
		}
		if (nbr <= 20 || nbr == 26)
			return (ft_sqrt(nbr * 4) + ABS(ABS(min_w - min_h)
						- ABS(max_w - max_h) + ((min_w == max_w) ? 1 : 0)));
	}
	return (ft_sqrt(nbr * 4));
}
