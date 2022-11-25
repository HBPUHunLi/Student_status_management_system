#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <stdio.h>
#include <mysql.h>
#include <string.h>

using namespace std;

MYSQL mysql; //mysql连接
//MYSQL_FIELD* fd;  //字段列数组
//char field[32][32];  //存字段名二维数组
//MYSQL_RES* res; //这个结构代表返回行的一个查询结果集
//MYSQL_ROW column; //一个行数据的类型安全(type-safe)的表示，表示数据行的列
char query[150]; //查询语句



bool ConnectDatabase();		//连接数据库 
//void FreeConnect();			//释放资源  
//bool QueryDatabase1();  	//查询1  
//bool QueryDatabase2();  	//查询2  
bool InsertData();			//增
//bool ModifyData();			//改
//bool DeleteData();			//删




//-----------------------------主函数-----------------------------
int main() {

	ConnectDatabase();
	InsertData();
	//FreeConnect();
	return 0;
}
//-----------------------------主函数-----------------------------



//连接数据库  
bool ConnectDatabase()
{
	cout << "Link Start..." << endl << endl;
	//初始化mysql  
	mysql_init(&mysql);  //连接mysql，数据库  
	const char host[] = "127.0.0.1";
	const char user[] = "root";
	const char psw[] = "123456";
	const char database[] = "student_stuats_management_system";
	const int port = 3306;
	//返回false则连接失败，返回true则连接成功  
	if (!(mysql_real_connect(&mysql, host, user, psw, database, port, NULL, 0)))
		//中间分别是主机，用户名，密码，数据库名，端口号（可以写默认0或者3306等），可以先写成参数再传进去  
	{
		printf("Error connecting to database:%s\n", mysql_error(&mysql));
		return false;
	}
	else
	{
		printf("Connected...\n\n");
		mysql_query(&mysql, "set names gbk");
		return true;
	}
}
/*
//释放资源
void FreeConnect()
{
	mysql_free_result(res);  //释放一个结果集合使用的内存。
	mysql_close(&mysql);	 //关闭一个服务器连接。
}
*/
/*
//查询数据
bool QueryDatabase1()
{
	char queryin[150];
	cin >> queryin;
	strcpy(query,queryin); //输入查询语句
	mysql_query(&mysql, "set names gbk"); //设置编码格式（SET NAMES GBK也行），否则cmd下中文乱码

	//返回0 查询成功，返回1查询失败
	if (mysql_query(&mysql, query)) // 执行指定为一个空结尾的字符串的SQL查询。
	{
		printf("Query failed (%s)\n\n", mysql_error(&mysql));
			return false;
	}
	else
	{
		printf("query success\n\n");
	}

	//获取结果集
	if (!(res = mysql_store_result(&mysql)))    //获得sql语句结束后返回的结果集
	{
		printf("Couldn't get result from %s\n\n", mysql_error(&mysql));
			return false;
	}

	//打印数据行数
	printf("number of dataline returned: %d\n", mysql_affected_rows(&mysql));

	//获取字段的信息
	char* str_field[32];			//定义一个字符串数组存储字段信息
	for (int i = 0; i < 4; i++)		//在已知字段数量的情况下获取字段名
	{
		str_field[i] = mysql_fetch_field(res)->name;	//返回一个所有字段结构的数组。
	}

	for (int i = 0; i < 4; i++)		//打印字段
		printf("%10s	", str_field[i]);

	printf("");

	//打印获取的数据
	while (column = mysql_fetch_row(res))   //在已知字段数量情况下，获取并打印下一行
	{
		printf("%10s	%10s	%10s	%10s", column[0], column[1], column[2], column[3]);  //column是列数组
	}

	return true;
}
*/
//插入数据  
bool InsertData()
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