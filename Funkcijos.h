#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cin;

const double ND_kof = 0.4;
const double EGZAM_kof = 0.6;

struct studentas {
    string vardas;
    string pavarde;
    vector<int> paz;
    int egzam;
    double rez;
};

template <class T>
bool compare(T &a,T &b) {
    return a < b;
}

void clearInput();
void vidurkis(studentas &S);
void mediana(studentas &S);
void rusiavimas(vector<studentas> &A, int sort_choice);
bool string_checker(string &str);
void outputas(vector<studentas> &A, int stud_skaicius);

#endif