#include"studentM.h"

bool dept_QueryDeptIFDname(MYSQL mysql)
{
	char query[500]; //��ѯ���
	MYSQL_RES* res; //����ṹ�������е�һ����ѯ�����
	MYSQL_ROW column; //һ�������ݵ����Ͱ�ȫ(type-safe)�ı�ʾ����ʾ�����е���

	char queryin[500];
	char Dname[40];
	cin >> Dname;
	strcpy(queryin, "select Dname as ѧԺ�� from Dept where Dname='"); //�����ѯ���
	strcat(queryin, Dname);
	strcat(queryin, "';");
	mysql_query(&mysql, "set names gbk"); //���ñ����ʽ��SET NAMES GBKҲ�У�������cmd����������
	strcpy(query, queryin);
	//����0 ��ѯ�ɹ�������1��ѯʧ��
	if (mysql_query(&mysql, query)) // ִ��ָ��Ϊһ���ս�β���ַ�����SQL��ѯ��
	{
		printf("Query failed (%s)\n\n", mysql_error(&mysql));
		return false;
	}
	else
	{
		printf("Query success\n\n");
	}

	//��ȡ�����
	if (!(res = mysql_store_result(&mysql)))    //���sql�������󷵻صĽ����
	{
		printf("Couldn't get result from %s\n\n", mysql_error(&mysql));
		return false;
	}

	//��ӡ��������
	printf("number of dataline returned: %d\n\n", (int)mysql_affected_rows(&mysql));

	//��ȡ�ֶε���Ϣ
	char* str_field[32];			//����һ���ַ�������洢�ֶ���Ϣ
	for (int i = 0; i < 1; i++)		//����֪�ֶ�����������»�ȡ�ֶ���
	{
		str_field[i] = mysql_fetch_field(res)->name;	//����һ�������ֶνṹ�����顣
	}

	for (int i = 0; i < 1; i++)		//��ӡ�ֶ�
		printf("%10s	", str_field[i]);

	printf("\n");

	//��ӡ��ȡ������
	if (column = mysql_fetch_row(res))   //����֪�ֶ���������£���ȡ����ӡ��һ��
	{
		printf("����");
	}
	else
		printf("������");


	return true;
}