#include"studentM.h"

bool report_InsertData(MYSQL mysql)
{
	char query[500];
	char Sno[20];
	char Mno[20];
	char pass[5];
	cout << "请输入学号 专业号 通过情况（0或1）" << endl;
	cin >> Sno >> Mno >> pass;
	strcpy(query, "insert into Report values ('");
	strcat(query, Sno);
	strcat(query, "','");
	strcat(query, Mno);
	strcat(query, "','");
	strcat(query, pass);
	strcat(query, "');");

	//	cout << endl << query << endl;

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
//insert into report value('003','5',1);