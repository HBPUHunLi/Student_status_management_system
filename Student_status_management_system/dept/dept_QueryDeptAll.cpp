#include"studentM.h"

bool dept_QueryDeptAll(MYSQL mysql)
{
	char query[500]; //��ѯ���
	MYSQL_RES* res; //����ṹ�������е�һ����ѯ�����
	MYSQL_ROW column; //һ�������ݵ����Ͱ�ȫ(type-safe)�ı�ʾ����ʾ�����е���

	strcpy(query, "select Dname as ѧԺ�� from Dept;"); //�����ѯ���
	mysql_query(&mysql, "set names gbk"); //���ñ����ʽ��SET NAMES GBKҲ�У�������cmd����������

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
	while (column = mysql_fetch_row(res))   //����֪�ֶ���������£���ȡ����ӡ��һ��
	{
		printf("%10s\n", column[0]);  //column��������
	}

	return true;
}