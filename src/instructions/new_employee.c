/*
** EPITECH PROJECT, 2023
** B-SYN-200-MPL-2-1-calendar-allan1.leherpeux
** File description:
** new_employee.c
*/

#include "instructions.h"
#include "tools.h"

void new_employee(calendar_t *calendar, char *line)
{
    char **array = str_to_word_array(line);
    employee_t *employee = malloc(sizeof(employee_t));
    int len = get_array_len(array);

    if (len != 6) {
        fprintf(stderr, "Invalid arguments\n");
        free(employee);
        return;
    }
    
    employee->firstname = strdup(array[2]);
    employee->lastname = strdup(array[1]);
    employee->position = strdup(array[3]);
    employee->zip_code = strdup(array[4]);
    employee->id = atoi(array[5]);

    for (list_t *tmp = calendar->employees; tmp != NULL; tmp = tmp->next) {
        if (((employee_t *)tmp->data)->id == employee->id) {
            printf("Employee id already exists\n");
            free(employee);
            return;
        }
    }

    push_back(&calendar->employees, employee);
}

void display_employee(employee_t *employee)
{
    printf("Employee %d: %s %s | Pos: %s Zipcode: %s\n", employee->id, employee->firstname, employee->lastname, employee->position, employee->zip_code);
}

employee_t *get_employee_by_id(list_t *employees, int id)
{
    for (list_t *tmp = employees; tmp != NULL; tmp = tmp->next) {
        if (((employee_t *)tmp->data)->id == id)
            return tmp->data;
    }
    return NULL;
}