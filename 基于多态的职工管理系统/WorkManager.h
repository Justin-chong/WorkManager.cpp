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
	//记入职工人数
	int m_EmpNum;
	//职工数组指针
	worker** m_EmpArray;
	//添加人数
	void Add_Emp();

	//保存文件
	void save();

	//判断文件是否为空
	bool m_FileIsEmpty;

	//统计文件中人数
	int get_EmpNum();

	//初始化员工
	void init_Emp();

	//显示员工
	void show_Emp();
	//判断职工释放存在
	int is_exist(int id);

	//删除职工
	void Del_Emp();

	//修改职工
	void Mod_Emp();

	//查找职工
	void Find_Emp();

	//编号排序
	void bubble_sort();
	
	//清空文件
	void Clean_File();

	~workManager();

};