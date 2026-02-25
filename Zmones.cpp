#include "Zmones.h"

zmogus gen() {
    zmogus a;

    switch(rand() % 10) {
        case 0: a.vardas = "Jonas"; break;
        case 1: a.vardas = "Petras"; break;
        case 2: a.vardas = "Dainius"; break;
        case 3: a.vardas = "Rokas"; break;
        case 4: a.vardas = "Marius"; break;
        case 5: a.vardas = "Irma"; break;
        case 6: a.vardas = "Lina"; break;
        case 7: a.vardas = "Giedre"; break;
        case 8: a.vardas = "Toma"; break;
        case 9: a.vardas = "Laura"; break;
    }
    switch(*a.vardas.rbegin()) {
        case 's':
            switch(rand() % 5) {
                case 0: a.pavarde = "Pavardenis1"; break;
                case 1: a.pavarde = "Pavardenis2"; break;
                case 2: a.pavarde = "Pavardenis3"; break;
                case 3: a.pavarde = "Pavardenis4"; break;
                case 4: a.pavarde = "Pavardenis5"; break;
            }
            break;
        default:
            switch(rand() % 5) {
                case 0: a.pavarde = "Pavardaite1"; break;
                case 1: a.pavarde = "Pavardaite2"; break;
                case 2: a.pavarde = "Pavardaite3"; break;
                case 3: a.pavarde = "Pavardaite4"; break;
                case 4: a.pavarde = "Pavardaite5"; break;
            }
            break;
    }
    return a;
}