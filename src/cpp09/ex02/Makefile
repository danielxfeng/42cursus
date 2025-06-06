SRCS = PmergeMe.cpp main.cpp
OBJS = PmergeMe.o main.o
NAME = pmergeme
CPPFLAGS = -Wall -Wextra -Werror -std=c++20

all: $(NAME)

$(NAME): $(OBJS)
	c++ -o $@ $^ $(CPPFLAGS)

%.o: %.cpp PmergeMe.hpp
	c++ -c $< $(CPPFLAGS)

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(OBJS) $(NAME)

re: fclean all

.PHONY: all clean fclean re
