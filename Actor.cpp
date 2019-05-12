#include "Actor.h"



void Actor::setPBonus(float x)
{
	pbonus = x;
}

void Actor::setIsMain(bool x[])
{
	isMain = new bool[filmsno];
	for (int i = 0; i < filmsno; i++)
		isMain[i] = x[i];
}

void Actor::setSalary(float x, int i)
{
	salary = salary + x * p;
	if (isMain[i])
		salary = salary + x * (0.1);
}

void Actor::show()
{
	cout << name << " este unul dintre actorii mei preferati.\n";
	if (filmsno > 0)
		cout << "Printre cele mai importante filme ale sale se numara ";
	else cout << "Desi acesta nu s-a afirmat inca si in industria cinematografica, potentialul sau il recomanda.";
	for (int i = 0; i < filmsno - 1; i++)
	{
		cout << films[i];
		if (isMain[i])
			cout << "(in rolul principal)";
		if (i != filmsno - 2)
			cout << ", ";
	}
	if (filmsno - 1 >= 0)
	{
		cout << "si " << films[filmsno - 1];
		if (isMain[filmsno-1])
			cout << "(in rolul principal)";
	}
	cout << ".\n";
	cout << "Pentru a-l identifica mai usor, il puteti cauta folosind cnp-ul: ";
	for (int i = 0; i < 13; i++)
		cout << cnp[i];
	cout << ".\n\n";
	//cout << p<<"\n";
}

Actor::~Actor()
{
	if (isMain != NULL)
		delete[] isMain;
}

istream& operator>>(istream& is, Actor& x)
{
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
	cout << "Names read\n";
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
	bool isPrincipal[15];
	for (int i = 0; i < fn; i++)
	{
		is >> isPrincipal[i];
	}
	x.setIsMain(isPrincipal);
	float p;
	is >> p;
	x.setP(p);
	return is;
}
