CC=c++
FLAGS=-Wall -Wextra -Werror -std=c++98
SRC=main.cpp Harl.cpp
NAME=harlFilter

all: $(NAME)

$(NAME) : $(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: clean $(NAME)
