/*
** EPITECH PROJECT, 2023
** B-SYN-200-MPL-2-1-calendar-allan1.leherpeux
** File description:
** main.c
*/

#include "requirements.h"
#include "calendar.h"
#include "instructions.h"

calendar_t *init_calendar(void)
{
    calendar_t *calendar = malloc(sizeof(calendar_t));

    calendar->running = true;

    return calendar;
}

void display_employees(list_t *employees)
{
    list_t *tmp = employees;

    while (tmp != NULL) {
        display_employee(tmp->data);
        tmp = tmp->next;
    }
}

void display_meetings(list_t *meetings)
{
    list_t *tmp = meetings;

    while (tmp != NULL) {
        display_meeting(tmp->data);
        tmp = tmp->next;
    }
}

int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    calendar_t *calendar = init_calendar();

    while ((read = getline(&line, &len, stdin)) != -1 && calendar->running) {
        get_instruction(calendar, line);
        switch (calendar->current_instruction)
        {
        case NEW_EMPLOYEE:
            new_employee(calendar, line);
            break;
        case NEW_MEETING:
            new_meeting(calendar, line);
            break;
        default:
            break;
        }
    }

    display_employees(calendar->employees);
    display_meetings(calendar->meetings);
    return 0;
}
