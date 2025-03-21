# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/19 10:04:29 by Xifeng            #+#    #+#              #
#    Updated: 2025/03/21 21:53:35 by Xifeng           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ClapTrap.cpp ScavTrap.cpp FragTrap.cpp main.cpp 
OBJS = ClapTrap.o ScavTrap.o FragTrap.o main.o
NAME = ft
CPPFLAGS = -Wall -Wextra -Werror -std=c++11

all: $(NAME)

$(NAME): $(OBJS)
	c++ -o $@ $^ $(CPPFLAGS)

%.o: %.cpp ClapTrap.hpp ScavTrap.hpp FragTrap.hpp
	c++ -c $< $(CPPFLAGS)

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(OBJS) $(NAME)

re: fclean all

.PHONY: all clean fclean re
