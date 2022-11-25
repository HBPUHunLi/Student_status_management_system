#include"studentM.h"

MYSQL mysql; //mysql连接

//-----------------------------主函数-----------------------------
int main() {

	mysql = ConnectDatabase();
	int x;
	cin >> x;
	if (x == 0)
		InsertData(mysql);
	else
		QueryStudentAll(mysql);
	//FreeConnect();
	return 0;
}
//-----------------------------主函数-----------------------------
