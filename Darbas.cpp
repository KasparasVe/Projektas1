#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setw;
using std::left;
using std::setprecision;
using std::sort;

struct studentas {
    string vardas, pavarde;
    int* nd;
    float egzam;
    float galutinisVid;
    float galutinisMed;
    char skaiciavimas;
    
};

void pild(studentas& kint);
void printas(studentas& kin);
float mediana(int a[], int n);

int main()
{
    studentas studentai[10];
    int k;
    cout << "Kiek studentu bus?";
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

    
    
    float med;
    cout << "Iveskite studento varda ir pavarde: ";
    cin >> kint.vardas >> kint.pavarde;
    

    
    
    float sum = 0, vid = 0; 
    int n = 0;
    kint.nd = new int[10];
    cout << "Iveskite pazymi, kai baigsite, iveskite bet kokia raide" << endl;
    for (int i = 0; i < 10; i++)
        if (cin >> kint.nd[i]) {
            sum += kint.nd[i];
            n++;
        }
        else { break; }
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while (n == 0) { 
        cout << "Klaida! Iveskite bent 1 pazymi!" << endl;
        for (int i = 0; i < 10; i++)
            if (cin >> kint.nd[i]) {
                sum += kint.nd[i];
                n++;
            }
            else { break; }
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
        
    
    vid = sum / n;
    med = mediana(kint.nd, n);
    delete[] kint.nd;

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
float mediana(int a[], int n) {
    sort(a, a + n);
    if (n % 2 != 0)
        return (float)a[n / 2];
    return (float)(a[(n - 1) / 2] + a[n / 2]) / 2.0;
}
