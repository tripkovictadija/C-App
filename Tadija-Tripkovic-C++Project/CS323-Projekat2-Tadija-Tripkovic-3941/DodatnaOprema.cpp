#include "DodatnaOprema.h"
#include <istream>
#include <ostream>
#include <fstream>
#include <vector>
#include "Proizvod.h"
#include <algorithm>


DodatnaOprema::DodatnaOprema()
{
}

DodatnaOprema::DodatnaOprema(int rednibr, string proizvodjac, string model, string boja, double cena, string tipOpreme, string garancija) : Proizvod(rednibr, proizvodjac, model, boja, cena)
{
	this->tipOpreme = tipOpreme;
	this->garancija = garancija;
}

void DodatnaOprema::setTipOpreme(string tipOpreme)
{
	this->tipOpreme = tipOpreme;
}

string DodatnaOprema::getTipOpreme()
{
	return tipOpreme;
}

void DodatnaOprema::setGarancija(string garancija)
{
	this->garancija = garancija;
}

string DodatnaOprema::getGarancija()
{
	return garancija;
}

istream& operator>>(istream& is, DodatnaOprema& o)
{
	is >> o.rednibr;
	is >> o.proizvodjac;
	is >> o.model;
	is >> o.boja;
	is >> o.cena;
	is >> o.tipOpreme;
	is >> o.garancija;
	return is;

}

bool operator==(DodatnaOprema const& o1, DodatnaOprema const& o2)
{
	if (o1.rednibr == o2.rednibr && o1.proizvodjac == o2.proizvodjac && o1.model == o2.model && o1.boja == o2.boja && o1.cena == o2.cena && o1.tipOpreme == o2.tipOpreme && o1.garancija == o2.garancija) {

		cout << "Proizvod je pronadjen!" << endl;
		return true;
	}
	else {
		cout << "Proizvod nije pronadjen!" << endl;
		return false;
	}

}

ostream& operator<<(ostream& out, const DodatnaOprema& o)
{
	out << "Redni broj: " << o.rednibr << ", Proizvodjac: " << o.proizvodjac << ", Model: " << o.model << ", Boja: " << o.boja << ", Cena: " << o.cena << ", Naziv proizvoda: " << o.tipOpreme << ", Garancija: " << o.garancija << " meseci. " << endl;
	return out;
}

void DodatnaOprema::upisUVektor() {

    DodatnaOprema o;
    char temp[50];

    while (1) {
        cout << "Unesite podatke o proizvodu:" << endl;
        cout << endl;
        cout << "Redni broj: ";
        cin >> temp;
        o.setRedniBroj(atof(temp));

        cout << "Proizvodjac: ";
        cin >> temp;
        o.setProizvodjac(temp);

        cout << "Model: ";
        cin >> temp;
        o.setModel(temp);

        cout << "Boja: ";
        cin >> temp;
        o.setBoja(temp);

        cout << "Cena: ";
        cin >> temp;
        o.setCena(atof(temp));

        cout << "Naziv proizvoda: ";
        cin >> temp;
        o.setTipOpreme(temp);

        cout << "Garancija: ";
        cin >> temp;
        o.setGarancija(temp);

        opremavec.push_back(o);

        cout << "Proizvod uspesno dodat! Trenutni broj objekata u fajlu je " << opremavec.size() << ". " << endl;
        cout << endl;
        cout << "   PREKID = 0; DODAVANJE NOVOG PROIZVODA = 1; " << endl;

        int prekid = 1;
        cin >> prekid;
        if (prekid == 0) {
            break;
        }
    }
}

void DodatnaOprema::upisiUFajl()
{
    ofstream opremafajl("oprema.txt");

    for (auto it = opremavec.begin(); it != opremavec.end(); ++it) {

        // autofajl.write((char*) &it, sizeof(it));
        opremafajl << it->getRednibr() << " " << it->getProizvodjac() << " " << it->getModel() << " " << it->getBoja() << " " << it->getCena() << " " << it->getTipOpreme() << " " << it->getGarancija() << endl;
    }

    opremafajl.close();
}

void DodatnaOprema::citanje()
{
    ifstream opremafajl;
    opremafajl.open("oprema.txt");
    if (!opremafajl) {
        cerr << "Greska pri otvaranju fajla---->Fajl nije pronadjen! " << endl;
    }

    DodatnaOprema o;
    ostream_iterator<DodatnaOprema> output(cout, "");

    opremavec.clear();

    while (opremafajl >> o) {

        opremavec.push_back(o);
    }

    copy(opremavec.begin(), opremavec.end(), output);
    cout << endl;

    opremafajl.close();
}

