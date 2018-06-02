#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include <string>
using namespace std;


class Student
{
public:
	Student();
	~Student();
	Student(long ID, string name, char sex[3], int age, int Class);


	virtual void showData() = 0;
	//set
	void setID();
	void setName();
	void setSex();
	void setAge();
	void setClass();
	//get
	long getID() const;
	string getName() const;
	char* getSex() const;
	int getAge() const;
	int getClass() const;
private:
	long ID;
	string name;
	char sex[3];
	int age;
	int Class;
};




class Pupil :public Student
{
public:
	Pupil(long ID, string name, char sex[3], int age, int Class, float CH, float MA, float EN);
	~Pupil();

	void showData();

private:
	float CH;
	float MA;
	float EN;
};




class Middle :public Pupil
{
public:
	Middle(long ID, string name, char sex[3], int age, int Class, 
		float CH, float MA, float EN, float GE, float HI, string address);
	~Middle();

	void showData();


private:
	float GE;
	float HI;
	string address;
};





class College :public Student
{
public:
	College(long ID, string name, char sex[3], int age, int Class, 
		float CH, float MA, float EN, string major, string address, string phoneNumber);
	~College();

	void showData();

private:
	string major;
	string address;
	string phoneNumber;
};





#endif