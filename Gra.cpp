//
// Created by Szymon 20.12.2022.
//

#include "Gra.h"
#include <iostream>
#include <sstream>
#include <cstring>
#include <ctime>
#include <cstdlib>
using namespace std;
Gra::Gra(){
    srand(time(NULL));
    Plansza = new int*[gameCols];
    for(int i = 0; i < gameCols; i++){
        Plansza[i] = new int[gameRows];
        for(int j = 0; j < gameRows; j++){
            Plansza[i][j]=0;
        }
    }
    for(int i=0;i<2;i++){
        rundy[i] = 0;
    }

    //roundCount = rand() % 2 + 1;
}

Gra::~Gra(){
}

bool Gra::isColLegal(int k){
    if(k<7 && k>-1) return true;
    return false;
}

bool Gra::isRowLegal(int w){
    if(w<6 && w>-1) return true;
    return false;
}

bool Gra::isMoveLegal(){
    return MoveLegal;
}


void Gra::setwiersz_kolumna_bota(int kolumna){
wiersz_bota = rowToInsert;
kolumna_bota = kolumna;
}


void Gra::WhereIsLegal(int k) {
    int i=0;
    if (!isColLegal(k)) {
            MoveLegal = false;
            //komunikat = "Ruch nielegalny!";
    }
    else {
        while (Plansza[k][i] != 0) i++;
        if (!isRowLegal(i)) {
                MoveLegal = false;
                //komunikat = "Ruch nielegalny!";
        }
        else {
            MoveLegal = true;
            rowToInsert = i;
            //komunikat = "Ruch legalny";
        }
    }
}

bool Gra::Rezultat() {
    if(CheckCols() || CheckRows() || CheckDiags()) return true;
    return false;
}

void Gra::WykonajRuch() {
    if(0 != roundCount % 2){
        tokenColor = 1;
    }
    else{
        tokenColor = 2;
    }
    //std::cout << "Tura gracza "<< tokenColor <<" - ktora kolumne wybierasz?";
    //std::cin >> lastPickCol;
    WhereIsLegal(lastPickCol-1);
    if(MoveLegal){
        Plansza[lastPickCol-1][rowToInsert] = tokenColor;
        roundCount++;
    }
    else{
        //std::cout << "Ten ruch jest nielegalny, wybierz inna kolumne." << std::endl;
        WykonajRuch();
    }

}

void Gra::WykonajRuch_z_AI() {
    //std::cout << "Tura gracza "<< tokenColor <<" - ktora kolumne wybierasz?";
    //std::cin >> lastPickCol;
    WhereIsLegal(lastPickCol-1);
    if(MoveLegal){
        Plansza[lastPickCol-1][rowToInsert] = PlayerColor;
        roundCount++;
    }
    else{
        //std::cout << "Ten ruch jest nielegalny, wybierz inna kolumne." << std::endl;
        WykonajRuch_z_AI();
    }

}




int Gra::DrukujPlansze(int numer_kolumny, int numer_wiersza) {
    return Plansza[numer_kolumny][numer_wiersza];

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
            rundy[0]++;
        }
        if(std::regex_search(kol_check, reg2)){
            //komunikat = "Wygrywa gracz 2!";
            isGameOver = true;
            winningToken = 2;
            rundy[1]++;
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
            rundy[0]++;
            return isGameOver = true;
        }
        if(std::regex_search(row_check, reg2)){
            //komunikat = "Wygrywa gracz 2!";
            winningToken = 2;
            rundy[1]++;
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
            rundy[0]++;
            return isGameOver = true;
        }
        if(std::regex_search(diag_check, reg2)){
            //komunikat = "Wygrywa gracz 2!";
            winningToken = 2;
            rundy[1]++;
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
            rundy[0]++;
            return isGameOver = true;
        }
        if(std::regex_search(diag_check, reg2)){
            //komunikat = "Wygrywa gracz 2!";
            winningToken = 2;
            rundy[1]++;
            return isGameOver = true;
        }
        //std::cout << diag_check << std::endl;
        diag_check = "";
    }
    return isGameOver;
}

int Gra::gettokenColor(){
return tokenColor;
}

void Gra::setLastPickCol(int kolumna){
lastPickCol = kolumna;
}

std::string Gra::getKomunikat(){
    return komunikat;
}

