#include"studentM.h"


//查询数据
bool QueryStudentAll(MYSQL mysql)
{
	char query[500]; //查询语句
	MYSQL_RES* res; //这个结构代表返回行的一个查询结果集
	MYSQL_ROW column; //一个行数据的类型安全(type-safe)的表示，表示数据行的列

	strcpy(query, "select Student.Sno as 学号,Sname as 姓名,Birthday as 生日,Ssex as 性别,Mname as 专业,Mdept as 所属学院,pass as 通过情况 from Student,report,major where report.Sno=student.Sno and major.Mno=report.Mno;"); //输入查询语句
	mysql_query(&mysql, "set names gbk"); //设置编码格式（SET NAMES GBK也行），否则cmd下中文乱码

	//返回0 查询成功，返回1查询失败
	if (mysql_query(&mysql, query)) // 执行指定为一个空结尾的字符串的SQL查询。
	{
		printf("Query failed (%s)\n\n", mysql_error(&mysql));
			return false;
	}
	else
	{
		printf("Query success\n\n");
	}

	//获取结果集
	if (!(res = mysql_store_result(&mysql)))    //获得sql语句结束后返回的结果集
	{
		printf("Couldn't get result from %s\n\n", mysql_error(&mysql));
			return false;
	}

	//打印数据行数
	printf("number of dataline returned: %d\n\n",(int)mysql_affected_rows(&mysql));

	//获取字段的信息
	char* str_field[32];			//定义一个字符串数组存储字段信息
	for (int i = 0; i < 7; i++)		//在已知字段数量的情况下获取字段名
	{
		str_field[i] = mysql_fetch_field(res)->name;	//返回一个所有字段结构的数组。
	}

	for (int i = 0; i < 7; i++)		//打印字段
		printf("%10s	", str_field[i]);

	printf("\n");

	//打印获取的数据
	while (column = mysql_fetch_row(res))   //在已知字段数量情况下，获取并打印下一行
	{
		printf("%10s	%10s	%10s	%10s	%10s	%10s	%10s\n", column[0], column[1], column[2], column[3], column[4], column[5], column[6]);  //column是列数组
	}

	return true;
}



bool QueryStudentOFSname(MYSQL mysql)
{
	char query[500]; //查询语句
	MYSQL_RES* res; //这个结构代表返回行的一个查询结果集
	MYSQL_ROW column; //一个行数据的类型安全(type-safe)的表示，表示数据行的列

	char queryin[500];
	char Sname[40];
	cin>>Sname;
	strcpy(queryin, "select Student.Sno as 学号,Sname as 姓名,Birthday as 生日,Ssex as 性别,Mname as 专业,Mdept as 所属学院,pass as 通过情况 from Student,report,major where report.Sno=student.Sno and major.Mno=report.Mno and Sname='"); //输入查询语句
	strcat(queryin, Sname);
	strcat(queryin, "';");
	mysql_query(&mysql, "set names gbk"); //设置编码格式（SET NAMES GBK也行），否则cmd下中文乱码
	strcpy(query,queryin);
	//返回0 查询成功，返回1查询失败
	if (mysql_query(&mysql, query)) // 执行指定为一个空结尾的字符串的SQL查询。
	{
		printf("Query failed (%s)\n\n", mysql_error(&mysql));
		return false;
	}
	else
	{
		printf("Query success\n\n");
	}

	//获取结果集
	if (!(res = mysql_store_result(&mysql)))    //获得sql语句结束后返回的结果集
	{
		printf("Couldn't get result from %s\n\n", mysql_error(&mysql));
		return false;
	}

	//打印数据行数
	printf("number of dataline returned: %d\n\n", (int)mysql_affected_rows(&mysql));

	//获取字段的信息
	char* str_field[32];			//定义一个字符串数组存储字段信息
	for (int i = 0; i < 7; i++)		//在已知字段数量的情况下获取字段名
	{
		str_field[i] = mysql_fetch_field(res)->name;	//返回一个所有字段结构的数组。
	}

	for (int i = 0; i < 7; i++)		//打印字段
		printf("%10s	", str_field[i]);

	printf("\n");

	//打印获取的数据
	while (column = mysql_fetch_row(res))   //在已知字段数量情况下，获取并打印下一行
	{
        printf("%10s	%10s	%10s	%10s	%10s	%10s	%10s\n", column[0], column[1], column[2], column[3], column[4], column[5], column[6]);  //column是列数组
	}

	return true;
}


