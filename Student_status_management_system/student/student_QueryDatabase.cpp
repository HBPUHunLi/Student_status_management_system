#include"studentM.h"


//��ѯ����
bool QueryStudentAll(MYSQL mysql)
{
	char query[500]; //��ѯ���
	MYSQL_RES* res; //����ṹ�������е�һ����ѯ�����
	MYSQL_ROW column; //һ�������ݵ����Ͱ�ȫ(type-safe)�ı�ʾ����ʾ�����е���

	strcpy(query, "select Student.Sno as ѧ��,Sname as ����,Birthday as ����,Ssex as �Ա�,Mname as רҵ,Mdept as ����ѧԺ,pass as ͨ����� from Student,report,major where report.Sno=student.Sno and major.Mno=report.Mno;"); //�����ѯ���
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
	printf("number of dataline returned: %d\n\n",(int)mysql_affected_rows(&mysql));

	//��ȡ�ֶε���Ϣ
	char* str_field[32];			//����һ���ַ�������洢�ֶ���Ϣ
	for (int i = 0; i < 7; i++)		//����֪�ֶ�����������»�ȡ�ֶ���
	{
		str_field[i] = mysql_fetch_field(res)->name;	//����һ�������ֶνṹ�����顣
	}

	for (int i = 0; i < 7; i++)		//��ӡ�ֶ�
		printf("%10s	", str_field[i]);

	printf("\n");

	//��ӡ��ȡ������
	while (column = mysql_fetch_row(res))   //����֪�ֶ���������£���ȡ����ӡ��һ��
	{
		printf("%10s	%10s	%10s	%10s	%10s	%10s	%10s\n", column[0], column[1], column[2], column[3], column[4], column[5], column[6]);  //column��������
	}

	return true;
}



bool QueryStudentOFSname(MYSQL mysql)
{
	char query[500]; //��ѯ���
	MYSQL_RES* res; //����ṹ�������е�һ����ѯ�����
	MYSQL_ROW column; //һ�������ݵ����Ͱ�ȫ(type-safe)�ı�ʾ����ʾ�����е���

	char queryin[500];
	char Sname[40];
	cin>>Sname;
	strcpy(queryin, "select Student.Sno as ѧ��,Sname as ����,Birthday as ����,Ssex as �Ա�,Mname as רҵ,Mdept as ����ѧԺ,pass as ͨ����� from Student,report,major where report.Sno=student.Sno and major.Mno=report.Mno and Sname='"); //�����ѯ���
	strcat(queryin, Sname);
	strcat(queryin, "';");
	mysql_query(&mysql, "set names gbk"); //���ñ����ʽ��SET NAMES GBKҲ�У�������cmd����������
	strcpy(query,queryin);
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
	for (int i = 0; i < 7; i++)		//����֪�ֶ�����������»�ȡ�ֶ���
	{
		str_field[i] = mysql_fetch_field(res)->name;	//����һ�������ֶνṹ�����顣
	}

	for (int i = 0; i < 7; i++)		//��ӡ�ֶ�
		printf("%10s	", str_field[i]);

	printf("\n");

	//��ӡ��ȡ������
	while (column = mysql_fetch_row(res))   //����֪�ֶ���������£���ȡ����ӡ��һ��
	{
        printf("%10s	%10s	%10s	%10s	%10s	%10s	%10s\n", column[0], column[1], column[2], column[3], column[4], column[5], column[6]);  //column��������
	}

	return true;
}


