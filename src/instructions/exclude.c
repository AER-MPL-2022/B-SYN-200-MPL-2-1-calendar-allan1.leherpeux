/*
** EPITECH PROJECT, 2023
** B-SYN-200-MPL-2-1-calendar-allan1.leherpeux
** File description:
** exclude.c
*/

#include "instructions.h"
#include "tools.h"

void exclude(calendar_t *calendar, char *line)
{
    char **array = str_to_word_array(line);
    int len = get_array_len(array);

    if (len < 3) {
        fprintf(stderr, "Invalid arguments\n");
        return;
    }

    meeting_t *meeting = get_meeting_by_id(calendar->meetings, atoi(array[1]));

    if (meeting == NULL) {
        fprintf(stderr, "Meeting not found\n");
        return;
    }

    for (int i = 2; i < len; i++) {
        employee_t *employee = get_employee_by_id(calendar->employees, atoi(array[i]));

        if (employee == NULL) {
            printf("Employee not found\n");
            return;
        }

        remove_employee_by_id(meeting, employee->id);
    }
}