#include"studentM.h"

char* input()
{
	char Sno[20];
	cout<<"请输入要修改信息的学生的学号" << endl;
	cin >> Sno;
	return Sno;
}

bool student_ModifyData(MYSQL mysql)
{
	char query[150];
	char Sno[20];
	char Sname[40];
	char Birthday[12];
	char Ssex[4];
	char Sdept[40];
	int x;
	cout << "请输入序号来选择要修改的信息" << endl;
	cout << "1.姓名" << endl;
	cout << "2.生日" << endl;
	cout << "3.性别" << endl;
	cout << "4.学院" << endl;
	cout << "取消修改请输入其他任意键" << endl;
	cin >> x;
	switch (x)
	{
	case 1: {
		strcpy(Sno, input());
		cout << "请输入修改后的姓名" << endl;
		cin >> Sname;
		strcpy(query, "update student set Sname='");
		strcat(query,Sname);
		strcat(query, "' where Sno = '");
		strcat(query, Sno);
		strcat(query, "';");
		break;
	}
	case 2: {
		strcpy(Sno, input());
		cout << "请输入修改后的生日(xxxx.xx.xx)" << endl;
		cin >> Birthday;
		strcpy(query, "update student set Birthday='");
		strcat(query, Birthday);
		strcat(query, "' where Sno = '");
		strcat(query, Sno);
		strcat(query, "';");
		break;
	}
	case 3: {
		strcpy(Sno, input());
		cout << "请输入修改后的性别" << endl;
		cin >> Ssex;
		strcpy(query, "update student set Ssex='");
		strcat(query, Ssex);
		strcat(query, "' where Sno = '");
		strcat(query, Sno);
		strcat(query, "';");
		break;
	}
	case 4: {
		strcpy(Sno, input());
		cout << "请输入修改后的学院" << endl;
		cin >> Sdept;
		strcpy(query, "update student set Sdept='");
		strcat(query, Sdept);
		strcat(query, "' where Sno = '");
		strcat(query, Sno);
		strcat(query, "';");
		break;
	}
	default: {
		cout << "您选择了取消修改" << endl;
		return false;
	}
	}
	if (mysql_query(&mysql, query))        //执行SQL语句  
	{
		printf("Modify Data failed (%s)\n\n", mysql_error(&mysql));
			return false;
	}
	else
	{
		printf("Modify Data success\n\n");
		cout << "修改后的学生信息为" << endl;
		QueryStudentOFSno(mysql, Sno);
			return true;
	}

}