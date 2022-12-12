#include"studentM.h"

char* in()
{
    char Mno[20];
    cout << "请输入要修改信息的专业号" << endl;
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
    cout << "请输入序号来选择要修改的信息" << endl;
    cout << "1.专业名称" << endl;
    cout << "2.所属学院" << endl;
    cout << "取消修改请输入其他任意键" << endl;
    cin >> x;
    switch (x)
    {
    case 1: {
        strcpy(Mno, in());
        cout << "请输入修改后的专业名称" << endl;
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
        cout << "请输入修改后的所属学院" << endl;
        cin >> Mdept;
        strcpy(query, "update Major set Mdept='");
        strcat(query, Mdept);
        strcat(query, "' where Mno = '");
        strcat(query, Mno);
        strcat(query, "';");
        break;
    }
    default: {
        cout << "您选择了取消修改" << endl;
        return false;
    }
    }
    if (mysql_query(&mysql, query))        //执行SQL语句  
    {
        printf("Modify Data failed (%s)\n\n", mysql_error(&mysql));
        return false;
    }
    else
    {
        printf("Modify Data success\n\n");
        cout << "修改后的专业信息为" << endl;
        QueryMajorOFMno(mysql, Mno);
        return true;
    }

}