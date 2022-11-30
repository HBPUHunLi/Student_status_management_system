#include"studentM.h"

bool major_InsertData(MYSQL mysql)
{
	char query[500];
	char Mno[20];
	char Mname[20];
	char Mdept[20];
	cout << "请输入专业号 专业名称 所属学院" << endl;
	cin >> Mno>>Mname>>Mdept;
	strcpy(query, "insert into Major values ('");
	strcat(query,Mno);
	strcat(query, "','");
	strcat(query,Mname);
	strcat(query, "','");
	strcat(query, Mdept);
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
//insert into major values('Mno','Mname','Mdept');