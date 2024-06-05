/*
** EPITECH PROJECT, 2023
** B-SYN-200-MPL-2-1-calendar-allan1.leherpeux
** File description:
** requirement.c
*/
#include "requirement.h"

void push_back(list_t **begin, void *data)
{
    //printf("on push %d\n", *(int *)data);
    list_t *tmp = *begin;

    if (tmp == NULL) {
        *begin = malloc(sizeof(list_t));
        (*begin)->data = data;
        (*begin)->next = NULL;
    } else {
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }

        tmp->next = malloc(sizeof(list_t));
        tmp->next->data = data;
        tmp->next->next = NULL;
    }
}

void *pop_front(list_t **begin)
{
    void *data = (*begin)->data;

    *begin = (*begin)->next;

    return data;
}

void *pop_back(list_t **begin)
{
    list_t *tmp = *begin;
    void *data;

    if (tmp->next == NULL) {
        data = tmp->data;
        *begin = NULL;
        return data;
    }

    while (tmp->next->next != NULL) {
        tmp = tmp->next;
    }

    data = tmp->next->data;
    tmp->next = NULL;

    return data;
}

int list_len(list_t *begin)
{
    int i = 0;
    list_t *tmp = begin;

    while (tmp != NULL) {
        i++;
        tmp = tmp->next;
    }
    return i;
}

void display_list(list_t *begin)
{
    list_t *tmp = begin;

    while (tmp != NULL) {
        printf("%d\n", *(int *)tmp->data);
        tmp = tmp->next;
    }
}

int my_revlist_synthesis(list_t **begin)
{
    list_t *res = NULL;
    void *data;

    while (*begin != NULL) {
        data = pop_back(begin);
        push_back(&res, data);
    }

    *begin = res;

    return 0;
}

list_t *my_findnodeeqinlist_synthesis(list_t *begin, void *data_ref, int (*cmp)(void *, void *))
{
    list_t *tmp = begin;

    while (tmp != NULL) {
        if (!cmp(tmp->data, data_ref)) {
            return tmp;
        }
        tmp = tmp->next;
    }
    return NULL;
}