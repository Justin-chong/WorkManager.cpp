#include"manager.h"

Manager::Manager(int id, string name, int developId)
{
	this->m_id = id;
	this->m_name = name;
	this->m_development = developId;
}
//显示manager信息
void Manager::show_info()
{
	cout << "编号： " << this->m_id
		<< "\t姓名： " << this->m_name
		<< "\t部门： " << this->get_develop_name()
		<< "\t职责： 完成老板交付的任务并管理员工" << endl;
}
//获取岗位
string Manager::get_develop_name()
{
	return string("经理");
}