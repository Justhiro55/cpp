NAME = a.out
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp \
	  Animal.cpp \
	  Dog.cpp \
	  Cat.cpp \
	  WrongAnimal.cpp \
	  WrongCat.cpp
	  

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

all: directory $(NAME)

directory:
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.cpp
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@printf "\e[38;5;82m\n  ${NAME} Compiled🚀\e[0m\n\n"

clean:
	@rm -f $(OBJ)
	@rmdir $(OBJ_DIR) 2> /dev/null || true

fclean: clean
	@rm -f $(NAME)
	@printf "\e[38;5;208m\n  successfully deleted🗑\e[0m\n\n"

re: fclean all

.PHONY: all clean fclean re help

