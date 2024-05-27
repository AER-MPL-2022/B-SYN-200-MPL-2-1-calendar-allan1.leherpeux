/*
** EPITECH PROJECT, 2023
** B-SYN-200-MPL-2-1-calendar-allan1.leherpeux
** File description:
** get_instruction.c
*/

#include "instructions.h"

void get_instruction(calendar_t *calendar, char *line)
{
    if (strncmp(line, "new_employee", 11) == 0)
        calendar->current_instruction = NEW_EMPLOYEE;
    else if (strncmp(line, "new_meeting", 10) == 0)
        calendar->current_instruction = NEW_MEETING;
    else if (strncmp(line, "invite", 6) == 0)
        calendar->current_instruction = INVITE;
    else if (strncmp(line, "exclude", 7) == 0)
        calendar->current_instruction = EXCLUDE;
    else if (strncmp(line, "info_employees", 14) == 0) {
        calendar->current_instruction = INFO_EMPLOYEES;
    }
    else if (strncmp(line, "info_meetings", 13) == 0)
        calendar->current_instruction = INFO_MEETINGS;
    else if (strncmp(line, "cancel", 6) == 0)
        calendar->current_instruction = CANCEL;
    else if (strncmp(line, "fire", 4) == 0)
        calendar->current_instruction = FIRE;
    else if (strncmp(line, "END", 3) == 0)
        calendar->current_instruction = END;
    else
        calendar->current_instruction = -1;
}