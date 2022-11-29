#include"studentM.h"

bool dept_DropTable(MYSQL mysql)
{
	char Query[500];
	strcpy(Query, "drop table Dept;");
	if (mysql_query(&mysql, Query))
	{
		printf("Drop Table failed (%s)", mysql_error(&mysql));
		return false;
	}
	else
	{
		printf("Drop Table success\n\n");
		return true;
	}
}