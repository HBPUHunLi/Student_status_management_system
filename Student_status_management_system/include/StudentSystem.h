#pragma once
#pragma once

#ifndef   __STUDENTSYSTEM_H__
#define   __STUDENTSYSTEM_H__

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>
#include <string.h>
#include <ctime>

MYSQL ConnectDatabase();						//�������ݿ�
void FreeConnect(MYSQL mysql);					//�ͷ���Դ
bool CreatSystem(MYSQL mysql);					//�������ݿ�ϵͳ
bool DropSystem(MYSQL mysql);					//ɾ�����ݿ�ϵͳ

#endif