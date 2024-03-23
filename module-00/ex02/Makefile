CC=c++
FLAGS=-Wall -Wextra -Werror -std=c++98
SRC=tests.cpp Account.cpp
NAME=account

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: clean $(NAME)
