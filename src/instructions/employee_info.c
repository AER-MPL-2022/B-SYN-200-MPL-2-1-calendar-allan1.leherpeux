/*
** EPITECH PROJECT, 2023
** B-SYN-200-MPL-2-1-calendar-allan1.leherpeux
** File description:
** employee_info.c
*/

#include "instructions.h"
#include "tools.h"

bool compare_lastname(list_t *employee1, list_t *employee2)
{
    if (strcmp(((employee_t *)employee1->data)->lastname, ((employee_t *)employee2->data)->lastname) > 0) {
        employee_t *temp = employee1->data;
        employee1->data = employee2->data;
        employee2->data = temp;
        return true;
    } else if (strcmp(((employee_t *)employee1->data)->lastname, ((employee_t *)employee2->data)->lastname) == 0) {
        return false;
    }
    return true;
}

bool compare_firstname(list_t *employee1, list_t *employee2)
{
    if (strcmp(((employee_t *)employee1->data)->firstname, ((employee_t *)employee2->data)->firstname) > 0) {
        employee_t *temp = employee1->data;
        employee1->data = employee2->data;
        employee2->data = temp;
        return true;
    } else if (strcmp(((employee_t *)employee1->data)->firstname, ((employee_t *)employee2->data)->firstname) == 0) {
        return false;
    }
    return true;
}

bool compare_id(list_t *employee1, list_t *employee2)
{
    if (((employee_t *)employee1->data)->id > ((employee_t *)employee2->data)->id) {
        employee_t *temp = employee1->data;
        employee1->data = employee2->data;
        employee2->data = temp;
        return true;
    } else if (((employee_t *)employee1->data)->id == ((employee_t *)employee2->data)->id) {
        return false;
    }
    return true;
}

bool compare_job(list_t *employee1, list_t *employee2)
{
    if (strcmp(((employee_t *)employee1->data)->position, ((employee_t *)employee2->data)->position) > 0) {
        employee_t *temp = employee1->data;
        employee1->data = employee2->data;
        employee2->data = temp;
        return true;
    } else if (strcmp(((employee_t *)employee1->data)->position, ((employee_t *)employee2->data)->position) == 0) {
        return false;
    }
    return true;
}

bool compare_zip(list_t *employee1, list_t *employee2)
{
    if (strcmp(((employee_t *)employee1->data)->zip_code, ((employee_t *)employee2->data)->zip_code) > 0) {
        employee_t *temp = employee1->data;
        employee1->data = employee2->data;
        employee2->data = temp;
        return true;
    } else if (strcmp(((employee_t *)employee1->data)->zip_code, ((employee_t *)employee2->data)->zip_code) == 0) {
        return false;
    }
    return true;
}

void emp_sbn(calendar_t *calendar, char **ids)
{
    list_t *tmp = calendar->employees;
    list_t *tmp2 = calendar->employees;
    employee_t *tmp_data = NULL;

    while (tmp != NULL) {
        tmp2 = tmp->next;
        while (tmp2 != NULL) {
            if (!compare_lastname(tmp, tmp2)) {
                if (!compare_firstname(tmp, tmp2)) {
                    compare_id(tmp, tmp2);
                }
            }
            tmp2 = tmp2->next;
        }
        tmp = tmp->next;
    }
    disp_employees(calendar, ids);
}

void emp_sbf(calendar_t *calendar, char **ids)
{
    list_t *tmp = calendar->employees;
    list_t *tmp2 = calendar->employees;
    employee_t *tmp_data = NULL;

    while (tmp != NULL) {
        tmp2 = tmp->next;
        while (tmp2 != NULL) {
            if (!compare_firstname(tmp, tmp2)) {
                if (!compare_lastname(tmp, tmp2)) {
                    compare_id(tmp, tmp2);
                }
            }
            tmp2 = tmp2->next;
        }
        tmp = tmp->next;
    }
    disp_employees(calendar, ids);
}

void emp_sbj(calendar_t *calendar, char **ids)
{
    list_t *tmp = calendar->employees;
    list_t *tmp2 = calendar->employees;
    employee_t *tmp_data = NULL;

    while (tmp != NULL) {
        tmp2 = tmp->next;
        while (tmp2 != NULL) {
            if (!compare_job(tmp, tmp2)) {
                if (!compare_lastname(tmp, tmp2)) {
                    if (!compare_firstname(tmp, tmp2)) {
                        compare_id(tmp, tmp2);
                    }
                }
            }
            tmp2 = tmp2->next;
        }
        tmp = tmp->next;
    }
    disp_employees(calendar, ids);
}

void emp_sbz(calendar_t *calendar, char **ids)
{
    list_t *tmp = calendar->employees;
    list_t *tmp2 = calendar->employees;
    employee_t *tmp_data = NULL;

    while (tmp != NULL) {
        tmp2 = tmp->next;
        while (tmp2 != NULL) {
            if (!compare_zip(tmp, tmp2)) {
                if (!compare_lastname(tmp, tmp2)) {
                    if (!compare_firstname(tmp, tmp2)) {
                        compare_id(tmp, tmp2);
                    }
                }
            }
            tmp2 = tmp2->next;
        }
        tmp = tmp->next;
    }
    disp_employees(calendar, ids);
}

void emp_sbi(calendar_t *calendar, char **ids)
{
    list_t *tmp = calendar->employees;
    list_t *tmp2 = calendar->employees;
    employee_t *tmp_data = NULL;

    while (tmp != NULL) {
        tmp2 = tmp->next;
        while (tmp2 != NULL) {
            compare_id(tmp, tmp2);
            tmp2 = tmp2->next;
        }
        tmp = tmp->next;
    }
    disp_employees(calendar, ids);
}

void info_employee(calendar_t *calendar, char *line)
{
    char **array = str_to_word_array(line);

    if (get_array_len(array) < 2) {
        printf("Invalid arguments\n");
        return;
    }
    if (strcmp(array[1], "sortByName") == 0) {
        emp_sbn(calendar, array);
        return;
    }
    if (strcmp(array[1], "sortByForename") == 0) {
        emp_sbf(calendar, array);
        return;
    }
    if (strcmp(array[1], "sortByJob") == 0) {
        emp_sbj(calendar, array);
        return;
    }
    if (strcmp(array[1], "sortByZip") == 0) {
        emp_sbz(calendar, array);
        return;
    }
    if (strcmp(array[1], "sortById") == 0) {
        emp_sbi(calendar, array);
        return;
    }

}