CC=c++
FLAGS=-Wall -Wextra -Werror -std=c++98 -Wshadow
SRC=main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
NAME=diamondtrap

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: clean $(NAME)

.PHONY: all clean fclean re
