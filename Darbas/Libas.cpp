#include "Libas.h"
#include "Timer.h"
#include <numeric>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setw;
using std::left;
using std::setprecision;
using std::sort;
using std::getline;
using std::vector;
using std::ifstream;
using std::stringstream;
using std::exception;

vector<studentas> grupe_vec;
vector<studentas> nabagai_vec;
vector<studentas> protingi_vec;

list<studentas> grupe_lst;
list<studentas> nabagai_lst;
list<studentas> protingi_lst;




void pild(studentas& kint) {
    float sum = 0, vid = 0, n, med;
    int count = 0;

    cout << "Iveskite studento varda ir pavarde: ";
    cin >> kint.vardas >> kint.pavarde;

    cout << "Ar norite atsitiktinai generuoti pazymius? (Iveskite 't', jei taip, 'n' - jei ne): ";
    char ats;
    cin >> ats;
    while (cin.fail() || (ats != 't' && ats != 'n')) {
        cout << "Klaida! Iveskite raides 't' arba 'n'" << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> ats;
    }
    if (ats == 't') {
        cout << "Iveskite pazymiu skaiciu: ";
        int sk;
        
        tikrinimas(sk);
        for (int i = 0;i < sk;i++) {
            int x = rand() % 10 + 1;
            kint.nd.push_back(x);
            sum += kint.nd[i];
        }
        kint.egzam = rand() % 10 + 1;
        cout << "Ar galutini bala norite skaiciuoti pagal vidurki ar mediana? (Iveskite 'v', jei pagal vidurki, 'm' - pagal mediana):  ";
        cin >> kint.skaiciavimas;
        while (cin.fail() || (kint.skaiciavimas != 'v' && kint.skaiciavimas != 'm')) {
            cout << "Klaida! Iveskite raides 'v' arba 'm'" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin >> kint.skaiciavimas;
        }
        vid = sum / sk;
        med = mediana(kint.nd);
        kint.galutinisVid = vid * 0.4 + 0.6 * kint.egzam;
        kint.galutinisMed = med * 0.4 + 0.6 * kint.egzam;

    }
    else if (ats == 'n') {
        cout << "Iveskite pazymi, kai baigsite, iveskite bet kokia raide: " << endl;
        while (cin >> n) {
            kint.nd.push_back(n);
            sum += n;
            count++;
        }


        while (count == 0) {
            cout << "Klaida! Iveskite bent 1 pazymi" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            while (cin >> n) {
                kint.nd.push_back(n);
                sum += n;
                count++;
            }
        }

        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        

        cout << "Iveskite egzamino bala: ";
        
        tikrinimas(kint.egzam);

        cout << "Ar galutini bala norite skaiciuoti pagal vidurki ar mediana? (Iveskite 'v', jei pagal vidurki, 'm' - pagal mediana):  ";
        cin >> kint.skaiciavimas;
        while (cin.fail() || (kint.skaiciavimas != 'v' && kint.skaiciavimas != 'm')) {
            cout << "Klaida! Iveskite raides 'v' arba 'm'" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin >> kint.skaiciavimas;
        }
        
        vid = sum / count;
        med = mediana(kint.nd);

        kint.galutinisVid = vid * 0.4 + 0.6 * kint.egzam;
        kint.galutinisMed = med * 0.4 + 0.6 * kint.egzam;
    }
}
void printas(studentas& kin) {


    if (kin.skaiciavimas == 'v') {
        cout << setw(20) << left << kin.vardas << setw(20) << left << kin.pavarde << setw(20) << left << setprecision(3) << kin.galutinisVid << endl;
    }
    else
        cout << setw(20) << left << kin.vardas << setw(20) << left << kin.pavarde << setw(20) << left << setprecision(3) << kin.galutinisMed << endl;
}
float mediana(vector<float> vec) {
    typedef vector<float>::size_type vecSize;
    vecSize size = vec.size();
    if (size == 0)
        throw std::domain_error("Klaida! Negalima skaiciuoti medianos tusciam vektoriui");
    sort(vec.begin(), vec.end());
    vecSize vid = size / 2;
    return size % 2 == 0 ? (vec[vid] + vec[vid - 1]) / 2 : vec[vid];
}
bool mycompare(studentas& a, studentas& b) {
    return a.galutinisVid>b.galutinisVid;
}
void printfile(studentas& stud) {
    cout << setw(20) << left << stud.vardas << setw(20) << left << stud.pavarde << setw(20) << left << setprecision(3) << stud.galutinisVid << setw(20) << left << setprecision(3) << stud.galutinisMed << endl;
}
void tikrinimas(int &a) {
    cin >> a;
    do {
        try {
            if (cin.fail()) { throw std::runtime_error("Bloga ivestis!!!\n"); }
        }
        catch (const std::runtime_error& e) {
            cout << e.what();
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Veskite is naujo: ";
            cin >> a;
        }
        
    }
    while (cin.fail() == true);
}
void create_file(string name, float sk) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1, 10);

    std::ofstream failas;
    failas.open(name);

    for (int i = 1;i < sk + 1;i++) {
        int nd1 = dist(mt);
        int nd2 = dist(mt);
        int nd3 = dist(mt);
        int nd4 = dist(mt);
        int nd5 = dist(mt);
        int egz = dist(mt);
        failas << "Vardas" << i << "    Pavarde" << i << "        " << setw(10) << left << nd1 << setw(10) << left << nd2 << setw(10) << left << nd3 << setw(10) << left << nd4 << setw(10) << left << nd5 << setw(10) << left << egz << endl;
    }
    failas.close();

}

