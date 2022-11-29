

#include"studentM.h"
bool dept_InsertData(MYSQL mysql)
{
	char query[500];
	char Dname[20];
	cout << "请输入学院名称" << endl;
	cin >> Dname;
	strcpy(query, "insert into dept values ('");
	strcat(query, Dname);
	strcat(query, "'); ");
	cout << endl << query << endl;
	if (mysql_query(&mysql, query))        //执行SQL语句  
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
//