# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/27 18:42:18 by Xifeng            #+#    #+#              #
#    Updated: 2024/12/05 12:42:59 by Xifeng           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap
CC := cc
LIBC = ar rcs
CFLAGS := -Wall -Wextra -Werror
RM = rm -f

# Directories
SRC_DIR := .
LIBFT_DIR := libft
FT_PRINTF_DIR := ft_printf
ASTAR_SORT_DIR := astar_sort
LESS_NUM_SORT_DIR := less_numbers_sort
STACKS_DIR := stacks

LIBFT := $(LIBFT_DIR)/libft.a
FT_PRINTF := $(FT_PRINTF_DIR)/libftprintf.a

SRC_FILES := $(SRC_DIR)/push_swap.c $(SRC_DIR)/utils.c \
             $(ASTAR_SORT_DIR)/astar_sort.c $(ASTAR_SORT_DIR)/plans.c \
             $(STACKS_DIR)/list_node.c $(STACKS_DIR)/stack_factory.c $(STACKS_DIR)/stack_methods.c \
			 $(STACKS_DIR)/stack_methods_rr.c $(STACKS_DIR)/stack_methods_sp.c $(STACKS_DIR)/stack_methods_r.c \
			 $(LESS_NUM_SORT_DIR)/less_numbers_sort.c

OBJ_FILES := $(SRC_FILES:.c=.o)

INCLUDES := -I$(SRC_DIR) -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR)

all: $(LIBFT) $(FT_PRINTF) $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBFT) $(FT_PRINTF) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean
	$(RM) $(OBJ_FILES)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
