#include"studentM.h"


//��student���������  
bool student_InsertData(MYSQL mysql)
{
	char query[150];
	char Sno[20];
	char Sname[40];
	char Birthday[12];
	char Ssex[4];
	char queryin[150];
	cout << "������ѧ�� ���� �������ڣ�xxxx.xx.xx�� �Ա�" << endl;
	cin >> Sno >> Sname >> Birthday >> Ssex;

	strcpy(queryin, "insert into Student values ('");
	strcat(queryin, Sno);
	strcat(queryin, "','");
	strcat(queryin, Sname);
	strcat(queryin, "','");
	strcat(queryin, Birthday);
	strcat(queryin, "','");
	strcat(queryin, Ssex);
	strcat(queryin, "'); ");
	strcpy(query, queryin);
	cout << endl << query << endl;

	if (mysql_query(&mysql, query))        //ִ��SQL���  
	{
		printf("Insert Data failed (%s)\n\n", mysql_error(&mysql));
		return false;
	}
	else
	{
		printf("Insert Data success\n\n");
		return true;
	}
}