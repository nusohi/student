#pragma once
#ifndef DATABASE_H
#define DATABASE_H
#include <string>
#include <fstream>
#include <map>
using namespace std;



template<class T>
class DataBase
{
public:
	DataBase(string filePath);
	~DataBase();
	T* query(long ID);
	void insert(T& data);
	bool Delete(long ID);
	void showAllData();
	void saveMap();

	//SDB
	int calStuNum();
	int showGender(string gender);
	int* showAge();

protected:
	fstream file;
	string filePath;
	long fileLen;			//文件长度
	long size;				//记录大小
	typedef map<long, T> maptype;
	maptype dataMap;		//数据临时存储在内存中的地方
	int ages[30];	//0-30岁
};





template<class T>
DataBase<T>::DataBase(string filePath) {
	this->filePath = filePath;
	file.open(filePath, ios::in | ios::binary);
	size = sizeof(T);

	if (file.is_open()) {
		file.seekg(0,ios::end);
		fileLen = file.tellg();

		if (fileLen > 0) {
			T data;
			file.seekg(0,ios::beg);

			do {
				file.read((char*)&data, size);
				dataMap.insert(maptype::value_type(data.getID(), data));
			} while (file.tellg() < fileLen);
		}
		file.close();
	}
	else
		cout << filePath << " 无法打开！" << endl;

}

template<class T>
DataBase<T>::~DataBase() {
	saveMap();
}

template<class T>
T* DataBase<T>::query(long ID) {
	maptype::iterator iter;
	iter = dataMap.find(ID);
	if (iter == dataMap.end())
		return NULL;
	else 
		return &(iter->second);
}

template<class T>
void DataBase<T>::insert(T& data) {
	dataMap.insert(maptype::value_type(data.getID(), data));
	//dataMap[data.getID()] = data;
}

template<class T>
bool DataBase<T>::Delete(long ID) {
	if (query(ID) != NULL) {
		dataMap.erase(ID);
		return true;
	}
	return false;
}

template<class T>
void DataBase<T>::showAllData() {
	maptype::iterator iter;
	for (iter = dataMap.begin(); iter != dataMap.end(); iter++)
		(iter->second).showData();
}

template<class T>
void DataBase<T>::saveMap() {
	maptype::iterator iter;
	T data;
	file.open(filePath, ios::out | ios::binary | ios::trunc);
	for (iter = dataMap.begin(); iter != dataMap.end(); iter++)
		file.write((char*)&iter->second, size);
	file.close();

}


//SDB

template<class T>
int DataBase<T>::calStuNum() {
	return fileLen / size;
}

template<class T>
int DataBase<T>::showGender(string gender) {
	int num = 0;
	maptype::iterator iter;
	for (iter = dataMap.begin(); iter != dataMap.end(); iter++) {
		string sex((iter->second).getSex());
		if (gender.compare(sex) == 0) {
			(iter->second).showData();
			num++;
		}
	}
	return num;
}

template<class T>
int* DataBase<T>::showAge() {

	for (int i = 0; i < 30; i++)
		ages[i] = 0;

	maptype::iterator iter;
	for (iter = dataMap.begin(); iter != dataMap.end(); iter++) {
		ages[(iter->second).getAge() - 1]++;
	}
	return ages;
}



#endif