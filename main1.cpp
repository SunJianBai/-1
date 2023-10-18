#include<iostream>
#include<string>
#define MAX 1000    //�궨���������
using namespace std;
/*
1.�˵�����
	��װ���� void showmenu()����ʾ�˵�����
	���������е��÷�װ�õĺ���
*/
void showmenu()
{
	cout << "********************" << endl;
	cout << "****1.�����ϵ��****" << endl;
	cout << "****2.��ʾ��ϵ��****" << endl;
	cout << "****3.ɾ����ϵ��****" << endl;
	cout << "****4.������ϵ��****" << endl;
	cout << "****5.�޸���ϵ��****" << endl;
	cout << "****6.�����ϵ��****" << endl;
	cout << "****0.���ͨѶ¼****" << endl;
	cout << "********************" << endl;
}

struct person 
{
	string name;
	int sex;    //1���У�0��Ů
	int age;
	string phonenum;
};

struct addbooks   //����ͨѶ¼�ṹ��
{
	struct person arr[MAX];     //����ͨѶ¼��������
	int m_size;          //ͨѶ¼�������
};

//�ж���ϵ���Ƿ����,������ڣ�������������������ڣ�����-1
int panduan(addbooks* abs, string sname)
{
	for (int i = 0; i < abs->m_size; i++)
	{
		if (sname == abs->arr[i].name)
		{
			return i;
		}
	}
	return -1;
}

//1.�����ϵ��
void addperson(addbooks* abs)
{
	//�ж�ͨѶ¼�Ƿ�����
	if (abs->m_size == MAX)
	{
		cout << "ͨѶ¼�������޷���ӡ�" << endl;
		return ;
	}
	else  //δ��
	{
		//����
		
		while (true)
		{
			string name;
			cout << "������������ " << endl;
			cin >> name;
			if (panduan(abs, name) == -1)
			{
				abs->arr[abs->m_size].name = name;
				break;
			}
			else
			{
				cout << "�Ѵ��ڸ���ϵ�ˣ�����������" << endl;
			}
		}
		//�Ա�
		int sex;
		cout << "�������Ա�1���У�0��Ů���� " << endl;
		cin >> sex;
		while (sex != 1 && sex != 0)
		{
			cout << "����������������룺 " << endl;
			cin >> sex;
			
		}
		abs->arr[abs->m_size].sex = sex;
		
		//����
		int age;
		cout << "���������䣺 " << endl;
		cin >> age;
		abs->arr[abs->m_size].age = age;

		//�绰
		string phonenum;
		cout << "������绰���룺 " << endl;
		cin >> phonenum;
		abs->arr[abs->m_size].phonenum = phonenum;

		abs->m_size++;
		cout << "��ӳɹ���" << endl;
		system("pause");
		system("cls");
	}

}

//2. ��ʾ��ϵ��
void showperson(addbooks* abs)
{
	if (abs->m_size == 0)
	{
		cout << "ͨѶ¼Ϊ�ա�" << "\t";
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "������" << abs->arr[i].name << "\t";
			if (abs->arr[i].sex == 1)
			{
				cout << "�Ա���" << "\t";
			}
			else
			{
				cout << "�Ա�Ů" << "\t";
			}
			cout << "���䣺" << abs->arr[i].age << "\t";
			cout << "�绰��" << abs->arr[i].phonenum << endl;
		}
	}
	cout << "��ȫ�������" << endl;
	system("pause");
	system("cls");
}


