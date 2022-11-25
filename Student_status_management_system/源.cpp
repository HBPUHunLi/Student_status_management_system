#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <stdio.h>
#include <mysql.h>
#include <string.h>

using namespace std;

MYSQL mysql; //mysql����
//MYSQL_FIELD* fd;  //�ֶ�������
//char field[32][32];  //���ֶ�����ά����
//MYSQL_RES* res; //����ṹ�������е�һ����ѯ�����
//MYSQL_ROW column; //һ�������ݵ����Ͱ�ȫ(type-safe)�ı�ʾ����ʾ�����е���
char query[150]; //��ѯ���



bool ConnectDatabase();		//�������ݿ� 
//void FreeConnect();			//�ͷ���Դ  
//bool QueryDatabase1();  	//��ѯ1  
//bool QueryDatabase2();  	//��ѯ2  
bool InsertData();			//��
//bool ModifyData();			//��
//bool DeleteData();			//ɾ




//-----------------------------������-----------------------------
int main() {

	ConnectDatabase();
	InsertData();
	//FreeConnect();
	return 0;
}
//-----------------------------������-----------------------------



//�������ݿ�  
bool ConnectDatabase()
{
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
//�ͷ���Դ
void FreeConnect()
{
	mysql_free_result(res);  //�ͷ�һ���������ʹ�õ��ڴ档
	mysql_close(&mysql);	 //�ر�һ�����������ӡ�
}
*/
/*
//��ѯ����
bool QueryDatabase1()
{
	char queryin[150];
	cin >> queryin;
	strcpy(query,queryin); //�����ѯ���
	mysql_query(&mysql, "set names gbk"); //���ñ����ʽ��SET NAMES GBKҲ�У�������cmd����������

	//����0 ��ѯ�ɹ�������1��ѯʧ��
	if (mysql_query(&mysql, query)) // ִ��ָ��Ϊһ���ս�β���ַ�����SQL��ѯ��
	{
		printf("Query failed (%s)\n\n", mysql_error(&mysql));
			return false;
	}
	else
	{
		printf("query success\n\n");
	}

	//��ȡ�����
	if (!(res = mysql_store_result(&mysql)))    //���sql�������󷵻صĽ����
	{
		printf("Couldn't get result from %s\n\n", mysql_error(&mysql));
			return false;
	}

	//��ӡ��������
	printf("number of dataline returned: %d\n", mysql_affected_rows(&mysql));

	//��ȡ�ֶε���Ϣ
	char* str_field[32];			//����һ���ַ�������洢�ֶ���Ϣ
	for (int i = 0; i < 4; i++)		//����֪�ֶ�����������»�ȡ�ֶ���
	{
		str_field[i] = mysql_fetch_field(res)->name;	//����һ�������ֶνṹ�����顣
	}

	for (int i = 0; i < 4; i++)		//��ӡ�ֶ�
		printf("%10s	", str_field[i]);

	printf("");

	//��ӡ��ȡ������
	while (column = mysql_fetch_row(res))   //����֪�ֶ���������£���ȡ����ӡ��һ��
	{
		printf("%10s	%10s	%10s	%10s", column[0], column[1], column[2], column[3]);  //column��������
	}

	return true;
}
*/
//��������  
bool InsertData()
{
	char query[150];
	char Sno[20];
	char Sname[40];
	char Birthday[12];
	char Ssex[4];
	char Sdept[40];
	char queryin[150];
	cout << "������ѧ�� ���� �������ڣ�xxxx.xx.xx�� �Ա� ����ѧԺ" << endl;
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

	if (mysql_query(&mysql, query))        //ִ��SQL���  
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