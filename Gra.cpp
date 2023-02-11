
#include "Gra.h"
#include <iostream>
#include <sstream>
#include <cstring>
#include <ctime>
#include <cstdlib>
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

void Gra::WykonajRuch_z_Komputerem() {
    //std::cout << "Tura gracza "<< tokenColor <<" - ktora kolumne wybierasz?";
    //std::cin >> lastPickCol;
    WhereIsLegal(lastPickCol-1);
    if(MoveLegal){
        Plansza[lastPickCol-1][rowToInsert] = PlayerColor;
        roundCount++;
    }
    else{
        //std::cout << "Ten ruch jest nielegalny, wybierz inna kolumne." << std::endl;
        WykonajRuch_z_Komputerem();
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

int Gra::getToken() const{
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
    std::stringstream ss;
    ss<<std::to_string(rundy[numer_gracza]);
    std::string drukuj = ss.str();
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


void Gra::Ruch_Komputera() {
    int j;
    std::string check_col, check_row, check_diag1, check_diag2;
    std::string check_col_twos, check_row_twos, check_diag1_twos, check_diag_2twos;
    std::string check_col_ai, check_row_ai, check_diag1_ai, check_diag2_ai;
    std::string check_row_fives;
    //sprawdzanie trojek
    std::regex reg1a("0222"); std::string reg1a_s("0222");
    std::regex reg2a("2220"); std::string reg2a_s("2220");
    std::regex reg3a("2022"); std::string reg3a_s("2022");
    std::regex reg4a("2202"); std::string reg4a_s("2202");

    std::regex reg1b("0111"); std::string reg1b_s("0111");
    std::regex reg2b("1110"); std::string reg2b_s("1110");
    std::regex reg3b("1011"); std::string reg3b_s("1011");
    std::regex reg4b("1101"); std::string reg4b_s("1101");

    //sprawdzanie dwojek
    std::regex reg5("2200"); std::string reg5_s("2200");
    std::regex reg6("0022"); std::string reg6_s("0022");
    std::regex reg7("2002"); std::string reg7_s("2002");
    std::regex reg8("0202"); std::string reg8_s("0202");
    std::regex reg9("2020"); std::string reg9_s("2020");
    std::regex reg10("0220"); std::string reg10_s("0220");

    //sprawdzanie dwojek w piatkach przeciwnika

    std::regex reg11("01100"); std::string reg11_s("01100");
    std::regex reg12("00110"); std::string reg12_s("00110");




    //Trojki w wierszach

    //ai
    std::cout << "Sprawdzam trojki w wierszach dla AI" << std::endl;
    for(int i=0; i<6; i++){
        for(int j=0; j<7; j++){
            check_row += std::to_string(Plansza[j][i]);
            std::cout << check_row <<std::endl;
            if(std::regex_search(check_row, reg1a)){
                WhereIsLegal(j-3);
                if(MoveLegal){
                    if(CzyMoznaWstawic(j-3-(Ucinanie(check_row, reg1a_s).length()%4), i-1)) {
                        ruch_bota(j-3);
                        return;
                    }
                }
            }
            else if(std::regex_search(check_row, reg2a)){
                WhereIsLegal(j);
                if(MoveLegal){
                    if(CzyMoznaWstawic(j-(Ucinanie(check_row, reg2a_s).length()%4), i-1)) {
                        ruch_bota(j);
                        return;
                    }
                }
            }
            else if(std::regex_search(check_row, reg3a)){
                WhereIsLegal(j-2);
                if(MoveLegal){
                    if(CzyMoznaWstawic(j-2-(Ucinanie(check_row, reg3a_s).length()%4), i-1)) {
                        ruch_bota(j-2);
                        return;
                    }
                }
            }
            else if(std::regex_search(check_row, reg4a)){
                WhereIsLegal(j-1);
                if(MoveLegal){
                    if(CzyMoznaWstawic(j-1-(Ucinanie(check_row, reg4a_s).length()%4), i-1)) {
                        ruch_bota(j-1);
                        return;
                    }
                }
            }

        }
        check_row="";

    }

    //Trojki w kolumnach

    //ai
    std::cout << "Sprawdzam trojki w kolumnach dla AI" << std::endl;
    for(int i=0; i<7; i++){
        for(int j=0; j<6; j++){
            check_col += std::to_string(Plansza[i][j]);
            std::cout<<check_col<<std::endl;
            if(std::regex_search(check_col, reg1a)){
                WhereIsLegal(i);
                if(MoveLegal){
                    ruch_bota(i);
                    return;
                }
            }
            else if(std::regex_search(check_col, reg2a)){
                WhereIsLegal(i);
                if(MoveLegal){
                    ruch_bota(i);
                    return;
                }
            }
            else if(std::regex_search(check_col, reg3a)){
                WhereIsLegal(i);
                if(MoveLegal){
                    ruch_bota(i);
                    return;
                }
            }
            else if(std::regex_search(check_col, reg4a)){
                WhereIsLegal(i);
                if(MoveLegal){
                    ruch_bota(i);
                    return;
                }
            }

        }
        check_col="";
    }

    //Trojki na przekatnych
    //ai
    std::cout << "Sprawdzam trojki na przekatnych LDRU dla AI" << std::endl;
    for(int i = -2; i<4; i++){
        j = i;

        for(int k = 0; k<6; k++){
            if(isColLegal(j)){
                check_diag1 += std::to_string(Plansza[j][k]);
                std::cout << check_diag1 <<std::endl;
                if(std::regex_search(check_diag1, reg1a)){
                    WhereIsLegal(j-3);
                    if(MoveLegal){
                    //std::cout << check_diag1 <<std::endl;
                        if(CzyMoznaWstawic(j-3-(Ucinanie(check_diag1, reg1a_s).length()%4), k-4-(Ucinanie(check_diag1, reg1a_s).length()%4))) {
                            ruch_bota(j-3);
                            return;
                        }
                    }

                }
                else if(std::regex_search(check_diag1, reg2a)){
                    WhereIsLegal(j);
                    if(MoveLegal){
                    //std::cout << check_diag1 <<std::endl;
                        if(CzyMoznaWstawic(j-(Ucinanie(check_diag1, reg2a_s).length()%4), k-1-(Ucinanie(check_diag1, reg2a_s).length()%4))) {
                            ruch_bota(j);
                            return;
                        }
                    }

                }
                else if(std::regex_search(check_diag1, reg3a)){
                    WhereIsLegal(j-2);
                    if(MoveLegal){
                    //std::cout << check_diag1 <<std::endl;
                        if(CzyMoznaWstawic(j-2-(Ucinanie(check_diag1, reg3a_s).length()%4), k-3-(Ucinanie(check_diag1, reg3a_s).length()%4))) {
                            ruch_bota(j-2);
                            return;
                        }
                    }

                }
                else if(std::regex_search(check_diag1, reg4a)){
                    WhereIsLegal(j-1);
                    if(MoveLegal){
                    //std::cout << check_diag1 <<std::endl;
                        if(CzyMoznaWstawic(j-1-(Ucinanie(check_diag1, reg4a_s).length()%4), k-2-(Ucinanie(check_diag1, reg4a_s).length()%4))) {
                            ruch_bota(j-1);
                            return;
                        }
                    }
                    //check="";
                }
            }
            j++;
        }
        check_diag1="";
    }

    //ai
    std::cout << "Sprawdzam trojki na przekatnych LURD dla AI" << std::endl;
    for(int i = -2; i<4; i++){
        j = i;
        for(int k = 5; k>-1; k--){
            if(isColLegal(j)){
                check_diag2 += std::to_string(Plansza[j][k]);
                std::cout << check_diag2 <<std::endl;
                if(std::regex_search(check_diag2, reg1a)){
                    WhereIsLegal(j-3);
                    if(MoveLegal){
                        if(CzyMoznaWstawic(j-3-(Ucinanie(check_diag2, reg1a_s).length()%4), k+2+(Ucinanie(check_diag2, reg1a_s).length()%4))) {
                            ruch_bota(j-3);
                            return;
                        }
                    }

                }
                else if(std::regex_search(check_diag2, reg2a)){
                    WhereIsLegal(j);
                    if(MoveLegal){
                        if(CzyMoznaWstawic(j-(Ucinanie(check_diag2, reg2a_s).length()%4), k-1+(Ucinanie(check_diag2, reg2a_s).length()%4))) {
                            ruch_bota(j);
                            return;
                        }
                    }

                }
                else if(std::regex_search(check_diag2, reg3a)){
                    WhereIsLegal(j-2);
                    if(MoveLegal){
                        if(CzyMoznaWstawic(j-2-(Ucinanie(check_diag2, reg3a_s).length()%4), k+1+(Ucinanie(check_diag2, reg3a_s).length()%4))) {
                            ruch_bota(j-2);
                            return;
                        }
                    }

                }
                else if(std::regex_search(check_diag2, reg4a)){
                    WhereIsLegal(j-1);
                    if(MoveLegal){
                        if(CzyMoznaWstawic(j-1-(Ucinanie(check_diag2, reg4a_s).length()%4), k+(Ucinanie(check_diag2, reg4a_s).length()%4))) {
                            ruch_bota(j-1);
                            return;
                        }
                    }

                }
            }
            j++;
        }
        check_diag2="";
    }

    //Trojki w wierszach

    //gracz
    std::cout << "Sprawdzam trojki w wierszach dla gracza" << std::endl;
    for(int i=0; i<6; i++){
        for(int j=0; j<7; j++){
            check_row_ai += std::to_string(Plansza[j][i]);
            std::cout << check_row_ai <<std::endl;
            if(std::regex_search(check_row_ai, reg1b)){
                WhereIsLegal(j-3);
                if(MoveLegal){
                    if(CzyMoznaWstawic(j-3-(Ucinanie(check_row_ai, reg1b_s).length()%4), i-1)) {
                        ruch_bota(j-3);
                        return;
                    }
                }
            }
            else if(std::regex_search(check_row_ai, reg2b)){
                WhereIsLegal(j);
                if(MoveLegal){
                    if(CzyMoznaWstawic(j-(Ucinanie(check_row_ai, reg2b_s).length()%4), i-1)) {
                        ruch_bota(j);
                        return;
                    }
                }
            }
            else if(std::regex_search(check_row_ai, reg3b)){
                WhereIsLegal(j-2);
                if(MoveLegal){
                    if(CzyMoznaWstawic(j-2-(Ucinanie(check_row_ai, reg3b_s).length()%4), i-1)) {
                        ruch_bota(j-2);
                        return;
                    }
                }
            }
            else if(std::regex_search(check_row_ai, reg4b)){
                WhereIsLegal(j-1);
                if(MoveLegal){
                    if(CzyMoznaWstawic(j-1-(Ucinanie(check_row_ai, reg4b_s).length()%4), i-1)) {
                        ruch_bota(j-1);
                        return;
                    }
                }
            }

        }
        check_row_ai="";

    }

    //Trojki w kolumnach

    //gracz
    std::cout << "Sprawdzam trojki w kolumnach dla gracza" << std::endl;
    for(int i=0; i<7; i++){
        for(int j=0; j<6; j++){
            check_col_ai += std::to_string(Plansza[i][j]);
            std::cout<<check_col_ai<<std::endl;
            if(std::regex_search(check_col_ai, reg1b)){
                WhereIsLegal(i);
                if(MoveLegal){
                    ruch_bota(i);
                    return;
                }
            }
            else if(std::regex_search(check_col_ai, reg2b)){
                WhereIsLegal(i);
                if(MoveLegal){
                    ruch_bota(i);
                    return;
                }
            }
            else if(std::regex_search(check_col_ai, reg3b)){
                WhereIsLegal(i);
                if(MoveLegal){
                    ruch_bota(i);
                    return;
                }
            }
            else if(std::regex_search(check_col_ai, reg4b)){
                WhereIsLegal(i);
                if(MoveLegal){
                    ruch_bota(i);
                    return;
                }
            }

        }
        check_col_ai="";
    }

    //Trojki na przekatnych

    //gracz
    std::cout << "Sprawdzam trojki na przekatnych LDRU dla gracza" << std::endl;
    for(int i = -2; i<4; i++){
        j = i;

        for(int k = 0; k<6; k++){
            if(isColLegal(j)){
                check_diag1_ai += std::to_string(Plansza[j][k]);
                std::cout << check_diag1_ai <<std::endl;
                if(std::regex_search(check_diag1_ai, reg1b)){
                    WhereIsLegal(j-3);
                    if(MoveLegal){
                    //std::cout << check_diag1 <<std::endl;
                        if(CzyMoznaWstawic(j-3-(Ucinanie(check_diag1_ai, reg1b_s).length()%4), k-4-(Ucinanie(check_diag1_ai, reg1b_s).length()%4))) {
                            ruch_bota(j-3);
                            return;
                        }
                    }

                }
                else if(std::regex_search(check_diag1_ai, reg2b)){
                    WhereIsLegal(j);
                    if(MoveLegal){
                    //std::cout << check_diag1 <<std::endl;
                        if(CzyMoznaWstawic(j-(Ucinanie(check_diag1_ai, reg2b_s).length()%4), k-1-(Ucinanie(check_diag1_ai, reg2b_s).length()%4))) {
                            ruch_bota(j);
                            return;
                        }
                    }

                }
                else if(std::regex_search(check_diag1_ai, reg3b)){
                    WhereIsLegal(j-2);
                    if(MoveLegal){
                    //std::cout << check_diag1 <<std::endl;
                        if(CzyMoznaWstawic(j-2-(Ucinanie(check_diag1_ai, reg3b_s).length()%4), k-3-(Ucinanie(check_diag1_ai, reg3b_s).length()%4))) {
                            ruch_bota(j-2);
                            return;
                        }
                    }
                }
                else if(std::regex_search(check_diag1_ai, reg4b)){
                    WhereIsLegal(j-1);
                    if(MoveLegal){
                    //std::cout << check_diag1 <<std::endl;
                        if(CzyMoznaWstawic(j-1-(Ucinanie(check_diag1_ai, reg4b_s).length()%4), k-2-(Ucinanie(check_diag1_ai, reg4b_s).length()%4))) {
                            ruch_bota(j-1);
                            return;
                        }
                    }
                }
            }
            j++;
        }
        check_diag1_ai="";
    }

    //gracz
    std::cout << "Sprawdzam trojki na przekatnych LURD dla gracza" << std::endl;
    for(int i = -2; i<4; i++){
        j = i;
        for(int k = 5; k>-1; k--){
            if(isColLegal(j)){
                check_diag2_ai += std::to_string(Plansza[j][k]);
                std::cout << check_diag2_ai <<std::endl;
                if(std::regex_search(check_diag2_ai, reg1b)){
                    WhereIsLegal(j-3);
                    if(MoveLegal){
                        if(CzyMoznaWstawic(j-3-(Ucinanie(check_diag2_ai, reg1b_s).length()%4), k+2+(Ucinanie(check_diag2_ai, reg1b_s).length()%4))) {
                            ruch_bota(j-3);
                            return;
                        }
                    }
                }
                else if(std::regex_search(check_diag2_ai, reg2b)){
                    WhereIsLegal(j);
                    if(MoveLegal){
                        if(CzyMoznaWstawic(j-(Ucinanie(check_diag2_ai, reg2b_s).length()%4), k-1+(Ucinanie(check_diag2_ai, reg2b_s).length()%4))) {
                            ruch_bota(j);
                            return;
                        }
                    }

                }
                else if(std::regex_search(check_diag2_ai, reg3b)){
                    WhereIsLegal(j-2);
                    if(MoveLegal){
                        if(CzyMoznaWstawic(j-2-(Ucinanie(check_diag2_ai, reg3b_s).length()%4), k+1+(Ucinanie(check_diag2_ai, reg3b_s).length()%4))) {
                            ruch_bota(j-2);
                            return;
                        }
                    }
                }
                else if(std::regex_search(check_diag2_ai, reg4b)){
                    WhereIsLegal(j-1);
                    if(MoveLegal){
                        if(CzyMoznaWstawic(j-1-(Ucinanie(check_diag2_ai, reg4b_s).length()%4), k+(Ucinanie(check_diag2_ai, reg4b_s).length()%4))) {
                            ruch_bota(j-1);
                            return;
                        }
                    }
                }
            }
            j++;
        }
        check_diag2_ai="";
    }

    //Dwojki w wierszach
    std::cout << "Sprawdzam dwojki w wierszach dla AI" << std::endl;
    for(int i=0; i<6; i++){
        for(int j=0; j<7; j++){
            check_row_twos += std::to_string(Plansza[j][i]);
            std::cout<<check_row_twos<<std::endl;
            if(std::regex_search(check_row_twos, reg5)){
                WhereIsLegal(j);
                if(MoveLegal){
                    if(CzyMoznaWstawic(j-(Ucinanie(check_row_twos, reg5_s).length()%4), i-1)){
                        ruch_bota(j);
                        return;
                    }
                }
                WhereIsLegal(j-1);
                if(MoveLegal){
                    if(CzyMoznaWstawic(j-1-(Ucinanie(check_row_twos, reg5_s).length()%4), i-1)){
                        ruch_bota(j-1);
                        return;
                    }
                }
            }
            else if(std::regex_search(check_row_twos, reg6)){
                WhereIsLegal(j-2);
                if(MoveLegal){
                    if(CzyMoznaWstawic(j-2-(Ucinanie(check_row_twos, reg6_s).length()%4), i-1)){
                        ruch_bota(j-2);
                        return;
                    }
                }
                WhereIsLegal(j-3);
                if(MoveLegal){
                    if(CzyMoznaWstawic(j-3-(Ucinanie(check_row_twos, reg6_s).length()%4), i-1)){
                        ruch_bota(j-3);
                        return;
                    }
                }
            }
            else if(std::regex_search(check_row_twos, reg7)){

                WhereIsLegal(j-2);
                if(MoveLegal){
                    if(CzyMoznaWstawic(j-2-(Ucinanie(check_row_twos, reg7_s).length()%4), i-1)){
                        ruch_bota(j-2);
                        return;
                    }
                }
                WhereIsLegal(j-1);
                if(MoveLegal){
                    if(CzyMoznaWstawic(j-1-(Ucinanie(check_row_twos, reg7_s).length()%4), i-1)){
                        ruch_bota(j-1);
                        return;
                    }
                }
            }
            else if(std::regex_search(check_row_twos, reg8)){

                WhereIsLegal(j-1);
                if(MoveLegal){
                    if(CzyMoznaWstawic(j-1-(Ucinanie(check_row_twos, reg8_s).length()%4), i-1)){
                        ruch_bota(j-1);
                        return;
                    }
                }
                WhereIsLegal(j-3);
                if(MoveLegal){
                    if(CzyMoznaWstawic(j-3-(Ucinanie(check_row_twos, reg8_s).length()%4), i-1)){
                        ruch_bota(j-3);
                        return;
                    }
                }
            }
            else if(std::regex_search(check_row_twos, reg9)){

                WhereIsLegal(j-2);
                if(MoveLegal){
                    if(CzyMoznaWstawic(j-2-(Ucinanie(check_row_twos, reg9_s).length()%4), i-1)){
                        ruch_bota(j-2);
                        return;
                    }
                }
                WhereIsLegal(j);
                if(MoveLegal){
                    if(CzyMoznaWstawic(j-(Ucinanie(check_row_twos, reg9_s).length()%4), i-1)){
                        ruch_bota(j);
                        return;
                    }
                }
            }
            else if(std::regex_search(check_row_twos, reg10)){
                WhereIsLegal(j);
                if(MoveLegal){
                    if(CzyMoznaWstawic(j-(Ucinanie(check_row_twos, reg10_s).length()%4), i-1)) {
                        ruch_bota(j);
                        return;
                    }
                }
                WhereIsLegal(j-3);
                if(MoveLegal){
                    if(CzyMoznaWstawic(j-3-(Ucinanie(check_row_twos, reg10_s).length()%4), i-1)){
                        ruch_bota(j-3);
                        return;
                    }
                }
            }

        }
        check_row_twos="";
    }

    //Dwojki w kolumnach
    std::cout << "Sprawdzam dwojki w kolumnach dla AI" << std::endl;
    for(int i=0; i<7; i++){
        for(int j=0; j<6; j++){
            check_col_twos += std::to_string(Plansza[i][j]);
            std::cout<<check_col_twos<<std::endl;
            if(std::regex_search(check_col_twos, reg5)){
                WhereIsLegal(i);
                if(MoveLegal){
                    ruch_bota(i);
                    return;
                }
            }
            else if(std::regex_search(check_col_twos, reg6)){
                WhereIsLegal(i);
                if(MoveLegal){
                    ruch_bota(i);
                    return;
                }
            }
            else if(std::regex_search(check_col_twos, reg7)){
                WhereIsLegal(i);
                if(MoveLegal){
                    ruch_bota(i);
                    return;
                }
            }
            else if(std::regex_search(check_col_twos, reg8)){
                WhereIsLegal(i);
                if(MoveLegal){
                    ruch_bota(i);
                    return;
                }
            }
            else if(std::regex_search(check_col_twos, reg9)){
                WhereIsLegal(i);
                if(MoveLegal){
                    ruch_bota(i);
                    return;
                }
            }
            else if(std::regex_search(check_col_twos, reg10)){
                WhereIsLegal(i);
                if(MoveLegal){
                    ruch_bota(i);
                    return;
                }
            }

        }
        check_col_twos="";
    }

    //Dwojki na przekatnych
    std::cout << "Sprawdzam dwojki na przekatnych LDRU dla AI" << std::endl;
    for(int i=-2; i<4; i++){
        j=i;
        for(int k=0; k<6; k++){
            if(isColLegal(j)) {
                check_diag1_twos += std::to_string(Plansza[j][k]);
                std::cout<<check_diag1_twos<<std::endl;
                if(std::regex_search(check_diag1_twos, reg5)){
                    WhereIsLegal(j-1);
                    if(MoveLegal){
                        if(CzyMoznaWstawic(j-1-(Ucinanie(check_diag1_twos, reg5_s).length()%4), k-2-(Ucinanie(check_diag1_twos, reg5_s).length()%4))){
                            ruch_bota(j-1);
                            return;
                        }
                    }
                    WhereIsLegal(j);
                    if(MoveLegal){
                        if(CzyMoznaWstawic(j-(Ucinanie(check_diag1_twos, reg5_s).length()%4), k-1-(Ucinanie(check_diag1_twos, reg5_s).length()%4))){
                            ruch_bota(j);
                            return;
                        }
                    }
                }
                else if(std::regex_search(check_diag1_twos, reg6)){
                    WhereIsLegal(j-2);
                    if(MoveLegal){
                        if(CzyMoznaWstawic(j-2-(Ucinanie(check_diag1_twos, reg6_s).length()%4), k-3-(Ucinanie(check_diag1_twos, reg6_s).length()%4))) {
                            ruch_bota(j-2);
                            return;
                        }
                    }
                    WhereIsLegal(j-3);
                    if(MoveLegal){
                        if(CzyMoznaWstawic(j-3-(Ucinanie(check_diag1_twos, reg6_s).length()%4), k-4-(Ucinanie(check_diag1_twos, reg6_s).length()%4))) {
                            ruch_bota(j-3);
                            return;
                        }
                    }
                }
                else if(std::regex_search(check_diag1_twos, reg7)){
                    WhereIsLegal(j-1);
                    if(MoveLegal){
                        if(CzyMoznaWstawic(j-1-(Ucinanie(check_diag1_twos, reg7_s).length()%4), k-2-(Ucinanie(check_diag1_twos, reg7_s).length()%4))) {
                            ruch_bota(j-1);
                            return;
                        }
                    }
                    WhereIsLegal(j-2);
                    if(MoveLegal){
                        if(CzyMoznaWstawic(j-2-(Ucinanie(check_diag1_twos, reg7_s).length()%4), k-3-(Ucinanie(check_diag1_twos, reg7_s).length()%4))){
                            ruch_bota(j-2);
                            return;
                        }
                    }
                }
                else if(std::regex_search(check_diag1_twos, reg8)){
                    WhereIsLegal(j-3);
                    if(MoveLegal){
                        if(CzyMoznaWstawic(j-3-(Ucinanie(check_diag1_twos, reg8_s).length()%4), k-4-(Ucinanie(check_diag1_twos, reg8_s).length()%4))){
                            ruch_bota(j-3);
                            return;
                        }
                    }
                    WhereIsLegal(j-1);
                    if(MoveLegal){
                        if(CzyMoznaWstawic(j-1-(Ucinanie(check_diag1_twos, reg8_s).length()%4), k-2-(Ucinanie(check_diag1_twos, reg8_s).length()%4))){
                            ruch_bota(j-1);
                            return;
                        }
                    }
                }
                else if(std::regex_search(check_diag1_twos, reg9)){
                    WhereIsLegal(j);
                    if(MoveLegal){
                        if(CzyMoznaWstawic(j-(Ucinanie(check_diag1_twos, reg9_s).length()%4), k-1-(Ucinanie(check_diag1_twos, reg9_s).length()%4))){
                            ruch_bota(j);
                            return;
                        }
                    }
                    WhereIsLegal(j-2);
                    if(MoveLegal){
                        if(CzyMoznaWstawic(j-2-(Ucinanie(check_diag1_twos, reg9_s).length()%4), k-3-(Ucinanie(check_diag1_twos, reg9_s).length()%4))){
                            ruch_bota(j-2);
                            return;
                        }
                    }
                }
                else if(std::regex_search(check_diag1_twos, reg10)){
                    WhereIsLegal(j);
                    if(MoveLegal){
                        if(CzyMoznaWstawic(j-(Ucinanie(check_diag1_twos, reg10_s).length()%4), k-1-(Ucinanie(check_diag1_twos, reg10_s).length()%4))){
                            ruch_bota(j);
                            return;
                        }
                    }
                    WhereIsLegal(j-3);
                    if(MoveLegal){
                        if(CzyMoznaWstawic(j-3-(Ucinanie(check_diag1_twos, reg10_s).length()%4), k-4-(Ucinanie(check_diag1_twos, reg10_s).length()%4))){
                            ruch_bota(j-3);
                            return;
                        }
                    }
                }
            }
            j++;
        }
        check_diag1_twos="";
    }

    std::cout << "Sprawdzam dwojki na przekatnych LURD dla AI" << std::endl;
    for(int i=-2; i<4; i++){
        j=i;
        for(int k=5; k>-1; k--){
            if(isColLegal(j)) {
                check_diag_2twos += std::to_string(Plansza[j][k]);
                std::cout<<check_diag_2twos<<std::endl;
                if(std::regex_search(check_diag_2twos, reg5)){
                    WhereIsLegal(j-1);
                    if(MoveLegal){
                        if(CzyMoznaWstawic(j-1-(Ucinanie(check_diag_2twos, reg5_s).length()%4), k+(Ucinanie(check_diag_2twos, reg5_s).length()%4))){
                            ruch_bota(j-1);
                            return;
                        }
                    }
                    WhereIsLegal(j);
                    if(MoveLegal){
                        if(CzyMoznaWstawic(j-(Ucinanie(check_diag_2twos, reg5_s).length()%4), k+1+(Ucinanie(check_diag_2twos, reg5_s).length()%4))){
                            ruch_bota(j);
                            return;
                        }
                    }
                }
                else if(std::regex_search(check_diag_2twos, reg6)){
                    WhereIsLegal(j-2);
                    if(MoveLegal){
                        if(CzyMoznaWstawic(j-2-(Ucinanie(check_diag_2twos, reg6_s).length()%4), k+1+(Ucinanie(check_diag_2twos, reg6_s).length()%4))) {
                            ruch_bota(j-2);
                            return;
                        }
                    }
                    WhereIsLegal(j-3);
                    if(MoveLegal){
                        if(CzyMoznaWstawic(j-3-(Ucinanie(check_diag_2twos, reg6_s).length()%4), k+2+(Ucinanie(check_diag_2twos, reg6_s).length()%4))) {
                            ruch_bota(j-3);
                            return;
                        }
                    }
                }
                else if(std::regex_search(check_diag_2twos, reg7)){
                    WhereIsLegal(j-1);
                    if(MoveLegal){
                        if(CzyMoznaWstawic(j-1-(Ucinanie(check_diag_2twos, reg7_s).length()%4), k+(Ucinanie(check_diag_2twos, reg7_s).length()%4))) {
                            ruch_bota(j-1);
                            return;
                        }
                    }
                    WhereIsLegal(j-2);
                    if(MoveLegal){
                        if(CzyMoznaWstawic(j-2-(Ucinanie(check_diag_2twos, reg7_s).length()%4), k+1+(Ucinanie(check_diag_2twos, reg7_s).length()%4))){
                            ruch_bota(j-2);
                            return;
                        }
                    }
                }
                else if(std::regex_search(check_diag_2twos, reg8)){
                    WhereIsLegal(j-3);
                    if(MoveLegal){
                        if(CzyMoznaWstawic(j-3-(Ucinanie(check_diag_2twos, reg8_s).length()%4), k+2+(Ucinanie(check_diag_2twos, reg8_s).length()%4))){
                            ruch_bota(j-3);
                            return;
                        }
                    }
                    WhereIsLegal(j-1);
                    if(MoveLegal){
                        if(CzyMoznaWstawic(j-1-(Ucinanie(check_diag_2twos, reg8_s).length()%4), k+(Ucinanie(check_diag_2twos, reg8_s).length()%4))){
                            ruch_bota(j-1);
                            return;
                        }
                    }
                }
                else if(std::regex_search(check_diag_2twos, reg9)){
                    WhereIsLegal(j);
                    if(MoveLegal){
                        if(CzyMoznaWstawic(j-(Ucinanie(check_diag_2twos, reg9_s).length()%4), k-1+(Ucinanie(check_diag_2twos, reg9_s).length()%4))){
                            ruch_bota(j);
                            return;
                        }
                    }
                    WhereIsLegal(j-2);
                    if(MoveLegal){
                        if(CzyMoznaWstawic(j-2-(Ucinanie(check_diag_2twos, reg9_s).length()%4), k+1+(Ucinanie(check_diag_2twos, reg9_s).length()%4))){
                            ruch_bota(j-2);
                            return;
                        }
                    }
                }
                else if(std::regex_search(check_diag_2twos, reg10)){
                    WhereIsLegal(j);
                    if(MoveLegal){
                        if(CzyMoznaWstawic(j-(Ucinanie(check_diag_2twos, reg10_s).length()%4), k-1+(Ucinanie(check_diag_2twos, reg10_s).length()%4))){
                            ruch_bota(j);
                            return;
                        }
                    }
                    WhereIsLegal(j-3);
                    if(MoveLegal){
                        if(CzyMoznaWstawic(j-3-(Ucinanie(check_diag_2twos, reg10_s).length()%4), k+2+(Ucinanie(check_diag_2twos, reg10_s).length()%4))){
                            ruch_bota(j-3);
                            return;
                        }
                    }
                }
            }
            j++;
        }
        check_diag_2twos="";
    }

    //Dwojki przeciwnika w piatkach
    std::cout << "Sprawdzam dwojki w piatkach w wierszach dla AI" << std::endl;
    for(int i=0; i<6; i++){
        for(int j=0; j<7; j++){
            check_row_fives += std::to_string(Plansza[j][i]);
            std::cout << check_row_fives <<std::endl;
            if(std::regex_search(check_row_fives, reg11)){
                WhereIsLegal(j-1);
                if(MoveLegal){
                    if(CzyMoznaWstawic(j-1-(Ucinanie(check_row_fives, reg11_s).length()%4), i-1)) {
                        ruch_bota(j-1);
                        return;
                    }
                }
            }
            else if(std::regex_search(check_row_fives, reg12)){
                WhereIsLegal(j-3);
                if(MoveLegal){
                    if(CzyMoznaWstawic(j-3-(Ucinanie(check_row_fives, reg12_s).length()%4), i-1)) {
                        ruch_bota(j-3);
                        return;
                    }
                }
            }

        }
        check_row_fives="";
    }


    srand(time(NULL));
    lastPickCol = rand()%7 + 1;
    WhereIsLegal(lastPickCol-1);


    if(MoveLegal){
        ruch_bota(lastPickCol-1);
        std::cout << "Losowy ruch" << std::endl;
    }
    else{
        Ruch_Komputera();
    }


}

int Gra::getwiersz_bota(){
return wiersz_bota;
}

int Gra::getkolumna_bota(){
return kolumna_bota;
}



bool Gra::CzyMoznaWstawic(int i, int j) {
    return (Plansza[i][j]!=0);
}


void Gra::setgraAI(bool wartosc){
graAI = wartosc;
}

void Gra::ruch_bota(int kolumna){
    setwiersz_kolumna_bota(kolumna);
	Plansza[kolumna][rowToInsert] = AIColor;
        roundCount++;

}

std::string Gra::Ucinanie(std::string check, std::string reg){
    return check.substr(check.find(reg));
}
