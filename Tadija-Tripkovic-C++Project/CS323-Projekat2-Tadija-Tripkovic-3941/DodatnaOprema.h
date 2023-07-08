#include <iostream>
#include <string>
#include <vector>
#include "Proizvod.h"

using namespace std;

class DodatnaOprema :
    public Proizvod
{
private:
    string tipOpreme;
    string garancija;
    vector<DodatnaOprema> opremavec;

public:
    DodatnaOprema();
    DodatnaOprema(int rednibr, string proizvodjac, string model, string boja, double cena, string tipOpreme, string garancija);
    void setTipOpreme(string tipOpreme);
    string getTipOpreme();
    void setGarancija(string garancija);
    string getGarancija();

    void upisUVektor();
    void upisiUFajl();
    void citanje();
    void pretraga();
    void brisanje();
    void izmeni();

    friend istream& operator>>(istream& is, DodatnaOprema& o);
    friend bool operator== (DodatnaOprema const& o1, DodatnaOprema const& o2);
    friend ostream& operator<<(ostream& out, const DodatnaOprema& o);
    
};

