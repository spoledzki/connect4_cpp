/***************************************************************
 * Name:      kolko_i_krzyzykMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2022-11-17
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef KOLKO_I_KRZYZYKMAIN_H
#define KOLKO_I_KRZYZYKMAIN_H

//(*Headers(kolko_i_krzyzykDialog)
#include <wx/bmpbuttn.h>
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
//*)
#include "kik.h"

class kolko_i_krzyzykDialog: public wxDialog
{
    public:

        kolko_i_krzyzykDialog(wxWindow* parent,wxWindowID id = -1);
        virtual ~kolko_i_krzyzykDialog();
        void koniec();
        void Enable();
        void clear_bit();


    private:

        //(*Handlers(kolko_i_krzyzykDialog)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnInit(wxInitDialogEvent& event);
        void OnBitmapButton1Click(wxCommandEvent& event);
        void OnBitmapButton2Click(wxCommandEvent& event);
        void OnBitmapButton3Click(wxCommandEvent& event);
        void OnBitmapButton4Click(wxCommandEvent& event);
        void OnBitmapButton5Click(wxCommandEvent& event);
        void OnBitmapButton6Click(wxCommandEvent& event);
        void OnBitmapButton7Click(wxCommandEvent& event);
        void OnBitmapButton8Click(wxCommandEvent& event);
        void OnBitmapButton9Click(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnCheckBox1Click(wxCommandEvent& event);
        //*)

        //(*Identifiers(kolko_i_krzyzykDialog)
        static const long ID_BITMAPBUTTON1;
        static const long ID_BITMAPBUTTON2;
        static const long ID_BITMAPBUTTON3;
        static const long ID_BITMAPBUTTON4;
        static const long ID_BITMAPBUTTON5;
        static const long ID_BITMAPBUTTON6;
        static const long ID_BITMAPBUTTON7;
        static const long ID_BITMAPBUTTON8;
        static const long ID_BITMAPBUTTON9;
        static const long ID_CHECKBOX1;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_STATICTEXT1;
        static const long ID_STATICTEXT2;
        //*)

        //(*Declarations(kolko_i_krzyzykDialog)
        wxBitmapButton* BitmapButton1;
        wxBitmapButton* BitmapButton2;
        wxBitmapButton* BitmapButton3;
        wxBitmapButton* BitmapButton4;
        wxBitmapButton* BitmapButton5;
        wxBitmapButton* BitmapButton6;
        wxBitmapButton* BitmapButton7;
        wxBitmapButton* BitmapButton8;
        wxBitmapButton* BitmapButton9;
        wxBoxSizer* BoxSizer1;
        wxBoxSizer* BoxSizer2;
        wxButton* Button1;
        wxButton* Button2;
        wxCheckBox* CheckBox1;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        //*)
        wxBitmap rysunki[3];
        DECLARE_EVENT_TABLE()
};

#endif // KOLKO_I_KRZYZYKMAIN_H
