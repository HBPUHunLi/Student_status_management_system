#include"studentM.h"

char* in()
{
    char Mno[20];
    cout << "������Ҫ�޸���Ϣ��רҵ��" << endl;
    cin >> Mno;
    return Mno;
}

bool major_ModifyData(MYSQL mysql)
{
    char query[500];
    char Mno[20];
    char Mname[20];
    char Mdept[20];
    int x;
    cout << "�����������ѡ��Ҫ�޸ĵ���Ϣ" << endl;
    cout << "1.רҵ����" << endl;
    cout << "2.����ѧԺ" << endl;
    cout << "ȡ���޸����������������" << endl;
    cin >> x;
    switch (x)
    {
    case 1: {
        strcpy(Mno, in());
        cout << "�������޸ĺ��רҵ����" << endl;
        cin >> Mname;
        strcpy(query, "update Major set Mname='");
        strcat(query, Mname);
        strcat(query, "' where Mno = '");
        strcat(query, Mno);
        strcat(query, "';");
        break;
    }
    case 2: {
        strcpy(Mno, in());
        cout << "�������޸ĺ������ѧԺ" << endl;
        cin >> Mdept;
        strcpy(query, "update Major set Mdept='");
        strcat(query, Mdept);
        strcat(query, "' where Mno = '");
        strcat(query, Mno);
        strcat(query, "';");
        break;
    }
    default: {
        cout << "��ѡ����ȡ���޸�" << endl;
        return false;
    }
    }
    if (mysql_query(&mysql, query))        //ִ��SQL���  
    {
        printf("Modify Data failed (%s)\n\n", mysql_error(&mysql));
        return false;
    }
    else
    {
        printf("Modify Data success\n\n");
        cout << "�޸ĺ��רҵ��ϢΪ" << endl;
        QueryMajorOFMno(mysql, Mno);
        return true;
    }

}