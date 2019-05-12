#pragma once
#include "Worker.h"
#include<iostream>
#include <fstream>
using namespace std;
class FilmDirector :
	public Worker
{
private:
	static const int sum=1000;
public:
	FilmDirector() :Worker() {};
	void setSalary(float x);
	void show();
	~FilmDirector();
};

