PRZENOSZACE
class przyklad
{
public:
	przyklad() {}
	//KONSTRUKTOR PRZENOSZACY
	przyklad(przyklad&& org)
	{
		cout << "Dziala konstruktor przenoszacy\n";
	}
	//PRZENOSZACY OPERATOR
	przyklad& operator=(przyklad&& org)
	{
		cout << "Dziala przenoszacy operator =\n";
		return *this;
	}
};

KOPIUJACE

class przyklad
{
public:
	przyklad() {};
	//KONSTRUKTOR KOPIUJACY
	przyklad(const przyklad& org)
	{
		cout << "Dziala konstruktor kopiujacy\n";
	}
	//KOPIUJACY OPERATOR PRZYPISANIA
	przyklad& operator=(const przyklad& org)
	{
		cout << "Dziala kopiujacy operator =\n";
		return *this;
	}
};
