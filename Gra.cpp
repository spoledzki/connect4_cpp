//
// Created by Szymon 20.12.2022.
//

#include "Gra.h"
#include <cstdlib>
#include <time.h>


Gra::Gra(){
    Plansza = new int*[gameCols];
    for(int i = 0; i < gameCols; i++){
        Plansza[i] = new int[gameRows];
        for(int j = 0; j < gameRows; j++){
            Plansza[i][j]=0;
        }
    }
}

Gra::~Gra(){
    for(int i = 0; i < 7; i++){
        delete Plansza[i];
    }
    delete[]Plansza;
}

bool Gra::isColLegal(int k){
    if(k<7 && k>-1) return true;
    return false;
}

bool Gra::isRowLegal(int w){
    if(w<6 && w>-1) return true;
    return false;
}

void Gra::WhereIsLegal(int k) {
    int i=0;
    if (!isColLegal(k)) isMoveLegal = false;
    else {
        while (Plansza[k][i] != 0) i++;
        if (!isRowLegal(i)) isMoveLegal = false;
        else {
            isMoveLegal = true;
            rowToInsert = i;
        }
    }
}

bool Gra::Rezultat() {
    if(CheckCols() || CheckRows() || CheckDiags()) return true;
    return false;
}

void Gra::WykonajRuch() {
    std::cout << "Tura gracza "<< PlayerColor <<" - ktora kolumne wybierasz?";
    std::cin >> lastPickCol;
    WhereIsLegal(lastPickCol-1);
    if(isMoveLegal){
        Plansza[lastPickCol-1][rowToInsert] = PlayerColor;
        roundCount++;
    }
    else{
        std::cout << "Ten ruch jest nielegalny, wybierz inna kolumne." << std::endl;
        WykonajRuch();
    }
}

