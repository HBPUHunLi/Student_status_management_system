#include"studentM.h"

bool DropSystem(MYSQL mysql)
{
	bool DropS = true;
	DropS = DropS && report_DropTable(mysql);
	DropS = DropS && student_DropTable(mysql);
	DropS = DropS && major_DropTable(mysql);
	DropS = DropS && dept_DropTable(mysql);
	cout << endl;
	if (DropS)
	{
		cout << "ѧ������ϵͳɾ���ɹ�" << endl;
	}
	else
	{
		cout << "ѧ������ϵͳɾ��ʧ��" << endl;
	}
	return DropS;
}