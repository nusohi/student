// student.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include "Student.h"
#include "DataBase.h"
using namespace std;

// 菜单
void add(DataBase<Pupil>& pupil, DataBase<Middle>& middle, DataBase<College>& college);
void query(DataBase<Pupil>& pupil, DataBase<Middle>& middle, DataBase<College>& college);
void display(DataBase<Pupil>& pupil, DataBase<Middle>& middle, DataBase<College>& college);
void edit(DataBase<Pupil>& pupil, DataBase<Middle>& middle, DataBase<College>& college);
void Delete(DataBase<Pupil>& pupil, DataBase<Middle>& middle, DataBase<College>& college);
void count(DataBase<Pupil>& pupil, DataBase<Middle>& middle, DataBase<College>& college);



int main()
{
	DataBase<Pupil> pupil("e://Pupil.dat");
	DataBase<Middle> middle("e://Middle.dat");
	DataBase<College> college("e://College.dat");

	void(*menu[])(DataBase<Pupil>& pupil, DataBase<Middle>& middle, DataBase<College>& college)
	{ add, query, display, edit, Delete, count };

	char choice = 'X';

	while (choice != '0') {
		cout << "----------------------------------\n";
		cout << "\t0. 退出系统\n\t1. 添加\n\t2. 查询\n\t3. 显示\n\t4. 编辑\n\t5. 删除\n\t6. 统计\n";
		cout << "----------------------------------\n";
		cout << "->请输入： ";

		cin >> choice;
		if(choice!='0')
			menu[(int)(choice-'0'-1)](pupil, middle, college);
	}
    return 0;
}


void add(DataBase<Pupil>& pupil, DataBase<Middle>& middle, DataBase<College>& college) {
	int choice;

	long ID = -1;
	char name[10];
	char sex[6];
	int age, Class;
	float CH, MA, EN;
	float GE, HI;
	char address[30], major[16], phoneNumber[20];

	cout << "输入添加的学生类别： (1.小学生  2.中学生  3.大学生)" << endl;
	cin >> choice;
	if (choice == 0) {
		return;
	}
	else if (choice == 1) {
		while (ID != 0) {
			cout << "->请输入学生的学号 (输0终止)： ";
			//cin.ignore();
			cin >> ID;
			if (ID != 0) {
				if (!pupil.query(ID) && !middle.query(ID) && !college.query(ID)) {
					cout << "->请依次输入学生的姓名：";
					cin >> name;
					cout << setw(24) << right << "性别：";
					cin >> sex;
					cout << setw(24) << right << "年龄：";
					cin >> age;
					cout << setw(24) << right << "班级：";
					cin >> Class;
					cout << setw(24) << right << "语文成绩：";
					cin >> CH;
					cout << setw(24) << right << "数学成绩：";
					cin >> MA;
					cout << setw(24) << right << "英语成绩：";
					cin >> EN;

					Pupil temp(ID, name, sex, age, Class, CH, MA, EN);
					pupil.insert(temp);
					cout << ID << " 添加成功！" << endl;
				}
				else {
					cout << ID << "已存在!" << endl;
				}
			}
		}
	}
	else if (choice == 2) {
		while (ID != 0) {
			cout << "->请输入学生的学号 (输0终止)： ";
			//cin.ignore();
			cin >> ID;
			if (ID != 0){
				if (!pupil.query(ID) && !middle.query(ID) && !college.query(ID)) {
					cout << "->请依次输入学生的姓名：";
					cin >> name;
					cout << setw(24) << right << "性别：";
					cin >> sex;
					cout << setw(24) << right << "年龄：";
					cin >> age;
					cout << setw(24) << right << "班级：";
					cin >> Class;
					cout << setw(24) << right << "语文成绩：";
					cin >> CH;
					cout << setw(24) << right << "数学成绩：";
					cin >> MA;
					cout << setw(24) << right << "英语成绩：";
					cin >> EN;
					cout << setw(24) << right << "地理成绩：";
					cin >> GE;
					cout << setw(24) << right << "历史成绩：";
					cin >> HI;
					cout << setw(24) << right << "家庭住址：";
					cin >> address;

					Middle temp(ID, name, sex, age, Class, CH, MA, EN, GE, HI, address);
					middle.insert(temp);
					cout << ID << " 添加成功！" << endl;
				}
				else {
					cout << ID << "已存在!" << endl;
				}
			}
		}
	}
	else if (choice == 3) {
		while (ID != 0) {
			cout << "->请输入学生的学号 (输0终止)： ";
			cin >> ID;
			if (ID != 0) {
				if (!pupil.query(ID) && !middle.query(ID) && !college.query(ID)) {
					cout << "->请依次输入学生的姓名：";
					cin >> name;
					cout << setw(24) << right << "性别：";
					cin >> sex;
					cout << setw(24) << right << "年龄：";
					cin >> age;
					cout << setw(24) << right << "班级：";
					cin >> Class;
					cout << setw(24) << right << "专业：";
					cin >> major;
					cout << setw(24) << right << "家庭地址：";
					cin >> address;
					cout << setw(24) << right << "联系方式：";
					cin >> phoneNumber;

					College temp(ID, name, sex, age, Class, major, address, phoneNumber);
					college.insert(temp);
					cout << ID << " 添加成功！" << endl;
				}
				else {
					cout << ID << "已存在!" << endl;
				}
			}
		}
	}
}

