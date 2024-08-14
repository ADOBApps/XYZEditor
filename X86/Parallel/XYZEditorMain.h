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
#include <wx/button.h>
#include <wx/combobox.h>
#include <wx/filedlg.h>
#include <wx/filepicker.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/notebook.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/spinctrl.h>
#include <wx/stattext.h>
#include <wx/statusbr.h>
#include <wx/textctrl.h>
//*)
#include "cppglue.h"
#include "DumpFile.h"
#include "DumpFileMP.h"

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
        wxButton* btn_omdsplit;
        wxButton* btn_open;
        wxButton* btn_run;
        wxButton* btn_save;
        wxButton* btn_saveas;
        wxButton* btn_view;
        wxComboBox* ComboBox1;
        wxComboBox* ComboBoxView;
        wxFileDialog* SaveDialog;
        wxFilePickerCtrl* FilePickerCtrl_Element;
        wxFilePickerCtrl* FilePickerCtrl_editTab;
        wxFilePickerCtrl* FilePickerCtrl_ff;
        wxFilePickerCtrl* FilePickerCtrl_split;
        wxFilePickerCtrl* FilePickerxyz;
        wxNotebook* Notebook;
        wxPanel* Panel1;
        wxPanel* Panel2;
        wxPanel* Panel3;
        wxSpinCtrl* SpinCtrl_split;
        wxStaticText* StaticText1;
        wxStaticText* stxt_filepatj;
        wxStaticText* stxt_forcefield;
        wxStatusBar* StatusBar1;
        wxTextCtrl* TextCtrl_dump_name;
        wxTextCtrl* txtctrl_editor;
        //*)
        GlueMan* gluemanager;
        DumpFile* dumpfileman;
        DumpFileMP* dumpfile_omp;

        DECLARE_EVENT_TABLE()
};

#endif // XYZEDITORMAIN_H
