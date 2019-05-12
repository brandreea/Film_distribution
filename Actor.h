#pragma once
#include "Worker.h"
#include <xatomic.h>
class Actor :
	public Worker
{
private:
	float pbonus;
	bool *isMain;
public:
	Actor(const float x = 0.1) :Worker() { isMain = NULL; pbonus = 0.1; };
	
	//set-functions
	void setPBonus(float x);
	void setIsMain(bool x[]);
	void setSalary(float x,int i);
	friend istream& operator>>(istream& is, Actor& x);
	void show();
	~Actor();
};

