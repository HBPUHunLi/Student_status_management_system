#pragma once
#pragma once

#ifndef   __MAJOR_H__
#define   __MAJOR_H__

//--------------------------------Major
bool major_CreateTable(MYSQL mysql);		//创建Major表
bool major_DropTable(MYSQL mysql);			//删除Major表
bool major_InsertData(MYSQL mysql);			//向Major表添加值

#endif