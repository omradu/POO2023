#include <iostream>
#include <string>
using namespace std;


class Carte
{
	const string ISBN; 
	string titlu;
	string autor;
	int nrPagini;
	int nrCapitole;
	int* nrPaginiPerCapitol;

	static int nrCarti; 

public:
	Carte() : ISBN("12345")
	{
		this->titlu = "";
		this->autor = "";
		this->nrPagini = 0;
		this->nrCapitole = 0;
		this->nrPaginiPerCapitol = nullptr;

		nrCarti++;
	}

	Carte(string ISBN, string titlu, string autor, int nrPagini, int nrCapitole, int* nrPaginiPerCapitol) : ISBN(ISBN)
	{
		this->titlu = titlu;
		this->autor = autor;
		this->nrPagini = nrPagini;
		this->nrCapitole = nrCapitole;
		if (nrPaginiPerCapitol != nullptr)
		{
			this->nrPaginiPerCapitol = new int[nrCapitole];
			for (int i = 0; i < nrCapitole; i++)
			{
				this->nrPaginiPerCapitol[i] = nrPaginiPerCapitol[i];
			}
		}
		else
		{
			this->nrPaginiPerCapitol= nullptr;
		}

		nrCarti++;
	}

	Carte(const Carte& c) : ISBN(c.ISBN)
	{
		this->titlu = c.titlu;
		this->autor = c.autor;
		this->nrPagini = c.nrPagini;
		this->nrCapitole = c.nrCapitole;
		if (c.nrPaginiPerCapitol!= nullptr)
		{
			this->nrPaginiPerCapitol= new int[this->nrCapitole];
			for (int i = 0; i < this->nrCapitole; i++)
			{
				this->nrPaginiPerCapitol[i] = c.nrPaginiPerCapitol[i];
			}
		}

		nrCarti++;
	}

	~Carte()
	{
		if (this->nrPaginiPerCapitol != nullptr)
		{
			delete[] this->nrPaginiPerCapitol;
		}
	}

	static void faCeva()
	{
		cout << "Ceva la nivel de clasa\n";
	}

	//Getters
	string getISBN()
	{
		return this->ISBN;
	}

	string getTitlu()
	{
		return this->titlu;
	}

	int getNrPagini()
	{
		return this->nrPagini;
	}

	int getNrCapitole()
	{
		return this->nrCapitole;
	}

	int* getNrPaginiPerCapitol()
	{
		int* copie;
		if (this->nrPaginiPerCapitol != nullptr)
		{
			copie = new int[this->nrCapitole];
			for (int i = 0; i < this->nrCapitole; i++)
			{
				copie[i] = this->nrPaginiPerCapitol[i];
			}
		}
		else
		{
			copie = nullptr;
		}

		return copie;
	}

	static int getNrCarti()
	{
		return nrCarti;
	}

	//Setters
	void setTitlu(string titlu)
	{
		this->titlu = titlu;
	}

	void setAutor(string autor)
	{
		this->autor = autor;
	}

	void setNrPagini(int nrPagini)
	{
		this->nrPagini = nrPagini;
	}

	void setNrCapitole(int nrCapitole)
	{
		this->nrCapitole = nrCapitole;
	}

	void setNrPaginiPerCapitol(int* nrPaginiPerCapitol)
	{
		if (this->nrPaginiPerCapitol != nullptr)
		{
			delete[] this->nrPaginiPerCapitol;
		}

		if (nrPaginiPerCapitol != nullptr)
		{
			this->nrPaginiPerCapitol = new int[this->nrCapitole];
			for (int i = 0; i < this->nrCapitole; i++)
			{
				this->nrPaginiPerCapitol[i] = nrPaginiPerCapitol[i];
			}
		}
		else
		{
			this->nrPaginiPerCapitol = nullptr;
		}
	}

	void setNrCarti(int nrCarti)
	{
		Carte::nrCarti = nrCarti;
	}

	//supraincarcare operator =
	Carte& operator=(const Carte& c)
	{
		if (this != &c)
		{
			this->titlu = c.titlu;
			this->autor = c.autor;
			this->nrPagini = c.nrPagini;
			this->nrCapitole = c.nrCapitole;
			if (this->nrPaginiPerCapitol != nullptr)
			{
				delete[] this->nrPaginiPerCapitol;
			}

			if (c.nrPaginiPerCapitol != nullptr)
			{
				this->nrPaginiPerCapitol = new int[c.nrCapitole];
				for (int i = 0; i < this->nrCapitole; i++)
				{
					this->nrPaginiPerCapitol[i] = c.nrPaginiPerCapitol[i];
				}
			}
			else
			{
				this->nrPaginiPerCapitol = nullptr;
			}
		}

		return *this;
	}

	//o metoda care afiseaza tot continutul unei carti
	void showBook()
	{
		cout << "Cartea " << this->titlu << " de " << this->autor << " are ISBN: " << this->ISBN << " si " << this->nrPagini << " pagini cu " << this->nrCapitole << " capitole\n";
		if (this->nrPaginiPerCapitol != nullptr)
		{
			for (int i = 0; i < this->nrCapitole; i++)
			{
				cout << "Capitolul " << i+1 << " are " << this->nrPaginiPerCapitol[i] << " pagini\n";
			}
		}
	}


};

int Carte::nrCarti = 0;

