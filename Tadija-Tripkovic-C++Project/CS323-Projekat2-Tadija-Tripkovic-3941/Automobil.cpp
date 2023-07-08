#include "Automobil.h"
#include <istream>
#include <ostream>
#include <fstream>
#include <vector>
#include "Proizvod.h"
#include "MojIzuzetak.h"
#define _CRT_SECURE_NO_WARNINGS

MojIzuzetak e;

Automobil::Automobil()
{
}

Automobil::Automobil(int rednibr, string proizvodjac, string model, string boja, double cena,int kubikaza, int brojVrata, string tipKaroserije):Proizvod(rednibr, proizvodjac, model, boja, cena)
{
    this->kubikaza = kubikaza;
	this->brojVrata = brojVrata;
	this->tipKaroserije = tipKaroserije;
}

void Automobil::setKubikaza(int kubikaza)
{
    if (kubikaza < 0) {
        cout << e.what() << endl;
    }
    else {
        this->kubikaza = kubikaza;
    }
	
}

int Automobil::getKubikaza()
{
	return kubikaza;
}

void Automobil::setBrojVrata(int brojVrata)
{
   // this->brojVrata = brojVrata;
    if (brojVrata < 0) {
        cout << e.what() << endl;
    }
    else {
        this->brojVrata = brojVrata;
    }
}

int Automobil::getBrojVrata()
{
	return brojVrata;
}

void Automobil::setTipKaroserije(string tipKaroserije)
{
	this->tipKaroserije = tipKaroserije;
}

string Automobil::getTipKaroserije()
{
	return tipKaroserije;
}

istream& operator>>(istream& is, Automobil& a)
{
	is >> a.rednibr;
	is >> a.proizvodjac;
	is >> a.model;
	is >> a.boja;
	is >> a.cena;
	is >> a.kubikaza;
	is >> a.brojVrata;
	is >> a.tipKaroserije;
    return is;

}



ostream& operator<<(ostream& out,const Automobil& a)
{
	out << "Redni broj: " << a.rednibr << ", Proizvodjac: " << a.proizvodjac << ", Model: " << a.model << ", Boja: " << a.boja << ", Cena: " << a.cena << ", Kubikaza: " << a.kubikaza << ", Broj vrata: " << a.brojVrata << ", Tip karoserije: " << a.tipKaroserije << endl;
	return out;
}

void Automobil::upisUVektor() {

    Automobil a;
    char temp[50];

    while (1) {
        cout << "Unesite podatke o automobilu:" << endl;
        cout << endl;
        cout << "Redni broj: ";
        cin >> temp;
        a.setRedniBroj(atof(temp));

        cout << "Proizvodjac: ";
        cin >> temp;
        a.setProizvodjac(temp);

        cout << "Model: ";
        cin >> temp;
        a.setModel(temp);

        cout << "Boja: ";
        cin >> temp;
        a.setBoja(temp);

        cout << "Cena: ";
        cin >> temp;
        a.setCena(atof(temp));

        cout << "Kubikaza: ";
        cin >> temp;
        a.setKubikaza(atof(temp));

        cout << "Broj vrata: ";
        cin >> temp;
        a.setBrojVrata(atof(temp));

        cout << "Karoserija: ";
        cin >> temp;
        a.setTipKaroserije(temp);

        autovec.push_back(a);

        cout << "Automobil uspesno dodat! Trenutni broj objekata u fajlu je " << autovec.size() << ". " << endl;
        cout << endl;
        cout << "   PREKID = 0; DODAVANJE NOVOG AUTOMOBILA = 1; " << endl;

        int prekid = 1;
        cin >> prekid;
        if (prekid == 0) {
            break;
        }
    }

}

void Automobil::upisiUFajl()
{
    ofstream autofajl("automobili.txt");

    for (auto it = autovec.begin(); it != autovec.end(); ++it) {

        autofajl << it->getRednibr() << " " << it->getProizvodjac() << " " << it->getModel() << " " << it->getBoja() << " " << it->getCena() << " " << it->getKubikaza() << " " << it->getBrojVrata() << " " << it->getTipKaroserije() << endl;
    }

    autofajl.close();
}

void Automobil::citanje()
{
    ifstream fin;
    fin.open("automobili.txt");
    if (!fin) {
        cerr << "Greska pri otvaranju fajla---->Fajl nije pronadjen! " << endl;
    }

    Automobil a;
    ostream_iterator<Automobil> output(cout, "");

    autovec.clear();

    while (fin >> a) {

        autovec.push_back(a);
    }

    copy(autovec.begin(), autovec.end(), output);
    cout << endl;

    fin.close();
}

