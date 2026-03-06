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
    string line, f_choice;
    cout << "Ar noretumet skaityti duomenis is failo? (t/n) ";
    f_choice = raide_choice(
        "Iveskite t arba n"
    );
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
        cout << "1 - ranka " << endl;
        cout << "2 - generuoti tik pazymius " << endl;
        cout << "3 - generuoti studentu vardus, pavardes ir pazymius " << endl;
        cout << "4 - baigti darba " << endl;
        eiga = getInput<int,1,4>(
            "Jusu pasirinkimas: ",
            "Iveskite skaiciu nuo 1 iki 4."
        );
        if(eiga == 4) {
            cout << "Darbas baigtas.";
            return 0;
        }
        stud_skaicius = getInput<int,1>(
            "Kiek yra studentu? ", 
            "Iveskite teigiama skaiciu."
        );
        while(true) {
            studentas S;
            if(eiga == 1 || eiga == 2) {
                S.vardas = getWordInput(
                    "Iveskite varda: ",
                    "Vardas turi buti sudarytas tik is raidziu."
                );
                S.pavarde = getWordInput(
                    "Iveskite pavarde: ",
                    "Pavarde turi buti sudaryta tik is raidziu."
                );
            }
            else if(eiga == 3) {
                zmogus z = gen();
                S.vardas = z.vardas;
                S.pavarde = z.pavarde;
                cout << "Sugeneruotas zmogus: " << S.vardas << " " << S.pavarde << endl;
            }
            if(eiga == 1) {
                while(true) {
                    temp = getInput<int,0,10>(
                        "Iveskite " + std::to_string(S.paz.size() + 1) + " semestro pazymi (0 - baigti): ",
                        "Iveskite skaiciu tarp 0 ir 10"
                    );
                    if(temp == 0) break;
                    S.paz.push_back(temp);
                }
            S.egzam = getInput<int,1,10>(
                "Iveskite egzamino pazymi: ", 
                "Iveskite skaiciu tarp 1 ir 10."
            );
            }
            else if(eiga == 2 || eiga == 3) {
                int paz_kiek;
                paz_kiek = getInput<int,0>(
                    "Kiek pazymiu sugeneruoti? ",
                    "Iveskite teigiama sveika skaiciu."
                );
                for(int i = 0; i < paz_kiek; i++) {
                    temp = rand() % 10 + 1;
                    cout << i+1 << " Sugeneruotas pazymys: " << temp << endl;
                    S.paz.push_back(temp);
                }
                S.egzam = rand() % 10 + 1;
                cout << "Sugeneruotas egzamino pazymys: " << S.egzam << endl;
            }
            A.push_back(S);
            string student_choice;
            while(true) {
                if(index < stud_skaicius - 1) break;
                else {
                    cout << "Ar noretumet ivesti dar viena studenta? (t/n) ";
                    student_choice = raide_choice(
                        "Iveskite t arba n"
                    );
                    if(student_choice == "t" || student_choice == "T") {
                        stud_skaicius++;
                    }
                    break;
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
    pasirinkimas = getInput<int,1,2>(
        "Isvesti vidurki ar mediana? (1 - vidurkis, 2 - mediana) ",
        "Iveskite 1 arba 2."
    );
    if(pasirinkimas == 1) {
        for(int i = 0; i < stud_skaicius; i++) {
            vidurkis(A[i]);
        }
    }
    else {
        for(int i = 0; i < stud_skaicius; i++) {
            mediana(A[i]);
        }
    }
    int sort_choice;
    sort_choice = getInput<int,1,3>(
        "Kaip surusiuoti rezultatus? (1 - pagal varda, 2 - pagal pavarde, 3 - pagal galutini bala) ",
        "Iveskite 1, 2 arba 3."
    );
    rusiavimas(A, sort_choice);
    int output_choice;
    output_choice = getInput<int,1,2>(
        "Kaip norite isvesti rezultatus? (1 - i ekrana, 2 - i faila) ",
        "Iveskite 1 arba 2."
    );
    auto start = high_resolution_clock::now();
    if(output_choice == 1) {
        print(cout, pasirinkimas, A, stud_skaicius);
        auto end = high_resolution_clock::now();
        duration<double> diff = end - start;
        cout << "Duomenu isvedimas uztruko: " << diff.count() << " sekundziu." << endl;
    }
    else {
        ofstream fout("rezultatai.txt");
        print(fout, pasirinkimas, A, stud_skaicius);
        auto end = high_resolution_clock::now();
        duration<double> diff = end - start;
        cout << "Rezultatai faile - rezultatai.txt" << endl;
        cout << "Duomenu isvedimas uztruko: " << diff.count() << " sekundziu." << endl;
    }
}


