#include"WorkManager.h"

workManager::workManager()
{
	//1.文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//读文件
	if (!ifs.is_open())
	{
		//cout << "文件不存在" << endl;
		//初始化属性
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		//初始化文件为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//2.文件存在但数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "文件为空" << endl;
		//初始化属性
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		//初始化文件为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//3.文件存在并记录
	int num = this->get_EmpNum();
	//cout << "职工人数为：" << num << endl;
	this->m_EmpNum = num;
	//开辟空间
	this->m_EmpArray = new worker * [this->m_EmpNum];
	//将文件数据存在数组中
	this->init_Emp();

	//测试代码
	/*for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "职工编号：" << this->m_EmpArray[i]->m_id<<" "
			<< "职工姓名：" << this->m_EmpArray[i]->m_name<<" "
			<< "部门编号：" << this->m_EmpArray[i]->m_development << endl;
	}*/
}

//菜单
void workManager::show_menu()
{
	cout << "************************" << endl;
	cout << "**欢饮使用职工管理系统**" << endl;
	cout << "*****0.退出程序  *******" << endl;
	cout << "*****1.增加职工信息*****" << endl;
	cout << "*****2.显示职工信息****" << endl;
	cout << "*****3.删除离职职员*****" << endl;
	cout << "*****4.修改职工信息*****" << endl;
	cout << "*****5.查找职工信息*****" << endl;
	cout << "*****6.按照编号排序*****" << endl;
	cout << "*****7.清空职工信息*****" << endl;
	cout << endl;
}
void workManager::exitSystem()
{
	cout << "欢迎下次使用！！！" << endl;
	exit(0);//退出程序
}
//添加职工
void workManager::Add_Emp()
{
	cout << "请输入想要添加的人数" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		//计算新空间大小
		int newSize = this->m_EmpNum + addNum;
		//开辟新空间
		worker** newSpace=new worker* [newSize];

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < newSize; i++)
			{
				newSpace[i]=this->m_EmpArray[i];
			}
		}
		//添加新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;//部门

			cout << "请输入第" << i + 1 << "个新职工编号：" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新职工姓名：" << endl;
			cin >> name;
			cout << "请选择该职工岗位：" << endl;
			cout << "1.普通员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;

			cin >> dSelect;
			worker* workman = NULL;
			switch (dSelect)
			{
			case 1:
				workman = new Employee(id, name, 1);
				break;
			case 2:
				workman = new Manager(id, name, 2);
				break;
			case 3:
				workman = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			//将创建的职工指针，保存到数组中
			newSpace[this->m_EmpNum + i] = workman;
		}
		//释放空间
		delete[]this->m_EmpArray;
		//更新新空间指向
		this->m_EmpArray = newSpace;
		//更新人数
		this->m_EmpNum = newSize;

		this->m_FileIsEmpty = false;
		cout << "成功添加" << addNum << "人" << endl;
		//保存
		this->save();
	}
	else
	{
		cout << "输入错误" << endl;
	}
	system("pause");
	system("cls");

}

//保存文件
void workManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//用输出的方式打开文件--写文件
	//将数据写入文件
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_id << " "
			<< this->m_EmpArray[i]->m_name << " "
			<< this->m_EmpArray[i]->m_development << endl;
	}
	//关闭文件
	ofs.close();
}
//统计文件中人数
int workManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//打开文件 读
	int id;
	string name;
	int dId;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;
	}
	return num;
}
//初始化员工
void workManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		worker* workman = NULL;
		if (dId == 1)
		{
			workman = new Employee(id, name, dId);
		}
		else if (dId == 2)
		{
			workman = new Manager(id, name, dId);
		}
		else if (dId == 3)
		{
			workman = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = workman;
		index++;
	}

	ifs.close();
}
//显示员工
void workManager::show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			//利用多态调用程序接口
			this->m_EmpArray[i]->show_info();
		}
	}
	system("pause");
	system("cls");
}
//判断职工是否存在,返回职工在数组中的下标
int workManager::is_exist(int id)
{
	int index = -1;
	for (int i = 0; i < m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_id == id)
		{
			index = i;
			break;
		}
	}
	
	return index;
	
}


