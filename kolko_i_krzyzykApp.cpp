/***************************************************************
 * Name:      kolko_i_krzyzykApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2022-11-17
 * Copyright:  ()
 * License:
 **************************************************************/

#include "kolko_i_krzyzykApp.h"

//(*AppHeaders
#include "kolko_i_krzyzykMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(kolko_i_krzyzykApp);

bool kolko_i_krzyzykApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	kolko_i_krzyzykDialog Dlg(0);
    	SetTopWindow(&Dlg);
    	Dlg.ShowModal();
    	wxsOK = false;
    }
    //*)
    return wxsOK;

}
