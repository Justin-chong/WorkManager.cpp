#include"employee.h"

Employee::Employee(int id,string name,int developId)
{
	this->m_id = id;
	this->m_name = name;
	this->m_development = developId;
}
void Employee::show_info()
//��ʾ������Ϣ
{
	cout << "��ţ� " << this->m_id
		<< "\t������ " << this->m_name
		<< "\t���ţ� " << this->get_develop_name()
		<< "\tְ�� ��ɾ�����������" << endl;
}
string Employee::get_develop_name()//��ȡ��λ
{
	return string("��ͨԱ��");
}