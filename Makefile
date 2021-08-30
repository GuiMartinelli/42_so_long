# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/26 15:03:46 by guferrei          #+#    #+#              #
#    Updated: 2021/08/26 19:03:42 by guferrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

FLAGS = -Wall -Wextra -Werror

MINILIBX = -Imlx -lX11 -lXext

LIBS = $(LIBFT) mlx/libmlx_Linux.a

LIBFT = libft/libft.a

FILES = get_position.c interaction.c key_input.c load_sprites.c \
		make_map.c map_read.c print_sprites.c so_long_utils.c so_long.c

all: $(NAME)

bonus: $(NAME)

$(NAME): $(LIBS) $(FILES)
	gcc $(FLAGS) $(FILES) $(LIBS) $(MINILIBX) -o $(NAME)

$(LIBS):
	make -C libft
	make clean -C libft

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)

norma:
	norminette $(FILES)

re: fclean all



