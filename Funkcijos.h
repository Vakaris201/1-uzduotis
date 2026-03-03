#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

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

void outputas(vector<studentas>& A, int m);

#endif