void DodatnaOprema::pretraga()
{
    //PRETRAGA PREMA PROIZVODJACU

    ifstream fin;
    fin.open("oprema.txt");
    if (!fin) {
        cerr << "Greska pri otvaranju fajla---->Fajl nije pronadjen! " << endl;
    }

    DodatnaOprema o;
    string id_temp;

    int id;
    string pr;
    string mo;
    string bo;
    double ce;
    string tip;
    string gar;

    ostream_iterator<DodatnaOprema> output(cout, "");

    cout << "  **Unesite naziv proizvodjaca opreme koje zelite da pronadjete:  ";
    cin >> id_temp;
    cout << endl;

    opremavec.clear();

    while (fin >> id >> pr >> mo >> bo >> ce >> tip >> gar) {

        o.setRedniBroj(id);
        o.setProizvodjac(pr);
        o.setModel(mo);
        o.setBoja(bo);
        o.setCena(ce);
        o.setTipOpreme(tip);
        o.setGarancija(gar);

        if (id_temp == o.getProizvodjac()) {

            opremavec.push_back(o);

        }
    }

    cout << "    Rezultat pretrage:  " << endl;
    copy(opremavec.begin(), opremavec.end(), output);
    cout << endl;

    fin.close();
}

void DodatnaOprema::brisanje()
{
    //BRISANJE PREMA ID

    ifstream fin;
    fin.open("oprema.txt");

    DodatnaOprema o;
    int id_temp;

    int id;
    string pr;
    string mo;
    string bo;
    double ce;
    string tip;
    string gar;

    ostream_iterator<DodatnaOprema> output(cout, "");

    cout << "  **Unesite redni broj proizvoda kog zelite da obrisete:  ";
    cin >> id_temp;

    opremavec.clear();

    while (fin >> id >> pr >> mo >> bo >> ce >> tip >> gar) {

        o.setRedniBroj(id);
        o.setProizvodjac(pr);
        o.setModel(mo);
        o.setBoja(bo);
        o.setCena(ce);
        o.setTipOpreme(tip);
        o.setGarancija(gar);

        opremavec.push_back(o);
    }

    for (auto it = opremavec.begin(); it != opremavec.end(); ++it) {
        if (id_temp == it->getRednibr()) {

            cout << "    USPESNO OBRISAN OBJEKAT: " << endl;
            cout << *it << endl;
            cout << endl;
            opremavec.erase(it);
            break;

        }
    }

    upisiUFajl();

}

void DodatnaOprema::izmeni()
{
    //IZMENA PODATAKA OBJEKTA PREKO ID

    ifstream fin;
    fin.open("oprema.txt");
    if (!fin) {
        cerr << "Greska pri otvaranju fajla---->Fajl nije pronadjen! " << endl;
    }

    DodatnaOprema o;
    int id_temp;

    int id;
    string pr;
    string mo;
    string bo;
    double ce;
    string tip;
    string gar;

    ostream_iterator<DodatnaOprema> output(cout, "");

    cout << "  **Unesite redni broj proizvoda cije podatke zelite da izmenite:  ";
    cout << endl;
    cin >> id_temp;

    opremavec.clear();

    while (fin >> id >> pr >> mo >> bo >> ce >> tip >> gar) {

        o.setRedniBroj(id);
        o.setProizvodjac(pr);
        o.setModel(mo);
        o.setBoja(bo);
        o.setCena(ce);
        o.setTipOpreme(tip);
        o.setGarancija(gar);

        opremavec.push_back(o);
    }

    for (auto it = opremavec.begin(); it != opremavec.end(); ++it) {
        if (id_temp == it->getRednibr()) {

            cout << "    Unesite nove podatke: " << endl;
            cout << "Proizvodjac: ";
            cin >> pr;

            cout << "Model: ";
            cin >> mo;

            cout << "Boja: ";
            cin >> bo;

            cout << "Cena: ";
            cin >> ce;

            cout << "Naziv proizvoda: ";
            cin >> tip;

            cout << "Garancija ";
            cin >> gar;
            cout << endl;
            cout << endl;

            it->setProizvodjac(pr);
            it->setModel(mo);
            it->setBoja(bo);
            it->setCena(ce);
            it->setTipOpreme(tip);
            it->setGarancija(gar);
            
        }

    }

    upisiUFajl();
    cout << "    SACUVANO!" << endl;
    cout << endl;
}