void Gra::ending(){
    for(int i = 0; i < 7; i++){
        delete Plansza[i];
    }
    delete[]Plansza;

    Plansza = new int*[gameCols];
    for(int i = 0; i < gameCols; i++){
        Plansza[i] = new int[gameRows];
        for(int j = 0; j < gameRows; j++){
            Plansza[i][j]=0;
        }
    }

    tokenColor = 0;
    MoveLegal = false;
    rowToInsert = 0;
    roundCount = rand() % 2 + 1;
    lastPickCol = 0;
    isGameOver = false;
    winningToken = 0;
}

std::string Gra::rundy_graczy(int numer_gracza){
    stringstream ss;
    ss<<to_string(rundy[numer_gracza]);
    string drukuj = ss.str();
return drukuj;
}

int Gra::getroundCount(){
return roundCount;
}

void Gra::koniec_rund(){
for(int i=0;i<2;i++){
        rundy[i] = 0;
    }
}


void Gra::RuchAI() {
    //srand(time(NULL));
    //lastPickCol = rand()%7 + 1;
    std::string check_col, check_row, check_diag1, check_diag2;
    std::string check_col_twos, check_row_twos, check_diag1_twos, check_diag_2twos;
    std::string check_col_ai, check_row_ai, check_diag1_ai, check_diag2_ai;
    std::string check_row_fives;
    int j;
    //sprawdzanie trojek
    std::regex reg1a("0222");
    std::regex reg2a("2220");
    std::regex reg3a("2022");
    std::regex reg4a("2202");

    std::regex reg1b("0111");
    std::regex reg2b("1110");
    std::regex reg3b("1011");
    std::regex reg4b("1101");

    //sprawdzanie dwojek
    std::regex reg5("2200");
    std::regex reg6("0022");
    std::regex reg7("2002");
    std::regex reg8("0202");
    std::regex reg9("2020");
    std::regex reg10("0220");

    //sprawdzanie dwojek w piatkach przeciwnika

    std::regex reg11("01100");
    std::regex reg12("00110");





    //Trojki w wierszach

    //ai
    for(int i=0; i<6; i++){
        for(int j=0; j<7; j++){
            check_row += std::to_string(Plansza[j][i]);
            //std::cout << check_row <<std::endl;
            if(std::regex_search(check_row, reg1a)){
                WhereIsLegal(j-3);
                if(CzyMoznaWstawic(j-3, rowToInsert)) {
                        ruch_bota(j-3);
                    Plansza[j-3][rowToInsert] = AIColor;
                    roundCount++;
                    return;
                }
            }
            else if(std::regex_search(check_row, reg2a)){
                WhereIsLegal(j);
                if(CzyMoznaWstawic(j, rowToInsert)) {ruch_bota(j);
                    Plansza[j][rowToInsert] = AIColor;

                    roundCount++;
                    return;
                }
            }
            else if(std::regex_search(check_row, reg3a)){
                WhereIsLegal(j-2);
                if(CzyMoznaWstawic(j-2, rowToInsert)) {ruch_bota(j-2);
                    Plansza[j-2][rowToInsert] = AIColor;

                    roundCount++;
                    return;
                }
            }
            else if(std::regex_search(check_row, reg4a)){
                WhereIsLegal(j-1);
                if(CzyMoznaWstawic(j-1, rowToInsert)) {ruch_bota(j-1);
                    Plansza[j-1][rowToInsert] = AIColor;

                    roundCount++;
                    return;
                }
            }

        }
        check_row="";

    }

    //gracz
    for(int i=0; i<6; i++){
        for(int j=0; j<7; j++){
            check_row_ai += std::to_string(Plansza[j][i]);
            //std::cout << check_row <<std::endl;
            if(std::regex_search(check_row_ai, reg1b)){
                WhereIsLegal(j-3);
                if(CzyMoznaWstawic(j-3, rowToInsert)) {ruch_bota(j-3);
                    Plansza[j-3][rowToInsert] = AIColor;

                    roundCount++;
                    return;
                }
            }
            else if(std::regex_search(check_row_ai, reg2b)){
                WhereIsLegal(j);
                if(CzyMoznaWstawic(j, rowToInsert)) {ruch_bota(j);
                    Plansza[j][rowToInsert] = AIColor;

                    roundCount++;
                    return;
                }
            }
            else if(std::regex_search(check_row_ai, reg3b)){
                WhereIsLegal(j-2);
                if(CzyMoznaWstawic(j-2, rowToInsert)) {ruch_bota(j-2);
                    Plansza[j-2][rowToInsert] = AIColor;

                    roundCount++;
                    return;
                }
            }
            else if(std::regex_search(check_row_ai, reg4b)){
                WhereIsLegal(j-1);
                if(CzyMoznaWstawic(j-1, rowToInsert)) {ruch_bota(j-1);
                    Plansza[j-1][rowToInsert] = AIColor;

                    roundCount++;
                    return;
                }
            }

        }
        check_row_ai="";

    }


    //Trojki w kolumnach

    //ai
    for(int i=0; i<7; i++){
        for(int j=0; j<6; j++){
            check_col += std::to_string(Plansza[i][j]);
            //std::cout<<check_col<<std::endl;
            if(std::regex_search(check_col, reg1a)){
                WhereIsLegal(i);
                ruch_bota(i);
                Plansza[i][rowToInsert] = AIColor;

                roundCount++;
                return;
            }
            else if(std::regex_search(check_col, reg2a)){
                WhereIsLegal(i);ruch_bota(i);
                Plansza[i][rowToInsert] = AIColor;

                roundCount++;
                return;
            }
            else if(std::regex_search(check_col, reg3a)){
                WhereIsLegal(i);ruch_bota(i);
                Plansza[i][rowToInsert] = AIColor;

                roundCount++;
                return;
            }
            else if(std::regex_search(check_col, reg4a)){
                WhereIsLegal(i);ruch_bota(i);
                Plansza[i][rowToInsert] = AIColor;

                roundCount++;
                return;
            }

        }
        check_col="";
    }

    //gracz
    for(int i=0; i<7; i++){
        for(int j=0; j<6; j++){
            check_col_ai += std::to_string(Plansza[i][j]);
            //std::cout<<check_col<<std::endl;
            if(std::regex_search(check_col_ai, reg1b)){
                WhereIsLegal(i);ruch_bota(i);
                Plansza[i][rowToInsert] = AIColor;

                roundCount++;
                return;
            }
            else if(std::regex_search(check_col_ai, reg2b)){
                WhereIsLegal(i);ruch_bota(i);
                Plansza[i][rowToInsert] = AIColor;

                roundCount++;
                return;
            }
            else if(std::regex_search(check_col_ai, reg3b)){
                WhereIsLegal(i);ruch_bota(i);
                Plansza[i][rowToInsert] = AIColor;

                roundCount++;
                return;
            }
            else if(std::regex_search(check_col_ai, reg4b)){
                WhereIsLegal(i);ruch_bota(i);
                Plansza[i][rowToInsert] = AIColor;

                roundCount++;
                return;
            }

        }
        check_col_ai="";
    }

    //Trojki na przekatnych
    //ai
    for(int i = -2; i<4; i++){
        j = i;

        for(int k = 0; k<6; k++){
            if(isColLegal(j)){
                check_diag1 += std::to_string(Plansza[j][k]);
                //std::cout << check_diag1 <<std::endl;
                if(std::regex_search(check_diag1, reg1a) || std::regex_search(check_diag1, reg1b)){
                    WhereIsLegal(j-3);
                    //std::cout << check_diag1 <<std::endl;
                    if(CzyMoznaWstawic(j-3, rowToInsert)) {ruch_bota(j-3);
                        Plansza[j-3][rowToInsert] = AIColor;

                        roundCount++;
                        return;
                    }

                }
                else if(std::regex_search(check_diag1, reg2a) || std::regex_search(check_diag1, reg2b)){
                    WhereIsLegal(j);
                    //std::cout << check_diag1 <<std::endl;
                    if(CzyMoznaWstawic(j, rowToInsert)) {ruch_bota(j);
                        Plansza[j][rowToInsert] = AIColor;

                        roundCount++;
                        return;
                    }

                }
                else if(std::regex_search(check_diag1, reg3a) || std::regex_search(check_diag1, reg3b)){
                    WhereIsLegal(j-2);
                    //std::cout << check_diag1 <<std::endl;
                    if(CzyMoznaWstawic(j-2, rowToInsert)) {ruch_bota(j-2);
                        Plansza[j-2][rowToInsert] = AIColor;

                        roundCount++;
                        return;
                    }

                }
                else if(std::regex_search(check_diag1, reg4a) || std::regex_search(check_diag1, reg4b)){
                    WhereIsLegal(j-1);
                    //std::cout << check_diag1 <<std::endl;
                    if(CzyMoznaWstawic(j-1, rowToInsert)) {ruch_bota(j-1);
                        Plansza[j-1][rowToInsert] = AIColor;

                        roundCount++;
                        return;
                    }
                //check="";
                }
            }
            j++;
        }
        check_diag1="";
    }

    //gracz
    for(int i = -2; i<4; i++){
        j = i;

        for(int k = 0; k<6; k++){
            if(isColLegal(j)){
                check_diag1_ai += std::to_string(Plansza[j][k]);
                //std::cout << check_diag1_ai <<std::endl;
                if(std::regex_search(check_diag1_ai, reg1b)){
                    WhereIsLegal(j-3);
                    //std::cout << check_diag1 <<std::endl;
                    if(CzyMoznaWstawic(j-3, rowToInsert)) {ruch_bota(j-3);
                        Plansza[j-3][rowToInsert] = AIColor;

                        roundCount++;
                        return;
                    }

                }
                else if(std::regex_search(check_diag1_ai, reg2b)){
                    WhereIsLegal(j);
                    //std::cout << check_diag1 <<std::endl;
                    if(CzyMoznaWstawic(j, rowToInsert)) {ruch_bota(j);
                        Plansza[j][rowToInsert] = AIColor;

                        roundCount++;
                        return;
                    }

                }
                else if(std::regex_search(check_diag1_ai, reg3b)){
                    WhereIsLegal(j-2);
                    //std::cout << check_diag1 <<std::endl;
                    if(CzyMoznaWstawic(j-2, rowToInsert)) {ruch_bota(j-2);
                        Plansza[j-2][rowToInsert] = AIColor;

                        roundCount++;
                        return;
                    }

                }
                else if(std::regex_search(check_diag1_ai, reg4b)){
                    WhereIsLegal(j-1);
                    //std::cout << check_diag1 <<std::endl;
                    if(CzyMoznaWstawic(j-1, rowToInsert)) {ruch_bota(j-1);
                        Plansza[j-1][rowToInsert] = AIColor;

                        roundCount++;
                        return;
                    }
                    //check="";
                }
            }
            j++;
        }
        check_diag1_ai="";
    }

    //ai
    for(int i = -2; i<4; i++){
        j = i;
        for(int k = 5; k>-1; k--){
            if(isColLegal(j)){
                check_diag2 += std::to_string(Plansza[j][k]);
                //std::cout << check_diag2 <<std::endl;
                if(std::regex_search(check_diag2, reg1a) || std::regex_search(check_diag2, reg1b)){
                    WhereIsLegal(j-3);
                    if(CzyMoznaWstawic(j-3, rowToInsert)) {ruch_bota(j-3);
                        Plansza[j-3][rowToInsert] = AIColor;

                        roundCount++;
                        return;
                    }

                }
                else if(std::regex_search(check_diag2, reg2a) || std::regex_search(check_diag2, reg2b)){
                    WhereIsLegal(j);
                    if(CzyMoznaWstawic(j, rowToInsert)) {ruch_bota(j-3);
                        Plansza[j][rowToInsert] = AIColor;

                        roundCount++;
                        return;
                    }

                }
                else if(std::regex_search(check_diag2, reg3a) || std::regex_search(check_diag2, reg3b)){
                    WhereIsLegal(j-2);
                    if(CzyMoznaWstawic(j-2, rowToInsert)) {ruch_bota(j-2);
                        Plansza[j-2][rowToInsert] = AIColor;

                        roundCount++;
                        return;
                    }

                }
                else if(std::regex_search(check_diag2, reg4a) || std::regex_search(check_diag2, reg4b)){
                    WhereIsLegal(j-1);
                    if(CzyMoznaWstawic(j-1, rowToInsert)) {ruch_bota(j-1);
                        Plansza[j-1][rowToInsert] = AIColor;

                        roundCount++;
                        return;
                    }

                }
            }
            j++;
        }
        check_diag2="";
    }

    //gracz
    for(int i = -2; i<4; i++){
        j = i;
        for(int k = 5; k>-1; k--){
            if(isColLegal(j)){
                check_diag2_ai += std::to_string(Plansza[j][k]);
                //std::cout << check_diag2 <<std::endl;
                if(std::regex_search(check_diag2_ai, reg1b)){
                    WhereIsLegal(j-3);
                    if(CzyMoznaWstawic(j-3, rowToInsert)) {ruch_bota(j-3);
                        Plansza[j-3][rowToInsert] = AIColor;

                        roundCount++;
                        return;
                    }

                }
                else if(std::regex_search(check_diag2_ai, reg2b)){
                    WhereIsLegal(j);
                    if(CzyMoznaWstawic(j, rowToInsert)) {ruch_bota(j);
                        Plansza[j][rowToInsert] = AIColor;

                        roundCount++;
                        return;
                    }

                }
                else if(std::regex_search(check_diag2_ai, reg3b)){
                    WhereIsLegal(j-2);
                    if(CzyMoznaWstawic(j-2, rowToInsert)) {ruch_bota(j-2);
                        Plansza[j-2][rowToInsert] = AIColor;

                        roundCount++;
                        return;
                    }

                }
                else if(std::regex_search(check_diag2_ai, reg4b)){
                    WhereIsLegal(j-1);
                    if(CzyMoznaWstawic(j-1, rowToInsert)) {ruch_bota(j-1);
                        Plansza[j-1][rowToInsert] = AIColor;

                        roundCount++;
                        return;
                    }

                }
            }
            j++;
        }
        check_diag2_ai="";
    }

    //Dwojki w wierszach
    for(int i=0; i<6; i++){
        for(int j=0; j<7; j++){
            check_row_twos += std::to_string(Plansza[j][i]);
            if(std::regex_search(check_row_twos, reg5)){
                WhereIsLegal(j-1);ruch_bota(j-1);
                Plansza[j-1][rowToInsert] = AIColor;

                roundCount++;
                return;
            }
            else if(std::regex_search(check_row_twos, reg6)){
                WhereIsLegal(j-2);ruch_bota(j-2);
                Plansza[j-2][rowToInsert] = AIColor;

                roundCount++;
                return;
            }
            else if(std::regex_search(check_row_twos, reg7)){
                WhereIsLegal(j-1);ruch_bota(j-1);
                Plansza[j-1][rowToInsert] = AIColor;

                roundCount++;
                return;
            }
            else if(std::regex_search(check_row_twos, reg8)){
                WhereIsLegal(j-3);ruch_bota(j-3);
                Plansza[j-3][rowToInsert] = AIColor;

                roundCount++;
                return;
            }
            else if(std::regex_search(check_row_twos, reg9)){
                WhereIsLegal(j);ruch_bota(j);
                Plansza[j][rowToInsert] = AIColor;

                roundCount++;
                return;
            }
            else if(std::regex_search(check_row_twos, reg10)){
                WhereIsLegal(j);ruch_bota(j);
                Plansza[j][rowToInsert] = AIColor;

                roundCount++;
                return;
            }

        }
        check_row_twos="";
    }

    //Dwojki w kolumnach
    for(int i=0; i<7; i++){
        for(int j=0; j<6; j++){
            check_col_twos += std::to_string(Plansza[i][j]);
            if(std::regex_search(check_col_twos, reg5)){
                WhereIsLegal(i);ruch_bota(i);
                Plansza[i][rowToInsert] = AIColor;

                roundCount++;
                return;
            }
            else if(std::regex_search(check_col_twos, reg6)){
                WhereIsLegal(i);ruch_bota(i);
                Plansza[i][rowToInsert] = AIColor;

                roundCount++;
                return;
            }
            else if(std::regex_search(check_col_twos, reg7)){
                WhereIsLegal(i);ruch_bota(i);
                Plansza[i][rowToInsert] = AIColor;

                roundCount++;
                return;
            }
            else if(std::regex_search(check_col_twos, reg8)){
                WhereIsLegal(i);ruch_bota(i);
                Plansza[i][rowToInsert] = AIColor;

                roundCount++;
                return;
            }
            else if(std::regex_search(check_col_twos, reg9)){
                WhereIsLegal(i);ruch_bota(i);
                Plansza[i][rowToInsert] = AIColor;

                roundCount++;
                return;
            }
            else if(std::regex_search(check_col_twos, reg10)){
                WhereIsLegal(i);ruch_bota(i);
                Plansza[i][rowToInsert] = AIColor;

                roundCount++;
                return;
            }

        }
        check_col_twos="";
    }


    //Dwojki na przekatnych

    for(int i=-2; i<4; i++){
        j=i;
        for(int k=0; k<6; k++){
            if(isColLegal(j)) {
                check_diag1_twos += std::to_string(Plansza[j][k]);
                //std::cout<<check_diag1_twos<<std::endl;
                if(std::regex_search(check_diag1_twos, reg5)){
                    WhereIsLegal(j-1);
                    if(CzyMoznaWstawic(j-1, rowToInsert)){ruch_bota(j-1);
                        Plansza[j-1][rowToInsert] = AIColor;

                        roundCount++;
                        return;
                    }
                    WhereIsLegal(j);
                    if(CzyMoznaWstawic(j, rowToInsert)){ruch_bota(j);
                        Plansza[j][rowToInsert] = AIColor;

                        roundCount++;
                        return;
                    }

                }
                else if(std::regex_search(check_diag1_twos, reg6)){
                    WhereIsLegal(j-2);
                    if(CzyMoznaWstawic(j-2, rowToInsert)) {ruch_bota(j-2);
                        Plansza[j-2][rowToInsert] = AIColor;

                        roundCount++;
                        return;
                    }
                    WhereIsLegal(j-3);
                    if(CzyMoznaWstawic(j-3, rowToInsert)) {ruch_bota(j-3);
                        Plansza[j-3][rowToInsert] = AIColor;

                        roundCount++;
                        return;
                    }

                }
                else if(std::regex_search(check_diag1_twos, reg7)){
                    WhereIsLegal(j-1);
                    if(CzyMoznaWstawic(j-1, rowToInsert)) {ruch_bota(j-1);
                        Plansza[j-1][rowToInsert] = AIColor;

                        roundCount++;
                        return;
                    }
                    WhereIsLegal(j-2);
                    if(CzyMoznaWstawic(j-2, rowToInsert)){ruch_bota(j-2);
                        Plansza[j-2][rowToInsert] = AIColor;

                        roundCount++;
                        return;
                    }

                }
                else if(std::regex_search(check_diag1_twos, reg8)){
                    WhereIsLegal(j-3);
                    if(CzyMoznaWstawic(j-3, rowToInsert)){ruch_bota(j-3);
                        Plansza[j-3][rowToInsert] = AIColor;

                        roundCount++;
                        return;
                    }
                    WhereIsLegal(j-1);
                    if(CzyMoznaWstawic(j-1, rowToInsert)){ruch_bota(j-1);
                        Plansza[j-1][rowToInsert] = AIColor;

                        roundCount++;
                        return;
                    }

                }
                else if(std::regex_search(check_diag1_twos, reg9)){
                    WhereIsLegal(j);
                    if(CzyMoznaWstawic(j, rowToInsert)){ruch_bota(j);
                        Plansza[j][rowToInsert] = AIColor;

                        roundCount++;
                        return;
                    }
                    WhereIsLegal(j-2);
                    if(CzyMoznaWstawic(j-2, rowToInsert)){ruch_bota(j-2);
                        Plansza[j-2][rowToInsert] = AIColor;

                        roundCount++;
                        return;
                    }
                }
                else if(std::regex_search(check_diag1_twos, reg10)){
                    WhereIsLegal(j);
                    if(CzyMoznaWstawic(j, rowToInsert)){ruch_bota(j);
                        Plansza[j][rowToInsert] = AIColor;

                        roundCount++;
                        return;
                    }
                    WhereIsLegal(j-3);
                    if(CzyMoznaWstawic(j-3, rowToInsert)){ruch_bota(j-3);
                        Plansza[j-3][rowToInsert] = AIColor;

                        roundCount++;
                        return;
                    }

                }
            }
            j++;
        }
        check_diag1_twos="";
    }


    for(int i=-2; i<4; i++){
        j=i;
        for(int k=5; k>-1; k--){
            if(isColLegal(j)) {
                check_diag_2twos += std::to_string(Plansza[j][k]);
                //std::cout<<check_diag1_twos<<std::endl;
                if(std::regex_search(check_diag_2twos, reg5)){
                    WhereIsLegal(j-1);
                    if(CzyMoznaWstawic(j-1, rowToInsert)){ruch_bota(j-1);
                        Plansza[j-1][rowToInsert] = AIColor;

                        roundCount++;
                        return;
                    }
                    WhereIsLegal(j);
                    if(CzyMoznaWstawic(j, rowToInsert)){ruch_bota(j);
                        Plansza[j][rowToInsert] = AIColor;

                        roundCount++;
                        return;
                    }

                }
                else if(std::regex_search(check_diag_2twos, reg6)){
                    WhereIsLegal(j-2);
                    if(CzyMoznaWstawic(j-2, rowToInsert)) {ruch_bota(j-2);
                        Plansza[j-2][rowToInsert] = AIColor;

                        roundCount++;
                        return;
                    }
                    WhereIsLegal(j-3);
                    if(CzyMoznaWstawic(j-3, rowToInsert)) {ruch_bota(j-3);
                        Plansza[j-3][rowToInsert] = AIColor;

                        roundCount++;
                        return;
                    }

                }
                else if(std::regex_search(check_diag_2twos, reg7)){
                    WhereIsLegal(j-1);
                    if(CzyMoznaWstawic(j-1, rowToInsert)) {ruch_bota(j-1);
                        Plansza[j-1][rowToInsert] = AIColor;

                        roundCount++;
                        return;
                    }
                    WhereIsLegal(j-2);
                    if(CzyMoznaWstawic(j-2, rowToInsert)){ruch_bota(j-2);
                        Plansza[j-2][rowToInsert] = AIColor;

                        roundCount++;
                        return;
                    }

                }
                else if(std::regex_search(check_diag_2twos, reg8)){
                    WhereIsLegal(j-3);
                    if(CzyMoznaWstawic(j-3, rowToInsert)){ruch_bota(j-3);
                        Plansza[j-3][rowToInsert] = AIColor;

                        roundCount++;
                        return;
                    }
                    WhereIsLegal(j-1);
                    if(CzyMoznaWstawic(j-1, rowToInsert)){ruch_bota(j-1);
                        Plansza[j-1][rowToInsert] = AIColor;

                        roundCount++;
                        return;
                    }

                }
                else if(std::regex_search(check_diag_2twos, reg9)){
                    WhereIsLegal(j);
                    if(CzyMoznaWstawic(j, rowToInsert)){ruch_bota(j);
                        Plansza[j][rowToInsert] = AIColor;

                        roundCount++;
                        return;
                    }
                    WhereIsLegal(j-2);
                    if(CzyMoznaWstawic(j-2, rowToInsert)){ruch_bota(j-2);
                        Plansza[j-2][rowToInsert] = AIColor;

                        roundCount++;
                        return;
                    }
                }
                else if(std::regex_search(check_diag_2twos, reg10)){
                    WhereIsLegal(j);
                    if(CzyMoznaWstawic(j, rowToInsert)){ruch_bota(j);
                        Plansza[j][rowToInsert] = AIColor;

                        roundCount++;
                        return;
                    }
                    WhereIsLegal(j-3);
                    if(CzyMoznaWstawic(j-3, rowToInsert)){ruch_bota(j-3);
                        Plansza[j-3][rowToInsert] = AIColor;

                        roundCount++;
                        return;
                    }

                }
            }
            j++;
        }
        check_diag_2twos="";
    }

    //Dwojki przeciwnika w piatkach

    for(int i=0; i<6; i++){
        for(int j=0; j<7; j++){
            check_row_fives += std::to_string(Plansza[j][i]);
            if(std::regex_search(check_row_fives, reg11)){
                WhereIsLegal(j-1);ruch_bota(j-1);
                Plansza[j-1][rowToInsert] = AIColor;

                roundCount++;
                return;
            }
            else if(std::regex_search(check_row_fives, reg12)){
                WhereIsLegal(j-3);ruch_bota(j-3);
                Plansza[j-3][rowToInsert] = AIColor;

                roundCount++;
                return;
            }

        }
        check_row_fives="";
    }







    srand(time(NULL));
    lastPickCol = rand()%7 + 1;
    WhereIsLegal(lastPickCol-1);

    if(isMoveLegal()){ruch_bota(lastPickCol-1);
        Plansza[lastPickCol-1][rowToInsert] = AIColor;

        roundCount++;

    }
    else{
        RuchAI();
    }


}

int Gra::getwiersz_bota(){
return wiersz_bota;
}

int Gra::getkolumna_bota(){
return kolumna_bota;
}



bool Gra::CzyMoznaWstawic(int i, int j) {
    return (Plansza[i][j-1]!=0);
}


void Gra::setgraAI(bool wartosc){
graAI = wartosc;
}

void Gra::ruch_bota(int kolumna){
    setwiersz_kolumna_bota(kolumna);


}
