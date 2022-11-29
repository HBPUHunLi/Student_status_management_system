#pragma once

#ifndef   __STUDENT_H__
#define   __STUDENT_H__

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>
#include <string.h>
#include <ctime>

//--------------------------------student
bool student_CreateTable(MYSQL mysql);			//创建student表
bool student_DropTable(MYSQL mysql);			//删除student表

bool student_InsertData(MYSQL mysql);			//向student表添加值
bool student_ModifyData(MYSQL mysql);			//通过学号修改student表的值

bool QueryStudentAll(MYSQL mysql);  			//查询student表全部内容
bool QueryStudentOFSname(MYSQL mysql);			//通过姓名查询student表
bool QueryStudentOFSno(MYSQL mysql);			//通过学号查询student表
bool QueryStudentOFSno(MYSQL mysql, char Sno[]);	//通过特定学号查询student表
bool QueryStudentOFAge(MYSQL mysql, int age);

bool student_DeleteData(MYSQL mysql);			//通过学号删除student表的值 

#endif