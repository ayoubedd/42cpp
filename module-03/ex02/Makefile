CC=c++
FLAGS=-Wall -Wextra -Werror -std=c++98
SRC=main.cpp FragTrap.cpp ClapTrap.cpp
NAME=fragtrap

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: clean $(NAME)

.PHONY: all clean fclean re