void Gra::RuchAI() {
    //srand(time(NULL));
    //lastPickCol = rand()%7 + 1;
    std::string check;
    int j;
    //sprawdzanie trojek
    std::regex reg1("0222");
    std::regex reg2("2220");
    std::regex reg3("2022");
    std::regex reg4("2202");
    //sprawdzanie dwojek
    std::regex reg5("2200");
    std::regex reg6("0022");
    std::regex reg7("2002");
    std::regex reg8("0202");
    std::regex reg9("2020");
    std::regex reg10("0220");




    //Trojki w wierszach
    for(int i=0; i<6; i++){
        for(int j=0; j<7; j++){
            check += std::to_string(Plansza[j][i]);
            if(std::regex_search(check, reg1)){
                WhereIsLegal(j-3);
                if(CzyMoznaWstawic(j-3, rowToInsert)) {
                    Plansza[j-3][rowToInsert] = AIColor;
                    roundCount++;
                    return;
                }
            }
            else if(std::regex_search(check, reg2)){
                WhereIsLegal(j);
                if(CzyMoznaWstawic(j, rowToInsert)) {
                    Plansza[j][rowToInsert] = AIColor;
                    roundCount++;
                    return;
                }
            }
            else if(std::regex_search(check, reg3)){
                WhereIsLegal(j-2);
                if(CzyMoznaWstawic(j-2, rowToInsert)) {
                    Plansza[j-2][rowToInsert] = AIColor;
                    roundCount++;
                    return;
                }
            }
            else if(std::regex_search(check, reg4)){
                WhereIsLegal(j-1);
                if(CzyMoznaWstawic(j-1, rowToInsert)) {
                    Plansza[j-1][rowToInsert] = AIColor;
                    roundCount++;
                    return;
                }
            }
        }
    }
    //Trojki w kolumnach
    for(int i=0; i<7; i++){
        for(int j=0; j<6; j++){
            check += std::to_string(Plansza[j][i]);
            if(std::regex_search(check, reg1)){
                WhereIsLegal(i);
                Plansza[i][rowToInsert] = AIColor;
                roundCount++;
                return;
            }
            else if(std::regex_search(check, reg2)){
                WhereIsLegal(i);
                Plansza[i][rowToInsert] = AIColor;
                roundCount++;
                return;
            }
            else if(std::regex_search(check, reg3)){
                WhereIsLegal(i);
                Plansza[i][rowToInsert] = AIColor;
                roundCount++;
                return;
            }
            else if(std::regex_search(check, reg4)){
                WhereIsLegal(i);
                Plansza[i][rowToInsert] = AIColor;
                roundCount++;
                return;
            }

        }

    }

    //Dwojki w wierszach
    /*for(int i=0; i<6; i++){
        for(int j=0; j<7; j++){
            check += std::to_string(Plansza[j][i]);
            if(std::regex_search(check, reg5)){
                WhereIsLegal(j-1);
                Plansza[j-1][rowToInsert] = AIColor;
                roundCount++;
                return;
            }
            else if(std::regex_search(check, reg6)){
                WhereIsLegal(j-2);
                Plansza[j-2][rowToInsert] = AIColor;
                roundCount++;
                return;
            }
            else if(std::regex_search(check, reg7)){
                WhereIsLegal(j-1);
                Plansza[j-1][rowToInsert] = AIColor;
                roundCount++;
                return;
            }
            else if(std::regex_search(check, reg8)){
                WhereIsLegal(j-3);
                Plansza[j-3][rowToInsert] = AIColor;
                roundCount++;
                return;
            }
            else if(std::regex_search(check, reg9)){
                WhereIsLegal(j);
                Plansza[j][rowToInsert] = AIColor;
                roundCount++;
                return;
            }
            else if(std::regex_search(check, reg10)){
                WhereIsLegal(j);
                Plansza[j][rowToInsert] = AIColor;
                roundCount++;
                return;
            }

        }
    }*/

    //Trojki na przekatnych
    /*for(int i = -2; i<4; i++){
        j = i;
        for(int k = 0; k<6; k++){
            if(isColLegal(j)){
                check += std::to_string(Plansza[j][k]);
                if(std::regex_search(check, reg1)){
                    WhereIsLegal(i);
                    if(CzyMoznaWstawic(i, rowToInsert)) {
                        Plansza[i][rowToInsert] = AIColor;
                        roundCount++;
                        return;
                    }

                }
                else if(std::regex_search(check, reg2)){
                    WhereIsLegal(i+3);
                    if(CzyMoznaWstawic(i+3, rowToInsert)) {
                        Plansza[i+3][rowToInsert] = AIColor;
                        roundCount++;
                        return;
                    }

                }
                else if(std::regex_search(check, reg3)){
                    WhereIsLegal(i+1);
                    if(CzyMoznaWstawic(i+1, rowToInsert)) {
                        Plansza[i+1][rowToInsert] = AIColor;
                        roundCount++;
                        return;
                    }

                }
                else if(std::regex_search(check, reg4)){
                    WhereIsLegal(i+2);
                    if(CzyMoznaWstawic(i+2, rowToInsert)) {
                        Plansza[i+2][rowToInsert] = AIColor;
                        roundCount++;
                        return;
                    }

                }
            }
            j++;
        }
    }*/

    /*for(int i = -2; i<4; i++){
        j = i;
        for(int k = 5; k>-1; k--){
            if(isColLegal(j)){
                check += std::to_string(Plansza[j][k]);
                if(std::regex_search(check, reg1)){
                    WhereIsLegal(j+1);
                    if(CzyMoznaWstawic(j+1, rowToInsert)) {
                        Plansza[j+1][rowToInsert] = AIColor;
                        roundCount++;
                        return;
                    }

                }
                else if(std::regex_search(check, reg2)){
                    WhereIsLegal(j+2);
                    if(CzyMoznaWstawic(j+2, rowToInsert)) {
                        Plansza[j+2][rowToInsert] = AIColor;
                        roundCount++;
                        return;
                    }

                }
                else if(std::regex_search(check, reg3)){
                    WhereIsLegal(j);
                    if(CzyMoznaWstawic(j, rowToInsert)) {
                        Plansza[j][rowToInsert] = AIColor;
                        roundCount++;
                        return;
                    }

                }
                else if(std::regex_search(check, reg4)){
                    WhereIsLegal(j+1);
                    if(CzyMoznaWstawic(j+1, rowToInsert)) {
                        Plansza[j+1][rowToInsert] = AIColor;
                        roundCount++;
                        return;
                    }

                }
            }
            j++;
        }
    }*/





    srand(time(NULL));
    lastPickCol = rand()%7 + 1;
    WhereIsLegal(lastPickCol-1);
    Plansza[lastPickCol-1][rowToInsert] = AIColor;
    roundCount++;
}

