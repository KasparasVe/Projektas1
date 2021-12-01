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

extern vector<studentas> grupe_vec;
extern vector<studentas> nabagai_vec;
extern vector<studentas> protingi_vec;

extern list<studentas> grupe_lst;
extern list<studentas> nabagai_lst;
extern list<studentas> protingi_lst;

void pild(studentas& kint);
void printas(studentas& kin);
float mediana(vector<float> vec);
bool mycompare(studentas a, studentas b);
void printfile(studentas& stud);
void tikrinimas(int &a);

void  nuskaitymas_vec(string read);
void nuskaitymas_lst(string read);
void create_file(string name, float sk);
void padalijimas1(vector<studentas>& vec);
void padalijimas1(list<studentas>& lst);
void isvedimas(vector<studentas>& vec, string pav);
void isvedimas(list<studentas>& lst, string pav);

void padalijimas2(vector<studentas>& vec);
void padalijimas2(list<studentas>& lst);
void padalijimas3(vector<studentas>& vec);

bool func(studentas st);
bool pred(studentas st);

void testas();
void uzpildymas();
