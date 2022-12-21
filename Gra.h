//
// Created by Szymon on 20.12.2022.
//

#ifndef CONNECT4_GRA_H
#define CONNECT4_GRA_H

#include <iostream>

class Gra {
public:
    Gra();
    ~Gra();
    void WhereIsLegal(int k);
    int Rezultat();
    void DrukujPlansze();
    void WykonajRuch();

    int *Plansza[7] = {K1, K2, K3, K4, K5, K6, K7};
private:
    //int kolumny_gra = 7;
    //int wiersze_gra = 6;
    int kolor_zetonu = 0;
    bool legalny_ruch = false;
    int tu_wstaw = 0;
    int tury = 1;
    int kolumna = 0;
    int K1[6] = {0,0,0,0,0,0};
    int K2[6] = {0,0,0,0,0,0};
    int K3[6] = {0,0,0,0,0,0};
    int K4[6] = {0,0,0,0,0,0};
    int K5[6] = {0,0,0,0,0,0};
    int K6[6] = {0,0,0,0,0,0};
    int K7[6] = {0,0,0,0,0,0};
};


#endif //CONNECT4_GRA_H
