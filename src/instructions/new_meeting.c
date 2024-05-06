/*
** EPITECH PROJECT, 2023
** B-SYN-200-MPL-2-1-calendar-allan1.leherpeux
** File description:
** new_meeting.c
*/

#include "instructions.h"
#include "tools.h"

void new_meeting(calendar_t *calendar, char *line)
{
    char **array = str_to_word_array(line);
    meeting_t *meeting = malloc(sizeof(meeting_t));
    employee_t *tmp;
    int len = get_array_len(array);

    if (len < 4) {
        printf("Invalid arguments\n");
        free(meeting);
        return;
    }

    meeting->zip_code = strdup(array[1]);
    //TODO: Error handling date
    meeting->date = strdup(array[2]);
    meeting->id = atoi(array[3]);

    for (int i = 4; i < len; i++) {
        tmp = get_employee_by_id(calendar->employees, atoi(array[i]));
        push_back(&meeting->employees, tmp);
    }

    push_back(&calendar->meetings, meeting);
}

void display_meeting(meeting_t *meeting)
{
    printf("Meeting %d: %s | Date: %s\n", meeting->id, meeting->zip_code, meeting->date);
    for (list_t *tmp = meeting->employees; tmp != NULL; tmp = tmp->next) {
        display_employee(tmp->data);
    }
}