//3.ɾ����ϵ��
void deleteperson(addbooks* abs)
{
	string d_name;
	cout << "������Ҫɾ������ϵ�����֣�" << endl;
	cin >> d_name;
	int p = panduan(abs, d_name);
	if (p == -1)
	{
		cout << "�����ڸ���ϵ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "�Ѳ�ѯ������" << endl;
		cout << "������" << abs->arr[p].name << "\t";
		if (abs->arr[p].sex == 1)
		{
			cout << "�Ա���" << "\t";
		}
		else
		{
			cout << "�Ա�Ů" << "\t";
		}
		cout << "���䣺" << abs->arr[p].age << "\t";
		cout << "�绰��" << abs->arr[p].phonenum << endl;
		cout << "�Ƿ�ɾ������ ��Y/N��" << endl;
		while(true)
		{
			
			string a;
			cin >> a;
			if (a == "Y")
			{
				for (int i = p; i < abs->m_size; i++)
				{
					abs->arr[i] = abs->arr[i + 1];
				}
				abs->m_size--;
				cout << "�ѳɹ�ɾ������ϵ��" << endl;
				system("pause");
				system("cls");
			}
			else if (a == "N")
			{
				cout << "��ȡ��ɾ��������" << endl;
				system("pause");
				system("cls");
			}
			else
			{
				cout << "����������������롣" << endl;
			}
		}
	}
}
//4.������ϵ��
void searchp(addbooks* abs)
{
	cout << "��������Ҫ��ѯ����ϵ��" << endl;
	string name;
	cin >> name;
	int temp = panduan(abs, name);
	if (temp == -1)
	{
		cout << "�����ڸ���ϵ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "�Ѳ�ѯ������" << endl;
		cout << "������" << abs->arr[temp].name << "\t";
		if (abs->arr[temp].sex == 1)
		{
			cout << "�Ա���" << "\t";
		}
		else
		{
			cout << "�Ա�Ů" << "\t";
		}
		cout << "���䣺" << abs->arr[temp].age << "\t";
		cout << "�绰��" << abs->arr[temp].phonenum << endl;
	}
}
//5.�޸���ϵ��
void changeperson(addbooks* abs)
{
	cout << "��������Ҫ��ѯ����ϵ��" << endl;
	string cname;
	cin >> cname;
	int temp = panduan(abs, cname);
	if (temp == -1)
	{
		cout << "�����ڸ���ϵ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "�Ѳ�ѯ������" << endl;
		cout << "������" << abs->arr[temp].name << "\t";
		if (abs->arr[temp].sex == 1)
		{
			cout << "�Ա���" << "\t";
		}
		else
		{
			cout << "�Ա�Ů" << "\t";
		}
		cout << "���䣺" << abs->arr[temp].age << "\t";
		cout << "�绰��" << abs->arr[temp].phonenum << endl;
		cout << "������޸�" << endl;
		//����
		while (true)
		{
			string nname;
			cout << "������������ " << endl;
			cin >> nname;
			if (panduan(abs, nname) == -1)
			{
				abs->arr[temp].name = nname;
				break;
			}
			else
			{
				cout << "�Ѵ��ڸ���ϵ�ˣ�����������" << endl;
			}
		}
		//�Ա�
		int nsex;
		cout << "�������Ա�1���У�0��Ů���� " << endl;
		cin >> nsex;
		while (nsex != 1 && nsex != 0)
		{
			cout << "����������������룺 " << endl;
			cin >> nsex;

		}
		abs->arr[temp].sex = nsex;

		//����
		int age;
		cout << "���������䣺 " << endl;
		cin >> age;
		abs->arr[temp].age = age;

		//�绰
		string phonenum;
		cout << "������绰���룺 " << endl;
		cin >> phonenum;
		abs->arr[temp].phonenum = phonenum;

		cout << "�޸ĳɹ���" << endl;
		system("pause");
		system("cls");
	}
}
//6.�����ϵ��
void clearperson(addbooks* abs)
{
	abs->m_size = 0;
	cout << "�����ͨѶ¼��" << endl;
	system("pause");
	system("cls");
}
int main(void)
{
	//�����ṹ�����
	addbooks abs;
	//��ʼ��ͨѶ¼��Ա����
	abs.m_size = 0;
	int select = 0;

	while (true)   //����ѭ�������Զ������
	{
		showmenu();
		cin >> select;
		switch (select)    //�ȴѡ��Ŀ��
		{
		case 1:          //�����ϵ��
			addperson(&abs);//���õ�ַ����
			break;
		case 2:          //��ʾ��ϵ��
			showperson(&abs);
			break;
		case 3:          //ɾ����ϵ��
			deleteperson(&abs);
			break;
		case 4:          //������ϵ��
			searchp(&abs);
			break;
		case 5:          //�޸���ϵ��
			changeperson(&abs);
			break;
		case 6:          //�����ϵ��
			break;
		case 0:          //���ͨѶ¼
			cout << "���˳�ͨѶ¼" << endl;
			system("pause");
			return 0;
			break;
		default :
			cout << "�����������������" << endl;
			break;
		}
	}
}