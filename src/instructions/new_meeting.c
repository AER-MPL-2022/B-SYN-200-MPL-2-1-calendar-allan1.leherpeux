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
        fprintf(stderr, "Invalid arguments\n");
        free(meeting);
        return;
    }

    meeting->zip_code = strdup(array[1]);
    //TODO: Error handling date
    meeting->date = strdup(array[2]);
    meeting->id = atoi(array[3]);

    for (list_t *tmp = calendar->meetings; tmp != NULL; tmp = tmp->next) {
        if (((meeting_t *)tmp->data)->id == meeting->id) {
            printf("Meeting id already exists\n");
            free(meeting);
            return;
        }
    }

    for (int i = 4; i < len; i++) {
        tmp = get_employee_by_id(calendar->employees, atoi(array[i]));

        if (tmp == NULL) {
            printf("Employee not found\n");
            free(meeting);
            return;
        }

        for (list_t *tmp2 = meeting->employees; tmp2 != NULL; tmp2 = tmp2->next) {
            if (tmp2->data == tmp) {
                printf("Employee already in the meeting\n");
                free(meeting);
                return;
            }
        }
        
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

meeting_t *get_meeting_by_id(list_t *meetings, int id)
{
    for (list_t *tmp = meetings; tmp != NULL; tmp = tmp->next) {
        if (((meeting_t *)tmp->data)->id == id)
            return tmp->data;
    }
    return NULL;
}

void remove_employee_by_id(meeting_t *meeting, int id)
{
    list_t *tmp = meeting->employees;
    list_t *prev = NULL;

    if (tmp != NULL && ((employee_t *)tmp->data)->id == id) {
        meeting->employees = tmp->next;
        free(tmp);
        return;
    }

    while (tmp != NULL && ((employee_t *)tmp->data)->id != id) {
        prev = tmp;
        tmp = tmp->next;
    }

    if (tmp == NULL) {
        return;
    }
    prev->next = tmp->next;
    free(tmp);
}