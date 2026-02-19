#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm> 

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::setw;
using std::left;
using std::endl;
using std::fixed;
using std::setprecision;

struct studentas {
    string vardas;
    string pavarde;
    vector<int> paz;
    int egzam;
    double rez;
};

int main() {
    vector<studentas> A;
    int temp, sum, m = 0;
    char testi;
    while(true) {
        studentas S;
        cout << "Iveskite varda ir pavarde: ";
        cin >> S.vardas >> S.pavarde;
        sum = 0;
        while(true) {
            cout << "Iveskite " << S.paz.size() + 1 << " semestro pazymi (0 - baigti): ";
            cin >> temp;
            if(temp == 0) break;
            sum += temp;
            S.paz.push_back(temp);
        }
        cout << "Iveskite egzamino pazymi: ";
        cin >> S.egzam;
        S.rez = sum * 1.0 / (S.paz.size() * 1.0) * 0.4 + S.egzam * 0.6;
        A.push_back(S);
        m++;
        if(m >= 0) {
            cout << "Ar norėtumėte pridėti dar vieną studentą? (t/n): ";
            cin >> testi;
            if(testi != 't' && testi != 'T') break;
        }
    }
}