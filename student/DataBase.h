#pragma once
#ifndef DATABASE_H
#define DATABASE_H
#include <string>
#include <fstream>
using namespace std;

template<class T>
class DataBase
{
public:
	DataBase(string fileName);
	~DataBase();
	T* query(long ID);
	void insert(T& data);
	bool Delete(long ID);
	void showAllData();
	void saveMap();
private:
	fstream file;
	string fileName;
	long fileLen;			//文件长度
	long size;				//记录大小
	typedef map<long, T> maptype;
	maptype dataMap;		//数据临时存储在内存中的地方
};





template<class T>
DataBase<T>::DataBase(string fileName) {

}

template<class T>
DataBase<T>::~DataBase() {
	saveMap();
}

template<class T>
T* DataBase<T>::query(long ID) {

}

template<class T>
void DataBase<T>::insert(T& data) {

}

template<class T>
bool DataBase<T>::Delete(long ID) {

}

template<class T>
void DataBase<T>::showAllData() {

}

template<class T>
void DataBase<T>::saveMap() {

}




#endif