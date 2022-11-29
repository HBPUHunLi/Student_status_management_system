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
		cout << "学籍管理系统删除成功" << endl;
	}
	else
	{
		cout << "学籍管理系统删除失败" << endl;
	}
	return DropS;
}