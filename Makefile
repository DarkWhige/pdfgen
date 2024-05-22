CC       = g++

SRC      = 	main.cpp			\
			window.cpp			\
			widget.cpp			\
			UI.cpp				\
			widgets/Image.cpp	\
			widgets/Text.cpp

CFLAGS   = -Wall -Wextra -std=c++20 -I/usr/include/SFML -I. -I./widgets

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
