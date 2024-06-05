/*
** EPITECH PROJECT, 2023
** B-SYN-200-MPL-2-1-calendar-allan1.leherpeux
** File description:
** requirements.h
*/
#pragma once
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct list {
    void *data;
    struct list *next;
} list_t;

void push_back(list_t **begin, void *data);
void display_list(list_t *begin);
int my_revlist_synthesis(list_t **begin);
list_t *my_findnodeeqinlist_synthesis(list_t *begin, void *data_ref, int (*cmp)(void *, void *));
void *pop_front(list_t **begin);
int list_len(list_t *begin);