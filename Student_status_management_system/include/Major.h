#pragma once
#pragma once

#ifndef   __MAJOR_H__
#define   __MAJOR_H__

//--------------------------------Major
bool major_CreateTable(MYSQL mysql);		//����Major��
bool major_DropTable(MYSQL mysql);			//ɾ��Major��
bool major_InsertData(MYSQL mysql);			//��Major�����ֵ

#endif