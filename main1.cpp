#include<iostream>
#include<string>
#define MAX 1000    //宏定义最大人数
using namespace std;
/*
1.菜单功能
	封装函数 void showmenu()来显示菜单界面
	在主函数中调用封装好的函数
*/
void showmenu()
{
	cout << "********************" << endl;
	cout << "****1.添加联系人****" << endl;
	cout << "****2.显示联系人****" << endl;
	cout << "****3.删除联系人****" << endl;
	cout << "****4.查找联系人****" << endl;
	cout << "****5.修改联系人****" << endl;
	cout << "****6.清空联系人****" << endl;
	cout << "****0.清空通讯录****" << endl;
	cout << "********************" << endl;
}

struct person 
{
	string name;
	int sex;    //1是男，0是女
	int age;
	string phonenum;
};

struct addbooks   //创建通讯录结构体
{
	struct person arr[MAX];     //定义通讯录保存数组
	int m_size;          //通讯录最大人数
};

//判断联系人是否存在,如果存在，返回索引，如果不存在，返回-1
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

//1.添加联系人
void addperson(addbooks* abs)
{
	//判断通讯录是否满了
	if (abs->m_size == MAX)
	{
		cout << "通讯录已满，无法添加。" << endl;
		return ;
	}
	else  //未满
	{
		//姓名
		
		while (true)
		{
			string name;
			cout << "请输入姓名： " << endl;
			cin >> name;
			if (panduan(abs, name) == -1)
			{
				abs->arr[abs->m_size].name = name;
				break;
			}
			else
			{
				cout << "已存在该联系人，请重新输入" << endl;
			}
		}
		//性别
		int sex;
		cout << "请输入性别（1是男，0是女）： " << endl;
		cin >> sex;
		while (sex != 1 && sex != 0)
		{
			cout << "输入错误，请重新输入： " << endl;
			cin >> sex;
			
		}
		abs->arr[abs->m_size].sex = sex;
		
		//年龄
		int age;
		cout << "请输入年龄： " << endl;
		cin >> age;
		abs->arr[abs->m_size].age = age;

		//电话
		string phonenum;
		cout << "请输入电话号码： " << endl;
		cin >> phonenum;
		abs->arr[abs->m_size].phonenum = phonenum;

		abs->m_size++;
		cout << "添加成功。" << endl;
		system("pause");
		system("cls");
	}

}

//2. 显示联系人
void showperson(addbooks* abs)
{
	if (abs->m_size == 0)
	{
		cout << "通讯录为空。" << "\t";
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "姓名：" << abs->arr[i].name << "\t";
			if (abs->arr[i].sex == 1)
			{
				cout << "性别：男" << "\t";
			}
			else
			{
				cout << "性别：女" << "\t";
			}
			cout << "年龄：" << abs->arr[i].age << "\t";
			cout << "电话：" << abs->arr[i].phonenum << endl;
		}
	}
	cout << "已全部输出。" << endl;
	system("pause");
	system("cls");
}


//3.删除联系人
void deleteperson(addbooks* abs)
{
	string d_name;
	cout << "请输入要删除的联系人名字：" << endl;
	cin >> d_name;
	int p = panduan(abs, d_name);
	if (p == -1)
	{
		cout << "不存在该联系人" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "已查询到此人" << endl;
		cout << "姓名：" << abs->arr[p].name << "\t";
		if (abs->arr[p].sex == 1)
		{
			cout << "性别：男" << "\t";
		}
		else
		{
			cout << "性别：女" << "\t";
		}
		cout << "年龄：" << abs->arr[p].age << "\t";
		cout << "电话：" << abs->arr[p].phonenum << endl;
		cout << "是否删除此人 【Y/N】" << endl;
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
				cout << "已成功删除此联系人" << endl;
				system("pause");
				system("cls");
			}
			else if (a == "N")
			{
				cout << "已取消删除操作。" << endl;
				system("pause");
				system("cls");
			}
			else
			{
				cout << "输入错误，请重新输入。" << endl;
			}
		}
	}
}
//4.查找联系人
void searchp(addbooks* abs)
{
	cout << "请输入你要查询的联系人" << endl;
	string name;
	cin >> name;
	int temp = panduan(abs, name);
	if (temp == -1)
	{
		cout << "不存在该联系人" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "已查询到此人" << endl;
		cout << "姓名：" << abs->arr[temp].name << "\t";
		if (abs->arr[temp].sex == 1)
		{
			cout << "性别：男" << "\t";
		}
		else
		{
			cout << "性别：女" << "\t";
		}
		cout << "年龄：" << abs->arr[temp].age << "\t";
		cout << "电话：" << abs->arr[temp].phonenum << endl;
	}
}
//5.修改联系人
void changeperson(addbooks* abs)
{
	cout << "请输入你要查询的联系人" << endl;
	string cname;
	cin >> cname;
	int temp = panduan(abs, cname);
	if (temp == -1)
	{
		cout << "不存在该联系人" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "已查询到此人" << endl;
		cout << "姓名：" << abs->arr[temp].name << "\t";
		if (abs->arr[temp].sex == 1)
		{
			cout << "性别：男" << "\t";
		}
		else
		{
			cout << "性别：女" << "\t";
		}
		cout << "年龄：" << abs->arr[temp].age << "\t";
		cout << "电话：" << abs->arr[temp].phonenum << endl;
		cout << "请进行修改" << endl;
		//姓名
		while (true)
		{
			string nname;
			cout << "请输入姓名： " << endl;
			cin >> nname;
			if (panduan(abs, nname) == -1)
			{
				abs->arr[temp].name = nname;
				break;
			}
			else
			{
				cout << "已存在该联系人，请重新输入" << endl;
			}
		}
		//性别
		int nsex;
		cout << "请输入性别（1是男，0是女）： " << endl;
		cin >> nsex;
		while (nsex != 1 && nsex != 0)
		{
			cout << "输入错误，请重新输入： " << endl;
			cin >> nsex;

		}
		abs->arr[temp].sex = nsex;

		//年龄
		int age;
		cout << "请输入年龄： " << endl;
		cin >> age;
		abs->arr[temp].age = age;

		//电话
		string phonenum;
		cout << "请输入电话号码： " << endl;
		cin >> phonenum;
		abs->arr[temp].phonenum = phonenum;

		cout << "修改成功。" << endl;
		system("pause");
		system("cls");
	}
}
//6.清空联系人
void clearperson(addbooks* abs)
{
	abs->m_size = 0;
	cout << "已清空通讯录。" << endl;
	system("pause");
	system("cls");
}
int main(void)
{
	//创建结构体变量
	addbooks abs;
	//初始化通讯录人员个数
	abs.m_size = 0;
	int select = 0;

	while (true)   //放入循环，可以多次运行
	{
		showmenu();
		cin >> select;
		switch (select)    //先搭建选择的框架
		{
		case 1:          //添加联系人
			addperson(&abs);//利用地址传递
			break;
		case 2:          //显示联系人
			showperson(&abs);
			break;
		case 3:          //删除联系人
			deleteperson(&abs);
			break;
		case 4:          //查找联系人
			searchp(&abs);
			break;
		case 5:          //修改联系人
			changeperson(&abs);
			break;
		case 6:          //清空联系人
			break;
		case 0:          //清空通讯录
			cout << "已退出通讯录" << endl;
			system("pause");
			return 0;
			break;
		default :
			cout << "输入错误，请重新输入" << endl;
			break;
		}
	}
}