#include"studentM.h"

//�ͷ���Դ
void FreeConnect(MYSQL mysql)
{
	mysql_close(&mysql);	 //�ر�һ�����������ӡ�
	cout << "------�����ѶϿ�------"<<endl<<endl;
	return;
}
