#include "studentM.h"

bool report_ModifyData(MYSQL mysql)
{
    char query[500];
    char Sno[20];
    char Mno[20];
    char pass[2];
    cout << "������Ҫ�޸ĵ�ѧ��ѧ��" << endl;
    cin >> Sno;
    cout << "�������޸ĺ��רҵ��" << endl;
    cin >> Mno;
    cout << "�������Ƿ�ͨ��"<<endl;
    cin >> pass;
    strcpy(query, "update Report set Mno='");
    strcat(query, Mno);
    strcat(query, "',pass = '");
    strcat(query, pass);
    strcat(query, "' where Sno = '");
    strcat(query, Sno);
    strcat(query, "';");

    if (mysql_query(&mysql, query))        //ִ��SQL���  
    {
        printf("Modify Data failed (%s)\n\n", mysql_error(&mysql));
        return false;
    }
    else
    {
        printf("Modify Data success\n\n");
        return true;
    }

}
