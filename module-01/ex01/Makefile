CC=c++
FLAGS=-Wall -Wextra -Werror -std=c++98
SRC=main.cpp Zombie.cpp zombieHorde.cpp
NAME=zombiehorde

all: $(NAME)

$(NAME) : $(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclen: clean

re: clean $(NAME)
