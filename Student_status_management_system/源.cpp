#include"studentM.h"

MYSQL mysql; //mysql����

//-----------------------------������-----------------------------
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
//-----------------------------������-----------------------------
