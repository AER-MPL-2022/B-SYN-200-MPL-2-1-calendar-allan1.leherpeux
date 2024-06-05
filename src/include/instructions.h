/*
** EPITECH PROJECT, 2023
** B-SYN-200-MPL-2-1-calendar-allan1.leherpeux
** File description:
** instructions.h
*/

#pragma once

#include "calendar.h"

void get_instruction(calendar_t *calendar, char *line);
void new_employee(calendar_t *calendar, char *line);
void display_employee(employee_t *employee);
employee_t *get_employee_by_id(list_t *employees, int id);
void new_meeting(calendar_t *calendar, char *line);
void display_meeting(meeting_t *meeting);
meeting_t *get_meeting_by_id(list_t *meetings, int id);
void remove_employee_by_id(meeting_t *meeting, int id);
void invite(calendar_t *calendar, char *line);
void exclude(calendar_t *calendar, char *line);
void fire(calendar_t *calendar, char *line);
void info_employee(calendar_t *calendar, char *line);
void disp_employees(calendar_t *calendar, char **ids);