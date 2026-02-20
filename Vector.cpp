#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm> 
#include <cctype>

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

void outputas(vector<studentas>& A, int m);

int main() {
    vector<studentas> A;
    int temp, sum, m = 0, x = 0;
    char testi;
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
    while(true) {
        studentas S;
        cout << "Iveskite varda ir pavarde: ";
        cin >> S.vardas >> S.pavarde;
        bool validname = true;
        for(char c : S.vardas) {
            if(!isalpha(c)) {
                validname = false;
                break;
            }
        }
        if(!validname) {
            cout << "Vardas turi buti sudarytas tik is raidziu. Pabandykite dar karta." << endl;
            continue;
        }
        for(char c : S.pavarde) {
            if(!isalpha(c)) {
                validname = false;
                break;
            }
        }
        if(!validname) {
            cout << "Pavarde turi buti sudaryta tik is raidziu. Pabandykite dar karta." << endl;
            continue;
        }
        sum = 0;
        while(true) {
            cout << "Iveskite " << S.paz.size() + 1 << " semestro pazymi (0 - baigti): ";
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
            S.paz.push_back(temp);
        }
        while(true) {
            cout << "Iveskite egzamino pazymi: ";
            cin >> S.egzam;
            if(cin.fail()) {
                cout << "Neteisinga ivestis. Iveskite skaiciu tarp 1 ir 10." << endl;
                cin.clear();
                cin.ignore(10000, '\n');
                continue;
            }
           if(S.egzam < 1 || S.egzam > 10) {
                cout << "Neteisinga ivestis. Iveskite skaiciu tarp 1 ir 10." << endl;
                continue;
            }
            break;
        }
        if (S.paz.empty()) {
            S.rez = S.egzam * 0.6;
        } 
        else {
            S.rez = sum * 1.0 / (S.paz.size() * 1.0) * 0.4 + S.egzam * 0.6;
        }
        A.push_back(S);
        x++;
        if(x >= m) break;
    }
    outputas(A, m);
}
void outputas(vector<studentas>& A, int m) {
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
            if (A[i].paz.empty()) {
                A[i].rez = A[i].egzam * 0.6;
            } 
            else {
                sort(A[i].paz.begin(), A[i].paz.end());
                double mediana;
                if(A[i].paz.size() % 2 == 0) {
                    mediana = (A[i].paz[A[i].paz.size() / 2 - 1] + A[i].paz[A[i].paz.size() / 2]) / 2.0;
                } else {
                    mediana = A[i].paz[A[i].paz.size() / 2];
                }
                A[i].rez = mediana * 0.4 + A[i].egzam * 0.6;
            }
            cout << left << setw(10) << A[i].vardas << left << setw(20) << A[i].pavarde;
            cout << setw(15) << fixed << setprecision(2) << A[i].rez << endl;
        }
    }
}