//
// Created by Szymon on 20.12.2022.
//

#ifndef CONNECT4_GRA_H
#define CONNECT4_GRA_H

#include <iostream>
#include <regex>
#include <string>
#include <sstream>

class Gra {
public:
    Gra();
    ~Gra();
    bool isColLegal(int k);
    bool isRowLegal(int w);
    bool isMoveLegal();
    void WhereIsLegal(int k);
    bool Rezultat();
    //void DrukujPlansze();
    void WykonajRuch();
    bool CheckCols();
    bool CheckRows();
    bool CheckDiags();
    bool CheckDiagsLDRU();
    bool CheckDiagsLURD();
    int getToken() const;
    int gettokenColor();
    void setLastPickCol(int kolumna);
    void ending();
    std::string getKomunikat();

private:
    std::string komunikat;
    int **Plansza;
    int gameCols = 7;
    int gameRows = 6;
    int tokenColor = 0;
    bool MoveLegal = false;
    int rowToInsert = 0;
    int roundCount = 1;
    int lastPickCol = 0;
    bool isGameOver = false;
    int winningToken = 0;
};


#endif //CONNECT4_GRA_H
