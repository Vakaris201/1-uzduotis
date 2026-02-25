#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm> 
#include <cctype>
#include <ctime>
#include "Zmones.h"

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
    srand(time(0));
    vector<studentas> A;
    int temp, m = 0, x = 0, eiga;
    cout << "Iveskite eiga: " << endl;
    while(true) {
        cout << "1 - ranka " << endl;
        cout << "2 - generuoti tik pazymius " << endl;
        cout << "3 - generuoti studentu vardus, pavardes ir pazymius " << endl;
        cout << "4 - baigti darba " << endl;
        cout << "Jusu pasirinkimas: ";
        cin >> eiga;
        if(cin.fail() || eiga < 1 || eiga > 4) {
            cout << "Neteisinga ivestis. Iveskite skaiciu nuo 1 iki 4. " << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        else if(eiga == 4) {
            cout << "Darbas baigtas.";
            return 0;
        }
        else break;
    }
    while(true) {
        cout << "Kiek yra studentu? ";
        cin >> m;
        if(cin.fail() || m <= 0) {
            cout << "Neteinga ivestis. Iveskite teigiama skaiciu. " << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        else break;
    }
    while(true) {
        studentas S;
        if(eiga == 1 || eiga == 2) {
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
        }
        else if(eiga == 3) {
            zmogus z = gen();
            S.vardas = z.vardas;
            S.pavarde = z.pavarde;
            cout << "Sugeneruotas zmogus: " << S.vardas << " " << S.pavarde << endl;
        }
        if(eiga == 1) {
            while(true) {
                cout << "Iveskite " << S.paz.size() + 1 << " semestro pazymi (0 - baigti): ";
                cin >> temp;
                if(temp == 0) break;
                else if(cin.fail() || temp < 1 || temp > 10) {
                    cout << "Neteisinga ivestis. Iveskite skaiciu tarp 1 ir 10." << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                    continue;
                }
                else S.paz.push_back(temp); 
            }
            while(true) {
                cout << "Iveskite egzamino pazymi: ";
                cin >> S.egzam;
                if(cin.fail() || S.egzam < 1 || S.egzam > 10) {
                    cout << "Neteisinga ivestis. Iveskite skaiciu tarp 1 ir 10." << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                    continue;
                }
                else break;
            }
        }
        else if(eiga == 2 || eiga == 3) {
            while(true) {
                int paz_kiek;
                cout << "Kiek pazymiu sugeneruoti? ";
                cin >> paz_kiek;
                if(cin.fail() || paz_kiek < 0) {
                    cout << "Neteisinga ivestis. Iveskite teigiama sveika skaiciu." << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                    continue;
                }
                for(int i = 0; i < paz_kiek; i++) {
                    temp = rand() % 10 + 1;
                    cout << i+1 << " Sugeneruotas pazymys: " << temp << endl;
                    S.paz.push_back(temp);
                }
                break;
            }
            S.egzam = rand() % 10 + 1;
            cout << "Sugeneruotas egzamino pazymys: " << S.egzam << endl;
        }
        A.push_back(S);
        string choice;
        while(true) {
            if(x < m - 1) break;
            else {
                cout << "Ar noretumet ivesti dar viena studenta? (t/n) ";
                cin >> choice;
                if(choice == "t" || choice == "T") {
                    m++;
                    break;
                }
                else if(choice == "n" || choice == "N") {
                    break;
                }
                else {
                    cout << "Neteisinga ivestis. Pabandykite dar karta." << endl;
                    continue;
                }
            }
        }
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
            if (A[i].paz.empty()) {
                A[i].rez = A[i].egzam * 0.6;
            }    
            else {
                double sum = 0;
                for(int j = 0; j < A[i].paz.size(); j++) {
                    sum += A[i].paz[j];
                }
            A[i].rez = sum / (A[i].paz.size() * 1.0) * 0.4 + A[i].egzam * 0.6;
            }
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
                } 
                else {
                    mediana = A[i].paz[A[i].paz.size() / 2];
                }
                A[i].rez = mediana * 0.4 + A[i].egzam * 0.6;
            }
            cout << left << setw(10) << A[i].vardas << left << setw(20) << A[i].pavarde;
            cout << setw(15) << fixed << setprecision(2) << A[i].rez << endl;
        }
    }
}