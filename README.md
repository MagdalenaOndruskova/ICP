# ICP projekt
## MHD simulátor 
**Autorky**: 
- Magdaléna Ondrušková <xondru16@stud.fit.vutbr.cz>
- Zuzana Hradilová <xhradi16@stud.fit.vutbr.cz>

**Programovací jazyk**: C++ 

## Implementačné detaily: 
Cielom projektu bolo implementovať MHD simulátor, ktorý po načítaní údajov zo súboru začne pohybovať vozidlá po mape. Vozidlá ktoré patria k tej istej linke majú tú istú farbu. Po kliknutí na vozidlo sa vyfarbí ich trasa na mape a v bočnom paneli sa ukáže jeho aktuálna trasa s názvom zastávok a časom odchodu z jednotlivých zástavok. Vozidlá sa postupne v čase objavujú na mape a miznú keď prídu na koniec trasy. 

**Skok v čase:** Skok v čase je implementovaný vo viacerých verziách: 
- Skok v čase na konci dňa: keď na hodinách tikne 21:30, automaticky sa simulácia "reštartuje" a skočí sa v čase znovu na začiatok: 08:00
- Po stlačení tlačítka Reset Time: Skočí sa na čas 08:00, čo je východzí čas pre simuláciu 
- Po stlačení tlačítka Jump in Time: Skočí sa na čas, ktorý je zadaný vyššie v time Edite. 

**Traffic:** Zvýšená dopravná situácia je implementovaná pomocou zachytenia kliknutím myši pravým tlačítkom -- jedno kliknutie zvýši traffic o jeden bod a prejazd vozidiel sa spomalí o 0.5bodu ich rýchlosti. 

**Obchádzky:** Obchádzky sú implementované následovne:
- Dvojklikom sa uzavrie ulica (sfarbí sa na čierno)
- Ak je uzavretá ulica prvou ulicou, vozidlo ju automaticky vynechá a začne od ďalšej ulice 
- Ak je uzavretá ulica poslednou ulicou, vozidlo ju automaticky vynechá a skončí o ulicu skôr 
- Zvyšné typy obchádzok (ktoré uživateľ nakliká) neboli implementované

### Tlačítka: 
- Jump in Time - po stlačení sa zoberie čas v timeEdit (nad tlačítkom) a skočí sa v čase na daný čas 
- Faster - zrýchli simuláciu 
- Slower - spomalí simuláciu
- Reset Time - po stlačení sa simulácia vráti do času 08:00 (východzí čas)
- Reset Lines - po stlačení sa odstránia všetky zvýraznené linky a aj výpis linky v bočnom paneli 
- Reset Traffic - po stlačení sa všetká traffic vráti do pôvodného stavu 
- Reset Detours - po stlačení sa všetky zatvorené ulice otvoria 

## Príklad spustenia: 
- make  - slúži na preklad programu
- make run  - spustí program
- make doxygen  - vygeneruje dokumentáciu 
- make clean - vymaže vygenerované súbory 
- make pack - zabalí súbory do .zip súboru

## Odovzdané súbory:
- ./src - priečinok so zdrojovými súbormi
- ./doc - priečinok do ktorého sa vygeneruje dokumentácia, pred vygenerovaním obsahuje iba súbor Doxyfile so základnou konfiguráciou 
- ./examples - priečinok, ktorý obsahuje súbory ktoré sú zdrojom pre mapu - ulice, zástavky, linky a vozidlá






