#include"studentM.h"

bool report_DropTable(MYSQL mysql)
{
	char Query[200];
	strcpy(Query, "drop table Report;");
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