#include"studentM.h"

bool major_DeleteData(MYSQL mysql)
{
    char query[500];
    char Mno[20];
    strcpy(query, "delete from Major where Mno='");
    cout << "������רҵ��ɾ����רҵ��Ϣ" << endl;
    cin >> Mno;
    strcat(query, Mno);
    strcat(query, "';");
    if (mysql_query(&mysql, query))
    {
        printf("Query failed (%s)", mysql_error(&mysql));
        return false;
    }
    else
    {
        printf("Delete Data success\n\n");
        return true;
    }
}