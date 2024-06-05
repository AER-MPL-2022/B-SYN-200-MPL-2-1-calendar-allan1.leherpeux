/*
** EPITECH PROJECT, 2023
** B-SYN-200-MPL-2-1-calendar-allan1.leherpeux
** File description:
** exclude.c
*/

#include "instructions.h"
#include "tools.h"

void fire_employee(calendar_t *calendar, char *name)
{
    int id = atoi(name);

    list_t *tmp = calendar->employees;
    list_t *prev = NULL;
    while (tmp != NULL && ((employee_t *)tmp->data)->id != id) {
        prev = tmp;
        tmp = tmp->next;
    }

    if (tmp == NULL) {
        printf("Employee not found\n");
        return;
    }

    list_t *meeting = calendar->meetings;
    while (meeting != NULL) {
        remove_employee_by_id((meeting_t *)meeting->data, id);
        meeting = meeting->next;
    }

    if (prev != NULL) {
        prev->next = tmp->next;
    } else {
        calendar->employees = tmp->next;
    }

    free(tmp);
}

void fire(calendar_t *calendar, char *line)
{
    char **array = str_to_word_array(line);
    int len = get_array_len(array);

    if (len < 2) {
        fprintf(stderr, "Invalid arguments\n");
        return;
    }

    for (int i = 1; i < len; i++) {
        fire_employee(calendar, array[i]);
    }
}