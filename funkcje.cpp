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
    }
    return 0;
}
