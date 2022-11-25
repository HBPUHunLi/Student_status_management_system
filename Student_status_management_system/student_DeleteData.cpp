#include"studentM.h"

bool student_DeleteData(MYSQL mysql)
{
	char query[100];
	char Sno[20];
	strcpy(query, "delete from student where Sno='");
	cout << "请输入学生学号删除学生信息" << endl;
	cin >> Sno;
	strcat(query, Sno);
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
