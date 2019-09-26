# Blockchain. Hash algoritmo kūrimas.
## Programos tikslas
Programa nuskaito vartotojo įvestį string tipu (informaciją galima pateikti per komandinę eilutę arba per tesktinį failą), tuomet gautiems simboliams yra pritaikomas Hash algoritmas ir atsakymas išspausdinimas į tekstinį failą `tuscias.txt`. Taip pat yra pateikiamas laikas per kurį informacija buvo konvertuota naudojantis Hash algoritmą.  
## Makefile komandos
Norint paleisti programą, užtenka nueiti į projekto direktoriją ir įvesti komandą `make`. Programa sukurs paleidimo failą, atliks užduotį ir ištrins visą nereikalingą informaciją.  
## Išvedimo pavyzdys
```shell
737472616970736e  
6e756f737461746f  
Visas laikas yra 0.0261791  
```
## Hash algoritmo analizė
1. Sukūrus du dokumentus su skirtingais simboliais (du failai po vieną simbolį), buvo gauti skirtingi atsakymai. Išvesties Pavyzdys:  

```shell
3631666666666666  
Visas laikas yra 0.000110609  
6266266266266266  
Visas laikas yra 7.8095e-05  
```
Sukūrus du skirtingus failus su daug simbolių taip pat buvo gauti skirtingai atsakymai prie kiekvieno žodžio. Kai skyrėsi visi simboliai, atsakymai buvo kardinaliai kitokie, o pateikus dokumentus, kur skyrėsi tik vienas simbolis, skyrėsi tik žodis su kitokiu simboliu (Tai įrodo, kad įvedus matas arba Matas, bus gauti kitokie atsakymai, net jeigu skirsis ir ne žymiai).  
2. Sukūrus `konstitucija.txt` ir pritaikius jai Hash algoritmą, vėl buvo gauti skirtingi atsakymai, darbas užtruko mažiau nei vieną sekundę (vidutiniškai 0.22 sekundės). Output pavyzdys, kai naudojamas konstitucijos failas, yra pateiktas žemiau:  
```shell
4575726f706f7379
53ffffffc4ffffff
74656973ffffffc4
616b747573ffffff
6e616772696effff
74656973ffffffc4
616b74ffffffc5ff
6e75737461747974
747661726b612e74
44ffffffc4ffffff
ffffffc5ffffffa1
70617369ffffffc5
5679726961757379
67616c6961757379
707269696d746979
737072656e64696d
617272656e64696d
72657a6f6c697563
6b757269ffffffc5
707269ffffffc4ff
6e657461696b6f6d
4b6f6e7374697475
39356e7374697475
737472616970736e
6e756f737461746f
Visas laikas yra 0.0261791
```
3. Sukūrus 1 000 000 eilučių failą ir jam pritaikius Hash algoritmą, buvo gauti skirtingai atsakymai (nepavyko rasti pasikartojimų). Tačiau, Hash algoritmo atsakymai buvo panašūs, jeigu simboliai buvo arčiau vienas kito pagal ASCII (skaičiai buvo panašesni vienas kitą, artimesni). Toks pasikartojimas buvo dėl Hash algoritmo veikimo principo.  
4. Dėl aukščiau paminėtų priežasčių, Hash algoritmas nepraeitų testo bitų lygmenyje (skirtumai labai minimalus, nors yra).  
## Versijų istorija
### [v0.1](https://github.com/MatasC/Blockchain_Hash/releases/tag/v0.1) - (2019–09–26)
-Sukurtas Hash algoritmas.  
-Pridėta algoritmo analizė.  
