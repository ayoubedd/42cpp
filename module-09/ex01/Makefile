CC=c++
FLAGS=-Wall -Wextra -Werror -std=c++98
NAME=RPN
SRC=main.cpp RPN.cpp

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all
