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
bool dept_CreateTable(MYSQL mysql);			//����Dept��
bool dept_DropTable(MYSQL mysql);			//ɾ��Dept��
bool dept_InsertData(MYSQL mysql);			//��Dept�����ֵ
bool dept_ModifyData(MYSQL mysql);          //�޸�ѧԺ����
bool dept_DeleteData(MYSQL mysql);          //ͨ��ѧԺ��ɾ��ѧԺ
bool dept_QueryDeptAll(MYSQL mysql);        //��ѯ����ѧԺ
bool dept_QueryDeptIFDname(MYSQL mysql);    //��ѯĳѧԺ�Ƿ����

#endif