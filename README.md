# Projektas1
v0.1:
* sukurta struktūra studentas.
* sukurta funkcija pild(), skirta ivesti studento vardą ir pavardę, namų darbų skaičių, namų darbų rezultatus, egzamino balą. Funkcija taip pat apskaičiuoja galutinį balą pagal vidurkį.
* sukurta funkcija printas(), kuri į ekraną tvarkingai išveda studento vardą, pavardę, galutinį balą pagal vidurkį.
* sukurta funkcija mediana(), kuri apskaičiuoja medianą.
* funkcija pild() papildyta taip, kad galėtų apskaičiuoti galutinį balą, naudojant medianą.
* uždėtos sąlygos, patikrinančios, ar vartotojas įveda tinkamus duomenis.
* programa papildyta taip, kad vartotojas galėtų pasirinkti, ar galutinį balą skaičiuoti pagal vidurkį ar medianą. Vartotojas pasirenka įvesdamas raidę "v" arba "m".
* sukurtas dinaminis masyvas *nd[].
* programa papildyta taip, kad vartotojui nereikėtų žinoti namų darbų skaičiaus iš anksto - baigęs vesti paskutinį pažymį, vartotojas įveda bet kokią raidę ir programa pati suskaičiuoja, kiek buvo įvesta namų darbų.
* vietoj dinaminio masyvo namų darbų pažymiams kaupti sukurtas vektorius.
* panaudojus funkciją rand(), sukurta galimybė vartotojui pasirinkti, ar namų darbų pažymius ir egzamino balą nori generuoti atsitiktinai. Vartotojas pasirenka įvesdamas raidę "t" arba "n".


v0.2:
* sukurta funkcija nuskaitymas(), kuri nuskaito studentų duomenis iš failo ir kviečia funkcijas uzpildymas() ir printas().
* sukurta funkcija uzpildymas(), kuri užpildo struktūrą "studentas" nuskaitytais duomenimis.
* v0.1 papyldyta taip, kad vartotojas galėtų pasirinkti, ar nori duomenis nuskaityti iš failo, ar pats juos įvesti.
* sukurtas comparatorius mycompare(), kuris palygina 2 studentus pagal vardą.
* programa papildyta taip, kad atspausdintas studentų sąrašas būtų surušiuotas abėcėlės tvarka pagal vardą.

V0.3
* sukurti header failai Libas.h, kuriame paskelbtos visos funkcijos ir struktūros, Libas.cpp, kuriame aprašytos funkcijos.
* sukurta funkcija tikrinimas(), kuri naudodama Exeption Handling tikrina vartotojo įvestis.
* pridėtas patikrinimas, ar egzistuoja failas, kurį norima nuskaityti.

V0.4:
* pridėta klasė Timer.h, kurioje patalpintas metodas, matuojantis laiką.
* sukurta funkcija create_file(), kuri sukuria pasirinkto dydžio failą su atsitiktinai sugeneruotais pažymiais.
* pridėta funkcija padalijimas(), kuri nuskaitytą studentų failą padalija į 2 vektorius pagal galutinį balą.
* pridėta funkcija isvedimas(), kuri vektorių išveda į .txt failą.
* main funkcijoje atlikti 5 testai su skirtingo dydžio failais ir kiekvieno žingsnio spartos matavimu.

v0.5:
* visi studentas tipo vektoriai pakeisti listais
* atlikti testai su skirtingo dydžio failas, norint ištirti spartos skirtumą tarp v0.4 ir v0.5
* REZULTATAI: tiek padalijimas, tiek nuskaitymas dažniausiai greičiau atliekamas su listais. Pagal visą testo laiką, testai su listais veikia apie 30-50% greičiau už testus su vektoriais.

v1.0:
* sukurtas papildomas studentų padalijimo metodas
* funkcijos pakoreguotos, kad veiktų tiek su vektoriais, tiek su listais
* atliktas testas su vektoriais ir su listais, kurio metu tiriama, kaip pasikeis studentų padalijimo sparta, priklausomai nuo naudojamo metodo
* sukurtas trečias dalijimo metodas, naudojant std::partition
* atliktas testas, lyginintis trečio padalijimo metodo spartą su ankstesniais buvusiais dviem metodais

**Naudojimosi instrukcija:**<br>
Atsakykite, ar norite atlikti padalijimo strategijų spartos testą. <br>
* Jei atsakėte 't', bus atliktas spartos testas, lyginantis 2 padalijimo strategijas vektoriams ir listams, bei 3 strategijos spartą su pirmomis 2 strategijomis. Rezultatai išvedami į ekraną.
* Jei atsakėte 'n', pasirinkite, ar norite duomenis nuskaityti iš failo. <br>
Jei atsakėte 't', įveskite egzistuojančio failo pavadinimą. Pasirinkite, ar norite studentus padalinti į 2 grupes ir išvesti į 2 failus. <br>
Jei atsakėte 't', bus sukurtas failas Nabagai.txt, kuriame talpinami visi studentai su galutiniu balu <5, ir failas Protingi.txt, kuriame talpinami likę studentai (galutinis balas >= 5). <br>
Jei atsakėte 'n', studentai išvedami į ekraną.<br>
Jei į  antrą klausimą atsakėte 'n', studentų duomenis įveskite patys, sekdami instrukcijas ekrane.<br>


<h3>REZULTATAI SU FIKSUOTU 100 000 STUDENTŲ FAILU:</h3>

**NAUDOJANT VEKTORIUS:**<br>
Padalijimas 1 budu uztruko: 0.0496662<br>
Padalijimas 2 budu uztruko: 0.0371622<br>
Santykis t1/t2: 1.33647<br>

**NAUDOJANT LISTUS:**<br>
Padalijimas 1 budu uztruko: 0.0275443<br>
Padalijimas 2 budu uztruko: 0.0315684<br>
Santykis t1/t2: 0.872528<br>

**3 STRATEGIJA, NAUDOJANT VEKTORIUS:**<br>
padalijimas 1 budu uztruko: 0.0378509 s<br>
padalijimas 2 budu uztruko: 0.0333835 s<br>
padalijimas 3 budu uztruko: 0.0146708 s<br>
Santykis t1/t3: 2.58002<br>
Santykis t2/t3: 2.27551<br>

**IŠVADOS:** su vektoriais 2 padalijimo metodas veikia greičiau už 1, su listais - lėčiau. 3 padalijimo metodas su vektoriais veikia greičiau nei 1 ir 2.
