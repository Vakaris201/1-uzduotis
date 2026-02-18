#include <iostream>
#include <iomanip>
#include <string> 
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::cin;


struct studentas {
    string vardas = "A";
    string pavarde = "B";
    vector <int> paz;
    int egzam;
    double rez;
};

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
}