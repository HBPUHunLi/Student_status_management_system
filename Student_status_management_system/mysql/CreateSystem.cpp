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
		cout << "ѧ������ϵͳ�����ɹ�" << endl;
	}
	else
	{
		cout << "ѧ������ϵͳ����ʧ��" << endl;
	}
	return CreateS;
}