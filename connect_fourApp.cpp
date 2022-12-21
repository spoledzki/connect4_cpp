/***************************************************************
 * Name:      connect_fourApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2022-12-14
 * Copyright:  ()
 * License:
 **************************************************************/

#include "connect_fourApp.h"

//(*AppHeaders
#include "connect_fourMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(connect_fourApp);

bool connect_fourApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	connect_fourDialog Dlg(0);
    	SetTopWindow(&Dlg);
    	Dlg.ShowModal();
    	wxsOK = false;
    }
    //*)
    return wxsOK;

}
