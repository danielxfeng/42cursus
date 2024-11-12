# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 19:29:06 by Xifeng            #+#    #+#              #
#    Updated: 2024/11/12 13:21:49 by Xifeng           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
LIBC = ar rcs
FLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = ft_printf.c str_helper.c unsigned_helper.c ft_bzero.c ft_memset.c

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(LIBC) $@ $^

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

