#pragma once
#include<iostream>
#include<string>
using namespace std;

class Persoana
{
private:
	string nume;
	string prenume;
	int varsta;
	char* adresa;
public:
	string getNume()
	{
		return nume;
	}
	void setNume(string nume)
	{
		if (nume.length() > 2)
		{
			this->nume = nume;
		}
	}

	string getPrenume()
	{
		return prenume;
	}
	void setPrenume(string prenume)
	{
		if (prenume.length() > 2)
		{
			this->prenume = prenume;
		}

	}

	int getVarsta()
	{
		return varsta;
	}
	void setVarsta(int varsta)
	{
		if (varsta > 0)
		{
			this->varsta = varsta;
		}
	}

	char* getAdresa()
	{
		return adresa;
	}
	void setAdresa(const char* adresa)
	{
		if (strlen(adresa) > 2)
		{
			if (this->adresa != nullptr)
			{
				delete[] this->adresa;
			}
			this->adresa = new char[strlen(adresa) + 1];
			strcpy_s(this->adresa, strlen(adresa) + 1, adresa);
		}
	}

	Persoana()
	{
		nume = " ";
		prenume = " ";
		varsta = 0;
		adresa = nullptr;
	}

	Persoana(string nume, string prenume, int varsta)
	{
		this->nume = nume;
		this->prenume = prenume;
		if (varsta > 0)
		{
			this->varsta = varsta;
		}
		else
		{
			this->varsta = 18;
		}
	}

	Persoana(string nume, string prenume, int varsta, const char* adresa)
	{
		this->nume = nume;
		this->prenume = prenume;
		if (varsta > 0)
		{
			this->varsta = varsta;
		}
		else
		{
			this->varsta = 18;
		}
		this->adresa = new char[strlen(adresa) + 1];
		strcpy_s(this->adresa, strlen(adresa) + 1, adresa);
	}

	Persoana(const Persoana& p)
	{
		this->nume = p.nume;
		this->prenume = p.prenume;
		this->varsta = p.varsta;
		if (p.adresa != nullptr)
		{
			this->adresa = new char[strlen(p.adresa) + 1];
			strcpy_s(this->adresa, strlen(p.adresa) + 1, p.adresa);
		}
		else
		{
			this->adresa = nullptr;
		}
	}

	~Persoana()
	{
		if (adresa != nullptr)
		{
			delete[] adresa;
		}
	}

	Persoana& operator=(const Persoana& p)
	{
		if (adresa != nullptr)
		{
			delete[] adresa;
		}
		this->nume = p.nume;
		this->prenume = p.prenume;
		this->varsta = p.varsta;
		if (p.adresa != nullptr)
		{
			this->adresa = new char[strlen(p.adresa) + 1];
			strcpy_s(this->adresa, strlen(p.adresa) + 1, p.adresa);
		}
		else
		{
			this->adresa = nullptr;
		}
		return *this;
	}

	Persoana operator+(int val)
	{
		if (val > 0)
		{
			Persoana copie = *this;
			copie.varsta += val;
			return copie;
		}
	}

	Persoana operator++()
	{
		this->varsta++;
		return *this;
	}

	Persoana operator++(int i)
	{
		Persoana copie = *this;
		this->varsta++;
		return copie;
	}

	explicit operator int()
	{
		return varsta;
	}

	int operator()()
	{
		if (adresa != nullptr)
		{
			return strlen(adresa);
		}
	}

	friend ostream& operator<<(ostream&, Persoana);
	friend istream& operator>>(istream&, Persoana&);
};

ostream& operator<<(ostream& out, Persoana p)
{
	cout << "Nume: ";
	out << p.nume << endl;
	cout << "Prenume: ";
	out << p.prenume << endl;
	cout << "Varsta: ";
	out << p.varsta << endl;
	cout << "Adresa: ";
	if (p.adresa != nullptr)
	{
		out << p.adresa;
	}
	else
	{
		out << "N/A";
	}
	out << endl;

	return out;
}

