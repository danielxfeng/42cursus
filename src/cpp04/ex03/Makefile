# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/19 10:04:29 by Xifeng            #+#    #+#              #
#    Updated: 2025/03/31 14:11:12 by Xifeng           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = AMateria.cpp Character.cpp Cure.cpp Ice.cpp ICharacter.cpp MateriaSource.cpp main.cpp
OBJS = AMateria.o Character.o Cure.o Ice.o ICharacter.o MateriaSource.o main.o
NAME = idk
CPPFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	c++ -o $@ $^ $(CPPFLAGS)

%.o: %.cpp AMateria.hpp Character.hpp Cure.hpp Ice.hpp ICharacter.hpp ImateriaSource.hpp MateriaSource.hpp
	c++ -c $< $(CPPFLAGS)

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(OBJS) $(NAME)

re: fclean all

.PHONY: all clean fclean re
