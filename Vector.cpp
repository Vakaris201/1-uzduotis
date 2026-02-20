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

void outputas(vector<studentas>& A, int m);

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
            else if(temp < 0 || temp > 10) {
                cout << "Pazymys turi būti tarp 1 ir 10. Pabandykite dar kartą." << endl;
                continue;
            }
            sum += temp;
            S.paz.push_back(temp);
        }
        cout << "Iveskite egzamino pazymi: ";
        cin >> S.egzam;
        if (S.paz.empty()) {
            S.rez = S.egzam * 0.6;
        } else {
            S.rez = sum * 1.0 / (S.paz.size() * 1.0) * 0.4 + S.egzam * 0.6;
        }
        A.push_back(S);
        m++;
        if(m >= 0) {
            cout << "Ar norėtumėte pridėti dar vieną studentą? (t/n): ";
            cin >> testi;
            if(testi != 't' && testi != 'T') break;
        }
    }
    outputas(A, m);
}
void outputas(vector<studentas>& A, int m) {
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
            if (A[i].paz.empty()) {
                A[i].rez = A[i].egzam * 0.6;
            } else {
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
    else {
        cout << "Pabandykite dar karta" << endl;
        outputas(A, m);
    }
}