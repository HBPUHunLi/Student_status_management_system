#include"studentM.h"

//释放资源
void FreeConnect(MYSQL mysql)
{
	mysql_close(&mysql);	 //关闭一个服务器连接。
	cout << "------连接已断开------"<<endl<<endl;
	return;
}
