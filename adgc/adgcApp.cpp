/***************************************************************
 * Name:      adgcApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Ricyn ()
 * Created:   2017-04-20
 * Copyright: Ricyn ()
 * License:
 **************************************************************/

#include "adgcApp.h"

//(*AppHeaders
#include "adgcMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(adgcApp);

bool adgcApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	adgcDialog Dlg(0);
    	SetTopWindow(&Dlg);
    	Dlg.ShowModal();
    	wxsOK = false;
    }
    //*)
    return wxsOK;

}
