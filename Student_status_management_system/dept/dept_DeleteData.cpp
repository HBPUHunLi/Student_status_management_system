#include"studentM.h"

bool dept_DeleteData(MYSQL mysql)
{
	char query[500];
	char Dname[20];
	strcpy(query, "delete from Dept where Dname='");
	cout << "������ѧԺ��ɾ��ѧԺ" << endl;
	cin >> Dname;
	strcat(query, Dname);
	strcat(query, "';");
	if (mysql_query(&mysql, query))
	{
		printf("Query failed (%s)", mysql_error(&mysql));
		return false;
	}
	else
	{
		printf("Delete Data success\n\n");
		return true;
	}
}