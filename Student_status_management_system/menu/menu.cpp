#include "studentM.h"

void SwitchStudent(MYSQL mysql)
{
	char x;
	cout << endl;
	cout << "您选择了Student表" << endl;
	cout << "创建Student表请输入1" << endl;
	cout << "删除Student表请输入2" << endl;
	cout << "插入学生信息请输入3" << endl;
	cout << "修改学生信息请输入4" << endl;
	cout << "根据学号删除学生信息请输入5" << endl;
	cout << "查询所有学生信息请输入6" << endl;
	cout << "根据学号查询学生信息请输入7" << endl;
	cout << "根据姓名查询学生信息请输入8" << endl;
	cout << "查询大于某一年龄的学生信息请输入9" << endl;
	cout << "请按其他键退出Student表" << endl;
	while (1)
	{
		cout << endl;
		cout << "请选择功能：";
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
		case '9': {
			int age;
			cin >> age;
			QueryStudentOFAge(mysql, age);
            break;
		}
		default:return;
		}
	}
	return;
}

void SwitchMajor(MYSQL mysql)
{
	char x;
	cout << endl;
	cout << "您选择了Major表" << endl;
	cout << "创建Major表请输入1" << endl;
	cout << "删除Major表请输入2" << endl;
	cout << "插入专业信息请输入3" << endl;
	cout << "修改专业信息请输入4" << endl;
	cout << "根据专业号删除专业信息请输入5" << endl;
	cout << "查询所有专业信息请输入6" << endl;
	cout << "根据专业号查询专业信息请输入7" << endl;
	cout << "根据专业名字查询专业信息请输入8" << endl;
	cout << "请按其他键退出Major表" << endl;
	while (1)
	{
		cout << endl;
		cout << "请选择功能：";
		cin >> x;
		switch (x)
		{
        case '1':major_CreateTable(mysql); break;
        case '2':major_DropTable(mysql); break;
        case '3':major_InsertData(mysql); break;
        case '4':major_ModifyData(mysql); break;
        case '5':major_DeleteData(mysql); break;
        case '6':QueryMajorAll(mysql); break;
        case '7':QueryMajorOFMno(mysql); break;
        case '8':QueryMajorOFMname(mysql); break;
        default:return;
		}
	}
}

void SwitchDept(MYSQL mysql)
{
	char x;
	cout << endl;
	cout << "您选择了Dept表" << endl;
	cout << "创建Dept表请输入1" << endl;
	cout << "删除Dept表请输入2" << endl;
	cout << "插入学院信息请输入3" << endl;
	cout << "修改学院信息请输入4" << endl;
	cout << "删除学院信息请输入5" << endl;
	cout << "查询所有学院信息请输入6" << endl;
	cout << "查询某学院是否存在请输入7" << endl;
	cout << "请按其他键退出Dept表" << endl;

	while (1)
	{
		cout << endl;
		cout << "请选择功能：";
		cin >> x;
		switch (x)
		{
		case '1':dept_CreateTable(mysql); break;
		case '2':dept_DropTable(mysql); break;
		case '3':dept_InsertData(mysql); break;
        case '4':dept_ModifyData(mysql); break;
		case '5':dept_DeleteData(mysql); break;
		case '6':dept_QueryDeptAll(mysql); break;
		case '7':dept_QueryDeptIFDname(mysql); break;
		default:return;
		}
	}
}

void SwitchReport(MYSQL mysql)
{
	char x;
	cout << endl;
	cout << "您选择了Report表" << endl;
	cout << "创建Report表请输入1" << endl;
	cout << "删除Report表请输入2" << endl;
	cout << "插入学生专业信息请输入3" << endl;
	cout << "修改学生专业信息请输入4" << endl;
	cout << "删除学生专业信息请输入5" << endl;
	cout << "查询所有学生专业信息请输入6" << endl;
	cout << "通过学号查询所在专业信息请输入7" << endl;
	cout << "通过专业查询该专业所有学生信息请输入8" << endl;
	cout << "请按其他键退出Dept表" << endl;
	while (1)
	{
		cout << "请选择功能：";
		cin >> x;
		switch (x)
		{
		case '1':report_CreateTable(mysql); break;
		case '2':report_DropTable(mysql); break;
		case '3':report_InsertData(mysql); break;
		case '4':report_ModifyData(mysql); break;
		case '5': {
			cout << "根据学号删除请输入0"<<endl;
			cout << "根据专业号删除请输入1" << endl;
			char No[20];
			int x5;
			cin >> x5;
			cout << "您输入了" << x5 << ",请输入学号或专业号:";
			cin >> No;
			report_DeleteData(mysql,No,x5);
		}
		case '6':QueryReportALL(mysql); break;
		case '7':QueryReportOFSno(mysql); break;
        case '8':QueryReportOFMname(mysql); break;
		default:return;
		}
	}
}
