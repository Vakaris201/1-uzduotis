#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm> 
#include <cctype>
#include <ctime>
#include <fstream>
#include <sstream>
#include <chrono>
#include <cstdlib>
#include "Zmones.h"
#include "Funkcijos.h"

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::setw;
using std::left;
using std::endl;
using std::fixed;
using std::setprecision;
using std::ifstream;
using std::ofstream;
using std::getline;
using std::sort;
using std::stringstream;
using std::chrono::high_resolution_clock;
using std::chrono::duration;


int main() {
    system("dir *.txt");
    srand(time(0));
    std::ios::sync_with_stdio(false);
    vector<studentas> A;
    int temp, stud_skaicius = 0, index = 0;
    string f_choice, line;
    cout << "Ar noretumet skaityti duomenis is failo? (t/n) ";
    cin >> f_choice;
    if(f_choice == "t" || f_choice == "T") {
        string filename;
        while(true) {
            cout << "Iveskite failo pavadinima: ";
            cin >> filename;
            try {
                ifstream test(filename);
                if(!test) {
                    throw std::runtime_error("Failas nerastas.");
                }
                break;
            }
            catch (std::exception& e) {
                cout << "Klaida: " << e.what() << " Pabandykite dar karta." << endl;
                continue;
            }
        }
        ifstream fin(filename);
        A.reserve(1000000);
        getline(fin, line);
        while(getline(fin, line)) {
            stringstream ss(line);
            studentas S;
            ss >> S.vardas >> S.pavarde;
            int pazymys;
            while(ss >> pazymys) {
                S.paz.push_back(pazymys);
            }
            if(!S.paz.empty()) {
                S.egzam = S.paz.back();
                S.paz.pop_back();
            }
            A.push_back(S);
            stud_skaicius++;
        }
        fin.close();
        outputas(A, stud_skaicius);
    }
    else {
    int eiga;
    cout << "Iveskite eiga: " << endl;
    while(true) {
        cout << "1 - ranka " << endl;
        cout << "2 - generuoti tik pazymius " << endl;
        cout << "3 - generuoti studentu vardus, pavardes ir pazymius " << endl;
        cout << "4 - baigti darba " << endl;
        cout << "Jusu pasirinkimas: ";
        cin >> eiga;
        if(cin.fail() || eiga < 1 || eiga > 4) {
            clearInput();
            cout << "Iveskite skaiciu nuo 1 iki 4. " << endl;
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
        cin >> stud_skaicius;
        if(cin.fail() || stud_skaicius <= 0) {
            clearInput();
            cout << "Iveskite teigiama skaiciu. " << endl;
            continue;
        }
        else break;
    }
    while(true) {
        studentas S;
        if(eiga == 1 || eiga == 2) {
            cout << "Iveskite varda ir pavarde: ";
            cin >> S.vardas >> S.pavarde;
            bool validname;
            validname = string_checker(S.vardas);
            if(!validname) continue;
            validname = string_checker(S.pavarde);
            if(!validname) continue;
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
                    clearInput();
                    cout << "Iveskite skaiciu tarp 1 ir 10." << endl;
                    continue;
                }
                else S.paz.push_back(temp); 
            }
            while(true) {
                cout << "Iveskite egzamino pazymi: ";
                cin >> S.egzam;
                if(cin.fail() || S.egzam < 1 || S.egzam > 10) {
                    clearInput();
                    cout << "Iveskite skaiciu tarp 1 ir 10." << endl;
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
                    clearInput();
                    cout << "Iveskite teigiama sveika skaiciu." << endl;
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
            if(index < stud_skaicius - 1) break;
            else {
                cout << "Ar noretumet ivesti dar viena studenta? (t/n) ";
                cin >> choice;
                if(choice == "t" || choice == "T") {
                    stud_skaicius++;
                    break;
                }
                else if(choice == "n" || choice == "N") {
                    break;
                }
                else {
                    clearInput();
                    cout << "Pabandykite dar karta." << endl;
                    continue;
                }
            }
        }
        index++;
        if(index >= stud_skaicius) break;
    }
    outputas(A, stud_skaicius);
    }
}
void outputas(vector<studentas>& A, int stud_skaicius) {
    int pasirinkimas;
    while(true) {
        cout << "Isvesti vidurki ar mediana? (1 - vidurkis, 2 - mediana) ";
        cin >> pasirinkimas;
        if(cin.fail() || pasirinkimas < 1 || pasirinkimas > 2) {
            clearInput();
            cout << "Iveskite 1 arba 2." << endl;
            continue;
        }
        else if(pasirinkimas == 1 || pasirinkimas == 2) {
            break;
        }
    }
    if(pasirinkimas == 1) {
        for(int i = 0; i < stud_skaicius; i++) {
            vidurkis(A[i]);
        }
    }
    else if(pasirinkimas == 2) {
        for(int i = 0; i < stud_skaicius; i++) {
            mediana(A[i]);
        }
    }
    cout << "Kaip surusiuoti rezultatus? (1 - pagal varda, 2 - pagal pavarde, 3 - pagal galutini bala) ";
    int sort_choice;
    while(true) {
        cin >> sort_choice;
        if(cin.fail() || sort_choice < 1 || sort_choice > 3) {
            clearInput();
            cout << "Iveskite 1, 2 arba 3. " << endl;
            continue;
        }
        else break;
    }
    rusiavimas(A, sort_choice);
    cout << "Kaip norite isvesti rezultatus? (1 - i ekrana, 2 - i faila) ";
    int output_choice;
    while(true) {
        cin >> output_choice;
        if(cin.fail() || output_choice < 1 || output_choice > 2) {
            clearInput();
            cout << "Iveskite 1 arba 2. " << endl;
            continue;
        }
        else break;
    }
    auto start = high_resolution_clock::now();
    if(output_choice == 1) {
        if(pasirinkimas == 1) {
            cout << left << setw(15) << "Vardas" << left << setw(20) << "Pavarde" << setw(10) << "Galutinis (Vid.)" << endl;
        }
        else {
            cout << left << setw(15) << "Vardas" << left << setw(20) << "Pavarde" << setw(10) << "Galutinis (Med.)" << endl;
        }
        for(int i = 0; i < stud_skaicius; i++) {
            cout << left << setw(15) << A[i].vardas << left << setw(20) << A[i].pavarde;
            cout << setw(10) << fixed << setprecision(2) << A[i].rez << endl;
        }
        auto end = high_resolution_clock::now();
        duration<double> diff = end - start;
        cout << "Duomenu isvedimas uztruko: " << diff.count() << " sekundziu." << endl;
    }
    else {
        ofstream fout("rezultatai.txt");
        if(pasirinkimas == 1) {
            fout << left << setw(15) << "Vardas" << left << setw(20) << "Pavarde" << setw(10) << "Galutinis (Vid.)" << endl;
        }
        else {
            fout << left << setw(15) << "Vardas" << left << setw(20) << "Pavarde" << setw(10) << "Galutinis (Med.)" << endl;
        }
        for(int i = 0; i < stud_skaicius; i++) {
            fout << left << setw(15) << A[i].vardas << left << setw(20) << A[i].pavarde;
            fout << setw(10) << fixed << setprecision(2) << A[i].rez << endl;
        }
        cout << "Rezultatai faile - rezultatai.txt" << endl;
        auto end = high_resolution_clock::now();
        duration<double> diff = end - start;
        cout << "Duomenu isvedimas uztruko: " << diff.count() << " sekundziu." << endl;
        fout.close();
    }
}

