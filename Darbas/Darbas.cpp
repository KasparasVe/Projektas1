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


    int n;
    cout << "Iveskite studentu skaiciu: ";
    cin >> n;
    cout << n << " studentu:" << "\n";
    cout << "**********************NAUDOJANT LISTUS**********************" << endl << endl;
    Timer t0;
    Timer t;
    if (n == 1000) { nuskaitymas_lst("stud1000.txt"); }
    else if(n==10000) { nuskaitymas_lst("stud10000.txt"); }
    else if (n == 100000) { nuskaitymas_lst("stud100000.txt"); }
    else if (n == 1000000) { nuskaitymas_lst("stud1000000.txt"); }
    else if (n == 10000000) { nuskaitymas_lst("stud10000000.txt"); }
    else { cout << "KLAIDA" << endl;
    exit(EXIT_FAILURE);
    }
    float t1_lst = t.elapsed();
    cout << "Nuskaityti duomenis is failo uztruko: " << t1_lst << " s" << endl;

    t.reset();
    padalijimas(grupe_lst);
    float t2_lst = t.elapsed();
    float t0_lst = t0.elapsed();
    cout << "Studentu padalijimas i 2 listus uztruko: " << t2_lst << " s" << endl;

    //isvedimas(nabagai_lst, "nabagai.txt");
    //isvedimas(protingi_lst, "protingi.txt");
    cout << "Visas testo laikas: " << t0_lst << " s" << endl;

    

    grupe_lst.clear();
    nabagai_lst.clear();
    protingi_lst.clear();

    cout << endl << "**********************NAUDOJANT VEKTORIUS**********************" << endl << endl;


    t0.reset();
    t.reset();
    if (n == 1000) { nuskaitymas_vec("stud1000.txt"); }
    else if (n == 10000) { nuskaitymas_vec("stud10000.txt"); }
    else if (n == 100000) { nuskaitymas_vec("stud100000.txt"); }
    else if (n == 1000000) { nuskaitymas_vec("stud1000000.txt"); }
    else if (n == 10000000) { nuskaitymas_vec("stud10000000.txt"); }
    else {
        cout << "KLAIDA" << endl;
        exit(EXIT_FAILURE);
    }

    float t1_vec = t.elapsed();
    cout << "Nuskaityti duomenis is failo uztruko: " << t1_vec << " s" << endl;

    t.reset();
    padalijimas(grupe_vec);
    float t2_vec = t.elapsed();
    float t0_vec = t0.elapsed();
    cout << "Studentu padalijimas i 2 vektorius uztruko: " << t2_vec << " s" << endl;
    cout << "Visas testo laikas: " << t0_vec << " s" << endl << endl;
    

    grupe_vec.clear();
    nabagai_vec.clear();
    protingi_vec.clear();

    cout << "Nuskaitymo laiko santykis t_vec/t_lst: " << t1_vec / t1_lst << endl;
    cout << "Padalijimo laiko santykis t_vec/t_lst: " << t2_vec / t2_lst << endl;
    cout<<"Viso testo laiko santykis t_vec/t_lst: "<< t0_vec / t0_lst << endl;

    system("pause");
}


    
