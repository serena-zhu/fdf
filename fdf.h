/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 15:45:10 by yazhu             #+#    #+#             */
/*   Updated: 2018/02/01 15:23:43 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <fcntl.h> 
# include "get_next_line.h"
# include "libft/libft.h"
# include "minilibx/minilibx_macos_elcapitan/mlx.h"

typedef struct	s_data
{
	char		**map;
	int			x_max;
	int			y_max;
	int			z_max;
	int			win_size_x;
	int			win_size_y;
	double		theta;
	double		scale_factor;
	double		x0;
	double		y0;
	void		*mlx;
	void		*window;	
}				t_data;

int				close_fd_and_exit(int fd, int return_value);
int				map_errors(int errors);
int				map_file_error(char *file_name);
int				usage_error(void);
int				main(int argc, char **argv);

# endif
