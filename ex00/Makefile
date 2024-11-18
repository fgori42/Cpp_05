SRC = ./src/
INCLUDE = ./include

file = $(addprefix $(SRC), main.cpp Bureaucrat.cpp)

NAME =  bureaucrat

cc = c++
flag = -Wall -Wextra -Werror -std=c++98 -g
fileobj = $(file:.cpp=.o)
all : $(NAME)

.cpp.o:
	$(cc) $(flag) -I$(INCLUDE) -c $< -o $@
$(NAME) : $(fileobj)
			$(cc) $(flag) -I$(INCLUDE) $(fileobj) -o $(NAME)

clean:
			@echo "nothing to clean"
fclean:
			rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re