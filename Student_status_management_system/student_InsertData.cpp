#include"studentM.h"


//��student���������  
bool InsertData(MYSQL mysql)
{
	char query[150];
	char Sno[20];
	char Sname[40];
	char Birthday[12];
	char Ssex[4];
	char Sdept[40];
	char queryin[150];
	cout << "������ѧ�� ���� �������ڣ�xxxx.xx.xx�� �Ա� ����ѧԺ" << endl;
	cin >> Sno >> Sname >> Birthday >> Ssex >> Sdept;

	strcpy(queryin, "insert into student values ('");
	strcat(queryin, Sno);
	strcat(queryin, "','");
	strcat(queryin, Sname);
	strcat(queryin, "','");
	strcat(queryin, Birthday);
	strcat(queryin, "','");
	strcat(queryin, Ssex);
	strcat(queryin, "','");
	strcat(queryin, Sdept);
	strcat(queryin, "'); ");
	strcpy(query, queryin);
	cout << endl << query << endl;

	if (mysql_query(&mysql, query))        //ִ��SQL���  
	{
		printf("Query failed (%s)\n\n", mysql_error(&mysql));
		return false;
	}
	else
	{
		printf("Insert success\n\n");
		return true;
	}
}