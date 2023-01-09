//
// Created by Szymon 20.12.2022.
//

#include "Gra.h"
#include <iostream>
#include <sstream>
#include <cstring>
#include <ctime>
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

    roundCount = rand() % 2 + 1;
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

/*void Gra::DrukujPlansze() {
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
}*/

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
