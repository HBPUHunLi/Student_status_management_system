#pragma once

#ifndef   __STUDENTM_H__
#define   __STUDENTM_H__

#define _CRT_SECURE_NO_DEPRECATE

#include"StudentSystem.h"
#include"Menu.h"
#include"Student.h"
#include"Report.h"
#include"Dept.h"
#include"Major.h"
#include"Alr.h"

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
/*
//--------------------------------Database
MYSQL ConnectDatabase();						//�������ݿ�
void FreeConnect(MYSQL mysql);					//�ͷ���Դ
bool CreatSystem(MYSQL mysql);					//�������ݿ�ϵͳ
bool DropSystem(MYSQL mysql);					//ɾ�����ݿ�ϵͳ
//--------------------------------menu

void SwitchStudent(MYSQL mysql);
void SwitchMajor(MYSQL mysql);
void SwitchDept(MYSQL mysql);
void SwitchReport(MYSQL mysql);

//--------------------------------student
bool student_CreateTable(MYSQL mysql);			//����student��
bool student_DropTable(MYSQL mysql);			//ɾ��student��

bool student_InsertData(MYSQL mysql);			//��student�����ֵ
bool student_ModifyData(MYSQL mysql);			//ͨ��ѧ���޸�student���ֵ

bool QueryStudentAll(MYSQL mysql);  			//��ѯstudent��ȫ������
bool QueryStudentOFSname(MYSQL mysql);			//ͨ��������ѯstudent��
bool QueryStudentOFSno(MYSQL mysql);			//ͨ��ѧ�Ų�ѯstudent��
bool QueryStudentOFSno(MYSQL mysql,char Sno[]);	//ͨ���ض�ѧ�Ų�ѯstudent��
bool QueryStudentOFAge(MYSQL mysql, int age);

bool student_DeleteData(MYSQL mysql);			//ͨ��ѧ��ɾ��student���ֵ 

//--------------------------------Dept
bool dept_CreateTable(MYSQL mysql);			//����Dept��
bool dept_DropTable(MYSQL mysql);			//ɾ��Dept��
bool dept_InsertData(MYSQL mysql);			//��Dept�����ֵ

//--------------------------------Major
bool major_CreateTable(MYSQL mysql);		//����Major��
bool major_DropTable(MYSQL mysql);			//ɾ��Major��
bool major_InsertData(MYSQL mysql);			//��Major�����ֵ

//--------------------------------Report
bool report_CreateTable(MYSQL mysql);		//����Report��
bool report_DropTable(MYSQL mysql);			//ɾ��Report��

bool report_InsertData(MYSQL mysql);			//��Report�����ֵ
//--------------------------------age
char* Sage(int age);							//���ش���age��ĳ�������
*/
#endif