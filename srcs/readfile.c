/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 15:45:49 by vkovsh            #+#    #+#             */
/*   Updated: 2017/11/28 16:47:16 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include "tetramino.h"

static int	ft_filelen(const char *filename)
{
	int		len;
	int		fd;
	char	buf[21];
	int		n;

	len = 0;
	if ((fd = open(filename, O_RDONLY)) == -1)
		return (READ_ERROR);
	while ((n = read(fd, buf, 21)) == 21)
		len += 16;
	if (n != 20)
		force_error(END_ERROR);
	if (close(fd) == -1)
		return (CLOSE_ERROR);
	return (len + 16);
}

static int	ft_check(char buf, int j)
{
	int		sq;

	sq = (j + 1) / 21;
	if (sq > 26)
		return (0);
	if (buf == '\n' && !((j + 1 - sq) % 5))
		return (1);
	if ((buf == '\n' || buf == '\0')
			&& !((j + 1) % 21))
		return (1);
	if ((buf == '#' || buf == '.')
			&& ((j + 1 - sq) % 5) > 0)
		return (1);
	return (0);
}

char		*ft_readfile(const char *filename)
{
	char	*sequence;
	char	*buf_str;
	char	buf;
	int		i;
	int		fd;

	if ((i = ft_filelen(filename)) < 0)
		force_error(i);
	if (i % 16 != 0 || !i)
		force_error(LEN_ERROR);
	if ((fd = open(filename, O_RDONLY)) == -1)
		force_error(READ_ERROR);
	sequence = ft_strnew(i);
	buf_str = sequence;
	i = 0;
	while (read(fd, &buf, 1) == 1)
	{
		if (!ft_check(buf, i++))
			force_error(SYMBOL_ERROR);
		if (buf != '\n')
			*sequence++ = buf;
	}
	if (close(fd) == -1)
		force_error(CLOSE_ERROR);
	return (buf_str);
}