void Automobil::pretraga()
{
    //PRETRAGA PREMA PROIZVODJACU

    ifstream fin;
    fin.open("automobili.txt");
    if (!fin) {
        cerr << "Greska pri otvaranju fajla---->Fajl nije pronadjen! " << endl;
    }

    Automobil a;
    string id_temp;

    int id;
    string pr;
    string mo;
    string bo;
    double ce;
    int kub;
    int bvr;
    string kar;

    ostream_iterator<Automobil> output(cout, "");

    cout << "  **Unesite naziv proizvodjaca vozila koje zelite da pronadjete:  ";
    cin >> id_temp;
    cout << endl;

    autovec.clear();

    while (fin >> id >> pr >> mo >> bo >> ce >> kub >> bvr >> kar) {

        a.setRedniBroj(id);
        a.setProizvodjac(pr);
        a.setModel(mo);
        a.setBoja(bo);
        a.setCena(ce);
        a.setKubikaza(kub);
        a.setBrojVrata(bvr);
        a.setTipKaroserije(kar);

        if (id_temp == a.getProizvodjac()) {

            autovec.push_back(a);

        }
    }

    cout << "    Rezultat pretrage:  " << endl;
    copy(autovec.begin(), autovec.end(), output);
    cout << endl;

    fin.close();
}

void Automobil::brisanje()
{
    //BRISANJE PREMA ID

    ifstream fin;
    fin.open("automobili.txt");

    Automobil a;
    int id_temp;

    int id;
    string pr;
    string mo;
    string bo;
    double ce;
    int kub;
    int bvr;
    string kar;

    ostream_iterator<Automobil> output(cout, "");

    cout << "  **Unesite redni broj vozila koje zelite da obrisete:  ";
    cin >> id_temp;

    autovec.clear();

    while (fin >> id >> pr >> mo >> bo >> ce >> kub >> bvr >> kar) {

        a.setRedniBroj(id);
        a.setProizvodjac(pr);
        a.setModel(mo);
        a.setBoja(bo);
        a.setCena(ce);
        a.setKubikaza(kub);
        a.setBrojVrata(bvr);
        a.setTipKaroserije(kar);

        autovec.push_back(a);
    }

    for (auto it = autovec.begin(); it != autovec.end(); ++it) {
        if (id_temp == it->getRednibr()) {

            cout << "    USPESNO OBRISAN OBJEKAT: " << endl;
            cout << *it << endl;
            cout << endl;
            autovec.erase(it);
            break;

        }
    }

    upisiUFajl();

}

void Automobil::izmeni()
{
    //IZMENA PODATAKA OBJEKTA PREKO ID

    ifstream fin;
    fin.open("automobili.txt");
    if (!fin) {
        cerr << "Greska pri otvaranju fajla---->Fajl nije pronadjen! " << endl;
    }

    Automobil a;
    int id_temp;

    int id;
    string pr;
    string mo;
    string bo;
    double ce;
    int kub;
    int bvr;
    string kar;

    ostream_iterator<Automobil> output(cout, "");

    cout << "  **Unesite redni broj vozila cije podatke zelite da izmenite:  ";
    cout << endl;
    cin >> id_temp;

    autovec.clear();

    while (fin >> id >> pr >> mo >> bo >> ce >> kub >> bvr >> kar) {

        a.setRedniBroj(id);
        a.setProizvodjac(pr);
        a.setModel(mo);
        a.setBoja(bo);
        a.setCena(ce);
        a.setKubikaza(kub);
        a.setBrojVrata(bvr);
        a.setTipKaroserije(kar);

        autovec.push_back(a);
    }

    for (auto it = autovec.begin(); it != autovec.end(); ++it) {
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

            cout << "Kubikaza: ";
            cin >> kub;

            cout << "Broj vrata: ";
            cin >> bvr;

            cout << "Karoserija: ";
            cin >> kar;
            cout << endl;
            cout << endl;

            it->setProizvodjac(pr);
            it->setModel(mo);
            it->setBoja(bo);
            it->setCena(ce);
            it->setKubikaza(kub);
            it->setBrojVrata(bvr);
            it->setTipKaroserije(kar);

        }

    }

    upisiUFajl();
    cout << "    SACUVANO!" << endl;
    cout << endl;
}


