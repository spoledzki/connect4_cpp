/***************************************************************
 * Name:      connect_fourMain.h
 * Purpose:   Deklaracje funkcji projektu connect_four.cpp
 * Author:    Igor Nowiński, Szymon Olędzki, Tymoteusz Romanowicz
 * Created:   2022-12-14
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef CONNECT_FOURMAIN_H
#define CONNECT_FOURMAIN_H
#undef _
#define _(s) wxString::FromUTF8(s)

#include <string>
//(*Headers(connect_fourDialog)
#include <wx/bmpbuttn.h>
#include <wx/checkbox.h>
#include <wx/choice.h>
#include <wx/dialog.h>
#include <wx/radiobut.h>
#include <wx/sizer.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>
//*)

class connect_fourDialog: public wxDialog
{
    public:

        connect_fourDialog(wxWindow* parent,wxWindowID id = -1);
        virtual ~connect_fourDialog();
        void czyszczenie_rysunkow();
        void koniec_gry();
        void przycisk(int kolumna);
        void przycisk_AI(int kolumna);
        void SetLiczbaRund(int rundy);
        void koniec_meczu(int gracz_1, int gracz_2);
        void update();
        void debugging();

    private:

        //(*Handlers(connect_fourDialog)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnBitmapButton1Click(wxCommandEvent& event);
        void OnBitmapButton43Click(wxCommandEvent& event);
        void OnBitmapButton44Click(wxCommandEvent& event);
        void OnBitmapButton45Click(wxCommandEvent& event);
        void OnBitmapButton46Click(wxCommandEvent& event);
        void OnBitmapButton47Click(wxCommandEvent& event);
        void OnBitmapButton48Click(wxCommandEvent& event);
        void OnBitmapButton49Click(wxCommandEvent& event);
        void OnBitmapButton2Click(wxCommandEvent& event);
        void OnBitmapButton3Click(wxCommandEvent& event);
        void OnBitmapButton4Click(wxCommandEvent& event);
        void OnBitmapButton5Click(wxCommandEvent& event);
        void OnBitmapButton6Click(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnButton3Click(wxCommandEvent& event);
        void OnBitmapButton51Click(wxCommandEvent& event);
        void OnBitmapButton50Click(wxCommandEvent& event);
        void OnBitmapButton52Click(wxCommandEvent& event);
        void OnBitmapButton53Click(wxCommandEvent& event);
        void OnCheckBox1Click(wxCommandEvent& event);
        void OnChoice1Select(wxCommandEvent& event);
        void OnRadioButton1Select(wxCommandEvent& event);
        void OnRadioButton2Select(wxCommandEvent& event);
        //*)

        //(*Identifiers(connect_fourDialog)
        static const long ID_STATICBITMAP1;
        static const long ID_BITMAPBUTTON7;
        static const long ID_BITMAPBUTTON8;
        static const long ID_BITMAPBUTTON9;
        static const long ID_BITMAPBUTTON10;
        static const long ID_BITMAPBUTTON11;
        static const long ID_BITMAPBUTTON12;
        static const long ID_BITMAPBUTTON13;
        static const long ID_BITMAPBUTTON14;
        static const long ID_BITMAPBUTTON15;
        static const long ID_BITMAPBUTTON16;
        static const long ID_BITMAPBUTTON17;
        static const long ID_BITMAPBUTTON18;
        static const long ID_BITMAPBUTTON19;
        static const long ID_BITMAPBUTTON20;
        static const long ID_BITMAPBUTTON21;
        static const long ID_BITMAPBUTTON22;
        static const long ID_BITMAPBUTTON23;
        static const long ID_BITMAPBUTTON24;
        static const long ID_BITMAPBUTTON25;
        static const long ID_BITMAPBUTTON26;
        static const long ID_BITMAPBUTTON27;
        static const long ID_BITMAPBUTTON28;
        static const long ID_BITMAPBUTTON29;
        static const long ID_BITMAPBUTTON30;
        static const long ID_BITMAPBUTTON31;
        static const long ID_BITMAPBUTTON32;
        static const long ID_BITMAPBUTTON33;
        static const long ID_BITMAPBUTTON34;
        static const long ID_BITMAPBUTTON35;
        static const long ID_BITMAPBUTTON36;
        static const long ID_BITMAPBUTTON37;
        static const long ID_BITMAPBUTTON38;
        static const long ID_BITMAPBUTTON39;
        static const long ID_BITMAPBUTTON40;
        static const long ID_BITMAPBUTTON41;
        static const long ID_BITMAPBUTTON42;
        static const long ID_BITMAPBUTTON43;
        static const long ID_BITMAPBUTTON44;
        static const long ID_BITMAPBUTTON45;
        static const long ID_BITMAPBUTTON46;
        static const long ID_BITMAPBUTTON47;
        static const long ID_BITMAPBUTTON48;
        static const long ID_BITMAPBUTTON1;
        static const long ID_BITMAPBUTTON2;
        static const long ID_BITMAPBUTTON3;
        static const long ID_BITMAPBUTTON4;
        static const long ID_BITMAPBUTTON5;
        static const long ID_BITMAPBUTTON6;
        static const long ID_BITMAPBUTTON49;
        static const long ID_BITMAPBUTTON51;
        static const long ID_BITMAPBUTTON52;
        static const long ID_STATICTEXT7;
        static const long ID_RADIOBUTTON1;
        static const long ID_RADIOBUTTON2;
        static const long ID_STATICTEXT8;
        static const long ID_STATICTEXT14;
        static const long ID_STATICTEXT13;
        static const long ID_STATICTEXT12;
        static const long ID_STATICTEXT11;
        static const long ID_STATICTEXT10;
        static const long ID_STATICTEXT9;
        static const long ID_STATICTEXT21;
        static const long ID_STATICTEXT20;
        static const long ID_STATICTEXT19;
        static const long ID_STATICTEXT18;
        static const long ID_STATICTEXT17;
        static const long ID_STATICTEXT16;
        static const long ID_STATICTEXT28;
        static const long ID_STATICTEXT27;
        static const long ID_STATICTEXT26;
        static const long ID_STATICTEXT25;
        static const long ID_STATICTEXT24;
        static const long ID_STATICTEXT23;
        static const long ID_STATICTEXT35;
        static const long ID_STATICTEXT34;
        static const long ID_STATICTEXT33;
        static const long ID_STATICTEXT32;
        static const long ID_STATICTEXT31;
        static const long ID_STATICTEXT30;
        static const long ID_STATICTEXT42;
        static const long ID_STATICTEXT41;
        static const long ID_STATICTEXT40;
        static const long ID_STATICTEXT39;
        static const long ID_STATICTEXT38;
        static const long ID_STATICTEXT37;
        static const long ID_STATICTEXT49;
        static const long ID_STATICTEXT48;
        static const long ID_STATICTEXT47;
        static const long ID_STATICTEXT46;
        static const long ID_STATICTEXT45;
        static const long ID_STATICTEXT44;
        static const long ID_STATICTEXT22;
        static const long ID_STATICTEXT15;
        static const long ID_STATICTEXT54;
        static const long ID_STATICTEXT53;
        static const long ID_STATICTEXT52;
        static const long ID_STATICTEXT51;
        static const long ID_STATICTEXT2;
        static const long ID_BITMAPBUTTON53;
        static const long ID_CHECKBOX1;
        static const long ID_STATICTEXT6;
        static const long ID_CHOICE1;
        static const long ID_BITMAPBUTTON54;
        static const long ID_STATICTEXT3;
        static const long ID_STATICTEXT4;
        static const long ID_STATICTEXT5;
        static const long ID_BITMAPBUTTON55;
        static const long ID_BITMAPBUTTON50;
        //*)

        //(*Declarations(connect_fourDialog)
        wxBitmapButton* BitmapButton10;
        wxBitmapButton* BitmapButton11;
        wxBitmapButton* BitmapButton12;
        wxBitmapButton* BitmapButton13;
        wxBitmapButton* BitmapButton14;
        wxBitmapButton* BitmapButton15;
        wxBitmapButton* BitmapButton16;
        wxBitmapButton* BitmapButton17;
        wxBitmapButton* BitmapButton18;
        wxBitmapButton* BitmapButton19;
        wxBitmapButton* BitmapButton1;
        wxBitmapButton* BitmapButton20;
        wxBitmapButton* BitmapButton21;
        wxBitmapButton* BitmapButton22;
        wxBitmapButton* BitmapButton23;
        wxBitmapButton* BitmapButton24;
        wxBitmapButton* BitmapButton25;
        wxBitmapButton* BitmapButton26;
        wxBitmapButton* BitmapButton27;
        wxBitmapButton* BitmapButton28;
        wxBitmapButton* BitmapButton29;
        wxBitmapButton* BitmapButton2;
        wxBitmapButton* BitmapButton30;
        wxBitmapButton* BitmapButton31;
        wxBitmapButton* BitmapButton32;
        wxBitmapButton* BitmapButton33;
        wxBitmapButton* BitmapButton34;
        wxBitmapButton* BitmapButton35;
        wxBitmapButton* BitmapButton36;
        wxBitmapButton* BitmapButton37;
        wxBitmapButton* BitmapButton38;
        wxBitmapButton* BitmapButton39;
        wxBitmapButton* BitmapButton3;
        wxBitmapButton* BitmapButton40;
        wxBitmapButton* BitmapButton41;
        wxBitmapButton* BitmapButton42;
        wxBitmapButton* BitmapButton43;
        wxBitmapButton* BitmapButton44;
        wxBitmapButton* BitmapButton45;
        wxBitmapButton* BitmapButton46;
        wxBitmapButton* BitmapButton47;
        wxBitmapButton* BitmapButton48;
        wxBitmapButton* BitmapButton49;
        wxBitmapButton* BitmapButton4;
        wxBitmapButton* BitmapButton50;
        wxBitmapButton* BitmapButton51;
        wxBitmapButton* BitmapButton52;
        wxBitmapButton* BitmapButton53;
        wxBitmapButton* BitmapButton54;
        wxBitmapButton* BitmapButton55;
        wxBitmapButton* BitmapButton5;
        wxBitmapButton* BitmapButton6;
        wxBitmapButton* BitmapButton7;
        wxBitmapButton* BitmapButton8;
        wxBitmapButton* BitmapButton9;
        wxBoxSizer* BoxSizer1;
        wxCheckBox* CheckBox1;
        wxChoice* Choice1;
        wxFlexGridSizer* FlexGridSizer19;
        wxRadioButton* RadioButton1;
        wxRadioButton* RadioButton2;
        wxStaticBitmap* StaticBitmap1;
        wxStaticText* StaticText10;
        wxStaticText* StaticText11;
        wxStaticText* StaticText12;
        wxStaticText* StaticText13;
        wxStaticText* StaticText14;
        wxStaticText* StaticText15;
        wxStaticText* StaticText16;
        wxStaticText* StaticText17;
        wxStaticText* StaticText18;
        wxStaticText* StaticText19;
        wxStaticText* StaticText20;
        wxStaticText* StaticText21;
        wxStaticText* StaticText22;
        wxStaticText* StaticText23;
        wxStaticText* StaticText24;
        wxStaticText* StaticText25;
        wxStaticText* StaticText26;
        wxStaticText* StaticText27;
        wxStaticText* StaticText28;
        wxStaticText* StaticText2;
        wxStaticText* StaticText30;
        wxStaticText* StaticText31;
        wxStaticText* StaticText32;
        wxStaticText* StaticText33;
        wxStaticText* StaticText34;
        wxStaticText* StaticText35;
        wxStaticText* StaticText37;
        wxStaticText* StaticText38;
        wxStaticText* StaticText39;
        wxStaticText* StaticText3;
        wxStaticText* StaticText40;
        wxStaticText* StaticText41;
        wxStaticText* StaticText42;
        wxStaticText* StaticText44;
        wxStaticText* StaticText45;
        wxStaticText* StaticText46;
        wxStaticText* StaticText47;
        wxStaticText* StaticText48;
        wxStaticText* StaticText49;
        wxStaticText* StaticText4;
        wxStaticText* StaticText51;
        wxStaticText* StaticText52;
        wxStaticText* StaticText53;
        wxStaticText* StaticText54;
        wxStaticText* StaticText5;
        wxStaticText* StaticText6;
        wxStaticText* StaticText7;
        wxStaticText* StaticText8;
        wxStaticText* StaticText9;
        //*)
        bool licznik = true;
    wxBitmap rysunki[12];
    wxBitmapButton *plansza1[6];
    wxBitmapButton *plansza2[6];
    wxBitmapButton *plansza3[6];
    wxBitmapButton *plansza4[6];
    wxBitmapButton *plansza5[6];
    wxBitmapButton *plansza6[6];
    wxBitmapButton *plansza7[6];
    int cykl[7] = {5,5,5,5,5,5,5};
    int licznik_ruchow=0;
    int liczba_rund;
    int licznik_rund;
    int kolumna_bota;
    bool debug_flag;
    bool gra_z_AI;
        DECLARE_EVENT_TABLE()
};

#endif // CONNECT_FOURMAIN_H
