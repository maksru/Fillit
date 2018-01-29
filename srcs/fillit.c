/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 13:42:46 by vkovsh            #+#    #+#             */
/*   Updated: 2017/11/28 14:49:53 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetramino.h"
#include "libft.h"

int			main(int ac, char **av)
{
	int		tetras;

	if (ac == 2)
		ft_putstr(solve(ft_tetramino(av[1], &tetras), tetras));
	else
		force_error(BAD_USAGE);
	return (0);
}
