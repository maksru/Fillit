/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 18:26:26 by vkovsh            #+#    #+#             */
/*   Updated: 2017/11/28 14:51:50 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft.h"
#include <stdlib.h>

void	force_error(int error)
{
	if (error == BAD_USAGE)
		ft_putendl(USAGE);
	else
		ft_putendl("error");
	exit(error);
}
