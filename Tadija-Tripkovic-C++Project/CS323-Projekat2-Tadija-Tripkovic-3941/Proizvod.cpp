#include "Proizvod.h"
#include "MojIzuzetak.h"



Proizvod::Proizvod()
{
}

Proizvod::Proizvod(int rednibr, string proizvodjac, string model, string boja, double cena)
{
	this->rednibr = rednibr;
	this->proizvodjac = proizvodjac;
	this->model = model;
	this->boja = boja;
	this->cena = cena;
}

void Proizvod::setRedniBroj(int rednibr)
{
	this->rednibr = rednibr;
}

int Proizvod::getRednibr()
{
	return rednibr;
}

void Proizvod::setProizvodjac(string proizvodjac)
{
	this->proizvodjac = proizvodjac;
}

string Proizvod::getProizvodjac()
{
	return proizvodjac;
}

void Proizvod::setModel(string model)
{
	this->model = model;
}

string Proizvod::getModel()
{
	return model;
}

void Proizvod::setBoja(string boja)
{
	this->boja = boja;
}

string Proizvod::getBoja()
{
	return boja;
}

void Proizvod::setCena(double cena)
{
	MojIzuzetak e;
	
	if (cena < 0) {
		cout << e.what() << endl;
	}
	else {
		this->cena = cena;
	}
}

double Proizvod::getCena()
{
	return cena;
}

bool operator==(Proizvod const& pr1, Proizvod const& pr2)
{
	if (pr1.rednibr == pr2.rednibr && pr1.proizvodjac == pr2.proizvodjac && pr1.model == pr2.model && pr1.boja == pr2.boja && pr1.cena == pr2.cena) {

		cout << "Objekat je pronadjen!" << endl;
		return true;
	}
	else {
		cout << "Objekat nije pronadjen!" << endl;
		return false;
	}

}

ostream& operator<<(ostream& out, const Proizvod& pr)
{
	out <<pr.rednibr << ", " << pr.proizvodjac << ", " << pr.model << ", " << pr.boja << ", " << pr.cena << endl;
	return out;
}

istream& operator>>(istream& is, Proizvod& pr)
{
	is >> pr.rednibr;
	is >> pr.proizvodjac;
	is >> pr.model;
	is >> pr.boja;
	is >> pr.cena;
	return is;

}