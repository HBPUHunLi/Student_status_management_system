#include"studentM.h"

MYSQL mysql; //mysql连接




//-----------------------------主函数-----------------------------
int main() {

	mysql = ConnectDatabase();
	while(1)
	{
		cout << endl;
		char x;
		cout << "创建学籍管理系统请输入0" << endl;
		cout << "操作Student表信息请输入1"<<endl;
		cout << "操作Major表信息请输入2" << endl;
		cout << "操作Dept表信息请输入3" << endl;
		cout << "操作Report表信息请输入4" << endl;
		cout << "输入其他字符以退出程序" << endl;
		cout << "请选择功能：";
		cin >> x;
		switch (x)
		{
		case '0':CreatSystem(mysql); break;
		case '1':SwitchStudent(mysql); break;
		case '2':SwitchMajor(mysql); break;
		case '3':SwitchDept(mysql); break;
		case '4':SwitchReport(mysql); break;
		default: 
			{
			cout << endl;
				FreeConnect(mysql);
				return 0;
			}
		}
	}
	return 0;
}
//-----------------------------主函数-----------------------------
