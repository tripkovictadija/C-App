#ifndef Automobil_HEADER
#define Automobil_HEADER
#include <iostream>
#include <string>
#include <istream>
#include <fstream>
#include <vector>
#include "Proizvod.h"

using namespace std;

class Automobil : public Proizvod
{
private:
    int kubikaza;
    int brojVrata;
    string tipKaroserije;
    vector<Automobil> autovec;
public:
    Automobil();
    Automobil(int rednibr, string proizvodjac, string model, string boja, double cena,int kubikaza, int brojVrata, string tipKaroserije);
    void setKubikaza(int kubikaza);
    int getKubikaza();
    void setBrojVrata(int brojVrata);
    int getBrojVrata();
    void setTipKaroserije(string tipKaroserije);
    string getTipKaroserije();
   
    void upisUVektor();
    void upisiUFajl();
    void citanje();
    void pretraga();
    void brisanje();
    void izmeni();

    friend istream& operator>>(istream& is, Automobil& a);
    friend ostream& operator<<(ostream& out,const Automobil& pr);

};
#endif
