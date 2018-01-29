/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 17:49:46 by vkovsh            #+#    #+#             */
/*   Updated: 2017/11/28 14:51:24 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H
# define USAGE "Usage: ./fillit [map.fillit]"
# define BAD_USAGE 0
# define READ_ERROR -1
# define CLOSE_ERROR -2
# define SYMBOL_ERROR -3
# define T_ERROR -4
# define BAD_SIZE -5
# define BAD_ALLOC -6
# define BAD_BRICK -7
# define LEN_ERROR -8
# define END_ERROR -9
# define EMPTY_FILE -10

void	force_error(int error);
#endif
