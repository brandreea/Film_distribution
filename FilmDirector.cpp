#include "FilmDirector.h"




void FilmDirector::setSalary(float x)
{	
	//cout << x;
	float news = x * p;
	salary = salary + news + sum;
	//cout << salary;
}

void FilmDirector::show()
{
	cout << name << " este un cunoscut director de film.\n";
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

FilmDirector::~FilmDirector()
{
}
