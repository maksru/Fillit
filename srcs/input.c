/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 01:21:58 by vkovsh            #+#    #+#             */
/*   Updated: 2017/11/28 15:10:17 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	overflow(char *out, char *t, int wd)
{
	int		len;

	len = (int)ft_strlen(out);
	if (t[0] + t[1] * (wd + 1) > len ||
			t[2] + t[3] * (wd + 1) > len ||
			t[4] + t[5] * (wd + 1) > len ||
			t[6] + t[7] * (wd + 1) > len)
		return (1);
	return (0);
}

int			set_value(char *out, char *t, int wd)
{
	int		len;

	len = (int)ft_strlen(out);
	if (overflow(out, t, wd))
		return (0);
	*(out + t[0] + t[1] * (wd + 1)) = t[10];
	*(out + t[2] + t[3] * (wd + 1)) = t[10];
	*(out + t[4] + t[5] * (wd + 1)) = t[10];
	*(out + t[6] + t[7] * (wd + 1)) = t[10];
	return (1);
}

int			reset_value(char *out, char *t, int wd)
{
	int		len;

	len = (int)ft_strlen(out);
	if (overflow(out, t, wd))
		return (0);
	*(out + t[0] + t[1] * (wd + 1)) = '.';
	*(out + t[2] + t[3] * (wd + 1)) = '.';
	*(out + t[4] + t[5] * (wd + 1)) = '.';
	*(out + t[6] + t[7] * (wd + 1)) = '.';
	return (1);
}

int			check_position(char *t, char *out, int wd)
{
	if (t[8] > (int)wd || t[9] > (int)wd)
		return (0);
	if (out[t[0] + t[1] * (wd + 1)] == '.' &&
			out[t[2] + t[3] * (wd + 1)] == '.' &&
			out[t[4] + t[5] * (wd + 1)] == '.' &&
			out[t[6] + t[7] * (wd + 1)] == '.')
		return (1);
	return (0);
}
