/***************************************************************
 * Name:      adgcMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Ricyn ()
 * Created:   2017-04-20
 * Copyright: Ricyn ()
 * License:
 **************************************************************/

#include "adgcMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(adgcDialog)
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

//(*IdInit(adgcDialog)
const long adgcDialog::ID_STATICTEXT1 = wxNewId();
const long adgcDialog::ID_STATICTEXT3 = wxNewId();
const long adgcDialog::ID_STATICLINE1 = wxNewId();
const long adgcDialog::ID_STATICTEXT2 = wxNewId();
const long adgcDialog::ID_FILEPICKERCTRL1 = wxNewId();
const long adgcDialog::ID_BUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(adgcDialog,wxDialog)
    //(*EventTable(adgcDialog)
    //*)
END_EVENT_TABLE()

adgcDialog::adgcDialog(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(adgcDialog)
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer3;

    Create(parent, wxID_ANY, _("ADG Cracker"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Affinic 2.0.1 is so great\nand easy to crack\nthat I can\'t help crack it!"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE, _T("ID_STATICTEXT1"));
    StaticText1->SetForegroundColour(wxColour(0,0,160));
    wxFont StaticText1Font(12,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,_T("Consolas"),wxFONTENCODING_DEFAULT);
    StaticText1->SetFont(StaticText1Font);
    BoxSizer1->Add(StaticText1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 10);
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("I believe softwares should be free for personal, non-commercial uses.\nBut cracking is definitely bad! Buy Affinic if you like it."), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE, _T("ID_STATICTEXT3"));
    wxFont StaticText3Font(6,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Tahoma"),wxFONTENCODING_DEFAULT);
    StaticText3->SetFont(StaticText3Font);
    BoxSizer1->Add(StaticText3, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    BoxSizer3->Add(StaticLine1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer3, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Specify Affinic\'s executable (adg.exe)"), wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT, _T("ID_STATICTEXT2"));
    BoxSizer2->Add(StaticText2, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FilePickerCtrl1 = new wxFilePickerCtrl(this, ID_FILEPICKERCTRL1, wxEmptyString, wxEmptyString, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxFLP_FILE_MUST_EXIST|wxFLP_OPEN|wxFLP_USE_TEXTCTRL, wxDefaultValidator, _T("ID_FILEPICKERCTRL1"));
    BoxSizer2->Add(FilePickerCtrl1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button1 = new wxButton(this, ID_BUTTON1, _("Crack!"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer1->Add(Button1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(BoxSizer1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&adgcDialog::OnButton1Click);
    //*)
}

adgcDialog::~adgcDialog()
{
    //(*Destroy(adgcDialog)
    //*)
}

void adgcDialog::OnButton1Click(wxCommandEvent& event)
{
    wxFileName FileSelected = FilePickerCtrl1->GetFileName();

    if(! FileSelected.FileExists()){
        wxMessageBox(TEXT("File does not exist."), TEXT("ADG Cracker"),wxOK | wxCENTER | wxICON_ERROR);
        return;
    }

    if(FileSelected.GetFullName().CmpNoCase(TEXT("ADG.EXE"))/*0 for identical*/){
        wxMessageBox(TEXT("File name is not \"adg.exe\"."), TEXT("ADG Cracker"),wxOK | wxCENTER | wxICON_ERROR);
        return;
    }

    if(!(FileSelected.IsFileReadable() && FileSelected.IsFileWritable())){
        wxMessageBox(TEXT("File is not readable and writable."),TEXT("ADG Cracker"),wxOK | wxCENTER | wxICON_ERROR);
        return;
    }

    if(FileSelected.GetSize()!=2798080){
        wxMessageBox(TEXT("Unexpected file size."),TEXT("ADG Cracker"),wxOK | wxCENTER | wxICON_ERROR);
        return;
    }

    FILE* fp = fopen(FileSelected.GetFullPath().c_str(),"rb+");

    if(!fp){
        wxMessageBox(TEXT("Cannot open file."),TEXT("ADG Cracker"),wxOK | wxCENTER | wxICON_ERROR);
        return;
    }

    uint8_t crack_data[2];

    fseek(fp,0x593b,SEEK_SET);
    fread(crack_data, 1, 2, fp);

    if(! (0x74==crack_data[0] && 0x07==crack_data[1])){
        if(0x90==crack_data[0] && 0x90==crack_data[1])
            wxMessageBox(TEXT("Cannot validate file integrity.\nFile seems already cracked."),TEXT("ADG Cracker"),wxOK | wxCENTER | wxICON_ERROR);
        else
            wxMessageBox(TEXT("Cannot validate file integrity."),TEXT("ADG Cracker"),wxOK | wxCENTER | wxICON_ERROR);
        return;
    }

    crack_data[0]=0x90; // x86 ASM : NOP
    crack_data[1]=0x90; // x86 ASM : NOP
    fseek(fp,0x593b,SEEK_SET); // Necessary!
    fwrite(crack_data, 1, 2, fp);

    fclose(fp);

    wxMessageBox(TEXT("Crack done successfully."),TEXT("ADG Cracker"),wxOK | wxCENTER | wxICON_INFORMATION);
}
