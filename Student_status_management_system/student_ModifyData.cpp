#include"studentM.h"

char* input()
{
	char Sno[20];
	cout<<"������Ҫ�޸���Ϣ��ѧ����ѧ��" << endl;
	cin >> Sno;
	return Sno;
}

bool student_ModifyData(MYSQL mysql)
{
	char query[150];
	char Sno[20];
	char Sname[40];
	char Birthday[12];
	char Ssex[4];
	char Sdept[40];
	int x;
	cout << "�����������ѡ��Ҫ�޸ĵ���Ϣ" << endl;
	cout << "1.����" << endl;
	cout << "2.����" << endl;
	cout << "3.�Ա�" << endl;
	cout << "4.ѧԺ" << endl;
	cout << "ȡ���޸����������������" << endl;
	cin >> x;
	switch (x)
	{
	case 1: {
		strcpy(Sno, input());
		cout << "�������޸ĺ������" << endl;
		cin >> Sname;
		strcpy(query, "update student set Sname='");
		strcat(query,Sname);
		strcat(query, "' where Sno = '");
		strcat(query, Sno);
		strcat(query, "';");
		break;
	}
	case 2: {
		strcpy(Sno, input());
		cout << "�������޸ĺ������(xxxx.xx.xx)" << endl;
		cin >> Birthday;
		strcpy(query, "update student set Birthday='");
		strcat(query, Birthday);
		strcat(query, "' where Sno = '");
		strcat(query, Sno);
		strcat(query, "';");
		break;
	}
	case 3: {
		strcpy(Sno, input());
		cout << "�������޸ĺ���Ա�" << endl;
		cin >> Ssex;
		strcpy(query, "update student set Ssex='");
		strcat(query, Ssex);
		strcat(query, "' where Sno = '");
		strcat(query, Sno);
		strcat(query, "';");
		break;
	}
	case 4: {
		strcpy(Sno, input());
		cout << "�������޸ĺ��ѧԺ" << endl;
		cin >> Sdept;
		strcpy(query, "update student set Sdept='");
		strcat(query, Sdept);
		strcat(query, "' where Sno = '");
		strcat(query, Sno);
		strcat(query, "';");
		break;
	}
	default: {
		cout << "��ѡ����ȡ���޸�" << endl;
		return false;
	}
	}
	if (mysql_query(&mysql, query))        //ִ��SQL���  
	{
		printf("Modify Data failed (%s)\n\n", mysql_error(&mysql));
			return false;
	}
	else
	{
		printf("Modify Data success\n\n");
		cout << "�޸ĺ��ѧ����ϢΪ" << endl;
		QueryStudentOFSno(mysql, Sno);
			return true;
	}

}