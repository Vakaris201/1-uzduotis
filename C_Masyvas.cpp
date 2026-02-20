#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
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

void outputas(studentas A[], int m);

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
            else if(temp < 0 || temp > 10) {
                cout << "Pazymys turi būti tarp 1 ir 10. Pabandykite dar karta." << endl;
                continue;
            }
            sum += temp;
            A[m].paz[A[m].paz_skaicius] = temp;
            A[m].paz_skaicius++;
        }
        cout << "Iveskite egzamino pazymi: ";
        cin >> A[m].egzam;
        if (A[m].paz_skaicius == 0) {
            A[m].rez = A[m].egzam * 0.6;
        } 
        else {
            A[m].rez = sum * 1.0 / (A[m].paz_skaicius * 1.0) * 0.4 + A[m].egzam * 0.6;
        }
        m++;
        if(m >= 0) {
            cout << "Ar norėtumėte pridėti dar vieną studentą? (t/n): ";
            cin >> testi;
            if(testi != 't' && testi != 'T') break;
        }
        if(m >= maxstud) break;
    }
    outputas(A, m);
    delete[] A;
}
void outputas(studentas A[], int m) {
    int pasirinkimas;
    cout << "Isvesti vidurki ar mediana? (1 - vidurkis, 2 - mediana) ";
    cin >> pasirinkimas;
    if(pasirinkimas == 1) {
        cout << left << setw(10) << "Vardas" << left << setw(20) << "Pavarde" << setw(15) << "Galutinis (Vid.)" << endl;
        for(int i = 0; i < m; i++) {
            cout << left << setw(10) << A[i].vardas << left << setw(20) << A[i].pavarde;
            cout << setw(15) << fixed << setprecision(2) << A[i].rez << endl;
        }
    }
    else if(pasirinkimas == 2) {
        cout << left << setw(10) << "Vardas" << left << setw(20) << "Pavarde" << setw(15) << "Galutinis (Med.)" << endl;
        for(int i = 0; i < m; i++) {
            if (A[i].paz_skaicius == 0) {
                A[i].rez = A[i].egzam * 0.6;
            } 
            else {
                sort(A[i].paz, A[i].paz + A[i].paz_skaicius);
                double mediana;
                if(A[i].paz_skaicius % 2 == 0) {
                    mediana = (A[i].paz[A[i].paz_skaicius / 2 - 1] + A[i].paz[A[i].paz_skaicius / 2]) / 2.0;
                } else {
                    mediana = A[i].paz[A[i].paz_skaicius / 2];
                }
                A[i].rez = mediana * 0.4 + A[i].egzam * 0.6;
            }
            cout << left << setw(10) << A[i].vardas << left << setw(20) << A[i].pavarde;
            cout << setw(15) << fixed << setprecision(2) << A[i].rez << endl;
        }
    }
    else {
        cout << "Pabandykite dar karta" << endl;
        outputas(A, m);
    }
}
