#pragma once
#pragma once

#ifndef   __REPORT_H__
#define   __REPORT_H__

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>
#include <string.h>
#include <ctime>

//--------------------------------Report
bool report_CreateTable(MYSQL mysql);		//创建Report表
bool report_DropTable(MYSQL mysql);			//删除Report表
bool report_InsertData(MYSQL mysql);			//向Report表添加值
#endif