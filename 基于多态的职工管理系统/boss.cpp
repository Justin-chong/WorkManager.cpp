#include"boss.h"

Boss::Boss(int id, string name, int developId)
{
	this->m_id = id;
	this->m_name = name;
	this->m_development = developId;
}
void Boss::show_info()
//显示个人信息
{
	cout << "编号： " << this->m_id
		<< "\t姓名： " << this->m_name
		<< "\t部门： " << this->get_develop_name()
		<< "\t职责： 管理员工和经理" << endl;
}
string Boss::get_develop_name()
//获取岗位
{
	return string("老板");
}