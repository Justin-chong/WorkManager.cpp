#include"boss.h"

Boss::Boss(int id, string name, int developId)
{
	this->m_id = id;
	this->m_name = name;
	this->m_development = developId;
}
void Boss::show_info()
//��ʾ������Ϣ
{
	cout << "��ţ� " << this->m_id
		<< "\t������ " << this->m_name
		<< "\t���ţ� " << this->get_develop_name()
		<< "\tְ�� ����Ա���;���" << endl;
}
string Boss::get_develop_name()
//��ȡ��λ
{
	return string("�ϰ�");
}