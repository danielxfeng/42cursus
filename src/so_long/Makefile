# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/27 18:42:18 by Xifeng            #+#    #+#              #
#    Updated: 2024/12/03 20:09:03 by Xifeng           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAMEBONUS = so_long_bonus
CC := cc
CFLAGS := -Wall -Wextra -Werror -Wunreachable-code -Ofast -fPIC \
	-I ./include -I ./libft -I ./ft_printf -I ./mlx/include
LIBFT := ./libft
PRINTF := ./ft_printf
LIBMLX := ./mlx
HEADERS = -I $(LIBMLX)/include/mlx
LIBS := $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm \
	$(LIBFT)/libft.a $(PRINTF)/libftprintf.a

SRCS := close_resource.c factory.c game.c so_long.c utils.c validation.c view_factory.c view.c
OBJS := ${SRCS:.c=.o}
OBJSB := ${SRCSB:.c=.o}
REPO_URL=https://github.com/codam-coding-college/MLX42.git
REPO_DIR=mlx

all: clone libmlx $(NAME)

clone:
	@if [ ! -d "$(REPO_DIR)" ]; then \
		git clone $(REPO_URL) REPO_DIR; \
	else \
		echo "$(REPO_DIR) already exists."; \
	fi

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	${MAKE} -C ${LIBFT}
	${MAKE} -C ${PRINTF}
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS) $(OBJSB)
	@rm -rf $(LIBMLX)/build
	${MAKE} -C ${LIBFT} fclean
	${MAKE} -C ${PRINTF} clean

fclean: clean
	@rm -rf $(NAME) $(NAMEBONUS)

re: fclean all

.PHONY: all clean fclean re bonus clone