#include "studentM.h"

bool report_ModifyData(MYSQL mysql)
{
    char query[500];
    char Sno[20];
    char Mno[20];
    char pass[2];
    cout << "请输入要修改的学生学号" << endl;
    cin >> Sno;
    cout << "请输入修改后的专业号" << endl;
    cin >> Mno;
    cout << "请输入是否通过"<<endl;
    cin >> pass;
    strcpy(query, "update Report set Mno='");
    strcat(query, Mno);
    strcat(query, "',pass = '");
    strcat(query, pass);
    strcat(query, "' where Sno = '");
    strcat(query, Sno);
    strcat(query, "';");

    if (mysql_query(&mysql, query))        //执行SQL语句  
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
