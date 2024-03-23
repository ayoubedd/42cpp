CC=g++
FLAGS=-Wall -Wextra -Werror -std=c++98
SRC=main.cpp Fixed.cpp Point.cpp bsp.cpp
NAME=inout

all: $(NAME)

$(NAME) : $(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: clean $(NAME)
