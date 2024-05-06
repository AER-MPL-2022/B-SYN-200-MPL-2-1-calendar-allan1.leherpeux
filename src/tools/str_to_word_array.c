/*
** EPITECH PROJECT, 2023
** B-SYN-200-MPL-2-1-calendar-allan1.leherpeux
** File description:
** stwa.c
*/

#include "tools.h"

int get_array_len(char **array)
{
    int i = 0;

    for (; array[i] != NULL; i++);
    return i;
}

char **str_to_word_array(char *str)
{
    //using strtok
    char **array = malloc(sizeof(char *) * 100);
    char *token = strtok(str, " \n");

    for (int i = 0; token != NULL; i++) {
        array[i] = strdup(token);
        token = strtok(NULL, " \n");
    }

    array[100] = NULL;
    return array;
}