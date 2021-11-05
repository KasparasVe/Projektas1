# v0.4 ir v0.5 rezultatų palyginimas
1. 1 000 studentu:
* **Su vektoriais:**
Nuskaitymas: 0.0071706 s | Padalijimas: 0.0003002 s | Visas testo laikas: 0.0415508 s

* **Su listais:**
Nuskaitymas: 0.0068449 s | Padalijimas: 0.0002774 s | Visas testo laikas: 0.034365 s

* **SANTYKIS(vektoriu_laikas/listu_laikas)**
Nuskaitymas: 1.05 | Padalijimas: 1.08 | Visas testo laikas: 1.21  

2. 10 000 studentu:
* **Su vektoriais:**
Nuskaitymas: 0.0787843 s | Padalijimas: 0.0035743 s | Visas testo laikas: 0.231288 s

* **Su listais:**
Nuskaitymas: 0.0666863 | Padalijimas: 0.0029205 | Visas testo laikas: 0.150085 

* **SANTYKIS(vektoriu_laikas/listu_laikas):**
Nuskaitymas: 1.18 | Padalijimas: 1.22 | Visas testo laikas: 1.54  

3. 100 000 studentu:
* **Su vektoriais:**
Nuskaitymas: 0.713956 s | Padalijimas: 0.0337589 s | Visas testo laikas: 2.24813 s

* **Su listais:**
Nuskaitymas: 0.821117 s | Padalijimas: 0.0282808 s | Visas testo laikas: 1.73987 s

* **SANTYKIS(vektoriu_laikas/listu_laikas):**
Nuskaitymas: 0.86 | Padalijimas: 1.19 | Visas testo laikas: 1.29   

4. 1 000 000 studentu:
* **Su vektoriais:**
Nuskaitymas: 7.02066 s | Padalijimas: 0.289766 s | Visas testo laikas: 18.9206 s

* **Su listais:**
Nuskaitymas: 6.61892 s | Padalijimas: 0.310551 s | Visas testo laikas: 14.0325 s

* **SANTYKIS(vektoriu_laikas/listu_laikas):**
Nuskaitymas: 1.06 | Padalijimas: 0.93 | Visas testo laikas: 1.35 

**IŠVADOS**: tiek padalijimas, tiek nuskaitymas dažniausiai greičiau atliekamas su listais. Pagal visą testo laiką, testai su listais veikia apie 30-50% greičiau už testus su vektoriais.