bool QueryStudentOFSno(MYSQL mysql)
{
	char query[500]; //��ѯ���
	MYSQL_RES* res; //����ṹ�������е�һ����ѯ�����
	MYSQL_ROW column; //һ�������ݵ����Ͱ�ȫ(type-safe)�ı�ʾ����ʾ�����е���

	char queryin[500];
	char Sno[20];
	cin >> Sno;
	strcpy(queryin, "select Student.Sno as ѧ��,Sname as ����,Birthday as ����,Ssex as �Ա�,Mname as רҵ,Mdept as ����ѧԺ,pass as ͨ����� from Student,report,major where report.Sno=student.Sno and major.Mno=report.Mno and student.Sno='"); //�����ѯ���
	strcat(queryin, Sno);
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
	for (int i = 0; i < 7; i++)		//����֪�ֶ�����������»�ȡ�ֶ���
	{
		str_field[i] = mysql_fetch_field(res)->name;	//����һ�������ֶνṹ�����顣
	}

	for (int i = 0; i < 7; i++)		//��ӡ�ֶ�
		printf("%10s	", str_field[i]);

	printf("\n");

	//��ӡ��ȡ������
	while (column = mysql_fetch_row(res))   //����֪�ֶ���������£���ȡ����ӡ��һ��
	{
        printf("%10s	%10s	%10s	%10s	%10s	%10s	%10s\n", column[0], column[1], column[2], column[3], column[4], column[5], column[6]);  //column��������
	}

	return true;
}

bool QueryStudentOFSno(MYSQL mysql, char Sno[])
{
	char query[500]; //��ѯ���
	MYSQL_RES* res; //����ṹ�������е�һ����ѯ�����
	MYSQL_ROW column; //һ�������ݵ����Ͱ�ȫ(type-safe)�ı�ʾ����ʾ�����е���

	char queryin[500];
	strcpy(queryin, "select Sno as ѧ��,Sname as ����,Birthday as ����,Ssex as �Ա� from Student where Sno='"); //�����ѯ���
	strcat(queryin, Sno);
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

	//��ȡ�ֶε���Ϣ
	char* str_field[32];			//����һ���ַ�������洢�ֶ���Ϣ
	for (int i = 0; i < 4; i++)		//����֪�ֶ�����������»�ȡ�ֶ���
	{
		str_field[i] = mysql_fetch_field(res)->name;	//����һ�������ֶνṹ�����顣
	}

	for (int i = 0; i < 4; i++)		//��ӡ�ֶ�
		printf("%10s	", str_field[i]);

	printf("\n");

	//��ӡ��ȡ������
	while (column = mysql_fetch_row(res))   //����֪�ֶ���������£���ȡ����ӡ��һ��
	{
		printf("%10s	%10s	%10s	%10s\n", column[0], column[1], column[2], column[3]);  //column��������
	}

	return true;
}

bool QueryStudentOFAge(MYSQL mysql, int age)
{
	char query[500]; //��ѯ���
	MYSQL_RES* res; //����ṹ�������е�һ����ѯ�����
	MYSQL_ROW column; //һ�������ݵ����Ͱ�ȫ(type-safe)�ı�ʾ����ʾ�����е���
	char Age[12];
	strcpy(Age, Sage(age));
	char queryin[500];
	//select Sno as ѧ��,Sname as ����,Birthday as ����,Ssex as �Ա� from Student where Birthday >= STR_TO_DATE('2000-1-1','%Y-%m-%d') order by Birthday desc;
	strcpy(queryin, "select Sno as ѧ��,Sname as ����,Birthday as ����,Ssex as �Ա� from Student where Birthday <= STR_TO_DATE('");
	strcat(queryin, Age);
	strcat(queryin, "','%Y-%m-%d')");
	strcat(queryin, " order by Birthday desc;");
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

	//��ȡ�ֶε���Ϣ
	char* str_field[32];			//����һ���ַ�������洢�ֶ���Ϣ
	for (int i = 0; i < 4; i++)		//����֪�ֶ�����������»�ȡ�ֶ���
	{
		str_field[i] = mysql_fetch_field(res)->name;	//����һ�������ֶνṹ�����顣
	}

	for (int i = 0; i < 4; i++)		//��ӡ�ֶ�
		printf("%10s	", str_field[i]);

	printf("\n");

	//��ӡ��ȡ������
	while (column = mysql_fetch_row(res))   //����֪�ֶ���������£���ȡ����ӡ��һ��
	{
		printf("%10s	%10s	%10s	%10s\n", column[0], column[1], column[2], column[3]);  //column��������
	}

	return true;
}