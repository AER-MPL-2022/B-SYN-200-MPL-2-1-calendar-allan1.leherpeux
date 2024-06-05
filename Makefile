##
## EPITECH PROJECT, 2023
## B-SYN-200-MPL-2-1-calendar-allan1.leherpeux
## File description:
## Makefile
##

SRC =	src/main.c \
		src/requirement.c \
		src/instructions/get_instruction.c \
		src/tools/str_to_word_array.c \
		src/instructions/new_employee.c \
		src/instructions/new_meeting.c \
		src/instructions/invite.c \
		src/instructions/exclude.c \
		src/instructions/fire.c \
		src/instructions/employee_info.c \
		src/instructions/disp_employees.c

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