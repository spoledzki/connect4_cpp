/***************************************************************
 * Name:      kolko_i_krzyzykMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2022-11-17
 * Copyright:  ()
 * License:
 **************************************************************/

#include "kolko_i_krzyzykMain.h"
#include <wx/msgdlg.h>
#undef _
#define _(s) wxString::FromUTF8(s)
#include "kolko_i_krzyzyk.h"
#include "kik.h"
#include <wx/image.h>
#include <wx/artprov.h>
#include <ctime>

//(*InternalHeaders(kolko_i_krzyzykDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(kolko_i_krzyzykDialog)
const long kolko_i_krzyzykDialog::ID_BITMAPBUTTON1 = wxNewId();
const long kolko_i_krzyzykDialog::ID_BITMAPBUTTON2 = wxNewId();
const long kolko_i_krzyzykDialog::ID_BITMAPBUTTON3 = wxNewId();
const long kolko_i_krzyzykDialog::ID_BITMAPBUTTON4 = wxNewId();
const long kolko_i_krzyzykDialog::ID_BITMAPBUTTON5 = wxNewId();
const long kolko_i_krzyzykDialog::ID_BITMAPBUTTON6 = wxNewId();
const long kolko_i_krzyzykDialog::ID_BITMAPBUTTON7 = wxNewId();
const long kolko_i_krzyzykDialog::ID_BITMAPBUTTON8 = wxNewId();
const long kolko_i_krzyzykDialog::ID_BITMAPBUTTON9 = wxNewId();
const long kolko_i_krzyzykDialog::ID_CHECKBOX1 = wxNewId();
const long kolko_i_krzyzykDialog::ID_BUTTON1 = wxNewId();
const long kolko_i_krzyzykDialog::ID_BUTTON2 = wxNewId();
const long kolko_i_krzyzykDialog::ID_STATICTEXT1 = wxNewId();
const long kolko_i_krzyzykDialog::ID_STATICTEXT2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(kolko_i_krzyzykDialog,wxDialog)
    //(*EventTable(kolko_i_krzyzykDialog)
    //*)
END_EVENT_TABLE()

