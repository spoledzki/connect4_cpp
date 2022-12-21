#ifndef KIK_H
#define KIK_H

#include <algorithm>

using namespace std;

class kik {
    public:

        kik();

        void restart(bool);
                                  // funkcja restartujaca, true znaczy że zaczyna człowiek
                                  // false znaczy, że zaczyna komputer
        int ruch_czlowieka(int);
                                  // tej funkcji przekazujemy numerek pola na które kliknął
                                  // człowiek, w odpowiedzi dostajemy numer rysunku, który
                                  // należy w tym miejscu umieścić o ile ruch jest OK, czyli
                                  // wynik "0" oznacza, że gra jest rozstrzygnięta już wcześniej lub
                                  // też pole jest zajęte
        pair<int,int> co_dalej();
                                  // funkcja która podaje (w formie pary (x,y))
                                  // odpowiedź na pytanie jaki następny ruch
                                  // "komputera": x oznacza numerek w którym należy umieścić obrazek
                                  // y to numer obrazka; jeśli to NIE jest kolej komputera "x" jest ujemny
                                  // jeśli gra juz została zakończona "x" jest ujemny
        int rezultat() const;
                                  // odpowiedź na pytanie jeki jest rezultat gry: "0" wciąż nierozstzygnięte
                                  // "1" remis, "2" wygrał człowiek (raczej teoretyczne),
                                  // "3" wygrał komputer



    private:

        bool zaczyna_czlowiek = true;

        int ile_ruchow = 0;

        int plansza[9]={0,0,0,0,0,0,0,0,0};

        int linia() const;
        void zapisz_ruch_komputera(int);

        int __rezultat = 0;

        void oblicz_rezultat();
};

#endif // KIK_H
