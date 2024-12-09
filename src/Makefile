# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/08 16:45:06 by Xifeng            #+#    #+#              #
#    Updated: 2024/12/09 20:32:06 by Xifeng           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := pipex
CC := cc
LIBC = ar rcs
CFLAGS := -Wall -Wextra -Werror
RM = rm -f

SRC_DIR := .
LIBFT_DIR := libft
FT_PRINTF_DIR := ft_printf
CORE_DIR := core
AST_DIR := ast
GET_NEXT_LINE_DIR := get_next_line

LIBFT := $(LIBFT_DIR)/libft.a
FT_PRINTF := $(FT_PRINTF_DIR)/libftprintf.a
GET_NEXT_LINE := $(GET_NEXT_LINE_DIR)/getnextline.a

SRC_FILES := $(CORE_DIR)/pipe_x.c $(CORE_DIR)/ast_handler.c $(CORE_DIR)/parameter_handler.c \
             $(AST_DIR)/ast_factory.c $(AST_DIR)/ast_close.c $(AST_DIR)/ast_print.c\

MENDATORY_FILES := $(SRC_FILES) $(SRC_DIR)/main.c

BONUS_FILES := $(SRC_FILES) $(SRC_DIR)/main_bonus.c

MENDATORY_OBJS := $(MENDATORY_FILES:.c=.o)

BONUS_OBJS := $(BONUS_FILES:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(LIBFT) $(FT_PRINTF) $(NAME)

$(NAME): $(MENDATORY_OBJS)
	$(CC) $(CFLAGS) $(MENDATORY_OBJS) $(LIBFT) $(FT_PRINTF) $(GET_NEXT_LINE) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

bonus: .bonus

.bonus: $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) $(FT_PRINTF) $(GET_NEXT_LINE) -o $(NAME)
	@touch .bonus

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean
	$(MAKE) -C $(GET_NEXT_LINE_DIR) clean
	$(RM) $(MANDATORY_OBJS) $(BONUS_OBJS)
	$(RM) .bonus

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean
	$(MAKE) -C $(GET_NEXT_LINE_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
