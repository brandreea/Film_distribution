
#include <iostream>
#include "Film.h"
#include "Worker.h"
#include "Actor.h"
#include "FilmDirector.h"
using namespace std;
ifstream fin("dates.txt");
int main()
{		
	
	Film x;
	fin >> x;
	cout << x;
	
	FilmDirector Y;
	Actor X;
	fin >> Y;
	fin >> X;
	Y.show();
	X.show();
	Y.setSalary(x.getMoney());
	cout << Y.getSalary() << "\n";
	X.setSalary(x.getMoney(),1);
	
	return 0;
}

