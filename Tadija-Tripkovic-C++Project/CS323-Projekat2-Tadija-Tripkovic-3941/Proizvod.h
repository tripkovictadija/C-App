#ifndef Proizvod_HEADER
#define Proizvod_HEADER
#include <iostream>
#include <string>

using namespace std;

class Proizvod
{
protected:
	int rednibr;
	string proizvodjac;
	string model;
	string boja;
	double cena;
public:
	Proizvod();
	Proizvod(int rednibr, string proizvodjac, string model, string boja, double cena);
	void setRedniBroj(int rednibr);
	int getRednibr();
	void setProizvodjac(string proizvodjac);
	string getProizvodjac();
	void setModel(string model);
	string getModel();
	void setBoja(string boja);
	string getBoja();
	void setCena(double cena);
	double getCena();
	
	virtual void upisUVektor() = 0;
	virtual void upisiUFajl() = 0;
	virtual void citanje() = 0;
	virtual void pretraga() = 0;
	virtual void brisanje() = 0;
	virtual void izmeni() = 0;

	friend bool operator== (Proizvod const& pr1, Proizvod const& pr2);
	friend ostream& operator<<(ostream& out, const Proizvod& pr);
	friend istream& operator>>(istream& is, Proizvod& pr);

};

#endif