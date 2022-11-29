#include"studentM.h"

bool report_CreateTable(MYSQL mysql)
{
	char query[500];
	strcpy(query, "create table Report(");
	strcat(query, "Sno varchar(20) not null,");
	strcat(query, "Mno varchar(20) not null,");
	strcat(query, "Pass tinyint(1) not null DEFAULT 0,");
	strcat(query, "primary key(Sno,Mno),");
	strcat(query, "foreign key(Sno) references Student(Sno),");
	strcat(query, "foreign key(Mno) references Major(Mno));");
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