kolko_i_krzyzykDialog::kolko_i_krzyzykDialog(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(kolko_i_krzyzykDialog)
    wxFlexGridSizer* FlexGridSizer1;
    wxFlexGridSizer* FlexGridSizer2;

    Create(parent, wxID_ANY, _("wxWidgets app"), wxDefaultPosition, wxDefaultSize, wxCAPTION|wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(200,400));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    FlexGridSizer1 = new wxFlexGridSizer(0, 3, 0, 0);
    BitmapButton1 = new wxBitmapButton(this, ID_BITMAPBUTTON1, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
    BitmapButton1->Disable();
    FlexGridSizer1->Add(BitmapButton1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton2 = new wxBitmapButton(this, ID_BITMAPBUTTON2, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON2"));
    BitmapButton2->Disable();
    FlexGridSizer1->Add(BitmapButton2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton3 = new wxBitmapButton(this, ID_BITMAPBUTTON3, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON3"));
    BitmapButton3->Disable();
    FlexGridSizer1->Add(BitmapButton3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton4 = new wxBitmapButton(this, ID_BITMAPBUTTON4, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON4"));
    BitmapButton4->Disable();
    FlexGridSizer1->Add(BitmapButton4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton5 = new wxBitmapButton(this, ID_BITMAPBUTTON5, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON5"));
    BitmapButton5->Disable();
    FlexGridSizer1->Add(BitmapButton5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton6 = new wxBitmapButton(this, ID_BITMAPBUTTON6, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON6"));
    BitmapButton6->Disable();
    FlexGridSizer1->Add(BitmapButton6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton7 = new wxBitmapButton(this, ID_BITMAPBUTTON7, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON7"));
    BitmapButton7->Disable();
    FlexGridSizer1->Add(BitmapButton7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton8 = new wxBitmapButton(this, ID_BITMAPBUTTON8, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON8"));
    BitmapButton8->Disable();
    FlexGridSizer1->Add(BitmapButton8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton9 = new wxBitmapButton(this, ID_BITMAPBUTTON9, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON9"));
    BitmapButton9->Disable();
    FlexGridSizer1->Add(BitmapButton9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(FlexGridSizer1, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer2 = new wxFlexGridSizer(0, 1, 0, 0);
    CheckBox1 = new wxCheckBox(this, ID_CHECKBOX1, _("Gracz zaczyna"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    CheckBox1->SetValue(true);
    FlexGridSizer2->Add(CheckBox1, 1, wxALL|wxEXPAND, 5);
    Button1 = new wxButton(this, ID_BUTTON1, _("Graj"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    FlexGridSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button2 = new wxButton(this, ID_BUTTON2, _("Restart"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    FlexGridSizer2->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Tekst"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE, _T("ID_STATICTEXT1"));
    FlexGridSizer2->Add(StaticText1, 1, wxALL|wxEXPAND, 5);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE, _T("ID_STATICTEXT2"));
    FlexGridSizer2->Add(StaticText2, 1, wxALL|wxEXPAND, 5);
    BoxSizer2->Add(FlexGridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer2, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    SetSizer(BoxSizer1);
    SetSizer(BoxSizer1);
    Layout();

    Connect(ID_BITMAPBUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&kolko_i_krzyzykDialog::OnBitmapButton1Click);
    Connect(ID_BITMAPBUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&kolko_i_krzyzykDialog::OnBitmapButton2Click);
    Connect(ID_BITMAPBUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&kolko_i_krzyzykDialog::OnBitmapButton3Click);
    Connect(ID_BITMAPBUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&kolko_i_krzyzykDialog::OnBitmapButton4Click);
    Connect(ID_BITMAPBUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&kolko_i_krzyzykDialog::OnBitmapButton5Click);
    Connect(ID_BITMAPBUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&kolko_i_krzyzykDialog::OnBitmapButton6Click);
    Connect(ID_BITMAPBUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&kolko_i_krzyzykDialog::OnBitmapButton7Click);
    Connect(ID_BITMAPBUTTON8,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&kolko_i_krzyzykDialog::OnBitmapButton8Click);
    Connect(ID_BITMAPBUTTON9,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&kolko_i_krzyzykDialog::OnBitmapButton9Click);
    Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&kolko_i_krzyzykDialog::OnCheckBox1Click);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&kolko_i_krzyzykDialog::OnButton1Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&kolko_i_krzyzykDialog::OnQuit);
    //*)
    BoxSizer1 -> Fit(this);
    rysunki[0]=wxBitmap(wxImage("blank.bmp"));
    rysunki[1]=wxBitmap(wxImage("circle.bmp"));
    rysunki[2]=wxBitmap(wxImage("cross.bmp"));
    BitmapButton1->SetBitmap(rysunki[0]);
    BitmapButton2->SetBitmap(rysunki[0]);
    BitmapButton3->SetBitmap(rysunki[0]);
    BitmapButton4->SetBitmap(rysunki[0]);
    BitmapButton5->SetBitmap(rysunki[0]);
    BitmapButton6->SetBitmap(rysunki[0]);
    BitmapButton7->SetBitmap(rysunki[0]);
    BitmapButton8->SetBitmap(rysunki[0]);
    BitmapButton9->SetBitmap(rysunki[0]);
}

kolko_i_krzyzyk gra;

kolko_i_krzyzykDialog::~kolko_i_krzyzykDialog(){
    //(*Destroy(kolko_i_krzyzykDialog)
    //*)
}

void kolko_i_krzyzykDialog::koniec(){
    if(gra.get_znak_tury() == 'O')
        StaticText2 -> SetLabel("Wygrana komputera");
    if(gra.get_znak_tury() == 'X')
        StaticText2 -> SetLabel("Wygrana gracza");
    if(gra.getremis() == 9)
        StaticText2 -> SetLabel("Remis");
    BitmapButton1 -> Disable();
    BitmapButton2 -> Disable();
    BitmapButton3 -> Disable();
    BitmapButton4 -> Disable();
    BitmapButton5 -> Disable();
    BitmapButton6 -> Disable();
    BitmapButton7 -> Disable();
    BitmapButton8 -> Disable();
    BitmapButton9 -> Disable();
    StaticText2 -> Show();
    BoxSizer2 -> Fit(this);
    Button2 -> Enable();
    Button1 -> Disable();
    CheckBox1 -> Enable();
}

void kolko_i_krzyzykDialog::Enable(){
    BitmapButton1 -> Enable();
    BitmapButton2 -> Enable();
    BitmapButton3 -> Enable();
    BitmapButton4 -> Enable();
    BitmapButton5 -> Enable();
    BitmapButton6 -> Enable();
    BitmapButton7 -> Enable();
    BitmapButton8 -> Enable();
    BitmapButton9 -> Enable();
}

void kolko_i_krzyzykDialog::clear_bit(){ //wyczyszczenie rysunków
    BitmapButton1->SetBitmap(rysunki[0]);
    BitmapButton2->SetBitmap(rysunki[0]);
    BitmapButton3->SetBitmap(rysunki[0]);
    BitmapButton4->SetBitmap(rysunki[0]);
    BitmapButton5->SetBitmap(rysunki[0]);
    BitmapButton6->SetBitmap(rysunki[0]);
    BitmapButton7->SetBitmap(rysunki[0]);
    BitmapButton8->SetBitmap(rysunki[0]);
    BitmapButton9->SetBitmap(rysunki[0]);
}

void kolko_i_krzyzykDialog::OnQuit(wxCommandEvent& event){//restart
    gra.restart();
    if(CheckBox1 -> IsChecked() == 1) gra.set_znak_tury('O');
        else gra.set_znak_tury('X');
    StaticText1 -> SetLabel(gra.wypisz_wiersz_kolumna());
    StaticText2 -> Hide();
    Button1 -> Enable();
    clear_bit();
}

void kolko_i_krzyzykDialog::OnAbout(wxCommandEvent& event){
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void kolko_i_krzyzykDialog::OnInit(wxInitDialogEvent& event){
}

void kolko_i_krzyzykDialog::OnBitmapButton1Click(wxCommandEvent& event){
    gra.get_wiersz_kolumna(0,0);
    if ( gra.get_znak_tury() == 'O') BitmapButton1->SetBitmap(rysunki[1]);
        else BitmapButton1->SetBitmap(rysunki[2]);
    gra.logika();
    StaticText1 -> SetLabel(gra.wypisz_wiersz_kolumna());
    if(gra.koniec_gry() == true) koniec();
    BoxSizer1 -> Fit(this);
}

void kolko_i_krzyzykDialog::OnBitmapButton2Click(wxCommandEvent& event){
    gra.get_wiersz_kolumna(1,0);
    if ( gra.get_znak_tury() == 'O') BitmapButton2->SetBitmap(rysunki[1]);
        else BitmapButton2->SetBitmap(rysunki[2]);
    gra.logika();
    StaticText1 -> SetLabel(gra.wypisz_wiersz_kolumna());
    if(gra.koniec_gry() == true) koniec();
    BoxSizer1 -> Fit(this);
}

void kolko_i_krzyzykDialog::OnBitmapButton3Click(wxCommandEvent& event){
    gra.get_wiersz_kolumna(2,0);
    if ( gra.get_znak_tury() == 'O') BitmapButton3->SetBitmap(rysunki[1]);
        else BitmapButton3->SetBitmap(rysunki[2]);
    gra.logika();
    StaticText1 -> SetLabel(gra.wypisz_wiersz_kolumna());
    if(gra.koniec_gry() == true) koniec();
    BoxSizer1 -> Fit(this);
}

void kolko_i_krzyzykDialog::OnBitmapButton4Click(wxCommandEvent& event){
    gra.get_wiersz_kolumna(0,1);
    if ( gra.get_znak_tury() == 'O') BitmapButton4->SetBitmap(rysunki[1]);
        else BitmapButton4->SetBitmap(rysunki[2]);
    gra.logika();
    StaticText1 -> SetLabel(gra.wypisz_wiersz_kolumna());
    if(gra.koniec_gry() == true) koniec();
    BoxSizer1 -> Fit(this);

}

void kolko_i_krzyzykDialog::OnBitmapButton5Click(wxCommandEvent& event){
    gra.get_wiersz_kolumna(1,1);
    if ( gra.get_znak_tury() == 'O') BitmapButton5->SetBitmap(rysunki[1]);
        else BitmapButton5->SetBitmap(rysunki[2]);
    gra.logika();
    StaticText1 -> SetLabel(gra.wypisz_wiersz_kolumna());
    if(gra.koniec_gry() == true) koniec();
    BoxSizer1 -> Fit(this);
}

void kolko_i_krzyzykDialog::OnBitmapButton6Click(wxCommandEvent& event){
    gra.get_wiersz_kolumna(2,1);
    if ( gra.get_znak_tury() == 'O') BitmapButton6->SetBitmap(rysunki[1]);
        else BitmapButton6->SetBitmap(rysunki[2]);
    gra.logika();
    StaticText1 -> SetLabel(gra.wypisz_wiersz_kolumna());
    if(gra.koniec_gry() == true) koniec();
    BoxSizer1 -> Fit(this);
}

void kolko_i_krzyzykDialog::OnBitmapButton7Click(wxCommandEvent& event){
    gra.get_wiersz_kolumna(0,2);
    if ( gra.get_znak_tury() == 'O') BitmapButton7->SetBitmap(rysunki[1]);
        else BitmapButton7->SetBitmap(rysunki[2]);
    gra.logika();
    StaticText1 -> SetLabel(gra.wypisz_wiersz_kolumna());
    if(gra.koniec_gry() == true) koniec();
    BoxSizer1 -> Fit(this);
}

void kolko_i_krzyzykDialog::OnBitmapButton8Click(wxCommandEvent& event){
    gra.get_wiersz_kolumna(1,2);
    if ( gra.get_znak_tury() == 'O') BitmapButton8->SetBitmap(rysunki[1]);
        else BitmapButton8->SetBitmap(rysunki[2]);
    gra.logika();
    StaticText1 -> SetLabel(gra.wypisz_wiersz_kolumna());
    if(gra.koniec_gry() == true) koniec();
    BoxSizer1 -> Fit(this);
}

void kolko_i_krzyzykDialog::OnBitmapButton9Click(wxCommandEvent& event){
    gra.get_wiersz_kolumna(2,2);
    if ( gra.get_znak_tury() == 'O') BitmapButton9->SetBitmap(rysunki[1]);
        else BitmapButton9->SetBitmap(rysunki[2]);
    gra.logika();
    StaticText1 -> SetLabel(gra.wypisz_wiersz_kolumna());
    if(gra.koniec_gry() == true) koniec();
    BoxSizer1 -> Fit(this);
}

void kolko_i_krzyzykDialog::OnButton1Click(wxCommandEvent& event){
    if(CheckBox1 -> IsChecked() == 1) gra.set_znak_tury('O');
        else gra.set_znak_tury('X');
    Enable();
    CheckBox1 -> Disable();
    Button2 -> Disable();
}

void kolko_i_krzyzykDialog::OnCheckBox1Click(wxCommandEvent& event){
    StaticText1 -> SetLabel(gra.wypisz_wiersz_kolumna());
}
