#pragma once
#include<iostream>
#include<string>
using namespace std;

class worker
{
public:
	virtual void show_info() = 0;//��ʾ������Ϣ
	virtual string get_develop_name() = 0;//��ȡ��λ

	//���
	int m_id;
	//����
	string m_name;
	//����
	int m_development;
};