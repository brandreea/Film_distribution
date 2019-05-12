#include "Worker.h"
#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;


Worker::Worker()
{	
	filmsno = 0;
	films = NULL;
	name = NULL;
	for (int i = 0; i < 13; i++)
		cnp[i] = 0;
	p = 0;
	salary = 0;

}

Worker::Worker(const Worker& x)
{
	for (int i = 0; i < 13; i++)
		cnp[i] = x.cnp[i];

	name = new char[strlen(x.name) + 1];
	name[strlen(x.name)] = '\0';
	strcpy(name, x.name);

	filmsno = x.filmsno;
	films = new char* [filmsno];
	for (int i = 0; i < filmsno; i++)
	{
		films[i] = new char[strlen(x.films[i]) + 1];
		films[strlen(x.films[i])] = '\0';
		strcpy(films[i], x.films[i]);
	}
	p = x.p;
	salary = x.salary;
}

const Worker& Worker::operator=(const Worker& x)
{
	if (this != &x)
	{	
		//cnp
		for (int i = 0; i < 13; i++)
			cnp[i] = x.cnp[i];
		//name
		if (name != NULL)
			delete[] name;
		name = new char[strlen(x.name) + 1];
		name[strlen(x.name)] = '\0';
		strcpy(name, x.name);

		//films
		for (int i = 0; i < filmsno; i++)
			if (films[i] != NULL)
				delete[] films[i];
		if (films != NULL)
			delete[]films;
		filmsno = x.filmsno;
		films = new char* [filmsno];
		for (int i = 0; i < filmsno; i++)
		{
			films[i] = new char[strlen(x.films[i]) + 1];
			films[strlen(x.films[i])] = '\0';
			strcpy(films[i], x.films[i]);
		}
	}
	p = x.p;
	salary = x.salary;
	return *this;
}


void Worker::setP(float x)
{
	p = x;
}

void Worker::setSalary(float x)
{
	salary =salary+ x*p;
	cout << salary;
}

void Worker::setCNP(int v[13])
{
	for (int i = 0; i < 13; i++)
		cnp[i] = v[i];
}

void Worker::setFilmsNO(int x)
{
	filmsno = x;
	films = new char* [filmsno];
}

void Worker::setName(char* s)
{
	if (name != NULL)
		delete[] name;
	name = new char[strlen(s) + 1];
	name[strlen(s)] = '\0';
	strcpy(name, s);
}

void Worker::setFilm(char* s, int poz)
{
	/*if (films[poz] != NULL)
		delete[] films[poz];*/
	films[poz] = new char[strlen(s) + 1];
	films[poz][strlen(s)] = '\0';
	strcpy(films[poz], s);
}




float Worker::getP()
{
	return p;
}

float Worker::getSalary()
{
	return salary;
}

void Worker::show()
{
	cout << name << " activeaza in industria cinematografica.\n";
		if (filmsno > 0)
			cout << "Printre cele mai importante filme ale sale se numara ";
		else cout << "Desi acesta nu a contribui inca in niciun film remarcabil, potentialul sau il recomanda";
		for (int i = 0; i < filmsno - 1; i++)
		{
			cout << films[i];
			if (i != filmsno - 2)
				cout << ", ";
		}
	cout << " si " << films[filmsno - 1];
	cout << ".\n";
	cout << "Pentru a-l identifica mai usor, il puteti cauta folosind cnp-ul: ";
	for (int i = 0; i < 13; i++)
		cout << cnp[i];
	cout << ".\n\n";
}

 Worker::~Worker()
{
	if (films != NULL)
		for (int i = 0; i < filmsno; i++)
			delete[] films[i];
	if (name != NULL)
		delete[] name;
	cout << "Deletion done!\n";
}

 istream& operator>>(istream& is, Worker& x)
 {
	 //cnp
	 int s[13];
	 for (int i = 0; i < 13; i++)
		 is >> s[i];
	 x.setCNP(s);
	 cout << "CNP Read\n";
	 is.get();
	 char c[50];
	 //name
	 is.getline(c, 50);
	 x.setName(c);
	 cout << "Name read\n";
	 //films

	 int fn;
	 is >> fn;
	 x.setFilmsNO(fn);
	 is.get();

	 for (int i = 0; i < fn; i++)
	 {
		 is.getline(c, 50);
		 x.setFilm(c, i);
	 }
	 cout << "Titles read";
	 float p;
	 is >> p;
	 x.setP(p);
	 return is;
 }