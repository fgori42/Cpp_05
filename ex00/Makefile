SRC = ./src/
INCLUDE = ./include

file = $(addprefix $(SRC), main.cpp Bureaucrat.cpp)

NAME = Polymorphism

cc = c++
flag = -Wall -Wextra -Werror -std=c++98 -g
fileobj = $(file:.c = .o)
all : $(NAME)

$(NAME) : $(fileobj)
			$(cc) $(flag) -I$(INCLUDE) $(fileobj) -o $(NAME)
%.o: %.c 
	$(cc) $(flag) -I$(INCLUDE) -c $< -o $@

clean:
			@echo "nothing to clean"
fclean:
			rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re