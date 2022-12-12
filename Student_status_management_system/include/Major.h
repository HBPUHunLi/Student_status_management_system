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
bool major_CreateTable(MYSQL mysql);		//����Major��
bool major_DropTable(MYSQL mysql);			//ɾ��Major��
bool major_InsertData(MYSQL mysql);			//��Major�����ֵ
bool major_ModifyData(MYSQL mysql);             //�޸�Major���ֵ
bool QueryMajorOFMname(MYSQL mysql);             //ͨ��רҵ���Ʋ�ѯMajor��ֵ
bool QueryMajorOFMno(MYSQL mysql);               //ͨ��רҵ�Ų�ѯMajor��ֵ
bool QueryMajorOFMno(MYSQL mysql, char Mno[]);   //ͨ���ر�רҵ�Ų�ѯMajor��ֵ
bool QueryMajorAll(MYSQL mysql);                 //��ѯMajor��������ֵ
bool major_DeleteData(MYSQL mysql);              //ͨ��רҵ��ɾ��Major���е�ֵ
#endif