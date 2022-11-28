#include "studentM.h"

void SwitchStudent(MYSQL mysql)
{
	char x;
	cout << endl;
	cout << "��ѡ����Student��" << endl;
	cout << "����Student��������1" << endl;
	cout << "ɾ��Student��������2" << endl;
	cout << "����ѧ����Ϣ������3" << endl;
	cout << "�޸�ѧ����Ϣ������4" << endl;
	cout << "����ѧ��ɾ��ѧ����Ϣ������5" << endl;
	cout << "��ѯ����ѧ����Ϣ������6" << endl;
	cout << "����ѧ�Ų�ѯѧ����Ϣ������7" << endl;
	cout << "����������ѯѧ����Ϣ������8" << endl;
	cout << "�밴�������˳�Student��" << endl;
	while (1)
	{
		cout << endl;
		cout << "��ѡ���ܣ�";
		cin >> x;
		switch (x)
		{
		case '1':student_CreateTable(mysql); break;
		case '2':student_DropTable(mysql); break;
		case '3':student_InsertData(mysql); break;
		case '4':student_ModifyData(mysql); break;
		case '5':student_DeleteData(mysql); break;
		case '6':QueryStudentAll(mysql); break;
		case '7':QueryStudentOFSno(mysql); break;
		case '8':QueryStudentOFSname(mysql); break;
		default:return;
		}
	}
	return;
}

void SwitchMajor(MYSQL mysql)
{
	char x;
	cout << endl;
	cout << "��ѡ����Major��" << endl;
	cout << "����Major��������1" << endl;
	cout << "ɾ��Major��������2" << endl;
	cout << "����רҵ��Ϣ������3" << endl;
	cout << "�޸�רҵ��Ϣ������4" << endl;
	cout << "����רҵ��ɾ��רҵ��Ϣ������5" << endl;
	cout << "��ѯ����רҵ��Ϣ������6" << endl;
	cout << "����רҵ�Ų�ѯרҵ��Ϣ������7" << endl;
	cout << "����רҵ���ֲ�ѯרҵ��Ϣ������8" << endl;
	cout << "�밴�������˳�Major��" << endl;
	while (1)
	{
		cout << endl;
		cout << "��ѡ���ܣ�";
		cin >> x;
		switch (x)
		{
		case '1':major_CreateTable(mysql); break;
		case '2':major_DropTable(mysql); break;
		case '3':break;
		case '4':break;
		case '5':break;
		case '6':break;
		case '7':break;
		case '8':break;
		default:return;
		}
	}
}

void SwitchDept(MYSQL mysql)
{
	char x;
	cout << endl;
	cout << "��ѡ����Dept��" << endl;
	cout << "����Dept��������1" << endl;
	cout << "ɾ��Dept��������2" << endl;
	cout << "����ѧԺ��Ϣ������3" << endl;
	cout << "�޸�ѧԺ��Ϣ������4" << endl;
	cout << "ɾ��ѧԺ��Ϣ������5" << endl;
	cout << "��ѯ����ѧԺ��Ϣ������6" << endl;
	cout << "�밴�������˳�Dept��" << endl;
	while (1)
	{
		cout << endl;
		cout << "��ѡ���ܣ�";
		cin >> x;
		switch (x)
		{
		case '1':dept_CreateTable(mysql); break;
		case '2':dept_DropTable(mysql); break;
		case '3':break;
		case '4':break;
		case '5':break;
		case '6':break;
		default:return;
		}
	}
}

void SwitchReport(MYSQL mysql)
{
	char x;
	cout << endl;
	cout << "��ѡ����Report��" << endl;
	cout << "����Report��������1" << endl;
	cout << "ɾ��Report��������2" << endl;
	cout << "����ѧ��רҵ��Ϣ������3" << endl;
	cout << "�޸�ѧ��רҵ��Ϣ������4" << endl;
	cout << "ɾ��ѧ��רҵ��Ϣ������5" << endl;
	cout << "��ѯ����ѧ��רҵ��Ϣ������6" << endl;
	cout << "ͨ��ѧ�Ų�ѯ����רҵ��Ϣ������7" << endl;
	cout << "ͨ��רҵ�Ų�ѯ��רҵ����ѧ����Ϣ������8" << endl;
	cout << "�밴�������˳�Dept��" << endl;
	while (1)
	{
		cout << "��ѡ���ܣ�";
		cin >> x;
		switch (x)
		{
		case '1':report_CreateTable(mysql); break;
		case '2':report_DropTable(mysql); break;
		case '3':break;
		case '4':break;
		case '5':break;
		case '6':break;
		case '7':break;
		case '8':break;
		default:return;
		}
	}
}
