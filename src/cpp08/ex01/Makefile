SRCS = Span.cpp main.cpp 
OBJS = Span.o main.o
NAME = span
CPPFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	c++ -o $@ $^ $(CPPFLAGS)

%.o: %.cpp Span.hpp
	c++ -c $< $(CPPFLAGS)

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(OBJS) $(NAME)

re: fclean all

.PHONY: all clean fclean re