//Vektoriams:
void nuskaitymas_vec(string read) {

    string eil;
    vector<string> eilutes;

    ifstream failas(read);
    if (!failas) {
        throw exception();
    }
    while (failas) {
        if (!failas.eof()) {
            std::getline(failas, eil);
            eilutes.push_back(eil);

        }
        else break;

    }
    failas.close();

    eilutes.pop_back();


    for (auto eil : eilutes) {
        stringstream s(eil);
        studentas tempas;
        float sum, vid;
        s >> tempas.vardas >> tempas.pavarde;
        int k;
        while (s >> k) {
            tempas.nd.push_back(k);

        }

        tempas.egzam = tempas.nd.back();
        tempas.nd.pop_back();


        sum = std::accumulate(tempas.nd.begin(), tempas.nd.end(), 0);


        vid = sum / tempas.nd.size();

        float med = mediana(tempas.nd);



        tempas.galutinisVid = 0.4 * vid + 0.6 * tempas.egzam;
        tempas.galutinisMed = med * 0.4 + 0.6 * tempas.egzam;
        grupe_vec.push_back(tempas);


    }



}
void padalijimas(vector<studentas>& vec) {

    for (auto p:vec) {
        if (p.galutinisVid < 5) {
            nabagai_vec.push_back(p);
        }
        else {
            protingi_vec.push_back(p);
        }

    }

}
void isvedimas(vector<studentas>& vec, string pav) {
    std::ofstream failas;
    failas.open(pav);
    failas << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(20) << left << "Galutinis balas" << "\n";
    for (auto p : vec) {

        failas << setw(20) << left << p.vardas << setw(20) << left << p.pavarde << setw(20) << left << p.galutinisVid << "\n";
    }

    failas.close();
}


//Listams:
void nuskaitymas_lst(string read) {

    string eil;
    list<string> eilutes;

    ifstream failas(read);
    if (!failas) {
        throw exception();
    }
    while (failas) {
        if (!failas.eof()) {
            std::getline(failas, eil);
            eilutes.push_back(eil);

        }
        else break;

    }
    failas.close();

    eilutes.pop_back();


    for (auto eil : eilutes) {
        stringstream s(eil);
        studentas tempas;
        float sum, vid;
        s >> tempas.vardas >> tempas.pavarde;
        int k;
        while (s >> k) {
            tempas.nd.push_back(k);

        }

        tempas.egzam = tempas.nd.back();
        tempas.nd.pop_back();


        sum = std::accumulate(tempas.nd.begin(), tempas.nd.end(), 0);


        vid = sum / tempas.nd.size();

        float med = mediana(tempas.nd);



        tempas.galutinisVid = 0.4 * vid + 0.6 * tempas.egzam;
        tempas.galutinisMed = med * 0.4 + 0.6 * tempas.egzam;
        grupe_lst.push_back(tempas);


    }



}
void padalijimas(list<studentas>& lst) {

    for (auto p : lst) {
        if (p.galutinisVid < 5) {
            nabagai_lst.push_back(p);
        }
        else {
            protingi_lst.push_back(p);
        }

    }

}
void isvedimas(list<studentas>& lst, string pav) {
    std::ofstream failas;
    failas.open(pav);
    failas << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(20) << left << "Galutinis balas" << "\n";
    for (auto p : lst) {

        failas << setw(20) << left << p.vardas << setw(20) << left << p.pavarde << setw(20) << left << p.galutinisVid << "\n";
    }

    failas.close();
}

