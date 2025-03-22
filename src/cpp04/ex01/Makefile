# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/19 10:04:29 by Xifeng            #+#    #+#              #
#    Updated: 2025/03/22 22:43:20 by Xifeng           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp main.cpp
OBJS = Animal.o Dog.o Cat.o WrongAnimal.o WrongCat.o Brain.o main.o
NAME = animal
CPPFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	c++ -o $@ $^ $(CPPFLAGS)

%.o: %.cpp Animal.hpp Dog.hpp Cat.hpp WrongAnimal.hpp WrongCat.hpp Brain.hpp
	c++ -c $< $(CPPFLAGS)

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(OBJS) $(NAME)

re: fclean all

.PHONY: all clean fclean re