void query(DataBase<Pupil>& pupil, DataBase<Middle>& middle, DataBase<College>& college) {
	long ID = -1;
	while (ID) {
		cout << "请输入要查询的学号(输0退出)： ";
		cin >> ID;
		if (ID != 0) {
			if (pupil.query(ID))
				pupil.query(ID)->showData();
			else if (middle.query(ID))
				middle.query(ID)->showData();
			else if (college.query(ID))
				college.query(ID)->showData();
			else
				cout << "没有查到！" << endl;
		}
	}
}

void display(DataBase<Pupil>& pupil, DataBase<Middle>& middle, DataBase<College>& college) {
	cout << "--------------- 小学生\n";
	cout << left << setw(16) << "学号" << setw(8) << "姓名" << setw(6) << right << "性别" << setw(6) << "年龄" << setw(8) << "班级"
		<< setw(6) << "语文" << setw(6) << "数学" << setw(6) << "英语" << endl;
	pupil.showAllData();
	cout << "--------------- 中学生\n";
	cout << left << setw(16) << "学号" << setw(8) << "姓名" << setw(6) << right << "性别" << setw(6) << "年龄" << setw(8) << "班级"
		<< setw(6) << "语文" << setw(6) << "数学" << setw(6) << "英语" << setw(6) << "地理" << setw(6) << "历史"
		<< left << "\t家庭地址" << endl;
	middle.showAllData();
	cout << "--------------- 大学生\n";
	cout << left << setw(16) << "学号" << setw(8) << "姓名" << setw(6) << right << "性别" << setw(6) << "年龄" << setw(8) << "班级"
		<< setw(10) << "专业"  <<'\t'<< left<< setw(20)<< "联系电话"  << '\t' << "家庭地址" << endl;
	college.showAllData();
	cout << "----------------------" << endl;
}

void edit(DataBase<Pupil>& pupil, DataBase<Middle>& middle, DataBase<College>& college) {
	long ID = -1;
	Student* stu;

	while (ID) {
		cout << "请输入要编辑的学号(输0退出)： ";
		cin >> ID;
		if (ID != 0) {
			if (stu = pupil.query(ID));
			else if (stu = middle.query(ID));
			else if (stu = college.query(ID));
			else {
				cout << "没有查到！" << endl;
				return;
			}
			stu->showData();
			cout << "修改学号请直接输入,否则输入0继续修改基本信息：";
			cin >> ID;
			if (ID) {
				if (pupil.query(ID)|| middle.query(ID)|| college.query(ID)) {
					cout << "该学号已存在！" << endl;
				}
				else {
					stu->setID(ID);
					cout << "修改成功！" << endl;
					stu->showData();
				}
			}
			else
				stu->editAll();
		}
	}
}

void Delete(DataBase<Pupil>& pupil, DataBase<Middle>& middle, DataBase<College>& college) {
	long ID = -1;
	while (ID) {
		cout << "请输入要删除的学号(输0退出)： ";
		cin >> ID;
		if (ID != 0) {
			if (pupil.query(ID)) {
				pupil.query(ID)->showData();
				pupil.Delete(ID);
				cout << "删除成功！" << endl;
			}
			else if (middle.query(ID)) {
				middle.query(ID)->showData();
				middle.Delete(ID);
				cout << "删除成功！" << endl;
			}
			else if (college.query(ID)) {
				college.query(ID)->showData();
				college.Delete(ID);
				cout << "删除成功！" << endl;
			}
			else
				cout << "记录为空！" << endl;
		}
	}
}

void count(DataBase<Pupil>& pupil, DataBase<Middle>& middle, DataBase<College>& college) {
	
}

