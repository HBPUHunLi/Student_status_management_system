#include"studentM.h"

MYSQL mysql; //mysql����

//-----------------------------������-----------------------------
int main() {

	mysql = ConnectDatabase();
	while(1)
	{
		int x;
		cin >> x;
		switch (x)
		{
		case 0:InsertData(mysql); break;
		case 1:QueryStudentAll(mysql); break;
		case 2:QueryStudentOFSname(mysql); break;
		case 3:QueryStudentOFSno(mysql); break;
		}
	}
	//FreeConnect();
	return 0;
}
//-----------------------------������-----------------------------
