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
   
    
    //1.*****************************************************************************
    cout << "1. 1 000 studentu:" << "\n";
    Timer t0;
    Timer t;
    create_file("stud1000.txt", 1000);
    
    cout << "Sukurti faila uztruko: " << t.elapsed() << " s" << endl;

    t.reset();
    
    nuskaitymas("stud1000.txt");
    cout << "Nuskaityti duomenis is failo uztruko: " << t.elapsed() << " s" << endl;

    t.reset();
    padalijimas(group);
    cout << "Studentu padalijimas i 2 vektorius uztruko: " << t.elapsed() << " s" << endl;

    t.reset();
    isvedimas(nabagai, "nabagai1k.txt");
    isvedimas(protingi, "protingi1k.txt");
    cout << "Vektoriu isvedimas i 2 failus uztruko: " << t.elapsed() << " s" << endl;

    

    group.clear();
    nabagai.clear();
    protingi.clear();
    cout << "Visas testo laikas: " << t0.elapsed() << " s" << endl;
    system("pause");
    cout << "\n";
    //2.*****************************************************************************
    cout << "2. 10 000 studentu:" << "\n";
    t0.reset();
    t.reset();

    create_file("stud10000.txt", 10000);
    cout << "Sukurti faila uztruko: " << t.elapsed() << " s" << endl;

    t.reset();
    nuskaitymas("stud10000.txt");
    cout << "Nuskaityti duomenis is failo uztruko: " << t.elapsed() << " s" << endl;

    t.reset();
    padalijimas(group);
    cout << "Studentu padalijimas i 2 vektorius uztruko: " << t.elapsed() << " s" << endl;

    t.reset();
    isvedimas(nabagai, "nabagai10k.txt");
    isvedimas(protingi, "protingi10k.txt");
    cout << "Vektoriu isvedimas i 2 failus uztruko: " << t.elapsed() << " s" << endl;

    group.clear();
    nabagai.clear();
    protingi.clear();
    cout << "Visas testo laikas: " << t0.elapsed() << " s" << endl;
    system("pause");
    cout << "\n";
    //3.*****************************************************************************
    cout << "3. 100 000 studentu:" << "\n";
    t0.reset();
    t.reset();
    create_file("stud100000.txt", 100000);
    cout << "Sukurti faila uztruko: " << t.elapsed() << " s" << endl;

    t.reset();
    nuskaitymas("stud100000.txt");
    cout << "Nuskaityti duomenis is failo uztruko: " << t.elapsed() << " s" << endl;

    t.reset();
    padalijimas(group);
    cout << "Studentu padalijimas i 2 vektorius uztruko: " << t.elapsed() << " s" << endl;

    t.reset();
    isvedimas(nabagai, "nabagai100k.txt");
    isvedimas(protingi, "protingi100k.txt");
    cout << "Vektoriu isvedimas i 2 failus uztruko: " << t.elapsed() << " s" << endl;

    group.clear();
    nabagai.clear();
    protingi.clear();
    cout << "Visas testo laikas: " << t0.elapsed() << " s" << endl;
    system("pause");
    cout << "\n";
    //4.*****************************************************************************
    cout << "4. 1 000 000 studentu:" << "\n";
    t0.reset();
    t.reset();

    create_file("stud1000000.txt", 1000000);
    cout << "Sukurti faila uztruko: " << t.elapsed() << " s" << endl;

    t.reset();
    nuskaitymas("stud1000000.txt");
    cout << "Nuskaityti duomenis is failo uztruko: " << t.elapsed() << " s" << endl;

    t.reset();
    padalijimas(group);
    cout << "Studentu padalijimas i 2 vektorius uztruko: " << t.elapsed() << " s" << endl;

    t.reset();
    isvedimas(nabagai, "nabagai1mln.txt");
    isvedimas(protingi, "protingi1mln.txt");
    cout << "Vektoriu isvedimas i 2 failus uztruko: " << t.elapsed() << " s" << endl;

    group.clear();
    nabagai.clear();
    protingi.clear();
    cout << "Visas testo laikas: " << t0.elapsed() << " s" << endl;
    system("pause");
    cout << "\n";

    //5.*****************************************************************************
    cout << "5. 10 000 000 studentu:" << "\n";
    t0.reset();
    t.reset();

    create_file("stud10000000.txt", 10000000);
    cout << "Sukurti faila uztruko: " << t.elapsed() << " s" << endl;

    t.reset();
    nuskaitymas("stud10000000.txt");
    cout << "Nuskaityti duomenis is failo uztruko: " << t.elapsed() << " s" << endl;

    t.reset();
    padalijimas(group);
    cout << "Studentu padalijimas i 2 vektorius uztruko: " << t.elapsed() << " s" << endl;

    t.reset();
    isvedimas(nabagai, "nabagai10mln.txt");
    isvedimas(protingi, "protingi10mln.txt");
    cout << "Vektoriu isvedimas i 2 failus uztruko: " << t.elapsed() << " s" << endl;

    group.clear();
    nabagai.clear();
    protingi.clear();

    cout << "Visas testo laikas: " << t0.elapsed() << " s" << endl;
    system("pause");

}


    

    
