#include"studentM.h"

//�������ݿ�  
MYSQL ConnectDatabase()
{
	MYSQL mysql;
	cout << "Link Start..." << endl << endl;
	//��ʼ��mysql  
	mysql_init(&mysql);  //����mysql�����ݿ�  
	const char host[] = "127.0.0.1";
	const char user[] = "root";
	const char psw[] = "123456";
	const char database[] = "student_stuats_management_system";
	const int port = 3306;
	//����false������ʧ�ܣ�����true�����ӳɹ�  
	if (!(mysql_real_connect(&mysql, host, user, psw, database, port, NULL, 0)))
		//�м�ֱ����������û��������룬���ݿ������˿ںţ�����дĬ��0����3306�ȣ���������д�ɲ����ٴ���ȥ  
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