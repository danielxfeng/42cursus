SRCS = SpanSlice.cpp sorting.cpp PmergeMe.cpp main.cpp
OBJS = SpanSlice.o sorting.o PmergeMe.o main.o
NAME = PmergeMe
CPPFLAGS = -Wall -Wextra -Werror -std=c++20

all: $(NAME)

$(NAME): $(OBJS)
	c++ -o $@ $^ $(CPPFLAGS)

%.o: %.cpp SpanSlice.hpp PmergeMe.hpp
	c++ -c $< $(CPPFLAGS)

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(OBJS) $(NAME)

re: fclean all

.PHONY: all clean fclean re
