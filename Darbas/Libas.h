#pragma once
#include "My_Libs.h"

using std::string;
using std::vector;
using std::list;

struct studentas {
    string vardas, pavarde;
    vector<float> nd;
    int egzam;
    float galutinisVid;
    float galutinisMed;
    char skaiciavimas;

};

extern list<studentas> grupe;
extern list<studentas> nabagai;
extern list<studentas> protingi;

void pild(studentas& kint);
void printas(studentas& kin);
float mediana(vector<float> vec);
void nuskaitymas(string read);
bool mycompare(studentas a, studentas b);
void printfile(studentas& stud);
void tikrinimas(int &a);






void create_file(string name, float sk);
void padalijimas(list<studentas>& lst);
void isvedimas(list<studentas>& lst, string pav);