bool Gra::CzyMoznaWstawic(int i, int j) {
    return (Plansza[i][j-1]!=0 && Plansza[i][j+1]==0);
}

void Gra::DrukujPlansze() {
    for(int j=5; j>=0 ; j--){
        std::cout << "| ";
        for (int i = 0; i < 7; i++) {
            if (Plansza[i][j] == 0) std::cout << " ";
            else std::cout << Plansza[i][j];
            std::cout << " ";
        }
        std::cout << "|" << std::endl;
    }
    std::cout << "=================" << std::endl;
}

bool Gra::CheckCols() {
    std::string kol_check;
    //std::string komunikat = "Gramy dalej!";
    std::regex reg1("1111");
    std::regex reg2("2222");

    for(int i=0; i<7; i++){
        for(int j=0; j<6; j++){
            kol_check += std::to_string(Plansza[i][j]);
        }
        if(std::regex_search(kol_check, reg1)){
            //komunikat = "Wygrywa gracz 1!";
            isGameOver = true;
            winningToken = 1;
        }
        if(std::regex_search(kol_check, reg2)){
            //komunikat = "Wygrywa gracz 2!";
            isGameOver = true;
            winningToken = 2;
        }
        //std::cout << kol_check << std::endl;
        kol_check = "";
    }
    //std::cout << komunikat <<std::endl;
    return isGameOver;
}

bool Gra::CheckRows() {
    std::string row_check;
    //std::string komunikat = "Gramy dalej!";
    std::regex reg1("1111");
    std::regex reg2("2222");

    for(int i=0; i<6; i++){
        for(int j=0; j<7; j++){
            row_check += std::to_string(Plansza[j][i]);
        }
        if(std::regex_search(row_check, reg1)){
            //komunikat = "Wygrywa gracz 1!";
            winningToken = 1;
            return isGameOver = true;
        }
        if(std::regex_search(row_check, reg2)){
            //komunikat = "Wygrywa gracz 2!";
            winningToken = 2;
            return isGameOver = true;
        }
        //std::cout << row_check << std::endl;
        row_check = "";
    }
    //std::cout << komunikat <<std::endl;
    return isGameOver;
}

int Gra::getToken() const {
    return winningToken;
}

bool Gra::CheckDiags() {
    if(CheckDiagsLDRU() || CheckDiagsLURD()) return true;
    return false;
}

bool Gra::CheckDiagsLDRU() {
    std::string diag_check;
    std::regex reg1("1111");
    std::regex reg2("2222");
    int j;
    for(int i = -2; i<4; i++){
        j = i;
        for(int k = 0; k<6; k++){
            if(isColLegal(j)){
                diag_check += std::to_string(Plansza[j][k]);
            }
            j++;
        }
        if(std::regex_search(diag_check, reg1)){
            //komunikat = "Wygrywa gracz 1!";
            winningToken = 1;
            return isGameOver = true;
        }
        if(std::regex_search(diag_check, reg2)){
            //komunikat = "Wygrywa gracz 2!";
            winningToken = 2;
            return isGameOver = true;
        }
        //std::cout << diag_check << std::endl;
        diag_check = "";
    }
    return isGameOver;
}

bool Gra::CheckDiagsLURD() {
    std::string diag_check;
    std::regex reg1("1111");
    std::regex reg2("2222");
    int j;
    for(int i = -2; i<4; i++){
        j = i;
        for(int k = 5; k>-1; k--){
            if(isColLegal(j)) {
                diag_check += std::to_string(Plansza[j][k]);
            }
            j++;
        }
        if(std::regex_search(diag_check, reg1)){
            //komunikat = "Wygrywa gracz 1!";
            winningToken = 1;
            return isGameOver = true;
        }
        if(std::regex_search(diag_check, reg2)){
            //komunikat = "Wygrywa gracz 2!";
            winningToken = 2;
            return isGameOver = true;
        }
        //std::cout << diag_check << std::endl;
        diag_check = "";
    }
    return isGameOver;
}

