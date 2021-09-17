#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setw;
using std::left;
using std::setprecision;
using std::sort;
using std::vector;

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

int main()
{
    studentas studentai[10];
    int k;
    cout << "Iveskite studentu skaiciu ";
    cin >> k;
    while (cin.fail() || k<0) {
        cout << "Klaida! Iveskite TEIGIAMA SVEIKA skaiciu" << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> k;   
    }
    for (int i = 0; i < k; i++)
        pild(studentai[i]);
    cout << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(20) << left << "Galutinis(Vid.)/Galutinis(Med.)"<< endl;
    for (int i = 0; i < k; i++)
        printas(studentai[i]);
}

void pild(studentas& kint) {


    cout << "Iveskite studento varda ir pavarde: ";
    cin >> kint.vardas >> kint.pavarde;
  
    float sum = 0, vid = 0, n, med; 
    int count = 0;
    
    cout << "Iveskite pazymi, kai baigsite, iveskite bet kokia raide" << endl;

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
    cout << "Spauskite v jei norite galutini bala skaiciuoti pagal vidurki ir m, jei pagal mediana: ";
    cin >> kint.skaiciavimas;
    while (cin.fail() || (kint.skaiciavimas != 'v' && kint.skaiciavimas != 'm') ){
        cout << "Klaida! Iveskite raides v arba m" << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> kint.skaiciavimas;
    }
    vid = sum / count;
    med = mediana(kint.nd);
    kint.galutinisVid = vid * 0.4 + 0.6 * kint.egzam;
    kint.galutinisMed = med * 0.4 + 0.6 * kint.egzam;




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
