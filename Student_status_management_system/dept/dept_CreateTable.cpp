#include"studentM.h"

bool dept_CreateTable(MYSQL mysql)
{
char query[100];
strcpy(query, "create table Dept(");
strcat(query, "Dname varchar(20) not null unique primary key);");

if (mysql_query(&mysql, query))
{
	printf("Create Table failed (%s)\n\n", mysql_error(&mysql));
	return false;
}
else
{
	printf("Create Table success\n\n");
	return true;
}

}