istream& operator>>(istream& in, Persoana& p)
{
	cout << "Nume: ";
	in >> p.nume;
	cout << "Prenume: ";
	in >> ws;
	getline(in, p.prenume);
	cout << "Varsta: ";
	in >> p.varsta;
	char buffer[100];
	cout << "Adresa: ";
	in >> ws;
	in.getline(buffer, 99);
	if (p.adresa != nullptr)
	{
		delete[] p.adresa;
	}
	p.adresa = new char[strlen(buffer) + 1];
	strcpy_s(p.adresa, strlen(buffer) + 1, buffer);

	return in;
}

class Client : public Persoana
{
private:
	int idClient;
	static string denumireAgentie;
	string email;
	int* greutateBagaj;
	int nrBagaje;
public:
	int getIdClient()
	{
		return idClient;
	}
	void setIdClient(int idClient)
	{
		if (idClient != 0)
		{
			this->idClient = idClient;
		}
	}

	static string getDenumireAgentie()
	{
		return denumireAgentie;
	}
	static void setDenumireAgentie(string denumireAgentie)
	{
		Client::denumireAgentie = denumireAgentie;
	}

	string getEmail()
	{
		return email;
	}
	void setEmail(string email)
	{
		if (email.length() > 5)
		{
			this->email = email;
		}
	}

	int* getGreutateBagaj()
	{
		if (greutateBagaj != nullptr)
		{
			int* copie = new int[nrBagaje];
			for (int i = 0; i < nrBagaje; i++)
			{
				copie[i] = greutateBagaj[i];
			}
			return copie;
		}
		else
		{
			return nullptr;
		}
	}
	void setGreutateBagaj(int* greutateBagaj, int nrBagaje)
	{
		if (greutateBagaj != nullptr && nrBagaje != 0)
		{
			this->nrBagaje = nrBagaje;
			if (this->greutateBagaj != nullptr)
			{
				delete[] this->greutateBagaj;
			}
			this->greutateBagaj = new int[nrBagaje];
			for (int i = 0; i < nrBagaje; i++)
			{
				this->greutateBagaj[i] = greutateBagaj[i];
			}
		}
	}

	int getNrBagaje()
	{
		return nrBagaje;
	}

	Client()
	{
		idClient = 0;
		email = " ";
		greutateBagaj = nullptr;
		nrBagaje = 0;
	}

	Client(string nume, string prenume, int varsta, const char* adresa, int idClient, string email) :
		Persoana(nume, prenume, varsta, adresa)
	{
		this->idClient = idClient;
		this->email = email;
	}

	Client(string nume, string prenume, int varsta, const char* adresa, int idClient, string email, int* greutateBagaj, int nrBagaje) :
		Persoana(nume, prenume, varsta, adresa)
	{
		this->idClient = idClient;
		this->email = email;
		if (greutateBagaj != nullptr && nrBagaje > 0)
		{
			this->nrBagaje = nrBagaje;
			this->greutateBagaj = new int[nrBagaje];
			for (int i = 0; i < nrBagaje; i++)
			{
				this->greutateBagaj[i] = greutateBagaj[i];
			}
		}
	}

	Client(const Client& c) : Persoana(c)
	{
		this->idClient = c.idClient;
		this->email = c.email;
		if (c.greutateBagaj != nullptr && c.nrBagaje != 0)
		{
			this->nrBagaje = c.nrBagaje;
			this->greutateBagaj = new int[c.nrBagaje];
			for (int i = 0; i < c.nrBagaje; i++)
			{
				this->greutateBagaj[i] = c.greutateBagaj[i];
			}
		}
		else
		{
			this->greutateBagaj = nullptr;
			this->nrBagaje = 0;
		}
	}

	~Client()
	{
		if (greutateBagaj != nullptr)
		{
			delete[] greutateBagaj;
		}
	}

	Client operator=(const Client& c)
	{
		Persoana::operator=(c);

		this->idClient = c.idClient;
		this->email = c.email;
		if (greutateBagaj != nullptr)
		{
			delete[] greutateBagaj;
		}
		if (c.greutateBagaj != nullptr && c.nrBagaje != 0)
		{
			this->nrBagaje = c.nrBagaje;
			this->greutateBagaj = new int[c.nrBagaje];
			for (int i = 0; i < c.nrBagaje; i++)
			{
				this->greutateBagaj[i] = c.greutateBagaj[i];
			}
		}
		else
		{
			this->greutateBagaj = nullptr;
			this->nrBagaje = 0;
		}
		return *this;
	}

