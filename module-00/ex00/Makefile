CC=c++
FLAGS=-Wall -Wextra -Werror -std=c++98
SRC=megaphone.cpp
NAME=megaphone

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: clean $(NAME)
