CC       = g++

SRC      = 	main.cpp		\
			window.cpp		\
			widget.cpp

CFLAGS   = -Wall -Wextra -std=c++20 -I/usr/include/SFML -I.

LDFLAGS  = -lsfml-graphics -lsfml-window -lsfml-system

NAME     = pdfgen

OBJ      = $(SRC:.cpp=.o)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
