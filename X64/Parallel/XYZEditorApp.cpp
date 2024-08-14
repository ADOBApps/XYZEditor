/***************************************************************
 * Name:      XYZEditorApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Acxel Orozco (acxel.orozco@correounivalle.edu.co)
 * Created:   2023-12-09
 * Copyright: Acxel Orozco ()
 * License:
 **************************************************************/

#include "XYZEditorApp.h"

//(*AppHeaders
#include "XYZEditorMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(XYZEditorApp);

bool XYZEditorApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	XYZEditorFrame* Frame = new XYZEditorFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
