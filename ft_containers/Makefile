NAME=ex
SRC=main.cpp
HPP=List.hpp
CC= clang++
OBJ=$(SRC:.cpp=.o)
FLAGS= -I . -Wall -Wextra  # -Werror 

all: $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ) $(HPP)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ);

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(NAME);

re: fclean all
