#include"studentM.h"

MYSQL mysql; //mysql����




//-----------------------------������-----------------------------
int main() {

	mysql = ConnectDatabase();
	while(1)
	{
		cout << endl;
		char x;
		cout << "����ѧ������ϵͳ������0" << endl;
		cout << "����Student����Ϣ������1"<<endl;
		cout << "����Major����Ϣ������2" << endl;
		cout << "����Dept����Ϣ������3" << endl;
		cout << "����Report����Ϣ������4" << endl;
		cout << "���������ַ����˳�����" << endl;
		cout << "��ѡ���ܣ�";
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
//-----------------------------������-----------------------------
