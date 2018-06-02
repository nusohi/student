#include "stdafx.h"
#include "Student.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
#pragma warning(disable:4996);

/************    学生     ***************************************************************/

Student::Student(long ID, const char* name, const char* sex, int age, int Class) {
	setID(ID);
	setName(name);
	setSex(sex);
	setAge(age);
	setClass(Class);
}

//set
void Student::setID(long ID){
	this->ID = ID;
}
void Student::setName(const char* name) {
	strcpy(this->name, name);
}
void Student::setSex(const char* sex) {
	strcpy(this->sex, sex);
}
void Student::setAge(int age) {
	this->age = age;
}
void Student::setClass(int Class) {
	this->Class = Class;
}
//get
long Student::getID() const {
	return ID;
}
char* Student::getName() {
	return name;
}
char* Student::getSex() {
	return sex;
}
int Student::getAge() const {
	return age;
}
int Student::getClass() const {
	return Class;
}

/************    小学生     ***************************************************************/

Pupil::Pupil(long ID, const char* name, const char* sex, int age, int Class, float CH, float MA, float EN)
	:Student(ID,name,sex,age,Class){
	setCH(CH);
	setMA(MA);
	setEN(EN);
}

void Pupil::editAll() {
	int choice = -1;
	char name[10];
	char sex[3];
	int age, Class;
	float grade;

	cout << "1姓名、2性别、3年龄、4班级、5语文、6数学、7英语成绩";
	while (choice != 0) {
		cout << "请输入序号+修改值(空格隔开,0退出)： ";
		cin >> choice;
		switch (choice) {
		case 1:
			cin >> name;
			setName(name);
			break;
		case 2:
			cin >> sex;
			setSex(sex);
			break;
		case 3:
			cin >> age;
			setAge(age);
			break;
		case 4:
			cin >> Class;
			setClass(Class);
			break;
		case 5:
			cin >> grade;
			setCH(grade);
			break;
		case 6:
			cin >> grade;
			setMA(grade);
			break;
		case 7:
			cin >> grade;
			setEN(grade);
			break;
		default:break;
		}
	}
}
void Pupil::showData() {
	cout << left << setw(16) << ID << setw(8) << name << setw(6) << right << sex << setw(6) << age << setw(8)
		<< Class << setw(6) << CH << setw(6) << MA << setw(6) << EN << endl;
}

//set
void Pupil::setCH(float CH){
	this->CH = CH;
}
void Pupil::setMA(float MA){
	this->MA = MA;
}
void Pupil::setEN(float EN){
	this->EN = EN;
}
//get
float Pupil::getCH(){
	return CH;
}
float Pupil::getMA(){
	return MA;
}
float Pupil::getEN(){
	return EN;
}

/************    中学生     ***************************************************************/

Middle::Middle(long ID, const char* name, const char* sex, int age, int Class, float CH, float MA, float EN, float GE, float HI, const char* address)
	:Pupil(ID, name, sex, age, Class, CH, MA, EN) {
	setGE(GE);
	setHI(HI);
	setAddress(address);
}

void Middle::editAll() {
	int choice = -1;
	char name[10], sex[3], address[30];
	int age, Class;
	float grade;

	cout << "1姓名、2性别、3年龄、4班级、5语文、6数学、7英语、8地理、9历史成绩、10家庭地址";
	while (choice != 0) {
		cout << "请输入序号+修改值(空格隔开,0退出)： ";
		cin >> choice;
		switch (choice) {
		case 1:
			cin >> name;
			setName(name);
			break;
		case 2:
			cin >> sex;
			setSex(sex);
			break;
		case 3:
			cin >> age;
			setAge(age);
			break;
		case 4:
			cin >> Class;
			setClass(Class);
			break;
		case 5:
			cin >> grade;
			setCH(grade);
			break;
		case 6:
			cin >> grade;
			setMA(grade);
			break;
		case 7:
			cin >> grade;
			setEN(grade);
			break;
		case 8:
			cin >> grade;
			setGE(grade);
			break;
		case 9:
			cin >> grade;
			setHI(grade);
			break;
		case 10:
			cin >> address;
			setAddress(address);
			break;
		default:break;
		}
	}
}
void Middle::showData() {
	cout << left << setw(16) << ID << setw(8) << name << setw(6) << right << sex << setw(6) << age << setw(8)
		<< Class << setw(6) << CH << setw(6) << MA << setw(6) << EN 
		<< setw(6) << GE << setw(6) << HI 
		<< '\t' << address << endl;
}

//set
void Middle::setGE(float GE) {
	this->GE = GE;
}
void Middle::setHI(float HI) {
	this->HI = HI;
}
void Middle::setAddress(const char* address) {
	strcpy(this->address, address);
}
//get
float Middle::getGE() {
	return GE;
}
float Middle::getHI() {
	return HI;
}
char* Middle::getAddress() {
	return address;
}

/************    大学生     ***************************************************************/

College::College(long ID, const char* name, const char* sex, int age, int Class,
	const char* major, const char* address, const char* phoneNumber)
	:Student(ID, name, sex, age, Class) {
	setMajor(major);
	setAddress(address);
	setPhoneNumber(phoneNumber);
}

void College::editAll() {
	int choice = -1;
	char name[10], sex[3];
	int age, Class;
	char str[30];

	cout << "1姓名、2性别、3年龄、4班级、5专业、6家庭地址、7联系电话\n";
	while (choice != 0) {
		cout << "请输入序号+修改值(空格隔开,0退出)： ";
		cin >> choice;
		switch (choice) {
		case 1:
			cin >> name;
			setName(name);
			break;
		case 2:
			cin >> sex;
			setSex(sex);
			break;
		case 3:
			cin >> age;
			setAge(age);
			break;
		case 4:
			cin >> Class;
			setClass(Class);
			break;
		case 5:
			cin >> str;
			setMajor(str);
			break;
		case 6:
			cin >> str;
			setAddress(str);
			break;
		case 7:
			cin >> str;
			setPhoneNumber(str);
			break;
		default:break;
		}
	}
}
void College::showData() {
	cout << left << setw(16) << ID << setw(8) << name << setw(6) << right << sex << setw(6) << age << setw(8) << Class
		<< setw(10) << major <<'\t'<< left<< setw(20) << phoneNumber  << '\t' << address << endl;
}

//set
void College::setMajor(const char* major) {
	strcpy(this->major, major);
}
void College::setAddress(const char* address) {
	strcpy(this->address, address);
}
void College::setPhoneNumber(const char* phoneNumber) {
	strcpy(this->phoneNumber, phoneNumber);
}
//get
char* College::getMajor() {
	return major;
}
char* College::getAddress() {
	return address;
}
char* College::getPhoneNumber() {
	return phoneNumber;
}



