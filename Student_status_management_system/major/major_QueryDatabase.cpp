#include"studentM.h"


//查询数据
bool QueryMajorAll(MYSQL mysql)
{
    char query[500]; //查询语句
    MYSQL_RES* res; //这个结构代表返回行的一个查询结果集
    MYSQL_ROW column; //一个行数据的类型安全(type-safe)的表示，表示数据行的列

    strcpy(query, "select Mno as 专业号,Mname as 专业名称,Mdept as 所属学院 from Major order by Mdept;"); //输入查询语句
    mysql_query(&mysql, "set names gbk"); //设置编码格式（SET NAMES GBK也行），否则cmd下中文乱码

    //返回0 查询成功，返回1查询失败
    if (mysql_query(&mysql, query)) // 执行指定为一个空结尾的字符串的SQL查询。
    {
        printf("Query failed (%s)\n\n", mysql_error(&mysql));
        return false;
    }
    else
    {
        printf("Query success\n\n");
    }

    //获取结果集
    if (!(res = mysql_store_result(&mysql)))    //获得sql语句结束后返回的结果集
    {
        printf("Couldn't get result from %s\n\n", mysql_error(&mysql));
        return false;
    }

    //打印数据行数
    printf("number of dataline returned: %d\n\n", (int)mysql_affected_rows(&mysql));

    //获取字段的信息
    char* str_field[32];			//定义一个字符串数组存储字段信息
    for (int i = 0; i < 3; i++)		//在已知字段数量的情况下获取字段名
    {
        str_field[i] = mysql_fetch_field(res)->name;	//返回一个所有字段结构的数组。
    }

    for (int i = 0; i < 3; i++)		//打印字段
        printf("%10s	", str_field[i]);

    printf("\n");

    //打印获取的数据
    while (column = mysql_fetch_row(res))   //在已知字段数量情况下，获取并打印下一行
    {
        printf("%10s	%10s	%10s	\n", column[0], column[1], column[2]);  //column是列数组
    }

    return true;
}


bool QueryMajorOFMno(MYSQL mysql, char Mno[])
{
    char query[500]; //查询语句
    MYSQL_RES* res; //这个结构代表返回行的一个查询结果集
    MYSQL_ROW column; //一个行数据的类型安全(type-safe)的表示，表示数据行的列

    char queryin[500];
    strcpy(queryin, "select Mno as 专业号,Mname as 专业名称,Mdept as 所属学院 from Major where Mno='"); //输入查询语句
    strcat(queryin, Mno);
    strcat(queryin, "';");
    mysql_query(&mysql, "set names gbk"); //设置编码格式（SET NAMES GBK也行），否则cmd下中文乱码
    strcpy(query, queryin);
    //返回0 查询成功，返回1查询失败
    if (mysql_query(&mysql, query)) // 执行指定为一个空结尾的字符串的SQL查询。
    {
        printf("Query failed (%s)\n\n", mysql_error(&mysql));
        return false;
    }
    else
    {
        printf("Query success\n\n");
    }

    //获取结果集
    if (!(res = mysql_store_result(&mysql)))    //获得sql语句结束后返回的结果集
    {
        printf("Couldn't get result from %s\n\n", mysql_error(&mysql));
        return false;
    }

    //获取字段的信息
    char* str_field[32];			//定义一个字符串数组存储字段信息
    for (int i = 0; i < 3; i++)		//在已知字段数量的情况下获取字段名
    {
        str_field[i] = mysql_fetch_field(res)->name;	//返回一个所有字段结构的数组。
    }

    for (int i = 0; i < 3; i++)		//打印字段
        printf("%10s	", str_field[i]);

    printf("\n");

    //打印获取的数据
    while (column = mysql_fetch_row(res))   //在已知字段数量情况下，获取并打印下一行
    {
        printf("%10s	%10s	%10s	\n", column[0], column[1], column[2]);  //column是列数组
    }

    return true;
}


