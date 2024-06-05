/*
** EPITECH PROJECT, 2023
** B-SYN-200-MPL-2-1-calendar-allan1.leherpeux
** File description:
** disp_employees.c
*/
#include "instructions.h"
#include "tools.h"

bool check_id(char **ids, employee_t *employee)
{
    for (int i = 1; ids[i] != NULL; i++) {
        if (atoi(ids[i]) == employee->id)
            return true;
    }
    return false;
}

void disp_employees(calendar_t *calendar, char **ids)
{
    list_t *tmp = calendar->employees;

    while (tmp != NULL) {
        if (ids[2] != NULL && !check_id(ids, (employee_t *)tmp->data)) {
            tmp = tmp->next;
            continue;
        }
        printf("******************************\n");
        printf("%s %s\n", ((employee_t *)tmp->data)->firstname,
            ((employee_t *)tmp->data)->lastname);
        printf("position: %s\n", ((employee_t *)tmp->data)->position);
        printf("city: %s\n", ((employee_t *)tmp->data)->zip_code);
        for (list_t *meeting = calendar->meetings; meeting != NULL;
            meeting = meeting->next) {
            if (((meeting_t *)meeting->data)->employees->next == NULL)
                continue;
            for (list_t *employee = ((meeting_t *)meeting->data)->employees;
                employee != NULL; employee = employee->next) {
                if (((employee_t *)employee->data)->id ==
                    ((employee_t *)tmp->data)->id) {
                    printf("meeting on %s, %s, with ",
                        ((meeting_t *)meeting->data)->date,
                        ((meeting_t *)meeting->data)->zip_code);
                    for (list_t *employee2 = ((meeting_t *)meeting->data)->employees;
                        employee2 != NULL; employee2 = employee2->next) {
                        if (((employee_t *)employee2->data)->id != ((employee_t *)employee->data)->id) {
                            printf("%s %s", ((employee_t *)employee2->data)->firstname, ((employee_t *)employee2->data)->lastname);
                            if (employee2->next != NULL && ((employee_t *)employee2->next->data)->id != ((employee_t *)employee->data)->id) {
                                printf(", ");
                            }
                        }
                    }
                    printf("\n");
                    break;
                }
            }
        }
        tmp = tmp->next;
    }
}