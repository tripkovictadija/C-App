#include <iostream>
#include <istream>
#include <fstream>
#include "Automobil.h"
#include "Proizvod.h"
#include "Proizvod.h"
#include "MojIzuzetak.h"
#include "DodatnaOprema.h"
#include <vector>

#define _CRT_SECURE_NO_WARNINGS

int main() {

    Proizvod* p;
    Automobil a1;

    p = &a1;

    DodatnaOprema o1;
    int izbor = 0;

    cout << "SALON AUTOMOBILA I OPREME ZA AUTOMOBILE" << endl;
    cout<< endl;
  
    while (1) {
        cout << "   **PRISTUP DELU SA AUTOMOBILIMA = 1   **" << endl;
        cout << "   **PRISTUP DELU SA DODATNOM OPREMOM = 2   **" << endl;
        cout << "Vas izbor: ";

        cin >> izbor;
        try {
            throw MojIzuzetak();
        }
        catch(MojIzuzetak& e){

            switch (izbor) {
            case 1:
                cout << "Izaberite opciju za rad sa automobilima: " << endl;
                while (izbor!=0) {
                    cout << " *** 1. upisi;  2. iscitaj;   3. pretrazi;  4. brisanje;   5. izmena;   6. izlaz;  *** " << endl;
                    cin >> izbor;
                    switch (izbor) {
                    case 1:
                        p->upisUVektor();
                        p->upisiUFajl();
                        break;
                    case 2:
                        p->citanje();
                        break;
                    case 3:
                        p->pretraga();
                        break;
                    case 4:
                        p->brisanje();
                        break;
                    case 5:
                        p->izmeni();
                        break;

                    case 6:
                        exit(0);
                        break;
                    }
                }
                break;

            case 2:

                p = &o1;
                cout << "Izaberite opciju za rad sa dodatnom opremom: " << endl;
                while (izbor!=0) {
                    cout << " *** 1. upisi;  2. iscitaj;   3. pretrazi;  4. brisanje;   5. izmena;   6. izlaz;  *** " << endl;
                    cin >> izbor;
                    switch (izbor) {
                    case 1:
                        p->upisUVektor();
                        p->upisiUFajl();
                        break;
                    case 2:
                        p->citanje();
                        break;
                    case 3:
                        p->pretraga();
                        break;
                    case 4:
                        p->brisanje();
                        break;
                    case 5:
                        p->izmeni();
                        break;
                    case 6:
                        exit(0);
                        break;
                    }
                }
                break;
                


            }

        }
        

    }

	return 0;
}

