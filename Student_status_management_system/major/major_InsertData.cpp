#include"studentM.h"

bool major_InsertData(MYSQL mysql)
{
	char query[500];
	char Mno[20];
	char Mname[20];
	char Mdept[20];
	cout << "������רҵ�� רҵ���� ����ѧԺ" << endl;
	cin >> Mno>>Mname>>Mdept;
	strcpy(query, "insert into Major values ('");
	strcat(query,Mno);
	strcat(query, "','");
	strcat(query,Mname);
	strcat(query, "','");
	strcat(query, Mdept);
	strcat(query, "');");
//	cout << endl << query << endl;
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
//insert into major values('Mno','Mname','Mdept');