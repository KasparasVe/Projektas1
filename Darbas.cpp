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
    float nd[5]{};
    float egzam;
    float galutinisVid;
    float galutinisMed;
    
};

void pild(studentas& kint);
void printas(studentas& kin);
float mediana(float a[], int n);

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
    cout << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(20) << left << "Galutinis(Vid.)" << setw(20) << left << "Galutinis(Med.)" << endl;
    for (int i = 0; i < k; i++)
        printas(studentai[i]);
}

void pild(studentas& kint) {

    int n;
    float med;
    cout << "Iveskite studento varda ir pavarde: ";
    cin >> kint.vardas >> kint.pavarde;
    cout << "Kiek nd bus?";
    cin >> n;

    while (cin.fail()||n<0) {
        cout << "Klaida! Iveskite SVEIKA skaiciu" << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> n;

    }
    cout << "Iveskite pazymius: " << endl;
    float sum = 0, vid = 0;
    for (int i = 0; i < n; i++) {
        cin >> kint.nd[i];
        while (cin.fail() || kint.nd[i] < 0 || kint.nd[i] > 10) {
            cout << "Klaida! Iveskite TEIGIAMA SVEIKA skaiciu 1-10" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin >> kint.nd[i];
        }
        sum += kint.nd[i];
    }
    vid = sum / n;
    med = mediana(kint.nd, n);
    cout << "Iveskite egzamino bala: "; 
    cin >> kint.egzam;
    while (cin.fail() || kint.egzam < 0 || kint.egzam > 10) {
        cout << "Klaida! Iveskite TEIGIAMA SVEIKA skaiciu 1-10" << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> kint.egzam;
    }

    kint.galutinisVid = vid * 0.4 + 0.6 * kint.egzam;
    kint.galutinisMed = med * 0.4 + 0.6 * kint.egzam;




}
void printas(studentas &kin) {
    
    cout << setw(20) << left << kin.vardas << setw(20) << left << kin.pavarde << setw(20) << left << setprecision(3) << kin.galutinisVid << setw(20) << left << setprecision(3) << kin.galutinisMed << endl;
}
float mediana(float a[], int n) {
    sort(a, a + n);
    if (n % 2 != 0)
        return (float)a[n / 2];
    return (float)(a[(n - 1) / 2] + a[n / 2]) / 2.0;
}
