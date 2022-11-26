#include"studentM.h"

MYSQL mysql; //mysql连接

//-----------------------------主函数-----------------------------
int main() {

	mysql = ConnectDatabase();
	while(1)
	{
		char x;
		cin >> x;
		switch (x)
		{
		case '0':student_InsertData(mysql); break;
		case '1':QueryStudentAll(mysql); break;
		case '2':QueryStudentOFSname(mysql); break;
		case '3':QueryStudentOFSno(mysql); break;
		case '4':student_ModifyData(mysql); break;
		case '5':student_DeleteData(mysql); break;
		case '6':student_CreateTable(mysql); break;
		case '7':student_DropTable(mysql); break;
		case '8':
			{
				int a;
				cin >> a;
				printf("%s\n%d", Sage(a),(int)strlen(Sage(18)));

				break;
			}
		default: 
			{
				FreeConnect(mysql);
				return 0;
			}
		}
	}
	return 0;
}
//-----------------------------主函数-----------------------------
