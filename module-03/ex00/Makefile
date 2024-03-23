CC=c++
FLAGS=-Wall -Wextra -Werror -std=c++98
SRC=main.cpp ClapTrap.cpp
NAME=claptrap

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: clean $(NAME)

.PHONY: all clean fclean re
