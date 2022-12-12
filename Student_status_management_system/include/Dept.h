#pragma once
#pragma once

#ifndef   __DEPT_H__
#define   __DEPT_H__

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>
#include <string.h>
#include <ctime>

//--------------------------------Dept
bool dept_CreateTable(MYSQL mysql);			//创建Dept表
bool dept_DropTable(MYSQL mysql);			//删除Dept表
bool dept_InsertData(MYSQL mysql);			//向Dept表添加值
bool dept_ModifyData(MYSQL mysql);          //修改学院名字
bool dept_DeleteData(MYSQL mysql);          //通过学院名删除学院
bool dept_QueryDeptAll(MYSQL mysql);        //查询所有学院
bool dept_QueryDeptIFDname(MYSQL mysql);    //查询某学院是否存在

#endif