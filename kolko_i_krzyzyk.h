#ifndef KOLKO_I_KRZYZYK_H
#define KOLKO_I_KRZYZYK_H
#include <iostream>
#include <cstring>
using namespace std;

class kolko_i_krzyzyk{
    public:
        kolko_i_krzyzyk();
        virtual ~kolko_i_krzyzyk();
        int get_wiersz_kolumna(int wier, int kol);
        string wypisz_wiersz_kolumna();
        void set_znak_tury(char znak);
        char get_znak_tury();
        void logika();
        bool koniec_gry();
        void restart();
        int getremis();

    private:
        char znak_tury;
        int wiersz, kolumna, remis = 0;
        char tablica[3][3] ={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
};

#endif // KOLKO_I_KRZYZYK_H
