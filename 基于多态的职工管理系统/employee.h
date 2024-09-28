#pragma once
#include<iostream>
#include<string>
using namespace std;
#include"worker.h"

class Employee :public worker
{
public:
	Employee(int id, string name, int developId);
	
	virtual void show_info();//显示个人信息
	virtual string get_develop_name();//获取岗位

};