# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 19:29:06 by Xifeng            #+#    #+#              #
#    Updated: 2024/12/09 20:29:33 by Xifeng           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = getnextline.a
CC = cc
LIBC = ar rcs
FLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = get_next_line.c get_next_line_utils.c

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

