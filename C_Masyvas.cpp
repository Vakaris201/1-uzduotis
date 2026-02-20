#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

const int maxpaz = 100;

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
    int temp, sum, m = 0;
    while(true) {
        cout << "Kiek yra studentu? ";
        cin >> m;
        if(cin.fail()) {
            cout << "Neteinga ivestis. Iveskite skaiciu. " << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
        else if(m <= 0) {
            cout << "Studentu skaicius turi būti teigiamas. Pabandykite dar karta." << endl;
            continue;
        }
        else break;
    }
    studentas *A = new studentas[m];
    int x = 0;
    while(true) {
        cout << "Iveskite varda ir pavarde: ";
        cin >> A[x].vardas >> A[x].pavarde;
        bool validname = true;
        for(char c : A[x].vardas) {
            if(!isalpha(c)) {
                validname = false;
                break;
            }
        }
        if(!validname) {
            cout << "Vardas turi buti sudarytas tik is raidziu. Pabandykite dar karta." << endl;
            continue;
        }
        for(char c : A[x].pavarde) {
            if(!isalpha(c)) {
                validname = false;
                break;
            }
        }
        if(!validname) {
            cout << "Pavarde turi buti sudaryta tik is raidziu. Pabandykite dar karta." << endl;
            continue;
        }
        A[x].paz_skaicius = 0;
        sum = 0;
        while(true) {
            cout << "Iveskite " << A[x].paz_skaicius + 1 << " semestro pazymi (0 - baigti): ";
            cin >> temp;
            if(cin.fail()) {
                cout << "Neteisinga ivestis. Iveskite skaiciu tarp 1 ir 10." << endl;
                cin.clear();
                cin.ignore(10000, '\n');
                continue;
            }
            if(temp == 0) break;
            else if(temp < 1 || temp > 10) {
                cout << "Neteisinga ivestis. Iveskite skaiciu tarp 1 ir 10." << endl;
                continue;
            }
            sum += temp;
            A[x].paz[A[x].paz_skaicius] = temp;
            A[x].paz_skaicius++;
        }
        while(true) {
            cout << "Iveskite egzamino pazymi: ";
            cin >> A[x].egzam;
            if(cin.fail()) {
                cout << "Neteisinga ivestis. Iveskite skaiciu tarp 1 ir 10." << endl;
                cin.clear();
                cin.ignore(10000, '\n');
                continue;
            }
            if(A[x].egzam < 1 || A[x].egzam > 10) {
                cout << "Neteisinga ivestis. Iveskite skaiciu tarp 1 ir 10." << endl;
                continue;
            }
            break;
        }
        if (A[x].paz_skaicius == 0) {
            A[x].rez = A[x].egzam * 0.6;
        } 
        else {
            A[x].rez = sum * 1.0 / (A[x].paz_skaicius * 1.0) * 0.4 + A[x].egzam * 0.6;
        }
        x++;
        if(x >= m) break;
    }
    outputas(A, m);
    delete[] A;
}
void outputas(studentas A[], int m) {
    int pasirinkimas;
    while(true) {
        cout << "Isvesti vidurki ar mediana? (1 - vidurkis, 2 - mediana) ";
        cin >> pasirinkimas;
        if(cin.fail()) {
            cout << "Neteisinga ivestis! Iveskite 1 arba 2." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        else if(pasirinkimas == 1 || pasirinkimas == 2) {
            break;
        }
        else {
            cout << "Neteisinga ivestis! Iveskite 1 arba 2." << endl;
            continue;
        }
    }
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
}
