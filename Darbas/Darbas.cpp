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
    cout << "NAUDOJANT VEKTORIUS:" << endl << endl;
    create_file("stud100000.txt", 100000);
    nuskaitymas_vec("stud100000.txt");
    Timer t;
    padalijimas1(grupe_vec);
    float t1 = t.elapsed();
    cout << "Padalijimas 1 budu uztruko: " << t1 << endl;

    protingi_vec.clear();
    nabagai_vec.clear();

    t.reset();
    padalijimas2(grupe_vec);
    float t2 = t.elapsed();
    cout << "Padalijimas 2 budu uztruko: " << t2 << endl;
    cout << "Santykis t1/t2: " << t1 / t2 << endl << endl;

    system("pause");
    cout << endl;
    //************************************************************************************


    cout << "NAUDOJANT LISTUS:" << endl << endl;
    
    nuskaitymas_lst("stud100000.txt");
    t.reset();
    padalijimas1(grupe_lst);
    t1 = t.elapsed();
    cout << "Padalijimas 1 budu uztruko: " << t1 << endl;

    protingi_lst.clear();
    nabagai_lst.clear();
    
    t.reset();
    padalijimas2(grupe_lst);
    t2 = t.elapsed();
    cout << "Padalijimas 2 budu uztruko: " << t2 << endl;
    cout << "Santykis t1/t2: " << t1 / t2 << endl<<endl;

    system("pause");
    cout << endl;
    //*************************************************************************************

    
    nuskaitymas_vec("stud100000.txt");
    t.reset();
    padalijimas1(grupe_vec);
    t1 = t.elapsed();
    protingi_vec.clear();
    nabagai_vec.clear();
    t.reset();
    padalijimas2(grupe_vec);
    t2 = t.elapsed();
    grupe_vec.clear();
    protingi_vec.clear();
    nabagai_vec.clear();
    nuskaitymas_vec("stud100000.txt");
    t.reset();

    padalijimas3(grupe_vec);


    float t3 = t.elapsed();



    cout << "padalijimas 1 budu uztruko: " << t1 << " s" << endl;
    cout << "padalijimas 2 budu uztruko: " << t2 << " s" << endl;
    cout << "padalijimas 3 budu uztruko: " << t3 << " s" << endl;

    cout << "Santykis t1/t3: " << t1 / t3 << endl;
    cout << "Santykis t2/t3: " << t2 / t3 << endl;

}


    
