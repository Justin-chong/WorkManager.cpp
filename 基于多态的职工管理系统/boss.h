#pragma once
#include<iostream>
#include<string>
using namespace std;
#include"worker.h"

class Boss:public worker
{
public:
	Boss(int id, string name, int developId);
	virtual void show_info();//��ʾ������Ϣ
	virtual string get_develop_name();//��ȡ��λ
};