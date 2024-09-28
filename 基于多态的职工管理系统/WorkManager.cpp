#include"WorkManager.h"

workManager::workManager()
{
	//1.�ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ�
	if (!ifs.is_open())
	{
		//cout << "�ļ�������" << endl;
		//��ʼ������
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		//��ʼ���ļ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//2.�ļ����ڵ�����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "�ļ�Ϊ��" << endl;
		//��ʼ������
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		//��ʼ���ļ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//3.�ļ����ڲ���¼
	int num = this->get_EmpNum();
	//cout << "ְ������Ϊ��" << num << endl;
	this->m_EmpNum = num;
	//���ٿռ�
	this->m_EmpArray = new worker * [this->m_EmpNum];
	//���ļ����ݴ���������
	this->init_Emp();

	//���Դ���
	/*for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "ְ����ţ�" << this->m_EmpArray[i]->m_id<<" "
			<< "ְ��������" << this->m_EmpArray[i]->m_name<<" "
			<< "���ű�ţ�" << this->m_EmpArray[i]->m_development << endl;
	}*/
}

//�˵�
void workManager::show_menu()
{
	cout << "************************" << endl;
	cout << "**����ʹ��ְ������ϵͳ**" << endl;
	cout << "*****0.�˳�����  *******" << endl;
	cout << "*****1.����ְ����Ϣ*****" << endl;
	cout << "*****2.��ʾְ����Ϣ****" << endl;
	cout << "*****3.ɾ����ְְԱ*****" << endl;
	cout << "*****4.�޸�ְ����Ϣ*****" << endl;
	cout << "*****5.����ְ����Ϣ*****" << endl;
	cout << "*****6.���ձ������*****" << endl;
	cout << "*****7.���ְ����Ϣ*****" << endl;
	cout << endl;
}
void workManager::exitSystem()
{
	cout << "��ӭ�´�ʹ�ã�����" << endl;
	exit(0);//�˳�����
}
//���ְ��
void workManager::Add_Emp()
{
	cout << "��������Ҫ��ӵ�����" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		//�����¿ռ��С
		int newSize = this->m_EmpNum + addNum;
		//�����¿ռ�
		worker** newSpace=new worker* [newSize];

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < newSize; i++)
			{
				newSpace[i]=this->m_EmpArray[i];
			}
		}
		//���������
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;//����

			cout << "�������" << i + 1 << "����ְ����ţ�" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "����ְ��������" << endl;
			cin >> name;
			cout << "��ѡ���ְ����λ��" << endl;
			cout << "1.��ͨԱ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;

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
			//��������ְ��ָ�룬���浽������
			newSpace[this->m_EmpNum + i] = workman;
		}
		//�ͷſռ�
		delete[]this->m_EmpArray;
		//�����¿ռ�ָ��
		this->m_EmpArray = newSpace;
		//��������
		this->m_EmpNum = newSize;

		this->m_FileIsEmpty = false;
		cout << "�ɹ����" << addNum << "��" << endl;
		//����
		this->save();
	}
	else
	{
		cout << "�������" << endl;
	}
	system("pause");
	system("cls");

}

//�����ļ�
void workManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//������ķ�ʽ���ļ�--д�ļ�
	//������д���ļ�
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_id << " "
			<< this->m_EmpArray[i]->m_name << " "
			<< this->m_EmpArray[i]->m_development << endl;
	}
	//�ر��ļ�
	ofs.close();
}
//ͳ���ļ�������
int workManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ� ��
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
//��ʼ��Ա��
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
//��ʾԱ��
void workManager::show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			//���ö�̬���ó���ӿ�
			this->m_EmpArray[i]->show_info();
		}
	}
	system("pause");
	system("cls");
}
//�ж�ְ���Ƿ����,����ְ���������е��±�
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


//ɾ��ְ��
void workManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		//���ձ��ɾ��
		cout << "������Ҫɾ��ְ����ţ�" << endl;
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
			//����ͬ�����µ��ļ���
			this->save();

			cout << "ɾ���ɹ�������" << endl;

		}
		else
		{
			cout << "ɾ��ʧ�ܣ�����δ�ҵ�������" << endl;
		}
		
	}
	system("pause");
	system("cls");

}
//�޸�ְ��
void workManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "�������޸ĵ�ְ����ţ�" << endl;
		int id;
		cin >> id;
		int ret = this->is_exist(id);
		if (ret != -1)
		{
			delete this->m_EmpArray[ret];
			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "�鵽��" << id << "�ŵ�ְ�����������µ�ְ���ţ�" << endl;
			cin >> newId;
			cout << "�������µ�������" << endl;
			cin >> newName;
			cout << "�������¸�λ��" << endl;
			cout << "1.��ͨԱ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
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
			cout << "�޸ĳɹ�������" << endl;
			this->save();
		}
		else
		{
			cout << "�޸�ʧ�ܣ����޴��ˣ�����" << endl;
		}
	}
	system("pause");
	system("cls");
}
//����ְ��
void workManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "��������ҷ�ʽ��" << endl;
		cout << "1.��ְ����Ų���" << endl;
		cout << "2.��ְ����������" << endl;
		int k = 0;
		cin >> k;
		if (k == 1)
		{
			cout << "��������Ҫ���ҵı�ţ�" << endl;
			int id = 0;
			cin >> id;
			int ret = this->is_exist(id);
			if (ret == -1)
			{
				cout << "����Ų���ʧ�ܣ��޴˱�ţ�" << endl;
			}
			else
			{
				cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
				//������ʾ��Ϣ�ӿ�
				this->m_EmpArray[ret]->show_info();
			}
		}
		else if (k == 2)
		{
			cout << "��������Ҫ����ְ����������" << endl;
			string name;
			cin >> name;
			bool flag = false;
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_name == name)
				{
					cout << "�鵽�ˣ����˱��Ϊ��" << this->m_EmpArray[i]->m_id
						<< ",��Ϣ���£�" << endl;
					this->m_EmpArray[i]->show_info();
					flag = true;
				}
			}
			if (flag == false)
			{
				cout << "�����ֲ���ʧ�ܣ��޴�������" << endl;
			}
		}
		else
		{
			cout << "��������" << endl;
		}
	}
	system("pause");
	system("cls");
}
//�������
void workManager::bubble_sort()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ��" << endl;
		cout << "1.�������" << endl;
		cout << "2.��Ž���" << endl;
		int k;
		cin >> k;
		for (int i = 0; i < m_EmpNum; i++)
		{
			if(k!=1&&k!=2)
			{
				cout << "����ʽѡ�����" << endl;
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
		cout << "����ɹ���������Ϊ��" << endl;
		this->save();//�������ļ���
		this->show_Emp();//չʾ����Ա��
	}
}
//����ļ�
void workManager::Clean_File()
{
	cout << "�Ƿ�����ļ���" << endl;
	cout << "1.���" << endl;
	cout << "2.����" << endl;
	int k;
	cin >> k;
	if (k == 1)
	{
		//����ļ�
		ofstream ofs(FILENAME, ios::trunc);//ɾ���ļ������´���
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
		cout << "��ճɹ���" << endl;
	}
	else if(k==2)
	{
		;
	}
	else
	{
		cout << "ѡ�����" << endl;
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