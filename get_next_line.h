/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 12:04:47 by yazhu             #+#    #+#             */
/*   Updated: 2018/01/30 18:16:12 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32

# include "libft/libft.h"

typedef struct	s_struct
{
	char		*buf;
	int			i;
	int			line;
	int			end;
}				t_struct;

int				get_next_line(const int fd, char **line);
#endif
