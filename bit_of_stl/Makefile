NAME=ex
SRC= \
tests/main.cpp \
tests/list.cpp \
tests/Map.cpp \
tests/queue.cpp \
tests/stack.cpp \
tests/vector.cpp \

HPP= \
List.hpp \
Map.hpp \
Queue.hpp \
Stack.hpp \
tests/tests.hpp \
Utils.hpp \
Vector.hpp

CC= clang++
OBJ=$(SRC:.cpp=.o)
FLAGS= -g -I . -Wall -Wextra  # -Werror 

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
