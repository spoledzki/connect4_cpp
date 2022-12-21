//
// Created by Szymon 20.12.2022.
//

#include "Gra.h"


Gra::Gra() = default;

Gra::~Gra() = default;

void Gra::WhereIsLegal(int k) {
    int i=0;
    while(Plansza[k][i] != 0) i++;
    if(i<6) {
        legalny_ruch = true;
        tu_wstaw = i;
    }
    else legalny_ruch = false;
}

int Gra::Rezultat() {
    return 0;
}

void Gra::WykonajRuch() {
    if(0 != tury % 2){
        kolor_zetonu = 1;
    }
    else{
        kolor_zetonu = 2;
    }
    std::cout << "Tura gracza "<< kolor_zetonu <<" - ktora kolumne wybierasz?";
    std::cin >> kolumna;
    WhereIsLegal(kolumna-1);
    if(legalny_ruch){
        Plansza[kolumna-1][tu_wstaw] = kolor_zetonu;
        tury++;
    }
    else{
        std::cout << "Ten ruch jest nielegalny, wybierz inna kolumne." << std::endl;
        WykonajRuch();
    }
}

void Gra::DrukujPlansze() {
    for(int j=5; j>=0 ; j--){
        std::cout << "| ";
        for (int i = 0; i < 7; i++)
            std::cout << Plansza[i][j] << " ";
        std::cout << "|" << std::endl;
    }
    std::cout << "=================" << std::endl;
}



