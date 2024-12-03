# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/27 18:42:18 by Xifeng            #+#    #+#              #
#    Updated: 2024/12/03 13:55:02 by Xifeng           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long
CC := cc
LIBC = ar rcs
CFLAGS := -Wall -Wextra -Werror
RM = rm -f

SRC_DIR := .
LIBFT_DIR := libft
FT_PRINTF_DIR := ft_printf
MINILIBX_DIR := mlx

LIBFT := $(LIBFT_DIR)/libft.a
FT_PRINTF := $(FT_PRINTF_DIR)/libftprintf.a
MINILIBX := $(MINILIBX_DIR)/libmlx.a

SRC_FILES := $(SRC_DIR)/so_long.c $(SRC_DIR)/factory.c $(SRC_DIR)/close_resource.c \
             $(SRC_DIR)/game.c $(SRC_DIR)/utils.c $(SRC_DIR)/validation.c $(SRC_DIR)/view.c \
			 $(SRC_DIR)/view_factory.c

OBJ_FILES := $(SRC_FILES:.c=.o)

INCLUDES := -I$(SRC_DIR) -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR) -I$(MINILIBX_DIR)
LDFLAGS := -L$(MINILIBX_DIR) -lmlx -lX11 -lXext -lbsd

all: $(LIBFT) $(FT_PRINTF) $(MINILIBX) $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBFT) $(FT_PRINTF) $(MINILIBX) $(LDFLAGS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(MINILIBX):
	$(MAKE) -C $(MINILIBX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean
	$(MAKE) -C $(MINILIBX_DIR) clean
	$(RM) $(OBJ_FILES)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean
	$(MAKE) -C $(MINILIBX_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
