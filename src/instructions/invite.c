/*
** EPITECH PROJECT, 2023
** B-SYN-200-MPL-2-1-calendar-allan1.leherpeux
** File description:
** invite.c
*/

#include "instructions.h"
#include "tools.h"

void invite(calendar_t *calendar, char *line)
{
    char **array = str_to_word_array(line);
    int len = get_array_len(array);

    if (len < 3) {
        printf("Invalid arguments\n");
        return;
    }

    meeting_t *meeting = get_meeting_by_id(calendar->meetings, atoi(array[1]));

    if (meeting == NULL) {
        printf("Meeting not found\n");
        return;
    }

    for (int i = 2; i < len; i++) {
        employee_t *employee = get_employee_by_id(calendar->employees, atoi(array[i]));

        if (employee == NULL) {
            printf("Employee not found\n");
            return;
        }

        for (list_t *tmp = meeting->employees; tmp != NULL; tmp = tmp->next) {
            if (tmp->data == employee) {
                printf("Employee already in the meeting\n");
                return;
            }
        }

        push_back(&meeting->employees, employee);
    }
}