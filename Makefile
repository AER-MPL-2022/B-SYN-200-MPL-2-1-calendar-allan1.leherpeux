##
## EPITECH PROJECT, 2023
## B-SYN-200-MPL-2-1-calendar-allan1.leherpeux
## File description:
## Makefile
##

SRC = $(shell find src -name "*.c")
CFLAGS = -W -Wextra -Wall -g3
CPPFLAGS = -I src/include
TARGET = calendar
OBJ = $(SRC:.c=.o)

all : $(TARGET)

$(TARGET) : $(OBJ)
	$(CC) -o $(TARGET) $(OBJ) 

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(TARGET)

re : fclean all