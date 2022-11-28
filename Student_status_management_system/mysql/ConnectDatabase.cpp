#include"studentM.h"

//连接数据库  
MYSQL ConnectDatabase()
{
	MYSQL mysql;
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
		return mysql;
	}
	else
	{
		printf("Connected...\n\n");
		mysql_query(&mysql, "set names gbk");
		return mysql;
	}
}