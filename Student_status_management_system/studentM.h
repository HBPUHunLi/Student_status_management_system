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

//MYSQL mysql; //mysql����
//MYSQL_FIELD* fd;  //�ֶ�������
//char field[32][32];  //���ֶ�����ά����
//MYSQL_RES* res; //����ṹ�������е�һ����ѯ�����
//MYSQL_ROW column; //һ�������ݵ����Ͱ�ȫ(type-safe)�ı�ʾ����ʾ�����е���
//char query[150]; //��ѯ���

using namespace std;
//--------------------------------Database
MYSQL ConnectDatabase();						//�������ݿ�
void FreeConnect(MYSQL mysql);					//�ͷ���Դ


//--------------------------------student
bool student_CreateTable(MYSQL mysql);			//����student��
bool student_DropTable(MYSQL mysql);			//ɾ��student��

bool student_InsertData(MYSQL mysql);			//��student�����ֵ
bool student_ModifyData(MYSQL mysql);			//ͨ��ѧ���޸�student���ֵ

bool QueryStudentAll(MYSQL mysql);  			//��ѯstudent��ȫ������
bool QueryStudentOFSname(MYSQL mysql);			//ͨ��������ѯstudent��
bool QueryStudentOFSno(MYSQL mysql);			//ͨ��ѧ�Ų�ѯstudent��
bool QueryStudentOFSno(MYSQL mysql,char Sno[]);	//ͨ���ض�ѧ�Ų�ѯstudent��

bool student_DeleteData(MYSQL mysql);			//ͨ��ѧ��ɾ��student���ֵ 

//--------------------------------age
char* Sage(int age);							//���ش���age��ĳ�������
#endif