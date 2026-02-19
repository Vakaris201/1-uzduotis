#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int maxpaz = 100;
const int maxstud = 10000;

struct studentas {
    string vardas;
    string pavarde;
    int paz[maxpaz];
    int paz_skaicius;
    int egzam;
    double rez;
};

int main() {
    studentas *A = new studentas[maxstud];
    int temp, sum, m = 0;
    char testi;
    while(true) {
        cout << "Iveskite varda ir pavarde: ";
        cin >> A[m].vardas >> A[m].pavarde;
        A[m].paz_skaicius = 0;
        sum = 0;
        while(true) {
            cout << "Iveskite " << A[m].paz_skaicius + 1 << " semestro pazymi (0 - baigti): ";
            cin >> temp;
            if(temp == 0) break;
            sum += temp;
            A[m].paz[A[m].paz_skaicius] = temp;
            A[m].paz_skaicius++;
        }
        cout << "Iveskite egzamino pazymi: ";
        cin >> A[m].egzam;
        A[m].rez = sum * 1.0/ (A[m].paz_skaicius * 1.0) * 0.4 + A[m].egzam * 0.6;
        m++;
        if(m >= maxstud) break;
    }
    delete[] A;
}

