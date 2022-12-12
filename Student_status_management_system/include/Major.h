#pragma once
#pragma once

#ifndef   __MAJOR_H__
#define   __MAJOR_H__

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>
#include <string.h>
#include <ctime>

//--------------------------------Major
bool major_CreateTable(MYSQL mysql);		//创建Major表
bool major_DropTable(MYSQL mysql);			//删除Major表
bool major_InsertData(MYSQL mysql);			//向Major表添加值
bool major_ModifyData(MYSQL mysql);             //修改Major表的值
bool QueryMajorOFMname(MYSQL mysql);             //通过专业名称查询Major表值
bool QueryMajorOFMno(MYSQL mysql);               //通过专业号查询Major表值
bool QueryMajorOFMno(MYSQL mysql, char Mno[]);   //通过特别专业号查询Major表值
bool QueryMajorAll(MYSQL mysql);                 //查询Major表中所有值
bool major_DeleteData(MYSQL mysql);              //通过专业号删除Major表中的值
#endif