# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/08 16:45:06 by Xifeng            #+#    #+#              #
#    Updated: 2025/01/29 16:00:55 by Xifeng           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := philo 
CC := cc
LIBC = ar rcs
CFLAGS := -Wall -Wextra -Werror
RM = rm -f

SRC_DIR := .

SRC_FILES := $(SRC_DIR)/close.c $(SRC_DIR)/factory.c $(SRC_DIR)/game.c $(SRC_DIR)/mq.c \
             $(SRC_DIR)/philo.c $(SRC_DIR)/utils.c

SRC_OBJS := $(SRC_FILES:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(SRC_OBJS)
	$(CC) $(CFLAGS) $(SRC_OBJS) -o $(NAME)

clean:
	$(RM) $(SRC_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
