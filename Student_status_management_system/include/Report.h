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
bool report_CreateTable(MYSQL mysql);				//����Report��
bool report_DropTable(MYSQL mysql);					//ɾ��Report��
bool report_InsertData(MYSQL mysql);				//��Report�����ֵ
bool report_DeleteData(MYSQL mysql,char No[],int x);//ͨ��ѧ�Ż���רҵ��ɾ��ѧ��רҵ��Ϣ
bool QueryReportALL(MYSQL mysql);                   //��ѯȫ����Ϣ
bool QueryReportOFSno(MYSQL mysql);                 //����ѧ�Ų�ѯ
bool QueryReportOFMname(MYSQL mysql);               //����רҵ��ѯ
bool report_ModifyData(MYSQL mysql);                //����ѧ���޸�רҵ��
#endif