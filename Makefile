CC       = g++

SRC      = 	main.cpp				\
			window.cpp				\
			widget.cpp				\
			UI.cpp					\
			widgets/Image.cpp		\
			widgets/Text.cpp		\
			widgets/Text_edit.cpp	\
			widgets/Gif.cpp			\
			events.cpp

CFLAGS   = -Wall -Wextra -std=c++20 -I/usr/include/SFML -I. -I./widgets

LDFLAGS  = -lsfml-graphics -lsfml-window -lsfml-system -std=c++17

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
