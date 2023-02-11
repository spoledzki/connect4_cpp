/***************************************************************
 * Name:      connect_fourMain.cpp
 * Purpose:   Realizacje funkcji klasy connect_fourDialog
 * Author:    Igor Nowiński, Szymon Olędzki, Tymoteusz Romanowicz
 * Created:   2022-12-14
 * Copyright:  ()
 * License:
 **************************************************************/

#include "connect_fourMain.h"
#include <wx/msgdlg.h>
#include "Gra.h"
#include <ctime>
#include <cstring>
#include <windows.h>
#undef _
#define _(s) wxString::FromUTF8(s)

//(*InternalHeaders(connect_fourDialog)
#include <wx/font.h>
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

wxString s2w(std::string s);

//(*IdInit(connect_fourDialog)
const long connect_fourDialog::ID_STATICBITMAP1 = wxNewId();
const long connect_fourDialog::ID_BITMAPBUTTON7 = wxNewId();
const long connect_fourDialog::ID_BITMAPBUTTON8 = wxNewId();
const long connect_fourDialog::ID_BITMAPBUTTON9 = wxNewId();
const long connect_fourDialog::ID_BITMAPBUTTON10 = wxNewId();
const long connect_fourDialog::ID_BITMAPBUTTON11 = wxNewId();
const long connect_fourDialog::ID_BITMAPBUTTON12 = wxNewId();
const long connect_fourDialog::ID_BITMAPBUTTON13 = wxNewId();
const long connect_fourDialog::ID_BITMAPBUTTON14 = wxNewId();
const long connect_fourDialog::ID_BITMAPBUTTON15 = wxNewId();
const long connect_fourDialog::ID_BITMAPBUTTON16 = wxNewId();
const long connect_fourDialog::ID_BITMAPBUTTON17 = wxNewId();
const long connect_fourDialog::ID_BITMAPBUTTON18 = wxNewId();
const long connect_fourDialog::ID_BITMAPBUTTON19 = wxNewId();
const long connect_fourDialog::ID_BITMAPBUTTON20 = wxNewId();
const long connect_fourDialog::ID_BITMAPBUTTON21 = wxNewId();
const long connect_fourDialog::ID_BITMAPBUTTON22 = wxNewId();
const long connect_fourDialog::ID_BITMAPBUTTON23 = wxNewId();
const long connect_fourDialog::ID_BITMAPBUTTON24 = wxNewId();
const long connect_fourDialog::ID_BITMAPBUTTON25 = wxNewId();
const long connect_fourDialog::ID_BITMAPBUTTON26 = wxNewId();
const long connect_fourDialog::ID_BITMAPBUTTON27 = wxNewId();
const long connect_fourDialog::ID_BITMAPBUTTON28 = wxNewId();
const long connect_fourDialog::ID_BITMAPBUTTON29 = wxNewId();
const long connect_fourDialog::ID_BITMAPBUTTON30 = wxNewId();
const long connect_fourDialog::ID_BITMAPBUTTON31 = wxNewId();
const long connect_fourDialog::ID_BITMAPBUTTON32 = wxNewId();
const long connect_fourDialog::ID_BITMAPBUTTON33 = wxNewId();
const long connect_fourDialog::ID_BITMAPBUTTON34 = wxNewId();
const long connect_fourDialog::ID_BITMAPBUTTON35 = wxNewId();
const long connect_fourDialog::ID_BITMAPBUTTON36 = wxNewId();
const long connect_fourDialog::ID_BITMAPBUTTON37 = wxNewId();
const long connect_fourDialog::ID_BITMAPBUTTON38 = wxNewId();
const long connect_fourDialog::ID_BITMAPBUTTON39 = wxNewId();
const long connect_fourDialog::ID_BITMAPBUTTON40 = wxNewId();
const long connect_fourDialog::ID_BITMAPBUTTON41 = wxNewId();
const long connect_fourDialog::ID_BITMAPBUTTON42 = wxNewId();
const long connect_fourDialog::ID_BITMAPBUTTON43 = wxNewId();
const long connect_fourDialog::ID_BITMAPBUTTON44 = wxNewId();
const long connect_fourDialog::ID_BITMAPBUTTON45 = wxNewId();
const long connect_fourDialog::ID_BITMAPBUTTON46 = wxNewId();
const long connect_fourDialog::ID_BITMAPBUTTON47 = wxNewId();
const long connect_fourDialog::ID_BITMAPBUTTON48 = wxNewId();
const long connect_fourDialog::ID_BITMAPBUTTON1 = wxNewId();
const long connect_fourDialog::ID_BITMAPBUTTON2 = wxNewId();
const long connect_fourDialog::ID_BITMAPBUTTON3 = wxNewId();
const long connect_fourDialog::ID_BITMAPBUTTON4 = wxNewId();
const long connect_fourDialog::ID_BITMAPBUTTON5 = wxNewId();
const long connect_fourDialog::ID_BITMAPBUTTON6 = wxNewId();
const long connect_fourDialog::ID_BITMAPBUTTON49 = wxNewId();
const long connect_fourDialog::ID_BITMAPBUTTON51 = wxNewId();
const long connect_fourDialog::ID_BITMAPBUTTON52 = wxNewId();
const long connect_fourDialog::ID_STATICTEXT7 = wxNewId();
const long connect_fourDialog::ID_RADIOBUTTON1 = wxNewId();
const long connect_fourDialog::ID_RADIOBUTTON2 = wxNewId();
const long connect_fourDialog::ID_STATICTEXT8 = wxNewId();
const long connect_fourDialog::ID_STATICTEXT14 = wxNewId();
const long connect_fourDialog::ID_STATICTEXT13 = wxNewId();
const long connect_fourDialog::ID_STATICTEXT12 = wxNewId();
const long connect_fourDialog::ID_STATICTEXT11 = wxNewId();
const long connect_fourDialog::ID_STATICTEXT10 = wxNewId();
const long connect_fourDialog::ID_STATICTEXT9 = wxNewId();
const long connect_fourDialog::ID_STATICTEXT21 = wxNewId();
const long connect_fourDialog::ID_STATICTEXT20 = wxNewId();
const long connect_fourDialog::ID_STATICTEXT19 = wxNewId();
const long connect_fourDialog::ID_STATICTEXT18 = wxNewId();
const long connect_fourDialog::ID_STATICTEXT17 = wxNewId();
const long connect_fourDialog::ID_STATICTEXT16 = wxNewId();
const long connect_fourDialog::ID_STATICTEXT28 = wxNewId();
const long connect_fourDialog::ID_STATICTEXT27 = wxNewId();
const long connect_fourDialog::ID_STATICTEXT26 = wxNewId();
const long connect_fourDialog::ID_STATICTEXT25 = wxNewId();
const long connect_fourDialog::ID_STATICTEXT24 = wxNewId();
const long connect_fourDialog::ID_STATICTEXT23 = wxNewId();
const long connect_fourDialog::ID_STATICTEXT35 = wxNewId();
const long connect_fourDialog::ID_STATICTEXT34 = wxNewId();
const long connect_fourDialog::ID_STATICTEXT33 = wxNewId();
const long connect_fourDialog::ID_STATICTEXT32 = wxNewId();
const long connect_fourDialog::ID_STATICTEXT31 = wxNewId();
const long connect_fourDialog::ID_STATICTEXT30 = wxNewId();
const long connect_fourDialog::ID_STATICTEXT42 = wxNewId();
const long connect_fourDialog::ID_STATICTEXT41 = wxNewId();
const long connect_fourDialog::ID_STATICTEXT40 = wxNewId();
const long connect_fourDialog::ID_STATICTEXT39 = wxNewId();
const long connect_fourDialog::ID_STATICTEXT38 = wxNewId();
const long connect_fourDialog::ID_STATICTEXT37 = wxNewId();
const long connect_fourDialog::ID_STATICTEXT49 = wxNewId();
const long connect_fourDialog::ID_STATICTEXT48 = wxNewId();
const long connect_fourDialog::ID_STATICTEXT47 = wxNewId();
const long connect_fourDialog::ID_STATICTEXT46 = wxNewId();
const long connect_fourDialog::ID_STATICTEXT45 = wxNewId();
const long connect_fourDialog::ID_STATICTEXT44 = wxNewId();
const long connect_fourDialog::ID_STATICTEXT22 = wxNewId();
const long connect_fourDialog::ID_STATICTEXT15 = wxNewId();
const long connect_fourDialog::ID_STATICTEXT54 = wxNewId();
const long connect_fourDialog::ID_STATICTEXT53 = wxNewId();
const long connect_fourDialog::ID_STATICTEXT52 = wxNewId();
const long connect_fourDialog::ID_STATICTEXT51 = wxNewId();
const long connect_fourDialog::ID_STATICTEXT2 = wxNewId();
const long connect_fourDialog::ID_BITMAPBUTTON53 = wxNewId();
const long connect_fourDialog::ID_CHECKBOX1 = wxNewId();
const long connect_fourDialog::ID_STATICTEXT6 = wxNewId();
const long connect_fourDialog::ID_CHOICE1 = wxNewId();
const long connect_fourDialog::ID_BITMAPBUTTON54 = wxNewId();
const long connect_fourDialog::ID_STATICTEXT3 = wxNewId();
const long connect_fourDialog::ID_STATICTEXT4 = wxNewId();
const long connect_fourDialog::ID_STATICTEXT5 = wxNewId();
const long connect_fourDialog::ID_BITMAPBUTTON55 = wxNewId();
const long connect_fourDialog::ID_BITMAPBUTTON50 = wxNewId();
//*)

