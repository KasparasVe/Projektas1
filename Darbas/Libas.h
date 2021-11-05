#pragma once
#include "My_Libs.h"

using std::string;
using std::vector;

struct studentas {
    string vardas, pavarde;
    vector<float> nd;
    int egzam;
    float galutinisVid;
    float galutinisMed;
    char skaiciavimas;

};

extern vector<studentas> group;
extern vector<studentas> nabagai;
extern vector<studentas> protingi;

void pild(studentas& kint);
void printas(studentas& kin);
float mediana(vector<float> vec);
void nuskaitymas(string read);
bool mycompare(studentas a, studentas b);
void printfile(studentas& stud);
void tikrinimas(int &a);






void create_file(string name, float sk);
void padalijimas(vector<studentas>& vec);
void isvedimas(vector<studentas>& vec, string pav);

