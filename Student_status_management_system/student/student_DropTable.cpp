#include"studentM.h"

bool student_DropTable(MYSQL mysql)
{
	char Query[200];
	strcpy(Query, "drop table Student;");
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