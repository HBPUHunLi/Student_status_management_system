#include"studentM.h"

bool major_CreateTable(MYSQL mysql)
{
	char query[100];
	strcpy(query, "create table Major(");
	strcat(query, "Mno varchar(20) not null unique primary key,");
	strcat(query, "Mname varchar(20) not null,");
	strcat(query, "Mdept varchar(20) not null,");
	strcat(query, "foreign key(Mdept) references Dept(Dname));");
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