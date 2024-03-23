CC=c++
FLAGS=-Wall -Wextra -Werror -std=c++98
SRC=main.cpp Character.cpp Cure.cpp Ice.cpp AMateria.cpp MateriaSource.cpp
NAME=whaaat


all: $(NAME)
$(NAME): $(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: clean $(NAME)

.PHONY: all clean fclean re
