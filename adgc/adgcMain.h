/***************************************************************
 * Name:      adgcMain.h
 * Purpose:   Defines Application Frame
 * Author:    Ricyn ()
 * Created:   2017-04-20
 * Copyright: Ricyn ()
 * License:
 **************************************************************/

#ifndef ADGCMAIN_H
#define ADGCMAIN_H

//(*Headers(adgcDialog)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/filepicker.h>
#include <wx/statline.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class adgcDialog: public wxDialog
{
    public:

        adgcDialog(wxWindow* parent,wxWindowID id = -1);
        virtual ~adgcDialog();

    private:

        //(*Handlers(adgcDialog)
        void OnButton1Click(wxCommandEvent& event);
        //*)

        //(*Identifiers(adgcDialog)
        static const long ID_STATICTEXT1;
        static const long ID_STATICTEXT2;
        static const long ID_STATICTEXT3;
        static const long ID_STATICLINE1;
        static const long ID_FILEPICKERCTRL1;
        static const long ID_BUTTON1;
        //*)

        //(*Declarations(adgcDialog)
        wxFilePickerCtrl* FilePickerCtrl1;
        wxStaticText* StaticText2;
        wxButton* Button1;
        wxStaticText* StaticText1;
        wxStaticText* StaticText3;
        wxStaticLine* StaticLine1;
        wxBoxSizer* BoxSizer1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // ADGCMAIN_H
