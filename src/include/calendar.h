/*
** EPITECH PROJECT, 2023
** B-SYN-200-MPL-2-1-calendar-allan1.leherpeux
** File description:
** calendar.h
*/
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "requirements.h"

enum instr {
    NEW_EMPLOYEE,
    NEW_MEETING,
    INVITE,
    EXCLUDE,
    INFO_EMPLOYEES,
    INFO_MEETINGS,
    CANCEL,
    FIRE,
    END
};

typedef struct employee_s {
    int id;
    char *lastname;
    char *firstname;
    char *position;
    char *zip_code;
} employee_t;

typedef struct meeting_s {
    int id;
    char *zip_code;
    char *date;
    list_t *employees;
} meeting_t;

typedef struct calendar_s {
    bool running;
    enum instr current_instruction;
    list_t *employees;
    list_t *meetings;
} calendar_t;
