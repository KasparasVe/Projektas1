# v0.4 ir v0.5 rezultatų palyginimas
* 1000 studentu: <br>
**NAUDOJANT LISTUS:**<br>
Nuskaityti duomenis is failo uztruko: 0.0052945 s <br>
Studentu padalijimas i 2 listus uztruko: 0.0002246 s <br>
Visas testo laikas: 0.0071372 s <br>
**NAUDOJANT VEKTORIUS:**<br>
Nuskaityti duomenis is failo uztruko: 0.005799 s <br>
Studentu padalijimas i 2 vektorius uztruko: 0.0003348 s <br>
isas testo laikas: 0.0066661 s <br>

Nuskaitymo laiko santykis t_vec/t_lst: 1.09529 <br>
Padalijimo laiko santykis t_vec/t_lst: 1.49065 <br>
Viso testo laiko santykis t_vec/t_lst: 0.933994

* 10 000 studentu:<br>
**NAUDOJANT LISTUS:**<br>
Nuskaityti duomenis is failo uztruko: 0.0532089 s<br>
Studentu padalijimas i 2 listus uztruko: 0.002682 s<br>
Visas testo laikas: 0.0578957 s<br>
**NAUDOJANT VEKTORIUS:**<br>
Nuskaityti duomenis is failo uztruko: 0.0527996 s<br>
Studentu padalijimas i 2 vektorius uztruko: 0.0029526 s<br>
Visas testo laikas: 0.057275 s<br>

Nuskaitymo laiko santykis t_vec/t_lst: 0.992308<br>
Padalijimo laiko santykis t_vec/t_lst: 1.10089<br>
Viso testo laiko santykis t_vec/t_lst: 0.989279<br>

* 100 000 studentu:<br>
**NAUDOJANT LISTUS:**<br>
Nuskaityti duomenis is failo uztruko: 0.536438 s<br>
Studentu padalijimas i 2 listus uztruko: 0.0265993 s<br>
Visas testo laikas: 0.564613 s<br>
**NAUDOJANT VEKTORIUS:**<br>
Nuskaityti duomenis is failo uztruko: 0.533045 s<br>
Studentu padalijimas i 2 vektorius uztruko: 0.0316796 s<br>
Visas testo laikas: 0.566209 s<br>

Nuskaitymo laiko santykis t_vec/t_lst: 0.993677<br>
Padalijimo laiko santykis t_vec/t_lst: 1.19099<br>
Viso testo laiko santykis t_vec/t_lst: 1.00283<br>

* 1 000 000 studentu:<br>
**NAUDOJANT LISTUS:**<br>
Nuskaityti duomenis is failo uztruko: 5.6844 s<br>
Studentu padalijimas i 2 listus uztruko: 0.278355 s<br>
Visas testo laikas: 5.96395 s<br>
**NAUDOJANT VEKTORIUS:**<br>
Nuskaityti duomenis is failo uztruko: 5.72209 s<br>
Studentu padalijimas i 2 vektorius uztruko: 0.286467 s<br>
Visas testo laikas: 6.00991 s<br>

Nuskaitymo laiko santykis t_vec/t_lst: 1.00663<br>
Padalijimo laiko santykis t_vec/t_lst: 1.02914<br>
Viso testo laiko santykis t_vec/t_lst: 1.00771<br>

IŠVADOS: tiek vektoriams, tiek listams nuskaitymo laikas maždaug vienodas, studentų padalijimas į dvi grupes šiek tiek greitestis naudojant listus.

