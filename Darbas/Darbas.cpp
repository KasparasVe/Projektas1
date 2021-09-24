#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream> 

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

struct studentas {
    string vardas, pavarde;
    vector<float> nd;
    float egzam;
    float galutinisVid;
    float galutinisMed;
    char skaiciavimas;
    
};

void pild(studentas& kint);
void printas(studentas& kin);
float mediana(vector<float> vec);
void nuskaitymas(string read);
void uzpildymas(studentas& k, string eilute);
bool mycompare(studentas a, studentas b);
void printfile(studentas& stud);

int main()
{
    vector<studentas> studentai;
    int k;
    char answ, g;
    string name;
    srand(time(NULL));
    
    cout << "Ar norite duomenis nuskaityti is failo? (Jei taip, iveskite 't', jei ne - bet koki simboli): ";
    cin >> answ;
    if (answ == 't') { 
        cout << "\n" << endl;
        cout << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(20) << left << "Galutinis(Vid.)" << setw(20) << left << "Galutinis(Med.)"<< endl;
        nuskaitymas("kursiokai.txt");   
    }
    else {
        cout << "Iveskite studentu skaiciu: ";
        cin >> k;
        while (cin.fail() || k<0) {
            cout << "Klaida! Iveskite TEIGIAMA SVEIKA skaiciu" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin >> k;
        }
        for (int i = 0; i < k; i++) {
            studentas temp;
            pild(temp);
            studentai.push_back(temp);
        }
        sort(studentai.begin(), studentai.end(), mycompare);
        cout << "\n" << endl;
        cout << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(20) << left << "Galutinis(Vid.)/Galutinis(Med.)"<< endl;
        for (int i = 0; i < k; i++)
            printas(studentai[i]);
    }
 
}

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
        cin >> sk;
        while (cin.fail() || sk < 0) {
            cout << "Klaida! Iveskite TEIGIAMA SVEIKA skaiciu" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin >> sk;
        }
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
        cout << "Iveskite pazymi, kai baigsite, iveskite bet kokia raide: "<<endl;

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
        cin >> kint.egzam;
        while (cin.fail() || kint.egzam < 0 || kint.egzam > 10) {
            cout << "Klaida! Iveskite TEIGIAMA SVEIKA skaiciu 1-10" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin >> kint.egzam;
        }
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
void printas(studentas &kin) {


    if (kin.skaiciavimas == 'v') {
        cout << setw(20) << left << kin.vardas << setw(20) << left << kin.pavarde << setw(20) << left << setprecision(3) << kin.galutinisVid<< endl;
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

void nuskaitymas(string read) {
    vector<string> sarasas;
    string eil;
    

    ifstream failas(read);
    while (failas) {
        if (!failas.eof()) {
            getline(failas, eil);
            sarasas.push_back(eil);
        }
        else break;
    }
    failas.close();

    vector<studentas> grupe;
    
    
    for (int i = 0; i < sarasas.size()-1;i++) {
        studentas tempas;
        uzpildymas(tempas, sarasas[i+1]);
        grupe.push_back(tempas);
        
    }
   
    sort(grupe.begin(), grupe.end(), mycompare);
    for (auto s : grupe) {
        printfile(s);
    }

    }
    
    

void uzpildymas(studentas& k, string eilute) {
    string str = eilute;
    stringstream s(str);
    float sum = 0, vid, med;


    float nd1, nd2, nd3, nd4, nd5, nd6, nd7, nd8, nd9, nd10, nd11, nd12, nd13, nd14, nd15, egzam;
    s >> k.vardas >> k.pavarde >> nd1 >> nd2 >> nd3 >> nd4 >> nd5 >> nd6 >> nd7 >> nd8 >> nd9 >> nd10 >> nd11 >> nd12 >> nd13 >> nd14 >> nd15 >> k.egzam;
    k.nd.push_back(nd1);
    k.nd.push_back(nd2);
    k.nd.push_back(nd3);
    k.nd.push_back(nd4);
    k.nd.push_back(nd5);
    k.nd.push_back(nd6);
    k.nd.push_back(nd7);
    k.nd.push_back(nd8);
    k.nd.push_back(nd9);
    k.nd.push_back(nd10);
    k.nd.push_back(nd11);
    k.nd.push_back(nd12);
    k.nd.push_back(nd13);
    k.nd.push_back(nd14);
    k.nd.push_back(nd15);

    for (float p : k.nd) {
        sum += p;
    }


    vid = sum / k.nd.size();
    med = mediana(k.nd);
    
    k.galutinisVid = 0.4 * vid + 0.6 * k.egzam;
    k.galutinisMed = med * 0.4 + 0.6 * k.egzam;
    
}

bool mycompare(studentas a, studentas b) {
    return a.vardas.compare(b.vardas) < 0;
}

void printfile(studentas& stud) {
    cout << setw(20) << left << stud.vardas << setw(20) << left << stud.pavarde << setw(20) << left << setprecision(3) << stud.galutinisVid << setw(20) << left << setprecision(3) << stud.galutinisMed << endl;
}
    

    
