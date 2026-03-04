#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include "Funkcijos.h"

using std::cout;
using std::sort;
using std::vector;
using std::string;
using std::endl;

void clearInput() {
    cout << "Neteisinga ivestis. ";
    cin.clear();
    cin.ignore(10000, '\n');
}

void vidurkis(studentas &S) {
    if (S.paz.empty()) {
        S.rez = S.egzam * EGZAM_kof;
    }    
    else {
        double sum = 0;
        for(int j = 0; j < S.paz.size(); j++) {
            sum += S.paz[j];
        }
        S.rez = sum / S.paz.size() * ND_kof + S.egzam * EGZAM_kof;
    }
}

void mediana(studentas &S) {
    if (S.paz.empty()) {
        S.rez = S.egzam * EGZAM_kof;
    } 
    else {
        sort(S.paz.begin(), S.paz.end());
        double mediana;
        if(S.paz.size() % 2 == 0) {
            mediana = (S.paz[S.paz.size() / 2 - 1] + S.paz[S.paz.size() / 2]) / 2.0;
        } 
        else {
            mediana = S.paz[S.paz.size() / 2];
        }
        S.rez = mediana * ND_kof + S.egzam * EGZAM_kof;
    }
}

void rusiavimas(vector<studentas> &A, int sort_choice) {
    if(sort_choice == 1) {
        sort(A.begin(), A.end(), [](studentas& a, studentas& b) {
            return compare(a.vardas, b.vardas);
        });
    }
    else if(sort_choice == 2) {
        sort(A.begin(), A.end(), [](studentas& a, studentas& b) {
            return compare(a.pavarde, b.pavarde);
        });
    }
    else {
        sort(A.begin(), A.end(), [](studentas& a, studentas& b) {
            return compare(b.rez, a.rez);
        });
    }
}

bool string_checker(string &str) {
    bool validname = true;
    for(char c : str) {
        if(!isalpha(c)) {
            validname = false;
            break;
        }
    }
    if(!validname) {
        cout << "Vardas ir pavarde turi buti sudaryti tik is raidziu. Pabandykite dar karta." << endl;
        return false;
    }
    return true;
}