bool QueryStudentOFSno(MYSQL mysql)
{
	char query[500]; //查询语句
	MYSQL_RES* res; //这个结构代表返回行的一个查询结果集
	MYSQL_ROW column; //一个行数据的类型安全(type-safe)的表示，表示数据行的列

	char queryin[500];
	char Sno[20];
	cin >> Sno;
	strcpy(queryin, "select Student.Sno as 学号,Sname as 姓名,Birthday as 生日,Ssex as 性别,Mname as 专业,Mdept as 所属学院,pass as 通过情况 from Student,report,major where report.Sno=student.Sno and major.Mno=report.Mno and student.Sno='"); //输入查询语句
	strcat(queryin, Sno);
	strcat(queryin, "';");
	mysql_query(&mysql, "set names gbk"); //设置编码格式（SET NAMES GBK也行），否则cmd下中文乱码
	strcpy(query, queryin);
	//返回0 查询成功，返回1查询失败
	if (mysql_query(&mysql, query)) // 执行指定为一个空结尾的字符串的SQL查询。
	{
		printf("Query failed (%s)\n\n", mysql_error(&mysql));
		return false;
	}
	else
	{
		printf("Query success\n\n");
	}

	//获取结果集
	if (!(res = mysql_store_result(&mysql)))    //获得sql语句结束后返回的结果集
	{
		printf("Couldn't get result from %s\n\n", mysql_error(&mysql));
		return false;
	}

	//打印数据行数
	printf("number of dataline returned: %d\n\n", (int)mysql_affected_rows(&mysql));

	//获取字段的信息
	char* str_field[32];			//定义一个字符串数组存储字段信息
	for (int i = 0; i < 7; i++)		//在已知字段数量的情况下获取字段名
	{
		str_field[i] = mysql_fetch_field(res)->name;	//返回一个所有字段结构的数组。
	}

	for (int i = 0; i < 7; i++)		//打印字段
		printf("%10s	", str_field[i]);

	printf("\n");

	//打印获取的数据
	while (column = mysql_fetch_row(res))   //在已知字段数量情况下，获取并打印下一行
	{
        printf("%10s	%10s	%10s	%10s	%10s	%10s	%10s\n", column[0], column[1], column[2], column[3], column[4], column[5], column[6]);  //column是列数组
	}

	return true;
}

bool QueryStudentOFSno(MYSQL mysql, char Sno[])
{
	char query[500]; //查询语句
	MYSQL_RES* res; //这个结构代表返回行的一个查询结果集
	MYSQL_ROW column; //一个行数据的类型安全(type-safe)的表示，表示数据行的列

	char queryin[500];
	strcpy(queryin, "select Sno as 学号,Sname as 姓名,Birthday as 生日,Ssex as 性别 from Student where Sno='"); //输入查询语句
	strcat(queryin, Sno);
	strcat(queryin, "';");
	mysql_query(&mysql, "set names gbk"); //设置编码格式（SET NAMES GBK也行），否则cmd下中文乱码
	strcpy(query, queryin);
	//返回0 查询成功，返回1查询失败
	if (mysql_query(&mysql, query)) // 执行指定为一个空结尾的字符串的SQL查询。
	{
		printf("Query failed (%s)\n\n", mysql_error(&mysql));
		return false;
	}
	else
	{
		printf("Query success\n\n");
	}

	//获取结果集
	if (!(res = mysql_store_result(&mysql)))    //获得sql语句结束后返回的结果集
	{
		printf("Couldn't get result from %s\n\n", mysql_error(&mysql));
		return false;
	}

	//获取字段的信息
	char* str_field[32];			//定义一个字符串数组存储字段信息
	for (int i = 0; i < 4; i++)		//在已知字段数量的情况下获取字段名
	{
		str_field[i] = mysql_fetch_field(res)->name;	//返回一个所有字段结构的数组。
	}

	for (int i = 0; i < 4; i++)		//打印字段
		printf("%10s	", str_field[i]);

	printf("\n");

	//打印获取的数据
	while (column = mysql_fetch_row(res))   //在已知字段数量情况下，获取并打印下一行
	{
		printf("%10s	%10s	%10s	%10s\n", column[0], column[1], column[2], column[3]);  //column是列数组
	}

	return true;
}

bool QueryStudentOFAge(MYSQL mysql, int age)
{
	char query[500]; //查询语句
	MYSQL_RES* res; //这个结构代表返回行的一个查询结果集
	MYSQL_ROW column; //一个行数据的类型安全(type-safe)的表示，表示数据行的列
	char Age[12];
	strcpy(Age, Sage(age));
	char queryin[500];
	//select Sno as 学号,Sname as 姓名,Birthday as 生日,Ssex as 性别 from Student where Birthday >= STR_TO_DATE('2000-1-1','%Y-%m-%d') order by Birthday desc;
	strcpy(queryin, "select Sno as 学号,Sname as 姓名,Birthday as 生日,Ssex as 性别 from Student where Birthday <= STR_TO_DATE('");
	strcat(queryin, Age);
	strcat(queryin, "','%Y-%m-%d')");
	strcat(queryin, " order by Birthday desc;");
	mysql_query(&mysql, "set names gbk"); //设置编码格式（SET NAMES GBK也行），否则cmd下中文乱码
	strcpy(query, queryin);
	//返回0 查询成功，返回1查询失败
	if (mysql_query(&mysql, query)) // 执行指定为一个空结尾的字符串的SQL查询。
	{
		printf("Query failed (%s)\n\n", mysql_error(&mysql));
		return false;
	}
	else
	{
		printf("Query success\n\n");
	}

	//获取结果集
	if (!(res = mysql_store_result(&mysql)))    //获得sql语句结束后返回的结果集
	{
		printf("Couldn't get result from %s\n\n", mysql_error(&mysql));
		return false;
	}

	//获取字段的信息
	char* str_field[32];			//定义一个字符串数组存储字段信息
	for (int i = 0; i < 4; i++)		//在已知字段数量的情况下获取字段名
	{
		str_field[i] = mysql_fetch_field(res)->name;	//返回一个所有字段结构的数组。
	}

	for (int i = 0; i < 4; i++)		//打印字段
		printf("%10s	", str_field[i]);

	printf("\n");

	//打印获取的数据
	while (column = mysql_fetch_row(res))   //在已知字段数量情况下，获取并打印下一行
	{
		printf("%10s	%10s	%10s	%10s\n", column[0], column[1], column[2], column[3]);  //column是列数组
	}

	return true;
}