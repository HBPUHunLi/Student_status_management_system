#include"studentM.h"


//向student表插入数据  
bool InsertData(MYSQL mysql)
{
	char query[150];
	char Sno[20];
	char Sname[40];
	char Birthday[12];
	char Ssex[4];
	char Sdept[40];
	char queryin[150];
	cout << "请输入学号 姓名 出生日期（xxxx.xx.xx） 性别 所属学院" << endl;
	cin >> Sno >> Sname >> Birthday >> Ssex >> Sdept;

	strcpy(queryin, "insert into student values ('");
	strcat(queryin, Sno);
	strcat(queryin, "','");
	strcat(queryin, Sname);
	strcat(queryin, "','");
	strcat(queryin, Birthday);
	strcat(queryin, "','");
	strcat(queryin, Ssex);
	strcat(queryin, "','");
	strcat(queryin, Sdept);
	strcat(queryin, "'); ");
	strcpy(query, queryin);
	cout << endl << query << endl;

	if (mysql_query(&mysql, query))        //执行SQL语句  
	{
		printf("Query failed (%s)\n\n", mysql_error(&mysql));
		return false;
	}
	else
	{
		printf("Insert success\n\n");
		return true;
	}
}