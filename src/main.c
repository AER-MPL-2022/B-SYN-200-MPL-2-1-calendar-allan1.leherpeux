/*
** EPITECH PROJECT, 2023
** B-SYN-200-MPL-2-1-calendar-allan1.leherpeux
** File description:
** main.c
*/

#include "requirements.h"

int main(void)
{
    list_t *list = NULL;
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;

    push_back(&list, &a);
    push_back(&list, &b);
    push_back(&list, &c);
    push_back(&list, &d);

    //display_list(list);

    my_revlist_synthesis(&list);

    display_list(list);

    return 0;
}
