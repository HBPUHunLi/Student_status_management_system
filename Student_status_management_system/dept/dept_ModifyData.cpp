#include "studentM.h"

bool dept_ModifyData(MYSQL mysql)
{
    char query[500];
    char Dname[20];
    char DnameM[20];
    cout << "������Ҫ�޸ĵ�ѧԺ����"<<endl;
    cin >> Dname;
    cout << "�������޸ĺ������ѧԺ" << endl;
    cin >> DnameM;
    strcpy(query, "update Dept set Dname='");
    strcat(query, DnameM);
    strcat(query, "' where Dname = '");
    strcat(query , Dname);
    strcat(query, "';");

    if (mysql_query(&mysql, query))        //ִ��SQL���  
    {
        printf("Modify Data failed (%s)\n\n", mysql_error(&mysql));
        return false;
    }
    else
    {
        printf("Modify Data success\n\n");
        cout << "�޸ĺ��ѧԺ��ϢΪ" <<endl<<DnameM<<endl;
        return true;
    }

}
