#include "My_libs.h"
#include "Libas.h"
#include <cstdio>
#include "Timer.h"

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::left;



int main()
{
    char ats;
    cout << "Ar norite atlikti padalijimo strategiju spartos testa? Irasykite t, jei taip, n, jei ne: ";
    cin >> ats;
    if (ats == 't') { testas(); }
    else { 
        int sz;
        string pvd;
        char ats_;
        cout << "Ar norite atsitiktinai sugeneruoti studentu faila? Irasykite t, jei taip, n, jei ne: ";
        cin >> ats_;
        if (ats_ == 't') {
            cout << "Iveskite failo pavadinima ir dydi: ";
            cin >> pvd >> sz;
            create_file(pvd, sz);
        }
        else{ uzpildymas(); }

         }

    system("pause");

}





    
