#include "studentM.h"

bool student_CreateTable(MYSQL mysql)
{
	char query[100];
	strcpy(query, "create table Student(");
	strcat(query, "Sno varchar(20) not null unique primary key,");
	strcat(query, "Sname varchar(20) not null,");
	strcat(query, "birthday varchar(12) not null,");
	strcat(query, "Ssex varchar(2) not null);");
	
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