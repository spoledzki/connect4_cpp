

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
    int DrukujPlansze(int numer_kolumny, int numer_wiersza);
    void WykonajRuch();
    void WykonajRuch_z_Komputerem();
    bool CheckCols();
    bool CheckRows();
    bool CheckDiags();
    bool CheckDiagsLDRU();
    bool CheckDiagsLURD();
    int getToken() const;
    int gettokenColor();
    int getroundCount();
    void koniec_rund();
    void setLastPickCol(int kolumna);
    std::string rundy_graczy(int numer_gracza);
    void ending();
    std::string getKomunikat();
    void Ruch_Komputera();
    bool CzyMoznaWstawic(int i, int j);
    void setgraAI(bool wartosc);
    void setwiersz_kolumna_bota(int kolumna);
    int getwiersz_bota();
    int getkolumna_bota();
    void ruch_bota(int kolumna);
    std::string Ucinanie(std::string check, std::string reg);

private:
    std::string komunikat;
    int **Plansza;
    int gameCols = 7;
    int gameRows = 6;
    int tokenColor = 0;
    bool MoveLegal = false;
    int rowToInsert = 0;
    int roundCount = 0;
    int lastPickCol = 0;
    bool isGameOver = false;
    int winningToken = 0;
    int liczba_rund;
    int rundy[2];
    int PlayerColor = 1;
    int AIColor = 2;
    bool graAI;
    int wiersz_bota;
    int kolumna_bota;
};


#endif //CONNECT4_GRA_H
