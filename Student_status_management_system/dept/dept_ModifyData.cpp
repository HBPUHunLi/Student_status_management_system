#include "studentM.h"

bool dept_ModifyData(MYSQL mysql)
{
    char query[500];
    char Dname[20];
    char DnameM[20];
    cout << "请输入要修改的学院名称"<<endl;
    cin >> Dname;
    cout << "请输入修改后的所属学院" << endl;
    cin >> DnameM;
    strcpy(query, "update Dept set Dname='");
    strcat(query, DnameM);
    strcat(query, "' where Dname = '");
    strcat(query , Dname);
    strcat(query, "';");

    if (mysql_query(&mysql, query))        //执行SQL语句  
    {
        printf("Modify Data failed (%s)\n\n", mysql_error(&mysql));
        return false;
    }
    else
    {
        printf("Modify Data success\n\n");
        cout << "修改后的学院信息为" <<endl<<DnameM<<endl;
        return true;
    }

}
