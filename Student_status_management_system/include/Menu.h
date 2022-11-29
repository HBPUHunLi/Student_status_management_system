#pragma once
#ifndef   __MENU_H__
#define   __MENU_H__

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>
#include <string.h>
#include <ctime>
//--------------------------------menu

void SwitchStudent(MYSQL mysql);
void SwitchMajor(MYSQL mysql);
void SwitchDept(MYSQL mysql);
void SwitchReport(MYSQL mysql);

#endif