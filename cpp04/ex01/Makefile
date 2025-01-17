NAME = Animal
SRCS = main.cpp Dog.cpp Cat.cpp Animal.cpp Brain.cpp
COMPILER = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(COMPILER) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
