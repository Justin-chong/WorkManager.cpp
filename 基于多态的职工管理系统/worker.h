#pragma once
#include<iostream>
#include<string>
using namespace std;

class worker
{
public:
	virtual void show_info() = 0;//显示个人信息
	virtual string get_develop_name() = 0;//获取岗位

	//编号
	int m_id;
	//名字
	string m_name;
	//部门
	int m_development;
};