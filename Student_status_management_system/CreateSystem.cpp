#include"studentM.h"

bool CreatSystem(MYSQL mysql)
{
	bool CreateS = true;
	CreateS = CreateS && dept_CreateTable(mysql);
	CreateS = CreateS && student_CreateTable(mysql);
	CreateS = CreateS && major_CreateTable(mysql);
	CreateS = CreateS && report_CreateTable(mysql);
	cout << endl;
	if (CreateS)
	{
		cout << "学籍管理系统创建成功" << endl;
	}
	else
	{
		cout << "学籍管理系统创建失败" << endl;
	}
	return CreateS;
}