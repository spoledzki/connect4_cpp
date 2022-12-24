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

//(*Headers(connect_fourDialog)
#include <wx/bmpbuttn.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/statline.h>
#include <wx/stattext.h>
//*)

class connect_fourDialog: public wxDialog
{
    public:

        connect_fourDialog(wxWindow* parent,wxWindowID id = -1);
        virtual ~connect_fourDialog();
        void czyszczenie_rysunkow();

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
        //*)

        //(*Identifiers(connect_fourDialog)
        static const long ID_STATICTEXT1;
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
        static const long ID_STATICLINE1;
        static const long ID_BITMAPBUTTON1;
        static const long ID_BITMAPBUTTON2;
        static const long ID_BITMAPBUTTON3;
        static const long ID_BITMAPBUTTON4;
        static const long ID_BITMAPBUTTON5;
        static const long ID_BITMAPBUTTON6;
        static const long ID_BITMAPBUTTON49;
        static const long ID_BITMAPBUTTON52;
        static const long ID_BITMAPBUTTON50;
        static const long ID_BITMAPBUTTON51;
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
        wxBitmapButton* BitmapButton5;
        wxBitmapButton* BitmapButton6;
        wxBitmapButton* BitmapButton7;
        wxBitmapButton* BitmapButton8;
        wxBitmapButton* BitmapButton9;
        wxBoxSizer* BoxSizer1;
        wxStaticLine* StaticLine1;
        wxStaticText* StaticText1;
        //*)
        bool licznik = true;
    wxBitmap rysunki[10];
    wxBitmapButton *plansza1[6];
    wxBitmapButton *plansza2[6];
    wxBitmapButton *plansza3[6];
    wxBitmapButton *plansza4[6];
    wxBitmapButton *plansza5[6];
    wxBitmapButton *plansza6[6];
    wxBitmapButton *plansza7[6];
    int cykl[7] = {5,5,5,5,5,5,5};
        DECLARE_EVENT_TABLE()
};

#endif // CONNECT_FOURMAIN_H
