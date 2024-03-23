CC=c++
FLAGS=-Wall -Wextra -Werror -std=c++98
SRC=main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
NAME=civilwar

all: $(NAME)

$(NAME) : $(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: clean $(NAME)
