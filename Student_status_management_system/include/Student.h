#pragma once

#ifndef   __STUDENT_H__
#define   __STUDENT_H__

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>
#include <string.h>
#include <ctime>

//--------------------------------student
bool student_CreateTable(MYSQL mysql);			//����student��
bool student_DropTable(MYSQL mysql);			//ɾ��student��

bool student_InsertData(MYSQL mysql);			//��student�����ֵ
bool student_ModifyData(MYSQL mysql);			//ͨ��ѧ���޸�student���ֵ

bool QueryStudentAll(MYSQL mysql);  			//��ѯstudent��ȫ������
bool QueryStudentOFSname(MYSQL mysql);			//ͨ��������ѯstudent��
bool QueryStudentOFSno(MYSQL mysql);			//ͨ��ѧ�Ų�ѯstudent��
bool QueryStudentOFSno(MYSQL mysql, char Sno[]);	//ͨ���ض�ѧ�Ų�ѯstudent��
bool QueryStudentOFAge(MYSQL mysql, int age);

bool student_DeleteData(MYSQL mysql);			//ͨ��ѧ��ɾ��student���ֵ 

#endif