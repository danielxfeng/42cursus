SRCS = BitcoinExchange.cpp main.cpp
OBJS = BitcoinExchange.o main.o
NAME = btc
CPPFLAGS = -Wall -Wextra -Werror -std=c++20

all: $(NAME)

$(NAME): $(OBJS)
	c++ -o $@ $^ $(CPPFLAGS)

%.o: %.cpp BitcoinExchange.hpp
	c++ -c $< $(CPPFLAGS)

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(OBJS) $(NAME)

re: fclean all

.PHONY: all clean fclean re
