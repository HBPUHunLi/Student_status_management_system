#include"studentM.h"

bool report_DeleteData(MYSQL mysql, char No[], int x)
{
	char query[500];

	if (x == 0)
	{
		strcpy(query, "delete from Report where Sno='");
	}
	else if (x == 1)
	{
		strcpy(query, "delete from Report where Mno='");
	}
	else
	{
		cout << "´íÎóÊäÈë"<<endl;
		return false;
	}
	strcat(query, No);
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