#pragma once
#include<iostream>
#include <fstream>
using namespace std;
class Worker
{
protected:
	int cnp[13];
	char* name;
	char** films;
	int filmsno;
	float salary;
	float p;
public:
	Worker();
	Worker(const Worker& x);
	//"=" operator
	const Worker& operator=(const Worker& x);
	//setting function
	virtual void setP(float x);
	virtual void setSalary(float x);
	void setCNP(int v[13]);
	void setFilmsNO(int x);
	void setName(char* s);
	void setFilm(char* s, int poz);
	//reading/showing functions
	
	float getP();
	float getSalary();
	virtual void show();
	virtual ~Worker();
	friend istream& operator>>(istream& is, Worker& x);
};

