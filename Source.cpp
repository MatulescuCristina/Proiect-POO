#include<iostream>
#include<string>
#include "Header.h"
using namespace std;

int main()
{
	Persoana p;
	p.setNume("Popescu");
	p.setVarsta(39);
	cout << p.getNume() << endl;
	cout << p.getVarsta() << endl;

	Persoana p1("Popa", "Ion", 20, "Valcea");
	cout << p1.getAdresa() << endl;

	Persoana p2 = p1;
	cout << p2.getVarsta()<< endl;

	Persoana p3("Ionescu", "Dan", 25, "Sibiu");
	cout << p3.getNume() << endl;

	Persoana p4("Dumitrescu", "Alin", 29, "Craiova");
	cout << p4.getAdresa() << endl;

	cout << "!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;

	cout << p1.getPrenume() << endl;

	p1 = p4;
	cout << p1.getPrenume() << endl;

	cout << p3 << endl;

	Persoana p5;
	//cin >> p5;

	//cout << p5 << endl;
	
	p4 = p3 + 5;
	cout << p4.getVarsta() << endl;

	Persoana p6 = ++p2;
	cout << p6.getVarsta() << endl;
	Persoana p7 = p2++;
	cout << p7.getVarsta() << endl;

	int varsta = (int)p;
	cout << varsta << endl;

	cout << p1() << endl;

	cout << "\n-------------------------------\n" << endl;

	Client c();
	
	Client c1("Matulescu", "Cristina", 21, "Valcea", 1, "cristina@gmail.com");
	cout << c1 << endl;

	Client c2 = c1;
	cout << c2 << endl;

	Client c3("Dumitrescu", "Alex", 23, "Cluj", 2, "alex@gmail.com");
	cout << c3 << endl;

	Client c4("Popa", "Alin", 25, "Constanta", 3, "alin@gmail.com");
	cout << c4 << endl;

	c3 = c1;
	cout << c3<<endl;

	cout << "?????????????????????" << endl;

	//Client c5;
	//cin >> c5;
	//cout << c5 << endl;

	int greutateBagaj1[] = { 12, 10, 6 };
	Client c6("M", "C", 30, "V", 5, "mc@gmail.com", greutateBagaj1, 3);
	cout << c6 << endl;

	int greutateBagaj2[] = { 10, 15 };
	Client c7("A", "A", 32, "B", 6, "aa@gmail.com", greutateBagaj2, 2);
	cout << c7 << endl;

	//c7 = c6 - 2;
	//cout << c7 << endl;

	//Client c8 = --c6;
	//cout << c8.getNrBagaje() << endl;

	//Client c9 = c7--;
	//cout << c9.getNrBagaje() << endl;

	string email = (string)c1;
	cout << email << endl;

	bool areBagaj = !c7;
	cout << areBagaj << endl;

	Client clienti[] = { c6, c7 };
	float medie = Client::medieGreutate(clienti, 2);
	cout << medie << endl;

	/*char* v = new char[4];
	for (int i = 0; i < 4; i++)
	{

	}
	 char** v = { "Maldive", "Creta", "Mikonos", "Spania" };
	 CompanieZbor c1(1, "Blue Air", 4, v);*/

	int cz1[] = { 32, 35, 40 };
	Avion a1(34, "Boeing 340", cz1, 3);

	int cz2[] = { 40, 50, 50 };
	Avion a2(35, "Boeing 345", cz2, 3);

	a2.setId(36);
	cout << a2.getId() << endl;

	/*int c3[] = { 45,55,65,75 };
	a2.setCapacitate(c3, 4);
	cout << a2.getCapacitate();*/

	/*int* x = a2.getCapacitate();
	for (int i = 0; i < a2.getnrClase(); i++)
	{
		cout << x[i] << endl;
	}

	cout << endl;
	delete[] x;
	x = nullptr;*/

	Bilet b1(566, "Maldive", "12-07-2021", 150, "Ionica");
	Bilet b2(567, "Tenerife", "15-07-2021", 160, "Vasilica");
	b2.setPret(170);
	cout << b2.getPret()<<endl;
	
	c7.setEmail(email);
	c7.serializare();

	c7.deserializare();

	a2.setId(34);
	a2.serializare();

	a2.deserializare();

	b1.setDestinatie("Maldive");
	b1.serializare();

	b1.deserializare();



}
