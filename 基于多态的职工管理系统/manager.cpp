#include"manager.h"

Manager::Manager(int id, string name, int developId)
{
	this->m_id = id;
	this->m_name = name;
	this->m_development = developId;
}
//��ʾmanager��Ϣ
void Manager::show_info()
{
	cout << "��ţ� " << this->m_id
		<< "\t������ " << this->m_name
		<< "\t���ţ� " << this->get_develop_name()
		<< "\tְ�� ����ϰ彻�������񲢹���Ա��" << endl;
}
//��ȡ��λ
string Manager::get_develop_name()
{
	return string("����");
}