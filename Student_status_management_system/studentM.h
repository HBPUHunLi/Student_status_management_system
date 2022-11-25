#pragma once

#ifndef   __STUDENTM_H__
#define   __STUDENTM_H__

#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <stdio.h>
#include <mysql.h>
#include <string.h>

//MYSQL mysql; //mysql����
//MYSQL_FIELD* fd;  //�ֶ�������
//char field[32][32];  //���ֶ�����ά����
//MYSQL_RES* res; //����ṹ�������е�һ����ѯ�����
//MYSQL_ROW column; //һ�������ݵ����Ͱ�ȫ(type-safe)�ı�ʾ����ʾ�����е���
//char query[150]; //��ѯ���

using namespace std;

MYSQL ConnectDatabase();		//�������ݿ� 
void FreeConnect(MYSQL mysql);			//�ͷ���Դ  
bool InsertData(MYSQL mysql);			//��
bool ModifyData(MYSQL mysql);			//��
bool DeleteData(MYSQL mysql);			//ɾ


bool QueryStudentAll(MYSQL mysql);  	//��ѯstudent��ȫ������
bool QueryStudentOFSname(MYSQL mysql);	//ͨ��������ѯstudent��
bool QueryStudentOFSno(MYSQL mysql);	//ͨ��ѧ�Ų�ѯstudent��


#endif