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
bool report_CreateTable(MYSQL mysql);		//����Report��
bool report_DropTable(MYSQL mysql);			//ɾ��Report��
bool report_InsertData(MYSQL mysql);			//��Report�����ֵ
#endif