BEGIN_EVENT_TABLE(connect_fourDialog,wxDialog)
    //(*EventTable(connect_fourDialog)
    //*)
END_EVENT_TABLE()


Gra object;
connect_fourDialog::connect_fourDialog(wxWindow* parent,wxWindowID id)
{
    srand(time(NULL));
    //(*Initialize(connect_fourDialog)
    wxFlexGridSizer* FlexGridSizer10;
    wxFlexGridSizer* FlexGridSizer11;
    wxFlexGridSizer* FlexGridSizer12;
    wxFlexGridSizer* FlexGridSizer13;
    wxFlexGridSizer* FlexGridSizer14;
    wxFlexGridSizer* FlexGridSizer15;
    wxFlexGridSizer* FlexGridSizer16;
    wxFlexGridSizer* FlexGridSizer17;
    wxFlexGridSizer* FlexGridSizer18;
    wxFlexGridSizer* FlexGridSizer1;
    wxFlexGridSizer* FlexGridSizer20;
    wxFlexGridSizer* FlexGridSizer21;
    wxFlexGridSizer* FlexGridSizer22;
    wxFlexGridSizer* FlexGridSizer23;
    wxFlexGridSizer* FlexGridSizer24;
    wxFlexGridSizer* FlexGridSizer25;
    wxFlexGridSizer* FlexGridSizer26;
    wxFlexGridSizer* FlexGridSizer27;
    wxFlexGridSizer* FlexGridSizer28;
    wxFlexGridSizer* FlexGridSizer29;
    wxFlexGridSizer* FlexGridSizer2;
    wxFlexGridSizer* FlexGridSizer30;
    wxFlexGridSizer* FlexGridSizer3;
    wxFlexGridSizer* FlexGridSizer4;
    wxFlexGridSizer* FlexGridSizer5;
    wxFlexGridSizer* FlexGridSizer6;
    wxFlexGridSizer* FlexGridSizer7;
    wxFlexGridSizer* FlexGridSizer8;
    wxFlexGridSizer* FlexGridSizer9;

    Create(parent, wxID_ANY, _("Connect 4"), wxDefaultPosition, wxDefaultSize, wxBORDER_DOUBLE|wxBORDER_NONE, _T("wxID_ANY"));
    SetBackgroundColour(wxColour(50,170,180));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    FlexGridSizer13 = new wxFlexGridSizer(0, 1, 0, 0);
    StaticBitmap1 = new wxStaticBitmap(this, ID_STATICBITMAP1, wxNullBitmap, wxDefaultPosition, wxSize(296,61), 0, _T("ID_STATICBITMAP1"));
    FlexGridSizer13->Add(StaticBitmap1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer17 = new wxFlexGridSizer(0, 2, 0, 0);
    FlexGridSizer4 = new wxFlexGridSizer(0, 1, 0, 0);
    FlexGridSizer2 = new wxFlexGridSizer(0, 1, 0, 0);
    FlexGridSizer1 = new wxFlexGridSizer(8, 7, 0, 0);
    FlexGridSizer5 = new wxFlexGridSizer(6, 1, 0, 0);
    BitmapButton7 = new wxBitmapButton(this, ID_BITMAPBUTTON7, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW|wxBORDER_DOUBLE, wxDefaultValidator, _T("ID_BITMAPBUTTON7"));
    FlexGridSizer5->Add(BitmapButton7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton8 = new wxBitmapButton(this, ID_BITMAPBUTTON8, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON8"));
    FlexGridSizer5->Add(BitmapButton8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton9 = new wxBitmapButton(this, ID_BITMAPBUTTON9, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON9"));
    FlexGridSizer5->Add(BitmapButton9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton10 = new wxBitmapButton(this, ID_BITMAPBUTTON10, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON10"));
    FlexGridSizer5->Add(BitmapButton10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton11 = new wxBitmapButton(this, ID_BITMAPBUTTON11, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON11"));
    FlexGridSizer5->Add(BitmapButton11, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton12 = new wxBitmapButton(this, ID_BITMAPBUTTON12, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON12"));
    FlexGridSizer5->Add(BitmapButton12, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(FlexGridSizer5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer6 = new wxFlexGridSizer(6, 1, 0, 0);
    BitmapButton13 = new wxBitmapButton(this, ID_BITMAPBUTTON13, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON13"));
    FlexGridSizer6->Add(BitmapButton13, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton14 = new wxBitmapButton(this, ID_BITMAPBUTTON14, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON14"));
    FlexGridSizer6->Add(BitmapButton14, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton15 = new wxBitmapButton(this, ID_BITMAPBUTTON15, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON15"));
    FlexGridSizer6->Add(BitmapButton15, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton16 = new wxBitmapButton(this, ID_BITMAPBUTTON16, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON16"));
    FlexGridSizer6->Add(BitmapButton16, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton17 = new wxBitmapButton(this, ID_BITMAPBUTTON17, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON17"));
    FlexGridSizer6->Add(BitmapButton17, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton18 = new wxBitmapButton(this, ID_BITMAPBUTTON18, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON18"));
    FlexGridSizer6->Add(BitmapButton18, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(FlexGridSizer6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer7 = new wxFlexGridSizer(6, 1, 0, 0);
    BitmapButton19 = new wxBitmapButton(this, ID_BITMAPBUTTON19, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON19"));
    FlexGridSizer7->Add(BitmapButton19, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton20 = new wxBitmapButton(this, ID_BITMAPBUTTON20, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON20"));
    FlexGridSizer7->Add(BitmapButton20, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton21 = new wxBitmapButton(this, ID_BITMAPBUTTON21, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON21"));
    FlexGridSizer7->Add(BitmapButton21, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton22 = new wxBitmapButton(this, ID_BITMAPBUTTON22, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON22"));
    FlexGridSizer7->Add(BitmapButton22, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton23 = new wxBitmapButton(this, ID_BITMAPBUTTON23, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON23"));
    FlexGridSizer7->Add(BitmapButton23, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton24 = new wxBitmapButton(this, ID_BITMAPBUTTON24, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON24"));
    FlexGridSizer7->Add(BitmapButton24, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(FlexGridSizer7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer8 = new wxFlexGridSizer(6, 1, 0, 0);
    BitmapButton25 = new wxBitmapButton(this, ID_BITMAPBUTTON25, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON25"));
    FlexGridSizer8->Add(BitmapButton25, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton26 = new wxBitmapButton(this, ID_BITMAPBUTTON26, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON26"));
    FlexGridSizer8->Add(BitmapButton26, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton27 = new wxBitmapButton(this, ID_BITMAPBUTTON27, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON27"));
    FlexGridSizer8->Add(BitmapButton27, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton28 = new wxBitmapButton(this, ID_BITMAPBUTTON28, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON28"));
    FlexGridSizer8->Add(BitmapButton28, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton29 = new wxBitmapButton(this, ID_BITMAPBUTTON29, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON29"));
    FlexGridSizer8->Add(BitmapButton29, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton30 = new wxBitmapButton(this, ID_BITMAPBUTTON30, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON30"));
    FlexGridSizer8->Add(BitmapButton30, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(FlexGridSizer8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer9 = new wxFlexGridSizer(6, 1, 0, 0);
    BitmapButton31 = new wxBitmapButton(this, ID_BITMAPBUTTON31, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON31"));
    FlexGridSizer9->Add(BitmapButton31, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton32 = new wxBitmapButton(this, ID_BITMAPBUTTON32, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON32"));
    FlexGridSizer9->Add(BitmapButton32, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton33 = new wxBitmapButton(this, ID_BITMAPBUTTON33, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON33"));
    FlexGridSizer9->Add(BitmapButton33, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton34 = new wxBitmapButton(this, ID_BITMAPBUTTON34, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON34"));
    FlexGridSizer9->Add(BitmapButton34, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton35 = new wxBitmapButton(this, ID_BITMAPBUTTON35, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON35"));
    FlexGridSizer9->Add(BitmapButton35, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton36 = new wxBitmapButton(this, ID_BITMAPBUTTON36, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON36"));
    FlexGridSizer9->Add(BitmapButton36, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(FlexGridSizer9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer10 = new wxFlexGridSizer(6, 1, 0, 0);
    BitmapButton37 = new wxBitmapButton(this, ID_BITMAPBUTTON37, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON37"));
    FlexGridSizer10->Add(BitmapButton37, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton38 = new wxBitmapButton(this, ID_BITMAPBUTTON38, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON38"));
    FlexGridSizer10->Add(BitmapButton38, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton39 = new wxBitmapButton(this, ID_BITMAPBUTTON39, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON39"));
    FlexGridSizer10->Add(BitmapButton39, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton40 = new wxBitmapButton(this, ID_BITMAPBUTTON40, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON40"));
    FlexGridSizer10->Add(BitmapButton40, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton41 = new wxBitmapButton(this, ID_BITMAPBUTTON41, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON41"));
    FlexGridSizer10->Add(BitmapButton41, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton42 = new wxBitmapButton(this, ID_BITMAPBUTTON42, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON42"));
    FlexGridSizer10->Add(BitmapButton42, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(FlexGridSizer10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer11 = new wxFlexGridSizer(6, 1, 0, 0);
    BitmapButton43 = new wxBitmapButton(this, ID_BITMAPBUTTON43, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON43"));
    FlexGridSizer11->Add(BitmapButton43, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton44 = new wxBitmapButton(this, ID_BITMAPBUTTON44, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON44"));
    FlexGridSizer11->Add(BitmapButton44, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton45 = new wxBitmapButton(this, ID_BITMAPBUTTON45, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON45"));
    FlexGridSizer11->Add(BitmapButton45, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton46 = new wxBitmapButton(this, ID_BITMAPBUTTON46, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON46"));
    FlexGridSizer11->Add(BitmapButton46, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton47 = new wxBitmapButton(this, ID_BITMAPBUTTON47, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON47"));
    FlexGridSizer11->Add(BitmapButton47, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton48 = new wxBitmapButton(this, ID_BITMAPBUTTON48, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON48"));
    FlexGridSizer11->Add(BitmapButton48, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(FlexGridSizer11, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2->Add(FlexGridSizer1, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer3 = new wxFlexGridSizer(0, 7, 0, 0);
    BitmapButton1 = new wxBitmapButton(this, ID_BITMAPBUTTON1, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
    BitmapButton1->Hide();
    FlexGridSizer3->Add(BitmapButton1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton2 = new wxBitmapButton(this, ID_BITMAPBUTTON2, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON2"));
    BitmapButton2->Hide();
    FlexGridSizer3->Add(BitmapButton2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton3 = new wxBitmapButton(this, ID_BITMAPBUTTON3, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON3"));
    BitmapButton3->Hide();
    FlexGridSizer3->Add(BitmapButton3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton4 = new wxBitmapButton(this, ID_BITMAPBUTTON4, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON4"));
    BitmapButton4->SetMaxSize(wxSize(50,50));
    BitmapButton4->Hide();
    FlexGridSizer3->Add(BitmapButton4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton5 = new wxBitmapButton(this, ID_BITMAPBUTTON5, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON5"));
    BitmapButton5->Hide();
    FlexGridSizer3->Add(BitmapButton5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton6 = new wxBitmapButton(this, ID_BITMAPBUTTON6, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON6"));
    BitmapButton6->Hide();
    FlexGridSizer3->Add(BitmapButton6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton49 = new wxBitmapButton(this, ID_BITMAPBUTTON49, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON49"));
    BitmapButton49->Hide();
    FlexGridSizer3->Add(BitmapButton49, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2->Add(FlexGridSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer4->Add(FlexGridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer17->Add(FlexGridSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer14 = new wxFlexGridSizer(0, 1, 0, 0);
    FlexGridSizer30 = new wxFlexGridSizer(0, 3, 0, 0);
    FlexGridSizer12 = new wxFlexGridSizer(0, 1, 0, 0);
    BitmapButton51 = new wxBitmapButton(this, ID_BITMAPBUTTON51, wxNullBitmap, wxDefaultPosition, wxSize(150,30), wxBU_AUTODRAW|wxBORDER_NONE, wxDefaultValidator, _T("ID_BITMAPBUTTON51"));
    wxFont BitmapButton51Font(10,wxFONTFAMILY_MODERN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Consolas"),wxFONTENCODING_DEFAULT);
    BitmapButton51->SetFont(BitmapButton51Font);
    FlexGridSizer12->Add(BitmapButton51, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton52 = new wxBitmapButton(this, ID_BITMAPBUTTON52, wxNullBitmap, wxDefaultPosition, wxSize(150,30), wxBU_AUTODRAW|wxBORDER_NONE, wxDefaultValidator, _T("ID_BITMAPBUTTON52"));
    FlexGridSizer12->Add(BitmapButton52, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("Wybierz rodzaj rozgrywki"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    FlexGridSizer12->Add(StaticText7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer20 = new wxFlexGridSizer(0, 2, 0, 0);
    RadioButton1 = new wxRadioButton(this, ID_RADIOBUTTON1, _("2 Gracz"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON1"));
    FlexGridSizer20->Add(RadioButton1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    RadioButton2 = new wxRadioButton(this, ID_RADIOBUTTON2, _("Komputer"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON2"));
    RadioButton2->SetValue(true);
    FlexGridSizer20->Add(RadioButton2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer12->Add(FlexGridSizer20, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer30->Add(FlexGridSizer12, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer29 = new wxFlexGridSizer(0, 1, 0, 0);
    StaticText8 = new wxStaticText(this, ID_STATICTEXT8, _("Komputerek: "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
    FlexGridSizer29->Add(StaticText8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer21 = new wxFlexGridSizer(0, 7, 0, 0);
    FlexGridSizer22 = new wxFlexGridSizer(0, 1, 0, 0);
    StaticText14 = new wxStaticText(this, ID_STATICTEXT14, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT14"));
    FlexGridSizer22->Add(StaticText14, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText13 = new wxStaticText(this, ID_STATICTEXT13, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT13"));
    FlexGridSizer22->Add(StaticText13, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText12 = new wxStaticText(this, ID_STATICTEXT12, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT12"));
    FlexGridSizer22->Add(StaticText12, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText11 = new wxStaticText(this, ID_STATICTEXT11, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT11"));
    FlexGridSizer22->Add(StaticText11, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText10 = new wxStaticText(this, ID_STATICTEXT10, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
    FlexGridSizer22->Add(StaticText10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText9 = new wxStaticText(this, ID_STATICTEXT9, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
    FlexGridSizer22->Add(StaticText9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer21->Add(FlexGridSizer22, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer23 = new wxFlexGridSizer(0, 1, 0, 0);
    StaticText21 = new wxStaticText(this, ID_STATICTEXT21, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT21"));
    FlexGridSizer23->Add(StaticText21, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText20 = new wxStaticText(this, ID_STATICTEXT20, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT20"));
    FlexGridSizer23->Add(StaticText20, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText19 = new wxStaticText(this, ID_STATICTEXT19, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT19"));
    FlexGridSizer23->Add(StaticText19, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText18 = new wxStaticText(this, ID_STATICTEXT18, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT18"));
    FlexGridSizer23->Add(StaticText18, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText17 = new wxStaticText(this, ID_STATICTEXT17, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT17"));
    FlexGridSizer23->Add(StaticText17, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText16 = new wxStaticText(this, ID_STATICTEXT16, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT16"));
    FlexGridSizer23->Add(StaticText16, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer21->Add(FlexGridSizer23, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer24 = new wxFlexGridSizer(0, 1, 0, 0);
    StaticText28 = new wxStaticText(this, ID_STATICTEXT28, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT28"));
    FlexGridSizer24->Add(StaticText28, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText27 = new wxStaticText(this, ID_STATICTEXT27, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT27"));
    FlexGridSizer24->Add(StaticText27, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText26 = new wxStaticText(this, ID_STATICTEXT26, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT26"));
    FlexGridSizer24->Add(StaticText26, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText25 = new wxStaticText(this, ID_STATICTEXT25, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT25"));
    FlexGridSizer24->Add(StaticText25, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText24 = new wxStaticText(this, ID_STATICTEXT24, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT24"));
    FlexGridSizer24->Add(StaticText24, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText23 = new wxStaticText(this, ID_STATICTEXT23, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT23"));
    FlexGridSizer24->Add(StaticText23, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer21->Add(FlexGridSizer24, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer25 = new wxFlexGridSizer(0, 1, 0, 0);
    StaticText35 = new wxStaticText(this, ID_STATICTEXT35, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT35"));
    FlexGridSizer25->Add(StaticText35, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText34 = new wxStaticText(this, ID_STATICTEXT34, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT34"));
    FlexGridSizer25->Add(StaticText34, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText33 = new wxStaticText(this, ID_STATICTEXT33, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT33"));
    FlexGridSizer25->Add(StaticText33, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText32 = new wxStaticText(this, ID_STATICTEXT32, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT32"));
    FlexGridSizer25->Add(StaticText32, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText31 = new wxStaticText(this, ID_STATICTEXT31, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT31"));
    FlexGridSizer25->Add(StaticText31, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText30 = new wxStaticText(this, ID_STATICTEXT30, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT30"));
    FlexGridSizer25->Add(StaticText30, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer21->Add(FlexGridSizer25, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer26 = new wxFlexGridSizer(0, 1, 0, 0);
    StaticText42 = new wxStaticText(this, ID_STATICTEXT42, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT42"));
    FlexGridSizer26->Add(StaticText42, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText41 = new wxStaticText(this, ID_STATICTEXT41, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT41"));
    FlexGridSizer26->Add(StaticText41, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText40 = new wxStaticText(this, ID_STATICTEXT40, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT40"));
    FlexGridSizer26->Add(StaticText40, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText39 = new wxStaticText(this, ID_STATICTEXT39, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT39"));
    FlexGridSizer26->Add(StaticText39, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText38 = new wxStaticText(this, ID_STATICTEXT38, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT38"));
    FlexGridSizer26->Add(StaticText38, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText37 = new wxStaticText(this, ID_STATICTEXT37, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT37"));
    FlexGridSizer26->Add(StaticText37, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer21->Add(FlexGridSizer26, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer27 = new wxFlexGridSizer(0, 1, 0, 0);
    StaticText49 = new wxStaticText(this, ID_STATICTEXT49, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT49"));
    FlexGridSizer27->Add(StaticText49, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText48 = new wxStaticText(this, ID_STATICTEXT48, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT48"));
    FlexGridSizer27->Add(StaticText48, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText47 = new wxStaticText(this, ID_STATICTEXT47, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT47"));
    FlexGridSizer27->Add(StaticText47, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText46 = new wxStaticText(this, ID_STATICTEXT46, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT46"));
    FlexGridSizer27->Add(StaticText46, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText45 = new wxStaticText(this, ID_STATICTEXT45, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT45"));
    FlexGridSizer27->Add(StaticText45, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText44 = new wxStaticText(this, ID_STATICTEXT44, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT44"));
    FlexGridSizer27->Add(StaticText44, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer21->Add(FlexGridSizer27, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer28 = new wxFlexGridSizer(0, 1, 0, 0);
    StaticText22 = new wxStaticText(this, ID_STATICTEXT22, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT22"));
    FlexGridSizer28->Add(StaticText22, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText15 = new wxStaticText(this, ID_STATICTEXT15, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT15"));
    FlexGridSizer28->Add(StaticText15, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText54 = new wxStaticText(this, ID_STATICTEXT54, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT54"));
    FlexGridSizer28->Add(StaticText54, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText53 = new wxStaticText(this, ID_STATICTEXT53, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT53"));
    FlexGridSizer28->Add(StaticText53, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText52 = new wxStaticText(this, ID_STATICTEXT52, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT52"));
    FlexGridSizer28->Add(StaticText52, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText51 = new wxStaticText(this, ID_STATICTEXT51, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT51"));
    FlexGridSizer28->Add(StaticText51, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer21->Add(FlexGridSizer28, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer29->Add(FlexGridSizer21, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer30->Add(FlexGridSizer29, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer14->Add(FlexGridSizer30, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer15 = new wxFlexGridSizer(0, 2, 0, 0);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Tura gracza:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    FlexGridSizer15->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton53 = new wxBitmapButton(this, ID_BITMAPBUTTON53, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON53"));
    FlexGridSizer15->Add(BitmapButton53, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer14->Add(FlexGridSizer15, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    CheckBox1 = new wxCheckBox(this, ID_CHECKBOX1, _("Rundy"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    CheckBox1->SetValue(true);
    FlexGridSizer14->Add(CheckBox1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer19 = new wxFlexGridSizer(0, 1, 0, 0);
    FlexGridSizer18 = new wxFlexGridSizer(0, 2, 0, 0);
    StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("Liczba rund: "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    FlexGridSizer18->Add(StaticText6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Choice1 = new wxChoice(this, ID_CHOICE1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
    Choice1->SetSelection( Choice1->Append(_("1")) );
    Choice1->Append(_("3"));
    Choice1->Append(_("5"));
    Choice1->Append(_("7"));
    FlexGridSizer18->Add(Choice1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer19->Add(FlexGridSizer18, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer16 = new wxFlexGridSizer(0, 5, 0, 0);
    BitmapButton54 = new wxBitmapButton(this, ID_BITMAPBUTTON54, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON54"));
    FlexGridSizer16->Add(BitmapButton54, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("0"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    FlexGridSizer16->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("-"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    FlexGridSizer16->Add(StaticText4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("0"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    FlexGridSizer16->Add(StaticText5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton55 = new wxBitmapButton(this, ID_BITMAPBUTTON55, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON55"));
    FlexGridSizer16->Add(BitmapButton55, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer19->Add(FlexGridSizer16, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer14->Add(FlexGridSizer19, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton50 = new wxBitmapButton(this, ID_BITMAPBUTTON50, wxNullBitmap, wxDefaultPosition, wxSize(150,30), wxBU_AUTODRAW|wxBORDER_NONE, wxDefaultValidator, _T("ID_BITMAPBUTTON50"));
    wxFont BitmapButton50Font(10,wxFONTFAMILY_MODERN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Consolas"),wxFONTENCODING_DEFAULT);
    BitmapButton50->SetFont(BitmapButton50Font);
    FlexGridSizer14->Add(BitmapButton50, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer17->Add(FlexGridSizer14, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer13->Add(FlexGridSizer17, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(FlexGridSizer13, 1, wxALL, 5);
    SetSizer(BoxSizer1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);
    Center();

    Connect(ID_BITMAPBUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&connect_fourDialog::OnBitmapButton1Click);
    Connect(ID_BITMAPBUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&connect_fourDialog::OnBitmapButton1Click);
    Connect(ID_BITMAPBUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&connect_fourDialog::OnBitmapButton1Click);
    Connect(ID_BITMAPBUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&connect_fourDialog::OnBitmapButton1Click);
    Connect(ID_BITMAPBUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&connect_fourDialog::OnBitmapButton1Click);
    Connect(ID_BITMAPBUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&connect_fourDialog::OnBitmapButton1Click);
    Connect(ID_BITMAPBUTTON49,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&connect_fourDialog::OnBitmapButton1Click);
    Connect(ID_BITMAPBUTTON51,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&connect_fourDialog::OnBitmapButton51Click);
    Connect(ID_BITMAPBUTTON52,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&connect_fourDialog::OnBitmapButton52Click);
    Connect(ID_RADIOBUTTON1,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&connect_fourDialog::OnRadioButton1Select);
    Connect(ID_RADIOBUTTON2,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&connect_fourDialog::OnRadioButton2Select);
    Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&connect_fourDialog::OnCheckBox1Click);
    Connect(ID_CHOICE1,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&connect_fourDialog::OnChoice1Select);
    Connect(ID_BITMAPBUTTON50,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&connect_fourDialog::OnQuit);
    //*)

    //ustawienie tablic i rysunków
    {
    rysunki[0]=wxBitmap(wxImage("bin/Release/pictures/blank.bmp"));
    rysunki[1]=wxBitmap(wxImage("bin/Release/pictures/circle.bmp"));
    rysunki[2]=wxBitmap(wxImage("bin/Release/pictures/circle2.bmp"));
    rysunki[3]=wxBitmap(wxImage("bin/Release/pictures/blank_button.bmp"));
    rysunki[4]=wxBitmap(wxImage("bin/Release/pictures/restart.bmp"));
    rysunki[5]=wxBitmap(wxImage("bin/Release/pictures/exit.bmp"));
    rysunki[6]=wxBitmap(wxImage("bin/Release/pictures/tutorial.bmp"));
    rysunki[7]=wxBitmap(wxImage("bin/Release/pictures/tutorial.jpg"));
    rysunki[8]=wxBitmap(wxImage("bin/Release/pictures/restart.jpg"));
    rysunki[9]=wxBitmap(wxImage("bin/Release/pictures/quit.jpg"));
    rysunki[10]=wxBitmap(wxImage("bin/Release/pictures/connect_4.png"));
    #define pw(nr, i) plansza1[i]=BitmapButton ##nr
    pw(7,0); pw(8,1); pw(9,2); pw(10,3); pw(11,4); pw(12,5);
    #undef pw

    #define pw(nr, i) plansza2[i]=BitmapButton ##nr
    pw(13,0); pw(14,1); pw(15,2); pw(16,3); pw(17,4); pw(18,5);
    #undef pw

    #define pw(nr, i) plansza3[i]=BitmapButton ##nr
    pw(19,0); pw(20,1); pw(21,2); pw(22,3); pw(23,4); pw(24,5);
    #undef pw

    #define pw(nr, i) plansza4[i]=BitmapButton ##nr
    pw(25,0); pw(26,1); pw(27,2); pw(28,3); pw(29,4); pw(30,5);
    #undef pw

    #define pw(nr, i) plansza5[i]=BitmapButton ##nr
    pw(31,0); pw(32,1); pw(33,2); pw(34,3); pw(35,4); pw(36,5);
    #undef pw

    #define pw(nr, i) plansza6[i]=BitmapButton ##nr
    pw(37,0); pw(38,1); pw(39,2); pw(40,3); pw(41,4); pw(42,5);
    #undef pw

    #define pw(nr, i) plansza7[i]=BitmapButton ##nr
    pw(43,0); pw(44,1); pw(45,2); pw(46,3); pw(47,4); pw(48,5);
    #undef pw

    for(int i=0; i<6; i++)
    {
        Connect(plansza1[i]->GetId(), wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&connect_fourDialog::OnBitmapButton1Click);
        Connect(plansza2[i]->GetId(), wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&connect_fourDialog::OnBitmapButton2Click);
        Connect(plansza3[i]->GetId(), wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&connect_fourDialog::OnBitmapButton3Click);
        Connect(plansza4[i]->GetId(), wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&connect_fourDialog::OnBitmapButton4Click);
        Connect(plansza5[i]->GetId(), wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&connect_fourDialog::OnBitmapButton5Click);
        Connect(plansza6[i]->GetId(), wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&connect_fourDialog::OnBitmapButton6Click);
        Connect(plansza7[i]->GetId(), wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&connect_fourDialog::OnBitmapButton49Click);
        plansza1[i] -> SetBitmap(rysunki[0]);
        plansza2[i] -> SetBitmap(rysunki[0]);
        plansza3[i] -> SetBitmap(rysunki[0]);
        plansza4[i] -> SetBitmap(rysunki[0]);
        plansza5[i] -> SetBitmap(rysunki[0]);
        plansza6[i] -> SetBitmap(rysunki[0]);
        plansza7[i] -> SetBitmap(rysunki[0]);
    }
    //BitmapButton50 -> SetBitmap(rysunki[5]);
    BitmapButton50 -> SetBitmap(rysunki[9]);
    BitmapButton50 -> SetLabel(wxString("Wyjdź z gry"));

    //BitmapButton52 -> SetBitmap(rysunki[4]);
    BitmapButton52 -> SetBitmap(rysunki[8]);
    BitmapButton52 -> SetLabel("Restart");
    //BitmapButton51 -> SetBitmap(rysunki[6]);
    BitmapButton51 -> SetBitmap(rysunki[7]);
    BitmapButton51 -> SetLabel(wxString("Instrukcja"));
    BitmapButton54 -> SetBitmap(rysunki[1]);
    BitmapButton55 -> SetBitmap(rysunki[2]);
    BitmapButton53 -> SetBitmap(rysunki[object.getroundCount()]);
    BoxSizer1 -> Fit(this);
    if(!CheckBox1 -> IsChecked()){
        BitmapButton54 -> Hide();
        BitmapButton55 -> Hide();
        StaticText3 -> Hide();
        StaticText4 -> Hide();
        StaticText5 -> Hide();
        StaticText6 -> Hide();
        Choice1 -> Hide();
    }
    if(CheckBox1 -> IsChecked()){
        BitmapButton54 -> Show();
        BitmapButton55 -> Show();
        StaticText3 -> Show();
        StaticText4 -> Show();
        StaticText5 -> Show();
        StaticText6 -> Show();
        Choice1 -> Show();
    }
    if( RadioButton2 -> GetValue() == true) {
        object.setgraAI(true);
        StaticText8 -> SetLabel("Komputerek: Tak");
        BoxSizer1 -> Fit(this);
    }
        else{
            object.setgraAI(false);
            StaticText8 -> SetLabel("Komputerek: Nie");
        }
    debug_flag = false;
    debugging();
    BoxSizer1 -> Fit(this);
     BitmapButton53 -> SetBitmap(rysunki[object.getroundCount()]);
    if(RadioButton2 -> GetValue() == true) gra_z_AI = true;
    else gra_z_AI = false;
}
StaticBitmap1 -> SetBitmap(rysunki[10]);
}

connect_fourDialog::~connect_fourDialog()
{

}

void connect_fourDialog::czyszczenie_rysunkow(){
    for(int i =0;i<6;i++){
        plansza1[i] -> SetBitmap(rysunki[0]);
        plansza2[i] -> SetBitmap(rysunki[0]);
        plansza3[i] -> SetBitmap(rysunki[0]);
        plansza4[i] -> SetBitmap(rysunki[0]);
        plansza5[i] -> SetBitmap(rysunki[0]);
        plansza6[i] -> SetBitmap(rysunki[0]);
        plansza7[i] -> SetBitmap(rysunki[0]);
    }
    for(int i =0;i<7;i++){
        cykl[i] = 5;
    }

}


void connect_fourDialog::przycisk(int kolumna){ //funkcja przycisk do obsługi gry z 2 graczem
    if(cykl[kolumna-1]>-1){
    object.setLastPickCol(kolumna);
    object.WykonajRuch();
    Choice1 -> Disable();
    switch(kolumna) {
        case 1:
            if(object.gettokenColor() == 1) {
            plansza1[cykl[kolumna-1]] -> SetBitmap(rysunki[1]);
            BitmapButton53 -> SetBitmap(rysunki[2]);
            } else {
                plansza1[cykl[kolumna-1]] -> SetBitmap(rysunki[2]);
                BitmapButton53 -> SetBitmap(rysunki[1]);
            }
            break;
    case 2:
            if(object.gettokenColor() == 1) {
            plansza2[cykl[kolumna-1]] -> SetBitmap(rysunki[1]);
            BitmapButton53 -> SetBitmap(rysunki[2]);
            } else {
                plansza2[cykl[kolumna-1]] -> SetBitmap(rysunki[2]);
                BitmapButton53 -> SetBitmap(rysunki[1]);
            }
            break;
    case 3:
            if(object.gettokenColor() == 1) {
            plansza3[cykl[kolumna-1]] -> SetBitmap(rysunki[1]);
            BitmapButton53 -> SetBitmap(rysunki[2]);
            } else {
                plansza3[cykl[kolumna-1]] -> SetBitmap(rysunki[2]);
                BitmapButton53 -> SetBitmap(rysunki[1]);
            }
            break;
    case 4:
            if(object.gettokenColor() == 1) {
            plansza4[cykl[kolumna-1]] -> SetBitmap(rysunki[1]);
            BitmapButton53 -> SetBitmap(rysunki[2]);
            } else {
                plansza4[cykl[kolumna-1]] -> SetBitmap(rysunki[2]);
                BitmapButton53 -> SetBitmap(rysunki[1]);
            }
            break;
    case 5:
            if(object.gettokenColor() == 1) {
            plansza5[cykl[kolumna-1]] -> SetBitmap(rysunki[1]);
            BitmapButton53 -> SetBitmap(rysunki[2]);
            } else {
                plansza5[cykl[kolumna-1]] -> SetBitmap(rysunki[2]);
                BitmapButton53 -> SetBitmap(rysunki[1]);
            }
            break;
    case 6:
            if(object.gettokenColor() == 1) {
            plansza6[cykl[kolumna-1]] -> SetBitmap(rysunki[1]);
            BitmapButton53 -> SetBitmap(rysunki[2]);
            } else {
                plansza6[cykl[kolumna-1]] -> SetBitmap(rysunki[2]);
                BitmapButton53 -> SetBitmap(rysunki[1]);
            }
            break;
    case 7:
            if(object.gettokenColor() == 1) {
            plansza7[cykl[kolumna-1]] -> SetBitmap(rysunki[1]);
            BitmapButton53 -> SetBitmap(rysunki[2]);
            } else {
                plansza7[cykl[kolumna-1]] -> SetBitmap(rysunki[2]);
                BitmapButton53 -> SetBitmap(rysunki[1]);
            }
            break;
    default:
            break;
    }
    cykl[kolumna-1]--;
    licznik_ruchow++;
    } else wxMessageBox("Ten ruch jest nielegalny.", "Tak nie wolno!");
    if(object.Rezultat() || licznik_ruchow == 42) {
            koniec_gry();
            koniec_meczu(stoi(object.rundy_graczy(0)), stoi(object.rundy_graczy(1)));
            object.ending();
            BitmapButton53 -> SetBitmap(rysunki[object.getroundCount()]);
            }
}



void connect_fourDialog::przycisk_AI(int kolumna){ //funkcja przycisk do obsługi gry z komputerem
    if(cykl[kolumna-1]>=0){
    object.setLastPickCol(kolumna);
    object.WykonajRuch_z_Komputerem();
    Choice1 -> Disable();
    //ruchy gracza
    switch(kolumna) {
        case 1:
        plansza1[cykl[kolumna-1]] -> SetBitmap(rysunki[1]);
        BitmapButton53 -> SetBitmap(rysunki[2]);
        break;
    case 2:
        plansza2[cykl[kolumna-1]] -> SetBitmap(rysunki[1]);
        BitmapButton53 -> SetBitmap(rysunki[2]);
        break;
    case 3:
        plansza3[cykl[kolumna-1]] -> SetBitmap(rysunki[1]);
        BitmapButton53 -> SetBitmap(rysunki[2]);
        break;
    case 4:
        plansza4[cykl[kolumna-1]] -> SetBitmap(rysunki[1]);
        BitmapButton53 -> SetBitmap(rysunki[2]);
        break;
    case 5:
        plansza5[cykl[kolumna-1]] -> SetBitmap(rysunki[1]);
        BitmapButton53 -> SetBitmap(rysunki[2]);
        break;
    case 6:
        plansza6[cykl[kolumna-1]] -> SetBitmap(rysunki[1]);
        BitmapButton53 -> SetBitmap(rysunki[2]);
        break;
    case 7:
        plansza7[cykl[kolumna-1]] -> SetBitmap(rysunki[1]);
        BitmapButton53 -> SetBitmap(rysunki[2]);
        break;
    default:
        break;
    }
        cykl[kolumna-1]--;
    licznik_ruchow++;
    } else {
        wxMessageBox("Ten ruch jest nielegalny.", "Tak nie wolno!");

        return;
    }

    if(object.Rezultat() || licznik_ruchow == 42) {
        koniec_gry();
        koniec_meczu(stoi(object.rundy_graczy(0)), stoi(object.rundy_graczy(1)));
        object.ending();
        if(gra_z_AI) BitmapButton53 -> SetBitmap(rysunki[1]);
            else BitmapButton53 -> SetBitmap(rysunki[object.getroundCount()]);
        return;
    }
     //AI
//debugging();

    object.Ruch_Komputera();
    kolumna_bota = object.getkolumna_bota()+1;
    StaticText8 -> SetLabel(std::to_string(kolumna_bota));
     if(cykl[kolumna_bota-1]>=0){
    object.setLastPickCol(kolumna_bota);
    switch(kolumna_bota) {
        case 1:
        plansza1[cykl[kolumna_bota-1]] -> SetBitmap(rysunki[2]);
        BitmapButton53 -> SetBitmap(rysunki[1]);
        break;
    case 2:
        plansza2[cykl[kolumna_bota-1]] -> SetBitmap(rysunki[2]);
        BitmapButton53 -> SetBitmap(rysunki[1]);
        break;
    case 3:
        plansza3[cykl[kolumna_bota-1]] -> SetBitmap(rysunki[2]);
        BitmapButton53 -> SetBitmap(rysunki[1]);
        break;
    case 4:
        plansza4[cykl[kolumna_bota-1]] -> SetBitmap(rysunki[2]);
        BitmapButton53 -> SetBitmap(rysunki[1]);
        break;
    case 5:
        plansza5[cykl[kolumna_bota-1]] -> SetBitmap(rysunki[2]);
        BitmapButton53 -> SetBitmap(rysunki[1]);
        break;
    case 6:
        plansza6[cykl[kolumna_bota-1]] -> SetBitmap(rysunki[2]);
        BitmapButton53 -> SetBitmap(rysunki[1]);
        break;
    case 7:
        plansza7[cykl[kolumna_bota-1]] -> SetBitmap(rysunki[2]);
        BitmapButton53 -> SetBitmap(rysunki[1]);
        break;
    default:
        break;
    }

    }
    cykl[kolumna_bota-1]--;
    licznik_ruchow++;
    //debugging();
    if(object.Rezultat() || licznik_ruchow == 42) {
        koniec_gry();
        koniec_meczu(stoi(object.rundy_graczy(0)), stoi(object.rundy_graczy(1)));
        object.ending();
        if(gra_z_AI) BitmapButton53 -> SetBitmap(rysunki[1]);
            else BitmapButton53 -> SetBitmap(rysunki[object.getroundCount()]);
    }
}




void connect_fourDialog::OnBitmapButton1Click(wxCommandEvent& event){ //kolumna 1
    if(gra_z_AI) przycisk_AI(1);
        else przycisk(1);
}


void connect_fourDialog::OnBitmapButton2Click(wxCommandEvent& event){ //kolumna 2
    if(gra_z_AI) przycisk_AI(2);
        else przycisk(2);
}
void connect_fourDialog::OnBitmapButton3Click(wxCommandEvent& event){ //kolumna 3
    if(gra_z_AI) przycisk_AI(3);
        else przycisk(3);
}


void connect_fourDialog::OnBitmapButton4Click(wxCommandEvent& event){ //kolumna 4
    if(gra_z_AI) przycisk_AI(4);
        else przycisk(4);
}


void connect_fourDialog::OnBitmapButton5Click(wxCommandEvent& event){ //kolumna 5
    if(gra_z_AI) przycisk_AI(5);
        else przycisk(5);
}


void connect_fourDialog::OnBitmapButton6Click(wxCommandEvent& event){ //kolumna 6
    if(gra_z_AI) przycisk_AI(6);
        else przycisk(6);
}


void connect_fourDialog::OnBitmapButton49Click(wxCommandEvent& event){ //kolumna 7
    if(gra_z_AI) przycisk_AI(7);
        else przycisk(7);
}

void connect_fourDialog::OnQuit(wxCommandEvent& event){
    Close();
}



void connect_fourDialog::OnBitmapButton51Click(wxCommandEvent& event){//instrukcja
std::string instrukcja = "Pierwszy gracz wrzuca swój żeton do wybranej przez niego kolumny. Żeton zajmuje najniższą pozycję. Gracze wrzucają swoje żetony na przemian, aż jeden z nich ułoży cztery żetony w poziomie, pionie lub ukosie. Wygrywa ten gracz, który zrobi to jako pierwszy. Jeżeli natomiast plansza się zapełni, a nie utworzy się żadna czwórka, jest remis.";
wxMessageBox(s2w(instrukcja),"Instrukcja");
}


void connect_fourDialog::OnBitmapButton52Click(wxCommandEvent& event){//restart
   czyszczenie_rysunkow();
   object.ending();
   if(RadioButton2 -> GetValue() == true) BitmapButton53 -> SetBitmap(rysunki[1]);
        else BitmapButton53 -> SetBitmap(rysunki[object.getroundCount()]);
   StaticText3 -> SetLabel("0");
   StaticText5 -> SetLabel("0");
   object.koniec_rund();
   if(RadioButton2 -> GetValue() == true) gra_z_AI = true;
        else gra_z_AI = false;
   //debugging();
   Choice1 -> Enable();
}

void connect_fourDialog::koniec_gry(){ //koniec pojedyńczej rozgrywki
    if(licznik_ruchow==42) wxMessageBox(s2w("Wszystkie miejsca na planszy zostały zajęte, nikt nie wygrał."), s2w("Remis!"));
    else if(object.getToken()==2 && gra_z_AI) wxMessageBox(s2w("Komputer wygrał."), s2w("Zwycięstwo!"));
        else wxMessageBox(s2w("Gracz "+std::to_string(object.getToken())+" wygrał."), s2w("Zwycięstwo!"));
    if(object.getToken() == 1) StaticText3 -> SetLabel(object.rundy_graczy(0));
        else StaticText5 -> SetLabel(object.rundy_graczy(1));
    if(RadioButton2 -> GetValue() == true) gra_z_AI = true;
        else gra_z_AI = false;
    licznik_rund++;
    czyszczenie_rysunkow();
    //update();
    licznik_ruchow = 0;
}

void connect_fourDialog::koniec_meczu(int gracz_1, int gracz_2){ //koniec gry z rundami
    if(liczba_rund==1 &&(gracz_1==1 || gracz_2==1)){
        StaticText3 -> SetLabel("0");
        StaticText5 -> SetLabel("0");
        object.koniec_rund();
        Choice1 -> Enable();
    } else if((liczba_rund == 3 && (gracz_1==2 || gracz_2==2)) ||
              (liczba_rund == 5 && (gracz_1==3 || gracz_2==3)) ||
              (liczba_rund == 7 && (gracz_1==4 || gracz_2==4))) {
                if(gra_z_AI && (object.getToken()==2)) wxMessageBox(s2w("Komputer wygrał większość rund."), s2w("Koniec gry!"));
                else wxMessageBox(s2w("Gracz "+std::to_string(object.getToken())+" wygrał większość rund."), s2w("Koniec gry!"));
                StaticText3 -> SetLabel("0");
                StaticText5 -> SetLabel("0");
                object.koniec_rund();
                Choice1 -> Enable();
            }
    if(RadioButton2 -> GetValue() == true) gra_z_AI = true;
    else gra_z_AI = false;
}


//POLSKIE ZNAKI W OKNIE
wxString s2w(std::string s){
    return wxString(s.c_str(), wxConvUTF8);
}

void connect_fourDialog::OnCheckBox1Click(wxCommandEvent& event){//checkbox od rund
if(!CheckBox1 -> IsChecked()){
        BitmapButton54 -> Hide();
        BitmapButton55 -> Hide();
        Choice1 -> Hide();
        StaticText3 -> Hide();
        StaticText4 -> Hide();
        StaticText5 -> Hide();
        StaticText6 -> Hide();
    } else {
        BitmapButton54 -> Show();
        BitmapButton55 -> Show();
        Choice1 -> Show();
        StaticText3 -> Show();
        StaticText4 -> Show();
        StaticText5 -> Show();
        StaticText6 -> Show();
        BoxSizer1 -> Fit(this);
        }
}

void connect_fourDialog::SetLiczbaRund(int rundy){ //set rundy
    liczba_rund = rundy;
}


void connect_fourDialog::OnChoice1Select(wxCommandEvent& event){  //wybór liczby rund
    if(Choice1 ->GetSelection()==0) SetLiczbaRund(1);
        else if(Choice1 ->GetSelection()==1) SetLiczbaRund(3);
                else SetLiczbaRund(5);
}

void connect_fourDialog::OnRadioButton1Select(wxCommandEvent& event){  //2 graczy

    StaticText8 -> SetLabel("Komputerek: Nie");
    //debug_flag = false;
    //debugging();
}

void connect_fourDialog::OnRadioButton2Select(wxCommandEvent& event){ // z komputerem

    StaticText8 -> SetLabel("Komputerek: Tak");
    //debug_flag = true;
    //debugging();
}

void connect_fourDialog::update(){ //refresh tablicy z ruchami

StaticText9 -> SetLabel(std::to_string(object.DrukujPlansze(0, 0)));
StaticText10 -> SetLabel(std::to_string(object.DrukujPlansze(0, 1)));
StaticText11 -> SetLabel(std::to_string(object.DrukujPlansze(0, 2)));
StaticText12 -> SetLabel(std::to_string(object.DrukujPlansze(0, 3)));
StaticText13 -> SetLabel(std::to_string(object.DrukujPlansze(0, 4)));
StaticText14 -> SetLabel(std::to_string(object.DrukujPlansze(0, 5)));
StaticText16 -> SetLabel(std::to_string(object.DrukujPlansze(1, 0)));
StaticText17 -> SetLabel(std::to_string(object.DrukujPlansze(1, 1)));
StaticText18 -> SetLabel(std::to_string(object.DrukujPlansze(1, 2)));
StaticText19 -> SetLabel(std::to_string(object.DrukujPlansze(1, 3)));
StaticText20 -> SetLabel(std::to_string(object.DrukujPlansze(1, 4)));
StaticText21 -> SetLabel(std::to_string(object.DrukujPlansze(1, 5)));
StaticText23 -> SetLabel(std::to_string(object.DrukujPlansze(2, 0)));
StaticText24 -> SetLabel(std::to_string(object.DrukujPlansze(2, 1)));
StaticText25 -> SetLabel(std::to_string(object.DrukujPlansze(2, 2)));
StaticText26 -> SetLabel(std::to_string(object.DrukujPlansze(2, 3)));
StaticText27 -> SetLabel(std::to_string(object.DrukujPlansze(2, 4)));
StaticText28 -> SetLabel(std::to_string(object.DrukujPlansze(2, 5)));
StaticText30 -> SetLabel(std::to_string(object.DrukujPlansze(3, 0)));
StaticText31 -> SetLabel(std::to_string(object.DrukujPlansze(3, 1)));
StaticText32 -> SetLabel(std::to_string(object.DrukujPlansze(3, 2)));
StaticText33 -> SetLabel(std::to_string(object.DrukujPlansze(3, 3)));
StaticText34 -> SetLabel(std::to_string(object.DrukujPlansze(3, 4)));
StaticText35 -> SetLabel(std::to_string(object.DrukujPlansze(3, 5)));
StaticText37 -> SetLabel(std::to_string(object.DrukujPlansze(4, 0)));
StaticText38 -> SetLabel(std::to_string(object.DrukujPlansze(4, 1)));
StaticText39 -> SetLabel(std::to_string(object.DrukujPlansze(4, 2)));
StaticText40 -> SetLabel(std::to_string(object.DrukujPlansze(4, 3)));
StaticText41 -> SetLabel(std::to_string(object.DrukujPlansze(4, 4)));
StaticText42 -> SetLabel(std::to_string(object.DrukujPlansze(4, 5)));
StaticText44 -> SetLabel(std::to_string(object.DrukujPlansze(5, 0)));
StaticText45 -> SetLabel(std::to_string(object.DrukujPlansze(5, 1)));
StaticText46 -> SetLabel(std::to_string(object.DrukujPlansze(5, 2)));
StaticText47 -> SetLabel(std::to_string(object.DrukujPlansze(5, 3)));
StaticText48 -> SetLabel(std::to_string(object.DrukujPlansze(5, 4)));
StaticText49 -> SetLabel(std::to_string(object.DrukujPlansze(5, 5)));
StaticText51 -> SetLabel(std::to_string(object.DrukujPlansze(6, 0)));
StaticText52 -> SetLabel(std::to_string(object.DrukujPlansze(6, 1)));
StaticText53 -> SetLabel(std::to_string(object.DrukujPlansze(6, 2)));
StaticText54 -> SetLabel(std::to_string(object.DrukujPlansze(6, 3)));
StaticText15 -> SetLabel(std::to_string(object.DrukujPlansze(6, 4)));
StaticText22 -> SetLabel(std::to_string(object.DrukujPlansze(6, 5)));
}

void connect_fourDialog::debugging(){//wizualne podejrzenie wewnętrznej tablicy docelowo funkcja nieużywana
    if(debug_flag == true){
StaticText8 -> Show();
StaticText9 -> Show();
StaticText10 -> Show();
StaticText11 -> Show();
StaticText12 -> Show();
StaticText13 -> Show();
StaticText14 -> Show();
StaticText16 -> Show();
StaticText17 -> Show();
StaticText18 -> Show();
StaticText19 -> Show();
StaticText20 -> Show();
StaticText21 -> Show();
StaticText23 -> Show();
StaticText24 -> Show();
StaticText25 -> Show();
StaticText26 -> Show();
StaticText27 -> Show();
StaticText28 -> Show();
StaticText30 -> Show();
StaticText31 -> Show();
StaticText32 -> Show();
StaticText33 -> Show();
StaticText34 -> Show();
StaticText35 -> Show();
StaticText37 -> Show();
StaticText38 -> Show();
StaticText39 -> Show();
StaticText40 -> Show();
StaticText41 -> Show();
StaticText42 -> Show();
StaticText44 -> Show();
StaticText45 -> Show();
StaticText46 -> Show();
StaticText47 -> Show();
StaticText48 -> Show();
StaticText49 -> Show();
StaticText51 -> Show();
StaticText52 -> Show();
StaticText53 -> Show();
StaticText54 -> Show();
StaticText15 -> Show();
StaticText22 -> Show();
StaticText2 -> Hide();
BitmapButton53 -> Hide();
BoxSizer1 -> Fit(this);
update();
    } else {
StaticText8 -> Hide();
StaticText9 -> Hide();
StaticText10 -> Hide();
StaticText11 -> Hide();
StaticText12 -> Hide();
StaticText13 -> Hide();
StaticText14 -> Hide();
StaticText16 -> Hide();
StaticText17 -> Hide();
StaticText18 -> Hide();
StaticText19 -> Hide();
StaticText20 -> Hide();
StaticText21 -> Hide();
StaticText23 -> Hide();
StaticText24 -> Hide();
StaticText25 -> Hide();
StaticText26 -> Hide();
StaticText27 -> Hide();
StaticText28 -> Hide();
StaticText30 -> Hide();
StaticText31 -> Hide();
StaticText32 -> Hide();
StaticText33 -> Hide();
StaticText34 -> Hide();
StaticText35 -> Hide();
StaticText37 -> Hide();
StaticText38 -> Hide();
StaticText39 -> Hide();
StaticText40 -> Hide();
StaticText41 -> Hide();
StaticText42 -> Hide();
StaticText44 -> Hide();
StaticText45 -> Hide();
StaticText46 -> Hide();
StaticText47 -> Hide();
StaticText48 -> Hide();
StaticText49 -> Hide();
StaticText51 -> Hide();
StaticText52 -> Hide();
StaticText53 -> Hide();
StaticText54 -> Hide();
StaticText15 -> Hide();
StaticText22 -> Hide();
StaticText2 -> Show();
BitmapButton53 -> Show();
BoxSizer1 -> Fit(this);

}
}



