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
    string vardas = "A";
    string pavarde = "B";
    vector <int> paz;
    int egzam;
    double rez;
};

void outputas(const vector <studentas> &grupe);

int main(){
    studentas A;
    vector <studentas> grupe;
    for(int ii = 0; ii < 2; ii++)
    {
    cout << "Iveskite varda ir pavarde:";
    cin >> A.vardas >> A.pavarde;
    cout << "Iveskite semestro pazymius: \nKiek pazymiu bus? ";
    int n, temp, sum = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cout << "Iveskite " << i+1 << " pazymi is " << n << ": ";
        cin >> temp;
        A.paz.push_back(temp);
        sum += temp;
    }
    cout << "Iveskite egzamino pazymi: ";
    cin >> A.egzam;
    A.rez = sum * 1.0 / (A.paz.size() * 1.0) * 0.4 + A.egzam * 0.6;
    grupe.push_back(A);
    A.paz.clear();
    }
    outputas(grupe);
}

void outputas(const vector <studentas> &grupe)
{
    cout << "Isvesti vidurki ar mediana? (1 - vidurkis, 2 - mediana) ";
    int pasirinkimas;
    cin >> pasirinkimas;
    if(pasirinkimas == 1){
    cout << left << setw(10) << "Vardas" << left << setw(20) << "Pavarde" << setw(15) << "Galutinis (Vid.)" << endl;
    for(auto A: grupe){
    cout << left << setw(10) << A.vardas << left << setw(20) << A.pavarde;
    cout << setw(15) << fixed << setprecision(2) << A.rez << endl;
    }
    }
    else{
    cout << left << setw(10) << "Vardas" << left << setw(20) << "Pavarde" << setw(15) << "Galutinis (Med.)" << endl;
    for(auto A: grupe){
    cout << left << setw(10) << A.vardas << left << setw(20) << A.pavarde;

    sort(A.paz.begin(), A.paz.end());
    if(A.paz.size() % 2 == 0) {
        A.rez = (A.paz[A.paz.size() / 2 - 1] + A.paz[A.paz.size() / 2]) / 2.0 * 0.4 + A.egzam * 0.6;
    }
    else {
        A.rez = A.paz[A.paz.size() / 2] * 0.4 + A.egzam * 0.6;
    }
    cout << setw(15) << fixed << setprecision(2) << A.rez << endl;
    }
    }
}
