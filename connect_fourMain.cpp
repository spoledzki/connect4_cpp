/***************************************************************
 * Name:      connect_fourMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2022-12-14
 * Copyright:  ()
 * License:
 **************************************************************/

#include "connect_fourMain.h"
#include <wx/msgdlg.h>
#include "Gra.h"
#include <ctime>
using namespace std;

//(*InternalHeaders(connect_fourDialog)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/settings.h>
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

//(*IdInit(connect_fourDialog)
const long connect_fourDialog::ID_STATICTEXT1 = wxNewId();
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
const long connect_fourDialog::ID_STATICLINE1 = wxNewId();
const long connect_fourDialog::ID_BITMAPBUTTON1 = wxNewId();
const long connect_fourDialog::ID_BITMAPBUTTON2 = wxNewId();
const long connect_fourDialog::ID_BITMAPBUTTON3 = wxNewId();
const long connect_fourDialog::ID_BITMAPBUTTON4 = wxNewId();
const long connect_fourDialog::ID_BITMAPBUTTON5 = wxNewId();
const long connect_fourDialog::ID_BITMAPBUTTON6 = wxNewId();
const long connect_fourDialog::ID_BITMAPBUTTON49 = wxNewId();
const long connect_fourDialog::ID_BUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(connect_fourDialog,wxDialog)
    //(*EventTable(connect_fourDialog)
    //*)
END_EVENT_TABLE()

connect_fourDialog::connect_fourDialog(wxWindow* parent,wxWindowID id)
{
    srand(time(NULL));
    //(*Initialize(connect_fourDialog)
    wxFlexGridSizer* FlexGridSizer10;
    wxFlexGridSizer* FlexGridSizer11;
    wxFlexGridSizer* FlexGridSizer12;
    wxFlexGridSizer* FlexGridSizer1;
    wxFlexGridSizer* FlexGridSizer2;
    wxFlexGridSizer* FlexGridSizer3;
    wxFlexGridSizer* FlexGridSizer4;
    wxFlexGridSizer* FlexGridSizer5;
    wxFlexGridSizer* FlexGridSizer6;
    wxFlexGridSizer* FlexGridSizer7;
    wxFlexGridSizer* FlexGridSizer8;
    wxFlexGridSizer* FlexGridSizer9;

    Create(parent, wxID_ANY, _("Connect 4"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
    SetBackgroundColour(wxColour(50,170,180));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    FlexGridSizer4 = new wxFlexGridSizer(0, 1, 0, 0);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Connect 4"), wxDefaultPosition, wxSize(267,48), wxALIGN_CENTRE, _T("ID_STATICTEXT1"));
    wxFont StaticText1Font = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    if ( !StaticText1Font.Ok() ) StaticText1Font = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    StaticText1Font.SetPointSize(20);
    StaticText1->SetFont(StaticText1Font);
    FlexGridSizer4->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 10);
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
    StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxDefaultPosition, wxSize(340,3), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    FlexGridSizer2->Add(StaticLine1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
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
    FlexGridSizer12 = new wxFlexGridSizer(0, 3, 0, 0);
    Button1 = new wxButton(this, ID_BUTTON1, _("Restart"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    FlexGridSizer12->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2->Add(FlexGridSizer12, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer4->Add(FlexGridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(FlexGridSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(BoxSizer1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_BITMAPBUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&connect_fourDialog::OnBitmapButton1Click);
    Connect(ID_BITMAPBUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&connect_fourDialog::OnBitmapButton2Click);
    Connect(ID_BITMAPBUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&connect_fourDialog::OnBitmapButton3Click);
    Connect(ID_BITMAPBUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&connect_fourDialog::OnBitmapButton4Click);
    Connect(ID_BITMAPBUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&connect_fourDialog::OnBitmapButton5Click);
    Connect(ID_BITMAPBUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&connect_fourDialog::OnBitmapButton6Click);
    Connect(ID_BITMAPBUTTON49,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&connect_fourDialog::OnBitmapButton49Click);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&connect_fourDialog::OnButton1Click);
    //*)

    //ustawienie tablic i rysunków
    {
    rysunki[0]=wxBitmap(wxImage("blank.bmp"));
    rysunki[1]=wxBitmap(wxImage("circle.bmp"));
    rysunki[2]=wxBitmap(wxImage("circle2.bmp"));
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


}
}

connect_fourDialog::~connect_fourDialog()
{
    //(*Destroy(connect_fourDialog)
    //*)
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



void connect_fourDialog::OnBitmapButton1Click(wxCommandEvent& event){
if(cykl[0] >= 0){
plansza1[cykl[0]] -> SetBitmap(rysunki[rand()%2+1]);
cykl[0]--;
}
}



void connect_fourDialog::OnBitmapButton2Click(wxCommandEvent& event){
    if(cykl[1] >= 0){
    plansza2[cykl[1]] -> SetBitmap(rysunki[rand()%2+1]);
    cykl[1]--;
}
}

void connect_fourDialog::OnBitmapButton3Click(wxCommandEvent& event){
    if(cykl[2] >= 0){
    plansza3[cykl[2]] -> SetBitmap(rysunki[rand()%2+1]);
    cykl[2]--;
    }
}

void connect_fourDialog::OnBitmapButton4Click(wxCommandEvent& event){
    if(cykl[3] >= 0){
    plansza4[cykl[3]] -> SetBitmap(rysunki[rand()%2+1]);
    cykl[3]--;
}
}

void connect_fourDialog::OnBitmapButton5Click(wxCommandEvent& event){
    if(cykl[4] >= 0){
    plansza5[cykl[4]] -> SetBitmap(rysunki[rand()%2+1]);
    cykl[4]--;
    }
}

void connect_fourDialog::OnBitmapButton6Click(wxCommandEvent& event){
    if(cykl[5] >= 0){
    plansza6[cykl[5]] -> SetBitmap(rysunki[rand()%2+1]);
    cykl[5]--;
}
}

void connect_fourDialog::OnBitmapButton49Click(wxCommandEvent& event){
    if(cykl[6] >= 0){
    plansza7[cykl[6]] -> SetBitmap(rysunki[rand()%2+1]);
    cykl[6]--;
}
}

void connect_fourDialog::OnButton1Click(wxCommandEvent& event){
    czyszczenie_rysunkow();
}
