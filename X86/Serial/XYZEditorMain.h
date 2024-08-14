/***************************************************************
 * Name:      XYZEditorMain.h
 * Purpose:   Defines Application Frame
 * Author:    Acxel Orozco (acxel.orozco@correounivalle.edu.co)
 * Created:   2023-12-09
 * Copyright: Acxel Orozco ()
 * License:
 **************************************************************/

#ifndef XYZEDITORMAIN_H
#define XYZEDITORMAIN_H

//(*Headers(XYZEditorFrame)
#include <wx/notebook.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/menu.h>
#include <wx/textctrl.h>
#include <wx/filepicker.h>
#include <wx/spinctrl.h>
#include <wx/panel.h>
#include <wx/filedlg.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/combobox.h>
#include <wx/statusbr.h>
//*)
#include "cppglue.h"
#include "DumpFile.h"

class XYZEditorFrame: public wxFrame
{
    public:

        XYZEditorFrame(wxWindow* parent, wxWindowID id = -1);
        virtual ~XYZEditorFrame();

    private:

        //(*Handlers(XYZEditorFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void Onbtn_openClick(wxCommandEvent& event);
        void Onbtn_runClick(wxCommandEvent& event);
        void OnFilePickerCtrl1FileChanged(wxFileDirPickerEvent& event);
        void OnNotebookPageChanged(wxNotebookEvent& event);
        void OnFilePickerCtrl_xyzFileChanged(wxFileDirPickerEvent& event);
        void OnFilePickerCtrl_ffFileChanged(wxFileDirPickerEvent& event);
        void Onbtn_viewClick(wxCommandEvent& event);
        void Onbtn_saveClick(wxCommandEvent& event);
        void Onbtn_saveasClick(wxCommandEvent& event);
        void Onbtn_omdsplitClick(wxCommandEvent& event);
        void Onbtn_dump2xyzClick(wxCommandEvent& event);
        //*)

        //(*Identifiers(XYZEditorFrame)
        static const long ID_STATICTEXT1;
        static const long ID_FILEPICKERCTRL2;
        static const long ID_COMBOBOX1;
        static const long ID_STATICTEXT3;
        static const long ID_FILEPICKERCTRL4;
        static const long ID_STATICTEXT2;
        static const long ID_FILEPICKERCTRL3;
        static const long ID_BUTTON3;
        static const long ID_PANEL1;
        static const long ID_FILEPICKERCTRL1;
        static const long ID_BUTTON2;
        static const long ID_BUTTON4;
        static const long ID_COMBOBOX2;
        static const long ID_BUTTON1;
        static const long ID_BUTTON5;
        static const long ID_TEXTCTRL2;
        static const long ID_PANEL2;
        static const long ID_TEXTCTRL1;
        static const long ID_FILEPICKERCTRL5;
        static const long ID_SPINCTRL1;
        static const long ID_BUTTON6;
        static const long ID_PANEL3;
        static const long ID_NOTEBOOK1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(XYZEditorFrame)
        wxButton* btn_open;
        wxTextCtrl* txtctrl_editor;
        wxComboBox* ComboBoxView;
        wxStaticText* stxt_forcefield;
        wxButton* btn_run;
        wxFilePickerCtrl* FilePickerCtrl_split;
        wxSpinCtrl* SpinCtrl_split;
        wxPanel* Panel1;
        wxStaticText* StaticText1;
        wxFilePickerCtrl* FilePickerxyz;
        wxPanel* Panel3;
        wxButton* btn_omdsplit;
        wxFileDialog* SaveDialog;
        wxStatusBar* StatusBar1;
        wxButton* btn_view;
        wxButton* btn_save;
        wxComboBox* ComboBox1;
        wxFilePickerCtrl* FilePickerCtrl_editTab;
        wxButton* btn_saveas;
        wxStaticText* stxt_filepatj;
        wxPanel* Panel2;
        wxFilePickerCtrl* FilePickerCtrl_ff;
        wxFilePickerCtrl* FilePickerCtrl_Element;
        wxNotebook* Notebook;
        wxTextCtrl* TextCtrl_dump_name;
        //*)
        GlueMan* gluemanager;
        DumpFile* dumpfileman;

        DECLARE_EVENT_TABLE()
};

#endif // XYZEDITORMAIN_H
