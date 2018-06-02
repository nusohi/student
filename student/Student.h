#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include <string>
using namespace std;


/************    学生     ***************************************************************/
class Student
{
public:
	Student() {}
	Student(long ID, const char* name, const char* sex, int age, int Class);
	~Student() {}
	//
	virtual void editAll() = 0;
	virtual void showData() = 0;

	//set
	void setID(long ID);
	void setName(const char* name);
	void setSex(const char* sex);
	void setAge(int age);
	void setClass(int Class);
	//get
	long getID() const;
	char* getName();
	char* getSex();
	int getAge() const;
	int getClass() const;
protected:
	long ID;
	char name[10];
	char sex[6];
	int age;
	int Class;
};


/************    小学生     ***************************************************************/
class Pupil :public Student
{
public:
	Pupil() {}
	Pupil(long ID, const char* name, const char* sex, int age, int Class, float CH, float MA, float EN);
	//
	void editAll();
	void showData();
	//set
	void setCH(float CH);
	void setMA(float MA);
	void setEN(float EN);
	//get
	float getCH();
	float getMA();
	float getEN();
protected:
	float CH;
	float MA;
	float EN;
};


/************    中学生     ***************************************************************/
class Middle :public Pupil
{
public:
	Middle() {}
	Middle(long ID, const char* name, const char* sex, int age, int Class,
		float CH, float MA, float EN, float GE, float HI, const char* address);
	//
	void editAll();
	void showData();
	//set
	void setGE(float GE);
	void setHI(float HI);
	void setAddress(const char* address);
	//get
	float getGE();
	float getHI();
	char* getAddress();
private:
	float GE;
	float HI;
	char address[30];
};


/************    大学生     ***************************************************************/
class College :public Student
{
public:
	College() {}
	College(long ID, const char* name, const char* sex, int age, int Class,
		const char* major, const char* address, const char* phoneNumber);
	//
	void editAll();
	void showData();
	//set
	void setMajor(const char* major);
	void setAddress(const char* address);
	void setPhoneNumber(const char* phoneNumber);
	//get
	char* getMajor();
	char* getAddress();
	char* getPhoneNumber();
private:
	char major[16];
	char address[30];
	char phoneNumber[20];
};




#endif