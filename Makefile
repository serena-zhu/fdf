# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yazhu <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/26 19:06:12 by yazhu             #+#    #+#              #
#    Updated: 2018/01/31 13:56:34 by yazhu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRCS = main.c errors.c get_next_line.c
OFILES = $(SRCS:.c=.o)

LIBFT = libft/
MLX = minilibx/minilibx_macos_sierra

LFT = -L $(LIBFT) -lft
LMLX = -L $(MLX) -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):
	make -C $(LIBFT)
	make -C $(MLX)
	gcc -Wall -Wextra -Werror $(SRCS) $(LFT) $(LMLX) -o $(NAME)

clean:
	make -C $(LIBFT) clean
	make -C $(MLX) clean
	/bin/rm -f $(OFILES)

fclean: clean
	make -C $(LIBFT) fclean
	/bin/rm -f $(NAME)

re: fclean all
