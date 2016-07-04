# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnieto-m <lnieto-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/28 14:44:05 by lnieto-m          #+#    #+#              #
#    Updated: 2016/01/05 18:43:24 by lnieto-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

CFLAGS = -Wall -Wextra -Werror

LFLAGS = -lmlx -framework OpenGl -framework AppKit -lm

NAME = fdf

SRC_NAME = draw_segment.c \
		   draw_segment_2.c \
		   draw_segment_3.c \
		   draw_segment_4.c \
		   expose_hook.c \
		   key_p.c \
		   key_r.c \
		   ft_splitint.c \
		   ft_add_end_list.c \
		   vertical_draw.c \
		   horizontal_draw.c \
		   image_pixel_put.c \
		   ft_delete_lst.c \
		   ft_error_len.c \
		   ft_empty_map.c \
		   main.c \

OBJ_NAME = $(SRC_NAME:.c=.o)

LIBFT_PATH = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ_NAME)
	make -C libft/
	$(CC) $(LIBFT_PATH) $(OBJ_NAME) -o $(NAME) -L/usr/local/lib/ $(LFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -I./usr/local/include -I./libft/includes -c $<

clean:
	make -C libft/ clean
	rm -rf $(OBJ_NAME)

fclean: clean
	make -C libft/ fclean
	rm -rf $(NAME)

re: fclean all

norme:
	@echo "* Norme fdf"
	norminette $(SRC_NAME)
	@echo "* Norme Libft"
	make -C libft/ norme

.PHONY: clean fclean re all
