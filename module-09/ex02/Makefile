CC=c++
FLAGS=-Wall -Wextra -Werror -std=c++98
NAME=PmergeMe
SRC=main.cpp PmergeMe.cpp

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all
