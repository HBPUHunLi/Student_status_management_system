#include"studentM.h"

bool QueryReportALL(MYSQL mysql)
{
    char query[500]; //��ѯ���
    MYSQL_RES* res; //����ṹ�������е�һ����ѯ�����
    MYSQL_ROW column; //һ�������ݵ����Ͱ�ȫ(type-safe)�ı�ʾ����ʾ�����е���
    strcpy(query, "select Report.Sno as ѧ��,Sname as ѧ������,Mname as ����רҵ,Mdept as ����ѧԺ,pass as ͨ����� from student,report,major where student.Sno=report.Sno and major.Mno=report.Mno order by Mdept;"); //�����ѯ���
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
    for (int i = 0; i < 5; i++)		//����֪�ֶ�����������»�ȡ�ֶ���
    {
        str_field[i] = mysql_fetch_field(res)->name;	//����һ�������ֶνṹ�����顣
    }

    for (int i = 0; i < 5; i++)		//��ӡ�ֶ�
        printf("%10s	", str_field[i]);

    printf("\n");

    //��ӡ��ȡ������
    while (column = mysql_fetch_row(res))   //����֪�ֶ���������£���ȡ����ӡ��һ��
    {
        printf("%10s\t%10s\t%10s\t%10s\t%10s\n", column[0], column[1], column[2], column[3],column[4]);  //column��������
    }

    return true;
}

bool QueryReportOFSno(MYSQL mysql)
{
    char query[500]; //��ѯ���
    MYSQL_RES* res; //����ṹ�������е�һ����ѯ�����
    MYSQL_ROW column; //һ�������ݵ����Ͱ�ȫ(type-safe)�ı�ʾ����ʾ�����е���
    char Sno[20];
    cout << "������Ҫ��ѯ��ѧ��ѧ��"<<endl;
    cin >> Sno;
    strcpy(query, "select Report.Sno as ѧ��,Sname as ѧ������,Mname as ����רҵ,Mdept as ����ѧԺ,pass as ͨ����� from student,report,major where student.Sno=report.Sno and major.Mno=report.Mno and report.Sno = '"); //�����ѯ���
    strcat(query,Sno);
    strcat(query, "' order by Mdept;");
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
    for (int i = 0; i < 5; i++)		//����֪�ֶ�����������»�ȡ�ֶ���
    {
        str_field[i] = mysql_fetch_field(res)->name;	//����һ�������ֶνṹ�����顣
    }

    for (int i = 0; i < 5; i++)		//��ӡ�ֶ�
        printf("%10s	", str_field[i]);

    printf("\n");

    //��ӡ��ȡ������
    while (column = mysql_fetch_row(res))   //����֪�ֶ���������£���ȡ����ӡ��һ��
    {
        printf("%10s\t%10s\t%10s\t%10s\t%10s\n", column[0], column[1], column[2], column[3], column[4]);  //column��������
    }

    return true;
}

bool QueryReportOFMname(MYSQL mysql)
{
    char query[500]; //��ѯ���
    MYSQL_RES* res; //����ṹ�������е�һ����ѯ�����
    MYSQL_ROW column; //һ�������ݵ����Ͱ�ȫ(type-safe)�ı�ʾ����ʾ�����е���
    char Mname[20];
    cout << "������Ҫ��ѯ��רҵ" << endl;
    cin >> Mname;
    strcpy(query, "select Report.Sno as ѧ��,Sname as ѧ������,Mname as ����רҵ,Mdept as ����ѧԺ,pass as ͨ����� from student,report,major where student.Sno=report.Sno and report.Mno = major.Mno and major.Mname = '"); //�����ѯ���
    strcat(query, Mname);
    strcat(query, "' order by Mdept;");
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
    for (int i = 0; i < 5; i++)		//����֪�ֶ�����������»�ȡ�ֶ���
    {
        str_field[i] = mysql_fetch_field(res)->name;	//����һ�������ֶνṹ�����顣
    }

    for (int i = 0; i < 5; i++)		//��ӡ�ֶ�
        printf("%10s	", str_field[i]);

    printf("\n");

    //��ӡ��ȡ������
    while (column = mysql_fetch_row(res))   //����֪�ֶ���������£���ȡ����ӡ��һ��
    {
        printf("%10s\t%10s\t%10s\t%10s\t%10s\n", column[0], column[1], column[2], column[3], column[4]);  //column��������
    }

    return true;
}