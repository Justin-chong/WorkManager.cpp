#pragma once
#include<iostream>
#include<string>
using namespace std;
#include"worker.h"

class Manager :public worker
{
public:

	Manager(int id,string name,int developId);
	//��ʾmanager��Ϣ
	virtual void show_info();
	//��ȡ��λ
	virtual string get_develop_name();
};