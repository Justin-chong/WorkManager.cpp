#include<iostream>
using namespace std;
#include"WorkManager.h"
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

int main()
{
	/*worker* worker = NULL;
	worker = new Employee(1, "zhangsna", 1);
	worker->show_info();*/
	/*worker* worker = NULL;
	worker = new Boss(1, "ada", 1);
	worker->show_info();*/
	//实例化对象
	workManager wm;
	int input;
	do
	{
		wm.show_menu();
		cout << "请输入您的选择" << endl;
		cin >> input;
		switch (input)
		{
		case 0:
			wm.exitSystem();
			break;
		case 1://增加职工信息函数调用
			wm.Add_Emp();
			break;
		case 2:
			wm.show_Emp();
			break;

		case 3:
			wm.Del_Emp();
			break;

		case 4:
			wm.Mod_Emp();
			break;

		case 5:
			wm.Find_Emp();
			break;

		case 6:
			wm.bubble_sort();
			break;

		case 7:
			wm.Clean_File();
			break;

		default:
			system("cls");
			break;
		}
	} while (input);

	return 0;
}