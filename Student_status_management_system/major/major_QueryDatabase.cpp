#include"studentM.h"


//��ѯ����
bool QueryMajorAll(MYSQL mysql)
{
    char query[500]; //��ѯ���
    MYSQL_RES* res; //����ṹ�������е�һ����ѯ�����
    MYSQL_ROW column; //һ�������ݵ����Ͱ�ȫ(type-safe)�ı�ʾ����ʾ�����е���

    strcpy(query, "select Mno as רҵ��,Mname as רҵ����,Mdept as ����ѧԺ from Major order by Mdept;"); //�����ѯ���
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
    for (int i = 0; i < 3; i++)		//����֪�ֶ�����������»�ȡ�ֶ���
    {
        str_field[i] = mysql_fetch_field(res)->name;	//����һ�������ֶνṹ�����顣
    }

    for (int i = 0; i < 3; i++)		//��ӡ�ֶ�
        printf("%10s	", str_field[i]);

    printf("\n");

    //��ӡ��ȡ������
    while (column = mysql_fetch_row(res))   //����֪�ֶ���������£���ȡ����ӡ��һ��
    {
        printf("%10s	%10s	%10s	\n", column[0], column[1], column[2]);  //column��������
    }

    return true;
}


bool QueryMajorOFMno(MYSQL mysql, char Mno[])
{
    char query[500]; //��ѯ���
    MYSQL_RES* res; //����ṹ�������е�һ����ѯ�����
    MYSQL_ROW column; //һ�������ݵ����Ͱ�ȫ(type-safe)�ı�ʾ����ʾ�����е���

    char queryin[500];
    strcpy(queryin, "select Mno as רҵ��,Mname as רҵ����,Mdept as ����ѧԺ from Major where Mno='"); //�����ѯ���
    strcat(queryin, Mno);
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
    for (int i = 0; i < 3; i++)		//����֪�ֶ�����������»�ȡ�ֶ���
    {
        str_field[i] = mysql_fetch_field(res)->name;	//����һ�������ֶνṹ�����顣
    }

    for (int i = 0; i < 3; i++)		//��ӡ�ֶ�
        printf("%10s	", str_field[i]);

    printf("\n");

    //��ӡ��ȡ������
    while (column = mysql_fetch_row(res))   //����֪�ֶ���������£���ȡ����ӡ��һ��
    {
        printf("%10s	%10s	%10s	\n", column[0], column[1], column[2]);  //column��������
    }

    return true;
}


bool QueryMajorOFMno(MYSQL mysql)
{
    cout << "��������Ҫ��ѯ��רҵ��" << endl;
    char query[500]; //��ѯ���
    MYSQL_RES* res; //����ṹ�������е�һ����ѯ�����
    MYSQL_ROW column; //һ�������ݵ����Ͱ�ȫ(type-safe)�ı�ʾ����ʾ�����е���

    char queryin[500];
    char Mno[20];
    cin >> Mno;
    strcpy(queryin, "select Mno as רҵ��,Mname as רҵ����,Mdept as ����ѧԺ from Major where Mno='"); //�����ѯ���
    strcat(queryin, Mno);
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
    for (int i = 0; i < 3; i++)		//����֪�ֶ�����������»�ȡ�ֶ���
    {
        str_field[i] = mysql_fetch_field(res)->name;	//����һ�������ֶνṹ�����顣
    }

    for (int i = 0; i < 3; i++)		//��ӡ�ֶ�
        printf("%10s	", str_field[i]);

    printf("\n");

    //��ӡ��ȡ������
    while (column = mysql_fetch_row(res))   //����֪�ֶ���������£���ȡ����ӡ��һ��
    {
        printf("%10s	%10s	%10s	\n", column[0], column[1], column[2]);  //column��������
    }

    return true;
}



bool QueryMajorOFMname(MYSQL mysql)
{
    cout << "��������Ҫ��ѯרҵ����" << endl;
    char query[500]; //��ѯ���
    MYSQL_RES* res; //����ṹ�������е�һ����ѯ�����
    MYSQL_ROW column; //һ�������ݵ����Ͱ�ȫ(type-safe)�ı�ʾ����ʾ�����е���

    char queryin[500];
    char Mname[20];
    cin >> Mname;
    strcpy(queryin, "select Mno as רҵ��,Mname as רҵ����,Mdept as ����ѧԺ from Major where Mname='"); //�����ѯ���
    strcat(queryin, Mname);
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
    for (int i = 0; i < 3; i++)		//����֪�ֶ�����������»�ȡ�ֶ���
    {
        str_field[i] = mysql_fetch_field(res)->name;	//����һ�������ֶνṹ�����顣
    }

    for (int i = 0; i < 3; i++)		//��ӡ�ֶ�
        printf("%10s	", str_field[i]);

    printf("\n");

    //��ӡ��ȡ������
    while (column = mysql_fetch_row(res))   //����֪�ֶ���������£���ȡ����ӡ��һ��
    {
        printf("%10s	%10s	%10s	\n", column[0], column[1], column[2]);  //column��������
    }

    return true;
}
