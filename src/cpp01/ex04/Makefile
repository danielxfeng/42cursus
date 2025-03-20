# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/19 10:04:29 by Xifeng            #+#    #+#              #
#    Updated: 2025/03/20 16:20:26 by Xifeng           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.cpp
OBJS = main.o
NAME = sed
CPPFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	c++ -o $@ $^ $(CPPFLAGS)

%.o: %.cpp
	c++ -c $< $(CPPFLAGS)

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(OBJS) $(NAME)

re: fclean all

.PHONY: all clean fclean re
