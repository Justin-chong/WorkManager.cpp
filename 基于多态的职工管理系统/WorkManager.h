#pragma once
#include<iostream>
using namespace std;
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

#include<fstream>
#define FILENAME "empFile.txt"

class workManager
{
public:
	workManager();
	void show_menu();
	void exitSystem();
	//����ְ������
	int m_EmpNum;
	//ְ������ָ��
	worker** m_EmpArray;
	//�������
	void Add_Emp();

	//�����ļ�
	void save();

	//�ж��ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;

	//ͳ���ļ�������
	int get_EmpNum();

	//��ʼ��Ա��
	void init_Emp();

	//��ʾԱ��
	void show_Emp();
	//�ж�ְ���ͷŴ���
	int is_exist(int id);

	//ɾ��ְ��
	void Del_Emp();

	//�޸�ְ��
	void Mod_Emp();

	//����ְ��
	void Find_Emp();

	//�������
	void bubble_sort();
	
	//����ļ�
	void Clean_File();

	~workManager();

};