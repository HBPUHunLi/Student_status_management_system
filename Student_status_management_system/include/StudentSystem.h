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

MYSQL ConnectDatabase();						//连接数据库
void FreeConnect(MYSQL mysql);					//释放资源
bool CreatSystem(MYSQL mysql);					//创建数据库系统
bool DropSystem(MYSQL mysql);					//删除数据库系统

#endif