	int& operator[](int index)
	{
		if (index >= 0 && index < nrBagaje)
		{
			return greutateBagaj[index];
		}
	}

	Client operator-(int val)
	{
		if (val > 0)
		{
			Client copie = *this;
			copie.nrBagaje -= val;
			return copie;
		}
	}

	Client operator--()
	{
		this->nrBagaje--;
		return *this;
	}

	Client operator--(int i)
	{
		Client copie = *this;
		this->nrBagaje--;
		return copie;
	}

	explicit operator string()
	{
		return email;
	}

	bool operator!()
	{
		return nrBagaje > 0;
	}

	static float medieGreutate(Client* clienti, int nrClienti)
	{
		float suma = 0;
		int nr = 0;
		if (clienti != nullptr && nrClienti > 0)
		{
			for (int i = 0; i < nrClienti; i++)
			{
				if (clienti[i].greutateBagaj != nullptr)
				{
					for (int j = 0; j < clienti[i].nrBagaje; j++)
					{
						suma += clienti[i].greutateBagaj[j];
						nr++;
					}
				}
			}
			if (nr > 0)
			{
				return suma / nr;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
	}
	friend ostream& operator<<(ostream&, Client);
	friend istream& operator>>(istream&, Client&);
};
string Client::denumireAgentie = "Travel";

ostream& operator<<(ostream& out, Client c)
{
	out << (Persoana)c;
	cout << "Id client: ";
	out << c.idClient << endl;
	cout << "Email: ";
	out << c.email << endl;
	cout << "Numar bagaje: ";
	out << c.nrBagaje << endl;
	cout << "Greutate bagaj: ";
	if (c.greutateBagaj != nullptr)
	{
		for (int i = 0; i < c.nrBagaje; i++)
		{
			out << c.greutateBagaj[i] << " ";
		}
	}
	cout << endl;
	return out;
}
istream& operator>>(istream& in, Client& c)
{
	in >> (Persoana&)c;
	cout << "Id client: ";
	in >> c.idClient;
	cout << "Email: ";
	in >> c.email;
	cout << "Numar bagaje: ";
	in >> c.nrBagaje;
	if (c.greutateBagaj != nullptr)
	{
		delete[] c.greutateBagaj;
	}
	if (in.good() && c.nrBagaje > 0)
	{
		c.greutateBagaj = new int[c.nrBagaje];
		for (int i = 0; i < c.nrBagaje; i++)
		{
			cout << "Greutate bagaj[" << i << "]: ";
			in >> c.greutateBagaj[i];
		}
	}
	else
	{
		c.nrBagaje = 0;
		c.greutateBagaj = nullptr;
	}
	cout << endl;

	return in;
}

class CompanieZbor {
private:
	int idCompanie = 0;
	char* numeCompanie = nullptr;
	int nrDestinatii = 0;
	char* destinatii = nullptr;
public:
	// 2 constructori cu parametri

	CompanieZbor(int idCompanie, const char* numeCompanie)
	{
		this->idCompanie = idCompanie;
		this->numeCompanie = new char[strlen(numeCompanie) + 1];
		strcpy_s(this->numeCompanie, strlen(numeCompanie) + 1, numeCompanie);

	}
	CompanieZbor(int idCompanie, const char* numeCompanie, int nrDestinatii, const char* destinatii)
	{
		this->idCompanie = idCompanie;
		this->numeCompanie = new char[strlen(numeCompanie) + 1];
		strcpy_s(this->numeCompanie, strlen(numeCompanie) + 1, numeCompanie);
		this->nrDestinatii = nrDestinatii;
		this->destinatii = new char[nrDestinatii + 1];
		for (int i = 0; i < nrDestinatii; i++)
		{

			this->destinatii[i] = destinatii[i];
		}
	}

	//constructor de copiere
	CompanieZbor(const CompanieZbor& cz)
	{
		this->idCompanie = cz.idCompanie;
		if (cz.numeCompanie != nullptr)
		{
			this->numeCompanie = new char[strlen(cz.numeCompanie) + 1];
			strcpy_s(this->numeCompanie, strlen(cz.numeCompanie) + 1, cz.numeCompanie);
		}
		this->destinatii = new char[cz.nrDestinatii];
		if (cz.destinatii != nullptr && cz.nrDestinatii != 0)
		{
			for (int i = 0; i < cz.nrDestinatii; i++)
			{
				this->destinatii[i] = destinatii[i];
			}
		}
		else
		{
			nrDestinatii = 0;
			destinatii = nullptr;
		}
	}

	//operator egal
	CompanieZbor& operator=(const CompanieZbor& cz)
	{
		if (numeCompanie != nullptr)
		{
			delete[] numeCompanie;
		}

		if (destinatii != nullptr)
		{
			delete[] destinatii;
		}

		this->idCompanie = cz.idCompanie;
		if (cz.numeCompanie != nullptr)
		{
			this->numeCompanie = new char[strlen(cz.numeCompanie) + 1];
			strcpy_s(this->numeCompanie, strlen(cz.numeCompanie) + 1, cz.numeCompanie);

		}
		else
		{
			this->numeCompanie = nullptr;
		}

		this->destinatii = new char[cz.nrDestinatii];

		if (cz.destinatii != nullptr && cz.nrDestinatii != 0)
		{
			for (int i = 0; i < cz.nrDestinatii; i++)
			{
				this->destinatii[i] = destinatii[i];
			}
		}
		else
		{
			nrDestinatii = 0;
			destinatii = nullptr;
		}

		return *this;
	}

	//destructor
	~CompanieZbor()

	{
		if (numeCompanie != nullptr)
		{
			delete[] numeCompanie;
		}

		if (destinatii != nullptr)
		{
			delete[] destinatii;
		}
	}

	//operator de indexare
	const char& operator[](int index)
	{
		if (index >= 0 && index < nrDestinatii)
		{
			return destinatii[index];
		}
		throw exception("Index invalid");
	}

	//operator boolean
	bool operator!()
	{
		return nrDestinatii > 0;
	}

	//operator +
	CompanieZbor operator+(int incaODest)
	{
		if (incaODest > 0)
		{
			CompanieZbor copie = *this;
			copie.nrDestinatii += incaODest;
			return copie;
		}
		else
		{
			throw "Nu s-a adaugat nimic";
		}
	}

	//operator ++ post si pre incr
	CompanieZbor operator++()
	{
		this->nrDestinatii++;
		return *this;
	}

	CompanieZbor operator++(int i)
	{
		CompanieZbor copie = *this;
		this->nrDestinatii++;
		return copie;
	}

	//operator de cast la int
	explicit operator int()
	{
		return idCompanie;
	}

	//getteri si setteri
	int getId()
	{
		return idCompanie;
	}

	void setId(int id)
	{
		if (id > 0)
		{
			this->idCompanie = id;

		}
	}


	char* getNumeCompanie()
	{
		return numeCompanie;
	}

	void setNumeCompanie(const char* numeCompanie)
	{
		if (numeCompanie != nullptr)
			delete[] numeCompanie;
		this->numeCompanie = new char[strlen(numeCompanie) + 1];
		strcpy_s(this->numeCompanie, strlen(numeCompanie) + 1, numeCompanie);

	}

	int getnrDestinatii()
	{
		return nrDestinatii;
	}

	void setnrDestinatii(int nr)
	{
		if (nr > 0)
		{
			this->nrDestinatii = nr;

		}
	}

	char* getDestinatii()
	{
		if (destinatii != nullptr)
		{
			char* copie = new char[nrDestinatii];
			for (int i = 0; i < nrDestinatii; i++)
			{
				copie[i] = destinatii[i];
			}
			return copie;
		}
		else
		{
			return nullptr;
		}
	}

	char getDestinatii(int index)
	{
		if (index >= 0 && index < nrDestinatii && destinatii != nullptr)
		{
			return destinatii[index];
		}
	}

	void setDestinatii(char* destinatii, int nrDestinatii)
	{
		if (destinatii != nullptr && nrDestinatii > 0)
		{
			this->nrDestinatii = nrDestinatii;
			if (destinatii != nullptr)
			{
				delete[] destinatii;
			}
			this->destinatii = new char[nrDestinatii];
			for (int i = 0; i < nrDestinatii; i++)
			{
				this->destinatii[i] = destinatii[i];
			}
		}
	}



	friend ostream& operator<<(ostream&, CompanieZbor);
	friend istream& operator>>(istream&, CompanieZbor&);
};

ostream& operator<<(ostream& out, CompanieZbor s)
{
	cout << "Id: ";
	out << s.idCompanie << endl;

	cout << "Nume Companie: ";
	if (s.numeCompanie != nullptr)
	{
		out << s.numeCompanie;
	}
	else {
		out << "N/A";
	}

	cout << "Numar destinatii: ";
	out << s.nrDestinatii << endl;

	cout << "Destinatii: ";
	if (s.destinatii != nullptr)
	{
		for (int i = 0; i < s.nrDestinatii; i++)
		{
			out << s.destinatii[i] << " ";
		}
	}
	return out;
}

istream& operator>>(istream& in, CompanieZbor& s)
{
	cout << "Id: ";
	in >> s.idCompanie;

	char buffer[100];
	cout << "Nume companie: ";
	in >> ws;

	in.getline(buffer, 99);
	if (s.numeCompanie != nullptr)
	{
		delete[] s.numeCompanie;
	}
	s.numeCompanie = new char[strlen(buffer) + 1];
	strcpy_s(s.numeCompanie, strlen(buffer) + 1, buffer);


	cout << "Numar destinatii ";
	in >> s.nrDestinatii;

	if (s.destinatii != nullptr)
	{
		delete[] s.destinatii;
	}
	//validare biti bad si fail stream de intrare
	if (in.good() && s.nrDestinatii > 0)
	{
		s.destinatii = new char[s.nrDestinatii];
		for (int i = 0; i < s.nrDestinatii; i++)
		{
			cout << "Destinatia " << i << " este ";
			in >> s.destinatii[i];
		}
	}
	else
	{
		s.nrDestinatii = 0;
		s.destinatii = nullptr;
	}
	return in;
}

class Avion {
private:
	int idAvion;
	string model = "necunoscut";
	int* capacitate = nullptr;
	int nrClase = 0;

public:

	//constructori cu parametri
	Avion(int idAvion, string model)
	{
		this->idAvion = idAvion;
		this->model = model;
	}

	Avion(int idAvion, string model, int* capacitate, int nrClase)
	{
		this->idAvion = idAvion;
		this->model = model;
		this->nrClase = nrClase;
		this->capacitate = new int[nrClase];
		if (capacitate != nullptr && nrClase != 0)
		{
			for (int i = 0; i < nrClase; i++)
			{
				this->capacitate[i] = capacitate[i];
			}
		}
	}

	//constructor de copiere
	Avion(const Avion& a)
	{
		this->idAvion = a.idAvion;
		this->model = a.model;
		this->nrClase = a.nrClase;
		this->capacitate = new int[a.nrClase];
		if (a.capacitate != nullptr && a.nrClase != 0)
		{
			for (int i = 0; i < a.nrClase; i++)
			{
				this->capacitate[i] = a.capacitate[i];
			}
		}
		else

		{
			this->capacitate = nullptr;
			this->nrClase = 0;
		}
	}

	//operator egal
	Avion& operator=(const Avion& a)
	{
		if (capacitate != nullptr)
		{
			delete[] capacitate;
		}
		this->idAvion = a.idAvion;
		this->model = a.model;
		this->nrClase = a.nrClase;
		this->capacitate = new int[a.nrClase];
		if (a.capacitate != nullptr && a.nrClase != 0)
		{
			for (int i = 0; i < a.nrClase; i++)
			{
				this->capacitate[i] = a.capacitate[i];
			}
		}
		else

		{
			this->capacitate = nullptr;
			this->nrClase = 0;
		}
		return *this;
	}

	//destructor
	~Avion()
	{
		delete[] capacitate;
	}

	//operator de indexare
	int& operator[](int index)
	{
		if (index >= 0 && index < nrClase)
		{
			return capacitate[index];
		}
		throw exception("Index invalid");
	}

	//operator de negatie
	bool operator!()
	{
		return nrClase > 0;
	}

	//operator +
	Avion operator+(int valoare)
	{
		if (valoare > 0)
		{
			Avion copie = *this;
			copie.nrClase += valoare;
			return copie;
		}
		else
		{
			throw "clase standard";
		}
	}

	//operator ++ post si pre incr
	Avion operator++()
	{
		this->nrClase++;
		return *this;
	}

	Avion operator++(int i)
	{
		Avion copie = *this;
		this->nrClase++;
		return copie;
	}

	//operator de cast la int
	explicit operator string()
	{
		return model;
	}

	//getteri si setteri

	int getId()
	{
		return idAvion;
	}

	void setId(int id)
	{
		if (id > 0)
			this->idAvion = id;
	}

	string getModel()
	{
		return model;
	}

	void setModel(string model)
	{
		if (model != "necunoscut")
			this->model = model;
	}

	int getnrClase()
	{
		return nrClase;
	}

	void setnrClase(int nr)
	{
		if (nr > 0)
		{
			this->nrClase = nr;

		}
	}

	int* getCapacitate()
	{
		if (capacitate != nullptr)
		{
			int* copie = new int[nrClase];
			for (int i = 0; i < nrClase; i++)
			{
				copie[i] = capacitate[i];
			}
			return copie;
		}
		else
		{
			return nullptr;
		}
	}

	int getCapacitate(int index)
	{
		if (index >= 0 && index < nrClase && capacitate != nullptr)
		{
			return capacitate[index];
		}
	}

	void setCapacitate(int* capacitate, int nrClase)
	{
		if (capacitate != nullptr && nrClase > 0)
		{
			this->nrClase = nrClase;
			if (capacitate != nullptr)
			{
				delete[] capacitate;
			}
			this->capacitate = new int[nrClase];
			for (int i = 0; i < nrClase; i++)
			{
				this->capacitate[i] = capacitate[i];
			}
		}
	}

	friend ostream& operator<<(ostream&, Avion);
	friend istream& operator>>(istream&, Avion&);

};

ostream& operator<<(ostream& out, Avion a)
{
	cout << "Id avion: ";
	out << a.idAvion << endl;

	cout << "Model: ";
	out << a.model << endl;

	cout << "Numar clase: ";
	out << a.nrClase << endl;
	cout << "Capacitate/clasa ";
	if (a.capacitate != nullptr)
	{
		for (int i = 0; i < a.nrClase; i++)
		{
			out << a.capacitate[i] << " ";
		}
	}
	return out;
}

istream& operator>>(istream& in, Avion& a)
{
	cout << "Id avion: ";
	in >> a.idAvion;

	cout << "Model";
	in >> ws;
	getline(in, a.model);

	cout << "Numar clase ";
	in >> a.nrClase;
	if (a.capacitate != nullptr)
	{
		delete[] a.capacitate;
	}
	//validare biti bad si fail stream de intrare
	if (in.good() && a.nrClase > 0)
	{
		a.capacitate = new int[a.nrClase];
		for (int i = 0; i < a.nrClase; i++)
		{
			cout << "Capacitate clasa" << i << " = ";
			in >> a.capacitate[i];
		}
	}
	else
	{
		a.nrClase = 0;
		a.capacitate = nullptr;
	}
	return in;
}

class Bilet {
private:
	int idBilet;
	string destinatie = "necunoscuta";
	char* dataPlecare;
	int pretBilet = 0;
	string numeCalator = "anonim";
	const int anCurent = 2021;

public:
	//constructori cu parametri
	Bilet(int idBilet, string destinatie, int pretBilet) :anCurent(anCurent)
	{
		this->idBilet = idBilet;
		this->destinatie = destinatie;
		this->pretBilet = pretBilet;
	}

	Bilet(int idBilet, string destinatie, const char* dataPlecare, int pretBilet, string numeCalator) :anCurent(anCurent)
	{
		this->idBilet = idBilet;
		this->destinatie = destinatie;
		this->dataPlecare = new char[strlen(dataPlecare) + 1];
		strcpy_s(this->dataPlecare, strlen(dataPlecare) + 1, dataPlecare);
		this->pretBilet = pretBilet;
		this->numeCalator = numeCalator;

	}

	//constructor de copiere

	Bilet(const Bilet& b) :anCurent(b.anCurent)
	{
		this->idBilet = b.idBilet;
		this->destinatie = b.destinatie;
		if (b.dataPlecare != nullptr)
		{
			this->dataPlecare = new char[strlen(b.dataPlecare) + 1];
			strcpy_s(this->dataPlecare, strlen(b.dataPlecare) + 1, b.dataPlecare);
		}
		this->pretBilet = b.pretBilet;
		this->numeCalator = b.numeCalator;
	}

	//operator egal
	Bilet& operator=(const Bilet& b)
	{
		if (dataPlecare != nullptr)
		{
			delete[] dataPlecare;
		}
		this->idBilet = b.idBilet;
		this->destinatie = b.destinatie;
		if (b.dataPlecare != nullptr)
		{
			this->dataPlecare = new char[strlen(b.dataPlecare) + 1];
			strcpy_s(this->dataPlecare, strlen(b.dataPlecare) + 1, b.dataPlecare);
		}
		else
		{
			dataPlecare = nullptr;
		}
		this->pretBilet = b.pretBilet;
		this->numeCalator = b.numeCalator;
		return *this;
	}

	//destructor
	~Bilet()
	{
		delete[] dataPlecare;
	}

	//operator negatie
	bool operator!()
	{
		return pretBilet > 0;
	}

	//operator +
	Bilet operator+(int adaos)
	{
		if (adaos > 0)
		{
			Bilet copie = *this;
			copie.pretBilet += adaos;
			return copie;
		}
		else
		{
			throw "pret nemodificat";
		}
	}

	//operator ++ post si pre incr
	Bilet operator++()
	{
		this->pretBilet++;
		return *this;
	}

	Bilet operator++(int i)
	{
		Bilet copie = *this;
		this->pretBilet++;
		return copie;
	}

	//operator de cast la int
	explicit operator char* ()
	{
		return dataPlecare;
	}

	int getId()
	{
		return idBilet;
	}

	void setId(int id)
	{
		if (id > 0)
			this->idBilet = id;
	}

	string getDestinatie()
	{
		return destinatie;
	}

	void setDestinatie(string destinatie)
	{
		if (destinatie != "necunoscuta")
			this->destinatie = destinatie;
	}

	int getPret()
	{
		return pretBilet;
	}

	void setPret(int pret)
	{
		if (pret > 0)
		{
			this->pretBilet = pret;
		}
	}

	string getNumeCalator()
	{
		return numeCalator;
	}

	void setNumeCalator(string nume)
	{
		if (nume != "anonim")
			this->numeCalator = nume;
	}


	char* getDataPlecare()
	{
		return dataPlecare;
	}

	void setDataPlecare(const char* dataPlecare)
	{
		if (dataPlecare != nullptr)
			delete[] dataPlecare;
		this->dataPlecare = new char[strlen(dataPlecare) + 1];
		strcpy_s(this->dataPlecare, strlen(dataPlecare) + 1, dataPlecare);


	}

	static float totalIncasari(int bilet)
	{
		float suma = 0;

		if (bilet > 0) {

			suma += bilet;
		}

		else
		{
			return 0;
		}
	}


	friend ostream& operator<<(ostream&, Bilet);
	friend istream& operator>>(istream&, Bilet&);
};

ostream& operator<<(ostream& out, Bilet b)
{
	cout << "Id bilet: ";
	out << b.idBilet << endl;

	cout << "Destinatie: ";
	out << b.destinatie << endl;

	cout << "Data plecare:  ";
	if (b.dataPlecare != nullptr)
	{
		out << b.dataPlecare;
	}
	else {
		out << "N/A";
	}
	out << endl;

	cout << "Pret bilet: ";
	out << b.pretBilet << endl;

	cout << "Nume calator: ";
	out << b.numeCalator << endl;

	return out;
}

istream& operator>>(istream& in, Bilet& b)
{
	cout << "Id bilet:  ";
	in >> b.idBilet;

	cout << "Destinatie: ";
	in >> ws;
	getline(in, b.destinatie);

	char buffer[100];
	cout << "Data plecare: ";
	in >> ws;

	in.getline(buffer, 99);
	if (b.dataPlecare != nullptr)
	{
		delete[] b.dataPlecare;
	}
	
	b.dataPlecare = new char[strlen(buffer) + 1];
	strcpy_s(b.dataPlecare, strlen(buffer) + 1, buffer);

	cout << "Pret bilet: ";
	in >> b.pretBilet;

	cout << "Nume calator: ";
	in >> ws;
	getline(in, b.numeCalator);

	return in;
}