bool QueryMajorOFMno(MYSQL mysql)
{
    cout << "请输入需要查询的专业号" << endl;
    char query[500]; //查询语句
    MYSQL_RES* res; //这个结构代表返回行的一个查询结果集
    MYSQL_ROW column; //一个行数据的类型安全(type-safe)的表示，表示数据行的列

    char queryin[500];
    char Mno[20];
    cin >> Mno;
    strcpy(queryin, "select Mno as 专业号,Mname as 专业名称,Mdept as 所属学院 from Major where Mno='"); //输入查询语句
    strcat(queryin, Mno);
    strcat(queryin, "';");
    mysql_query(&mysql, "set names gbk"); //设置编码格式（SET NAMES GBK也行），否则cmd下中文乱码
    strcpy(query, queryin);
    //返回0 查询成功，返回1查询失败
    if (mysql_query(&mysql, query)) // 执行指定为一个空结尾的字符串的SQL查询。
    {
        printf("Query failed (%s)\n\n", mysql_error(&mysql));
        return false;
    }
    else
    {
        printf("Query success\n\n");
    }

    //获取结果集
    if (!(res = mysql_store_result(&mysql)))    //获得sql语句结束后返回的结果集
    {
        printf("Couldn't get result from %s\n\n", mysql_error(&mysql));
        return false;
    }

    //打印数据行数
    printf("number of dataline returned: %d\n\n", (int)mysql_affected_rows(&mysql));

    //获取字段的信息
    char* str_field[32];			//定义一个字符串数组存储字段信息
    for (int i = 0; i < 3; i++)		//在已知字段数量的情况下获取字段名
    {
        str_field[i] = mysql_fetch_field(res)->name;	//返回一个所有字段结构的数组。
    }

    for (int i = 0; i < 3; i++)		//打印字段
        printf("%10s	", str_field[i]);

    printf("\n");

    //打印获取的数据
    while (column = mysql_fetch_row(res))   //在已知字段数量情况下，获取并打印下一行
    {
        printf("%10s	%10s	%10s	\n", column[0], column[1], column[2]);  //column是列数组
    }

    return true;
}



bool QueryMajorOFMname(MYSQL mysql)
{
    cout << "请输入需要查询专业名称" << endl;
    char query[500]; //查询语句
    MYSQL_RES* res; //这个结构代表返回行的一个查询结果集
    MYSQL_ROW column; //一个行数据的类型安全(type-safe)的表示，表示数据行的列

    char queryin[500];
    char Mname[20];
    cin >> Mname;
    strcpy(queryin, "select Mno as 专业号,Mname as 专业名称,Mdept as 所属学院 from Major where Mname='"); //输入查询语句
    strcat(queryin, Mname);
    strcat(queryin, "';");
    mysql_query(&mysql, "set names gbk"); //设置编码格式（SET NAMES GBK也行），否则cmd下中文乱码
    strcpy(query, queryin);
    //返回0 查询成功，返回1查询失败
    if (mysql_query(&mysql, query)) // 执行指定为一个空结尾的字符串的SQL查询。
    {
        printf("Query failed (%s)\n\n", mysql_error(&mysql));
        return false;
    }
    else
    {
        printf("Query success\n\n");
    }

    //获取结果集
    if (!(res = mysql_store_result(&mysql)))    //获得sql语句结束后返回的结果集
    {
        printf("Couldn't get result from %s\n\n", mysql_error(&mysql));
        return false;
    }

    //打印数据行数
    printf("number of dataline returned: %d\n\n", (int)mysql_affected_rows(&mysql));

    //获取字段的信息
    char* str_field[32];			//定义一个字符串数组存储字段信息
    for (int i = 0; i < 3; i++)		//在已知字段数量的情况下获取字段名
    {
        str_field[i] = mysql_fetch_field(res)->name;	//返回一个所有字段结构的数组。
    }

    for (int i = 0; i < 3; i++)		//打印字段
        printf("%10s	", str_field[i]);

    printf("\n");

    //打印获取的数据
    while (column = mysql_fetch_row(res))   //在已知字段数量情况下，获取并打印下一行
    {
        printf("%10s	%10s	%10s	\n", column[0], column[1], column[2]);  //column是列数组
    }

    return true;
}
