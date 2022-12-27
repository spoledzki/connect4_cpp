#include <iostream>
#include "Gra.h"

int licznik_ruchow = 0;

int main() {
    std::cout << "Witaj w grze Connect 4!" << std::endl;
    Gra g;
    while (licznik_ruchow <= 42) {
        g.WykonajRuch();
        licznik_ruchow++;
        g.DrukujPlansze();
        std::cout<<"Sprawdzam wynik..."<<std::endl;
        if(g.Rezultat()) break;
    }
    std::cout << "Wygrywa gracz " << g.getToken() <<"!"<< std::endl;
    return 0;
}
