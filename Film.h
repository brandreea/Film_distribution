#pragma once
#include <iostream>
#include <fstream>

using namespace std;
class Film
{
private:
	char *name;
	char *type;
	int lenght;
	float moneyMade;
public:
	//constructors
	Film();
	Film(const Film& x);

	//set-functions
	void setLenght(int x);
	void setName(char* s);
	void setType(char* s);
	void setMoneyMade(float x);
	void addMoney(float x);
	//get-functions
	int getLenght();
	char* getName();
	char* getType();
	int getMoney();
	//"="operator
	const Film& operator=(const Film &x);
	//read and write data
	friend istream& operator>>(istream& is, Film& x);
	friend ostream& operator<<(ostream& os, Film& x);
	~Film();
};

