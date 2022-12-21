#include "kolko_i_krzyzyk.h"
#include <iostream>
#include <cstring>
#include <sstream>

using namespace std;
kolko_i_krzyzyk::kolko_i_krzyzyk(){

}

kolko_i_krzyzyk::~kolko_i_krzyzyk(){
    //dtor
}

int kolko_i_krzyzyk::get_wiersz_kolumna(int wier, int kol){
wiersz = wier;
kolumna = kol;
}

void kolko_i_krzyzyk::logika(){
    if(znak_tury == 'X' && tablica[wiersz][kolumna] != 'X' && tablica[wiersz][kolumna] != 'O'){
        tablica[wiersz][kolumna] = 'X';
        znak_tury = 'O';
        remis++;
    }
        else if(znak_tury == 'O' && tablica[wiersz][kolumna] != 'X' && tablica[wiersz][kolumna] != 'O'){
            tablica[wiersz][kolumna] = 'O';
            znak_tury = 'X';
            remis++;
            }
}

string kolko_i_krzyzyk::wypisz_wiersz_kolumna(){
    stringstream wypiszss;
    string drukuj_wypisz;
    string tura;
    if(znak_tury == 'O') tura = "Gracz";
        else tura = "Komputer";
    wypiszss<<"Tura: "<<tura<<endl;
    drukuj_wypisz = wypiszss.str();
    return drukuj_wypisz;
}

void kolko_i_krzyzyk::set_znak_tury(char znak){
znak_tury = znak;
}

bool kolko_i_krzyzyk::koniec_gry(){
    if((tablica[0][0] == tablica[1][0] && tablica[0][0] == tablica[2][0] && tablica[1][0] == tablica[2][0]) || //poziomo górny
    (tablica[0][1] == tablica[1][1] && tablica[0][1] == tablica[2][1] && tablica[1][1] == tablica[2][1]) || //poziomo środkowy
    (tablica[0][2] == tablica[1][2] && tablica[0][2] == tablica[2][2] && tablica[1][2] == tablica[2][2]) || //poziomo dolny
    (tablica[0][0] == tablica[0][1] && tablica[0][0] == tablica[0][2] && tablica[0][1] == tablica[0][2]) || //pionowo lewy
    (tablica[1][0] == tablica[1][1] && tablica[1][0] == tablica[1][2] && tablica[1][1] == tablica[1][2]) || //pionowo środkowy
    (tablica[2][0] == tablica[2][1] && tablica[2][0] == tablica[2][2] && tablica[2][1] == tablica[2][2]) || //pionowo prawy
    (tablica[0][0] == tablica[1][1] && tablica[0][0] == tablica[2][2] && tablica[1][1] == tablica[2][2]) || //ukos w prawo
    (tablica[2][0] == tablica[1][1] && tablica[1][1] == tablica[0][2] && tablica[1][1] == tablica[2][0]) || //ukos w lewo
    remis == 9) return true;
    else return false;
    }

void kolko_i_krzyzyk::restart(){
    remis = 0;
    int wartosc = 10;
    for (wiersz = 0; wiersz<=2; wiersz++)
    {
        for (kolumna = 0;kolumna<=2 ; kolumna++)
        {
            tablica[wiersz][kolumna] =wartosc;
            wartosc++;
        }
    }
}

char kolko_i_krzyzyk::get_znak_tury(){
return znak_tury;
}

int kolko_i_krzyzyk::getremis(){
    return remis;
}
