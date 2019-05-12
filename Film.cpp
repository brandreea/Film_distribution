#include "Film.h"
#include "cstring"
#include "string.h"
#include <iostream>
using namespace std;



Film::Film()
{
	lenght = 0;
	name = NULL;
	type = NULL;
	moneyMade = 0;
}

Film::Film(const Film& x)
{
	lenght = x.lenght;
	name = new char[strlen (x.name) + 1];
	name [strlen(x.name)]='\0';
	strcpy(name, x.name);
	type = new char[strlen (x.type) + 1];
	type[strlen(x.type)] = '\0';
	strcpy(type, x.type);
	moneyMade = x.moneyMade;
}

void Film::setLenght(int x)
{
	lenght = x;
}

void Film::setName(char* s)
{
	delete[] name;
	name = new char[strlen(s) + 1];
	name[strlen(s)] = '\0';
	strcpy(name, s);
}

void Film::setType(char* s)
{
	delete[] type;
	type = new char[strlen(s) + 1];
	type[strlen(s)] = '\0';
	strcpy(type, s);
}

void Film::setMoneyMade(float x)
{
	moneyMade = x;
}

void Film::addMoney(float x)
{
	moneyMade = moneyMade + x;
}

int Film::getLenght()
{
	return lenght;
}

char* Film::getName()
{
	return name;
}

char* Film::getType()
{
	return type;
}

int Film::getMoney()
{
	return moneyMade;
}

const Film& Film::operator=(const Film& x)
{
	if (this != (&x))
	{
		lenght = x.lenght;
		if(name!=NULL)
			delete[] name;
		name = new char[strlen(x.name) + 1];
		name[strlen(x.name)]= '\0';
		strcpy(name, x.name);
		if (type != NULL)
			delete[] type;
		type = new char[strlen(x.type) + 1];
		type[strlen(x.type)] = '\0';
		strcpy(type, x.type);
		moneyMade = x.moneyMade;
	}
	return *this;
}

Film::~Film()
{
	delete[] name;
	delete[] type;
	cout << "Deletion done!\n";
}

istream& operator>>(istream& is, Film& x)
{	
	int l;
	is >> l;
	char s[50], p[50];
	is.get();
	is.getline(s, 50);
	is.getline(p, 50);
	
	x.setLenght(l);
	is >> l;
	x.setMoneyMade(l);
	x.setName(s);
	x.setType(p);
	return is;
}

ostream& operator<<(ostream& os, Film& x)
{
	os << "Filmul "<<x.getName() << " din categoria "<<x.getType() << " are durata " <<x.getLenght()<< " minute si incasari de peste  "<<x.getMoney()<<" dolari.\n\n";
	return os;
}
