/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 23:31:53 by vkovsh            #+#    #+#             */
/*   Updated: 2017/11/28 14:15:55 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*fresh_square(int width)
{
	int		i;
	int		sz;
	char	*out;

	i = 1;
	sz = (width + 1) * width;
	out = ft_strnew(sz);
	while (i <= sz)
		if (i % (width + 1))
			out[i++ - 1] = '.';
		else
			out[i++ - 1] = '\n';
	return (out);
}