//删除职工
void workManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		//按照编号删除
		cout << "请输入要删除职工编号：" << endl;
		int id = 0;
		cin >> id;
		int index=this->is_exist(id);
		if (index != -1)
		{
			for (int i = index; i + 1 < m_EmpNum; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
			//数据同步更新到文件中
			this->save();

			cout << "删除成功！！！" << endl;

		}
		else
		{
			cout << "删除失败！！！未找到！！！" << endl;
		}
		
	}
	system("pause");
	system("cls");

}
//修改职工
void workManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请输入修改的职工编号：" << endl;
		int id;
		cin >> id;
		int ret = this->is_exist(id);
		if (ret != -1)
		{
			delete this->m_EmpArray[ret];
			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "查到：" << id << "号的职工，请输入新的职工号：" << endl;
			cin >> newId;
			cout << "请输入新的姓名：" << endl;
			cin >> newName;
			cout << "请输入新岗位：" << endl;
			cout << "1.普通员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> dSelect;
			worker* workman = NULL;
			switch (dSelect)
			{
			case 1:
				workman = new Employee(newId, newName, dSelect);
				break;
			case 2:
				workman = new Manager(newId, newName, dSelect);

				break; 
			case 3:
				workman = new Boss(newId, newName, dSelect);

				break;
			default:
				break;

			}
			this->m_EmpArray[ret] = workman;
			cout << "修改成功！！！" << endl;
			this->save();
		}
		else
		{
			cout << "修改失败，查无此人！！！" << endl;
		}
	}
	system("pause");
	system("cls");
}
//查找职工
void workManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请输入查找方式：" << endl;
		cout << "1.按职工编号查找" << endl;
		cout << "2.按职工姓名查找" << endl;
		int k = 0;
		cin >> k;
		if (k == 1)
		{
			cout << "请输入需要查找的编号：" << endl;
			int id = 0;
			cin >> id;
			int ret = this->is_exist(id);
			if (ret == -1)
			{
				cout << "按编号查找失败，无此编号！" << endl;
			}
			else
			{
				cout << "查找成功！该职工信息如下：" << endl;
				//调用显示信息接口
				this->m_EmpArray[ret]->show_info();
			}
		}
		else if (k == 2)
		{
			cout << "请输入需要查找职工的姓名：" << endl;
			string name;
			cin >> name;
			bool flag = false;
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_name == name)
				{
					cout << "查到了，此人编号为：" << this->m_EmpArray[i]->m_id
						<< ",信息如下：" << endl;
					this->m_EmpArray[i]->show_info();
					flag = true;
				}
			}
			if (flag == false)
			{
				cout << "按名字查找失败，无此姓名！" << endl;
			}
		}
		else
		{
			cout << "输入有误！" << endl;
		}
	}
	system("pause");
	system("cls");
}
//编号排序
void workManager::bubble_sort()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式：" << endl;
		cout << "1.编号升序" << endl;
		cout << "2.编号降序" << endl;
		int k;
		cin >> k;
		for (int i = 0; i < m_EmpNum; i++)
		{
			if(k!=1&&k!=2)
			{
				cout << "排序方式选择错误！" << endl;
				break;
			}
			for (int j = 0; j < m_EmpNum - i - 1; j++)
			{
				if (k == 1)
				{
					if (this->m_EmpArray[j]->m_id > this->m_EmpArray[j + 1]->m_id)
					{
						worker* tmp = this->m_EmpArray[j];
						this->m_EmpArray[j] = this->m_EmpArray[j + 1];
						this->m_EmpArray[j + 1] = tmp;
					}
				}
				else 
				{
					if (this->m_EmpArray[j]->m_id < this->m_EmpArray[j + 1]->m_id)
					{
						worker* tmp = this->m_EmpArray[j];
						this->m_EmpArray[j] = this->m_EmpArray[j + 1];
						this->m_EmpArray[j + 1] = tmp;
					}
				}
				
			}
		}
		cout << "排序成功！排序结果为：" << endl;
		this->save();//保存至文件中
		this->show_Emp();//展示所有员工
	}
}
//清空文件
void workManager::Clean_File()
{
	cout << "是否清空文件？" << endl;
	cout << "1.清空" << endl;
	cout << "2.返回" << endl;
	int k;
	cin >> k;
	if (k == 1)
	{
		//清空文件
		ofstream ofs(FILENAME, ios::trunc);//删除文件后重新创建
		ofs.close();
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < m_EmpNum; i++)
			{
				
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
				
			}
			this->m_EmpNum = 0;
			delete[]this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功！" << endl;
	}
	else if(k==2)
	{
		;
	}
	else
	{
		cout << "选择错误！" << endl;
	}
	system("pause");
	system("cls");
}
workManager::~workManager()
{
	if (this->m_EmpArray != NULL)
	{
		delete[]this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}