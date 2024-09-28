#pragma once
#include<iostream>
#include<string>
using namespace std;
#include"worker.h"

class Manager :public worker
{
public:

	Manager(int id,string name,int developId);
	//显示manager信息
	virtual void show_info();
	//获取岗位
	virtual string get_develop_name();
};