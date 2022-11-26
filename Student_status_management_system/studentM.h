#pragma once

#ifndef   __STUDENTM_H__
#define   __STUDENTM_H__

#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>
#include <string.h>
#include <ctime>

//MYSQL mysql; //mysql连接
//MYSQL_FIELD* fd;  //字段列数组
//char field[32][32];  //存字段名二维数组
//MYSQL_RES* res; //这个结构代表返回行的一个查询结果集
//MYSQL_ROW column; //一个行数据的类型安全(type-safe)的表示，表示数据行的列
//char query[150]; //查询语句

using namespace std;
//--------------------------------Database
MYSQL ConnectDatabase();						//连接数据库
void FreeConnect(MYSQL mysql);					//释放资源


//--------------------------------student
bool student_CreateTable(MYSQL mysql);			//创建student表
bool student_DropTable(MYSQL mysql);			//删除student表

bool student_InsertData(MYSQL mysql);			//向student表添加值
bool student_ModifyData(MYSQL mysql);			//通过学号修改student表的值

bool QueryStudentAll(MYSQL mysql);  			//查询student表全部内容
bool QueryStudentOFSname(MYSQL mysql);			//通过姓名查询student表
bool QueryStudentOFSno(MYSQL mysql);			//通过学号查询student表
bool QueryStudentOFSno(MYSQL mysql,char Sno[]);	//通过特定学号查询student表

bool student_DeleteData(MYSQL mysql);			//通过学号删除student表的值 

//--------------------------------age
char* Sage(int age);							//返回大于age岁的出生日期
#endif