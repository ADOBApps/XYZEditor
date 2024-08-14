/***************************************************************
 * Name:      XYZEditorMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Acxel Orozco (acxel.orozco@correounivalle.edu.co)
 * Created:   2023-12-09
 * Copyright: Acxel Orozco ()
 * License:
 **************************************************************/

#include "XYZEditorMain.h"
#include "cppglue.h"
#include "DumpFile.h"
#include "DumpFileMP.h"
#include <wx/msgdlg.h>
#include <thread>
#if defined (_OPENMP)
#include <omp.h>
#endif // defined
#ifdef IS_MPI
#include <mpi.h>
#endif

//(*InternalHeaders(XYZEditorFrame)
#include <wx/bitmap.h>
#include <wx/icon.h>
#include <wx/image.h>
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

//(*IdInit(XYZEditorFrame)
const long XYZEditorFrame::ID_STATICTEXT1 = wxNewId();
const long XYZEditorFrame::ID_FILEPICKERCTRL2 = wxNewId();
const long XYZEditorFrame::ID_COMBOBOX1 = wxNewId();
const long XYZEditorFrame::ID_STATICTEXT3 = wxNewId();
const long XYZEditorFrame::ID_FILEPICKERCTRL4 = wxNewId();
const long XYZEditorFrame::ID_STATICTEXT2 = wxNewId();
const long XYZEditorFrame::ID_FILEPICKERCTRL3 = wxNewId();
const long XYZEditorFrame::ID_BUTTON3 = wxNewId();
const long XYZEditorFrame::ID_PANEL1 = wxNewId();
const long XYZEditorFrame::ID_FILEPICKERCTRL1 = wxNewId();
const long XYZEditorFrame::ID_BUTTON2 = wxNewId();
const long XYZEditorFrame::ID_BUTTON4 = wxNewId();
const long XYZEditorFrame::ID_COMBOBOX2 = wxNewId();
const long XYZEditorFrame::ID_BUTTON1 = wxNewId();
const long XYZEditorFrame::ID_BUTTON5 = wxNewId();
const long XYZEditorFrame::ID_TEXTCTRL2 = wxNewId();
const long XYZEditorFrame::ID_PANEL2 = wxNewId();
const long XYZEditorFrame::ID_TEXTCTRL1 = wxNewId();
const long XYZEditorFrame::ID_FILEPICKERCTRL5 = wxNewId();
const long XYZEditorFrame::ID_SPINCTRL1 = wxNewId();
const long XYZEditorFrame::ID_BUTTON6 = wxNewId();
const long XYZEditorFrame::ID_PANEL3 = wxNewId();
const long XYZEditorFrame::ID_NOTEBOOK1 = wxNewId();
const long XYZEditorFrame::idMenuQuit = wxNewId();
const long XYZEditorFrame::idMenuAbout = wxNewId();
const long XYZEditorFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(XYZEditorFrame,wxFrame)
    //(*EventTable(XYZEditorFrame)
    //*)
END_EVENT_TABLE()

XYZEditorFrame::XYZEditorFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(XYZEditorFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;
    wxStaticBoxSizer* StaticBoxSizer10;
    wxStaticBoxSizer* StaticBoxSizer11;
    wxStaticBoxSizer* StaticBoxSizer1;
    wxStaticBoxSizer* StaticBoxSizer2;
    wxStaticBoxSizer* StaticBoxSizer3;
    wxStaticBoxSizer* StaticBoxSizer4;
    wxStaticBoxSizer* StaticBoxSizer5;
    wxStaticBoxSizer* StaticBoxSizer6;
    wxStaticBoxSizer* StaticBoxSizer7;
    wxStaticBoxSizer* StaticBoxSizer8;
    wxStaticBoxSizer* StaticBoxSizer9;

    Create(parent, wxID_ANY, _("XYZEditor OMP"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    {
    	wxIcon FrameIcon;
    	FrameIcon.CopyFromBitmap(wxBitmap(wxImage(_T("/usr/local/XYZEditor/bin/Resources/Images/icon.png"))));
    	SetIcon(FrameIcon);
    }
    Notebook = new wxNotebook(this, ID_NOTEBOOK1, wxDefaultPosition, wxDefaultSize, 0, _T("ID_NOTEBOOK1"));
    Panel1 = new wxPanel(Notebook, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, Panel1, _("XYZ Editor"));
    StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Force Field"));
    stxt_forcefield = new wxStaticText(Panel1, ID_STATICTEXT1, _("Force Field:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    StaticBoxSizer2->Add(stxt_forcefield, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FilePickerCtrl_ff = new wxFilePickerCtrl(Panel1, ID_FILEPICKERCTRL2, _T("/usr/local/XYZEditor/bin/Resources/json/"), _("Force Field file"), _T("JSON files (*.json)|*.json"), wxDefaultPosition, wxDefaultSize, wxFLP_FILE_MUST_EXIST|wxFLP_OPEN, wxDefaultValidator, _T("ID_FILEPICKERCTRL2"));
    StaticBoxSizer2->Add(FilePickerCtrl_ff, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ComboBox1 = new wxComboBox(Panel1, ID_COMBOBOX1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX1"));
    ComboBox1->Append(_("Force Field"));
    StaticBoxSizer2->Add(ComboBox1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1->Add(StaticBoxSizer2, 1, wxALL|wxEXPAND, 5);
    StaticBoxSizer3 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Elements"));
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT3, _("Elements File"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    StaticBoxSizer3->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FilePickerCtrl_Element = new wxFilePickerCtrl(Panel1, ID_FILEPICKERCTRL4, _T("/usr/local/XYZEditor/bin/Resources/json/"), wxEmptyString, _T("JSON files (*.json)|*.json"), wxDefaultPosition, wxDefaultSize, wxFLP_FILE_MUST_EXIST|wxFLP_OPEN, wxDefaultValidator, _T("ID_FILEPICKERCTRL4"));
    StaticBoxSizer3->Add(FilePickerCtrl_Element, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1->Add(StaticBoxSizer3, 1, wxALL|wxEXPAND, 5);
    StaticBoxSizer4 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("XYZ File"));
    stxt_filepatj = new wxStaticText(Panel1, ID_STATICTEXT2, _("File path:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    StaticBoxSizer4->Add(stxt_filepatj, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FilePickerxyz = new wxFilePickerCtrl(Panel1, ID_FILEPICKERCTRL3, wxEmptyString, wxEmptyString, _T("XYZ  cartesian coordinates format(*.xyz)|*.xyz|MDL Mol format (*.mol)|*.mol|Sybl Mol2 format (*.mol2)|*.mol2|Protein Data Bank format (*.pdb)|*.pdb"), wxDefaultPosition, wxDefaultSize, wxFLP_FILE_MUST_EXIST|wxFLP_OPEN, wxDefaultValidator, _T("ID_FILEPICKERCTRL3"));
    StaticBoxSizer4->Add(FilePickerxyz, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    btn_run = new wxButton(Panel1, ID_BUTTON3, _("Run"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    StaticBoxSizer4->Add(btn_run, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1->Add(StaticBoxSizer4, 1, wxALL|wxEXPAND, 5);
    Panel1->SetSizer(StaticBoxSizer1);
    StaticBoxSizer1->Fit(Panel1);
    StaticBoxSizer1->SetSizeHints(Panel1);
    Panel2 = new wxPanel(Notebook, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    StaticBoxSizer5 = new wxStaticBoxSizer(wxVERTICAL, Panel2, _("File"));
    StaticBoxSizer6 = new wxStaticBoxSizer(wxHORIZONTAL, Panel2, _("Search"));
    FilePickerCtrl_editTab = new wxFilePickerCtrl(Panel2, ID_FILEPICKERCTRL1, wxEmptyString, _("File selector"), _T("XYZ  cartesian coordinates format(*.xyz)|*.xyz|MDL Mol format (*.mol)|*.mol|Sybl Mol2 format (*.mol2)|*.mol2|Protein Data Bank format (*.pdb)|*.pdb"), wxDefaultPosition, wxDefaultSize, wxFLP_FILE_MUST_EXIST|wxFLP_OPEN, wxDefaultValidator, _T("ID_FILEPICKERCTRL1"));
    StaticBoxSizer6->Add(FilePickerCtrl_editTab, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    btn_open = new wxButton(Panel2, ID_BUTTON2, _("Open"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    StaticBoxSizer6->Add(btn_open, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    btn_save = new wxButton(Panel2, ID_BUTTON4, _("Save"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    StaticBoxSizer6->Add(btn_save, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer5->Add(StaticBoxSizer6, 0, wxALL|wxEXPAND, 1);
    StaticBoxSizer7 = new wxStaticBoxSizer(wxHORIZONTAL, Panel2, _("Visualizer"));
    ComboBoxView = new wxComboBox(Panel2, ID_COMBOBOX2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX2"));
    ComboBoxView->Append(_("Chimera"));
    ComboBoxView->Append(_("Jmol"));
    ComboBoxView->Append(_("VMD"));
    StaticBoxSizer7->Add(ComboBoxView, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    btn_view = new wxButton(Panel2, ID_BUTTON1, _("View"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    StaticBoxSizer7->Add(btn_view, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    btn_saveas = new wxButton(Panel2, ID_BUTTON5, _("Save As"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
    StaticBoxSizer7->Add(btn_saveas, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer5->Add(StaticBoxSizer7, 1, wxALL|wxEXPAND, 5);
    txtctrl_editor = new wxTextCtrl(Panel2, ID_TEXTCTRL2, _("Text"), wxDefaultPosition, wxSize(382,198), wxTE_MULTILINE|wxVSCROLL|wxHSCROLL, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    StaticBoxSizer5->Add(txtctrl_editor, 1, wxALL|wxEXPAND, 5);
    Panel2->SetSizer(StaticBoxSizer5);
    StaticBoxSizer5->Fit(Panel2);
    StaticBoxSizer5->SetSizeHints(Panel2);
    Panel3 = new wxPanel(Notebook, ID_PANEL3, wxPoint(160,15), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL3"));
    StaticBoxSizer8 = new wxStaticBoxSizer(wxVERTICAL, Panel3, _("Utilities"));
    StaticBoxSizer9 = new wxStaticBoxSizer(wxVERTICAL, Panel3, _("Spliter"));
    StaticBoxSizer11 = new wxStaticBoxSizer(wxHORIZONTAL, Panel3, _("ShortFile Name"));
    TextCtrl_dump_name = new wxTextCtrl(Panel3, ID_TEXTCTRL1, _("Short"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    StaticBoxSizer11->Add(TextCtrl_dump_name, 0, wxALL, wxDLG_UNIT(Panel3,wxSize(5,0)).GetWidth());
    FilePickerCtrl_split = new wxFilePickerCtrl(Panel3, ID_FILEPICKERCTRL5, wxEmptyString, wxEmptyString, _T("DUMP files (*.dump)|*.dump|OpenMD combined meta-data (*.omd)|*.omd|OpenMD output files (*.eor)|*.eor"), wxDefaultPosition, wxDefaultSize, wxFLP_FILE_MUST_EXIST|wxFLP_OPEN, wxDefaultValidator, _T("ID_FILEPICKERCTRL5"));
    StaticBoxSizer11->Add(FilePickerCtrl_split, 1, wxALL|wxFIXED_MINSIZE, 5);
    StaticBoxSizer9->Add(StaticBoxSizer11, 1, wxALL|wxEXPAND, 5);
    StaticBoxSizer10 = new wxStaticBoxSizer(wxHORIZONTAL, Panel3, _("Frame Number"));
    SpinCtrl_split = new wxSpinCtrl(Panel3, ID_SPINCTRL1, _T("2"), wxDefaultPosition, wxDefaultSize, 0, 1, 10000, 2, _T("ID_SPINCTRL1"));
    SpinCtrl_split->SetValue(_T("2"));
    StaticBoxSizer10->Add(SpinCtrl_split, 1, wxALL, 5);
    btn_omdsplit = new wxButton(Panel3, ID_BUTTON6, _("Split"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON6"));
    StaticBoxSizer10->Add(btn_omdsplit, 1, wxALL, 5);
    StaticBoxSizer9->Add(StaticBoxSizer10, 1, wxALL|wxEXPAND, 5);
    StaticBoxSizer8->Add(StaticBoxSizer9, 1, wxALL|wxEXPAND, 5);
    Panel3->SetSizer(StaticBoxSizer8);
    StaticBoxSizer8->Fit(Panel3);
    StaticBoxSizer8->SetSizeHints(Panel3);
    Notebook->AddPage(Panel1, _("Main"), false);
    Notebook->AddPage(Panel2, _("Editor"), false);
    Notebook->AddPage(Panel3, _("Spliter"), false);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    SaveDialog = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, wxFileSelectorDefaultWildcardStr, wxFD_SAVE|wxFD_OVERWRITE_PROMPT|wxVSCROLL|wxHSCROLL, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));

    Connect(ID_FILEPICKERCTRL2,wxEVT_COMMAND_FILEPICKER_CHANGED,(wxObjectEventFunction)&XYZEditorFrame::OnFilePickerCtrl_ffFileChanged);
    Connect(ID_FILEPICKERCTRL3,wxEVT_COMMAND_FILEPICKER_CHANGED,(wxObjectEventFunction)&XYZEditorFrame::OnFilePickerCtrl_xyzFileChanged);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&XYZEditorFrame::Onbtn_runClick);
    Connect(ID_FILEPICKERCTRL1,wxEVT_COMMAND_FILEPICKER_CHANGED,(wxObjectEventFunction)&XYZEditorFrame::OnFilePickerCtrl1FileChanged);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&XYZEditorFrame::Onbtn_openClick);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&XYZEditorFrame::Onbtn_saveClick);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&XYZEditorFrame::Onbtn_viewClick);
    Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&XYZEditorFrame::Onbtn_saveasClick);
    Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&XYZEditorFrame::Onbtn_omdsplitClick);
    Connect(ID_NOTEBOOK1,wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED,(wxObjectEventFunction)&XYZEditorFrame::OnNotebookPageChanged);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&XYZEditorFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&XYZEditorFrame::OnAbout);
    //*)
    // JSON manager
    gluemanager = new GlueMan();
    dumpfileman = new DumpFile();
    dumpfile_omp = new DumpFileMP();
}

XYZEditorFrame::~XYZEditorFrame()
{
    //(*Destroy(XYZEditorFrame)
    //*)
}

void XYZEditorFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void XYZEditorFrame::OnAbout(wxCommandEvent& event)
{
#if defined (_OPENMP)
int nthreads = 0;
#pragma omp parallel
{
    nthreads = omp_get_max_threads();
}
    wxString msg = wxString::Format(
        wxT("XYZEditor of Metallic System Builder for Molecular Dynamics Simulations (MSBDM).\n\nDeveloped by Acxel Orozco (acxel.orozco@correounivalle.edu.co).\n\nUnder %s.\n\nOpenMP Allowed Threads: %i."),
        wxbuildinfo(long_f),
        nthreads
    );
    wxMessageBox(msg, _("Welcome to..."));


#else
    int nthreads = std::thread::hardware_concurrency();
    wxString msg = wxString::Format(
        wxT("XYZEditor of Metallic System Builder for Molecular Dynamics Simulations (MSBDM).\n\nDeveloped by Acxel Orozco (acxel.orozco@correounivalle.edu.co).\n\nUnder %s.\n\nThreads: %i."),
        wxbuildinfo(long_f),
        nthreads
    );
    wxMessageBox(msg, _("Welcome to..."));
#endif // defined
}

void XYZEditorFrame::Onbtn_openClick(wxCommandEvent& event)
{
    // wxString sel_combo = ComboBox1->GetStringSelection();
    wxString xyz_path =  wxString::Format(
        wxT("%s"),
        FilePickerCtrl_editTab->GetPath()
    );
    txtctrl_editor->Clear();
    txtctrl_editor->LoadFile(xyz_path);
}

void XYZEditorFrame::Onbtn_runClick(wxCommandEvent& event)
{
    wxULongLong l_size = FilePickerxyz->GetFileName().GetSize();
    if(l_size > 400000000){
        wxString size_obj = wxString::Format(
            wxT("Size %s too long, split DUMP and re-generate XYZ file"),
            FilePickerxyz->GetFileName().GetSize().ToString()
        );
        wxMessageBox(size_obj, _("File size"));
    }
    else{
        wxString sel_combo = ComboBox1->GetStringSelection();
        wxString element_path =  wxString::Format(
            wxT("%s"),
            FilePickerCtrl_Element->GetPath()
        );
        wxString xyz_path =  wxString::Format(
            wxT("%s"),
            FilePickerxyz->GetPath()
        );
        txtctrl_editor->Clear();
        txtctrl_editor->LoadFile(xyz_path);

        string str_ff = std::string(sel_combo.mbc_str());
        string str_xyz_path = std::string(xyz_path.mbc_str());
        string str_element_path = std::string(element_path.mbc_str());
        map<string, string> my_elements;
        my_elements = gluemanager->getJSON2BDVector(
            str_element_path,
            str_ff
        );
        string xyz_text = txtctrl_editor->GetValue().ToStdString();
        std::vector<string> element_keys, element_values;
        for(map<string, string>::iterator map_it=my_elements.begin(); map_it!=my_elements.end(); ++map_it){
            element_keys.push_back(map_it->first);
            element_values.push_back(map_it->second);
            wxString msg = wxString::Format(
                wxT("key:%s, value:%s\n"),
                map_it->first,
                map_it->second
            );
            // dumpfileman->SerialReplace(xyz_text, map_it->first, map_it->second);
            dumpfile_omp->ParallelReplace(xyz_text, map_it->first, map_it->second);
        }
        txtctrl_editor->Clear();
        txtctrl_editor->AppendText(xyz_text);
    }

}

void XYZEditorFrame::OnFilePickerCtrl1FileChanged(wxFileDirPickerEvent& event)
{
    //wxString msg = wxString::Format(wxT("Path: %s"), event.GetPath());
    //wxMessageBox(msg, _("File name"));
}

void XYZEditorFrame::OnNotebookPageChanged(wxNotebookEvent& event)
{
}

void XYZEditorFrame::OnFilePickerCtrl_xyzFileChanged(wxFileDirPickerEvent& event)
{
}

void XYZEditorFrame::OnFilePickerCtrl_ffFileChanged(wxFileDirPickerEvent& event)
{
    txtctrl_editor->Clear();
    // txtctrl_editor->SetDefaultStyle(wxTextAttr(*wxRED));
    // txtctrl_editor->AppendText("Red text");

    // set force field list
    std::vector<string> myvector;
    wxString wxs_path =  wxString::Format(wxT("%s"), event.GetPath());
    string str_path = std::string(wxs_path.mbc_str());
    myvector = gluemanager->getJSON2Vector(
        str_path,
        "ForceField"
    );
    ComboBox1->Clear();
    for(unsigned i=0; i < myvector.size(); i++){
        ComboBox1->Append(
            wxString::Format(wxT("%s"), myvector[i])
        );
    }

    wxString msg_json = wxString::Format(
        wxT("%s"),
        wxString::Format("%s", myvector[1])
    );
    txtctrl_editor->AppendText(msg_json);
}

void XYZEditorFrame::Onbtn_viewClick(wxCommandEvent& event)
{
    //review
    wxString xyz_path =  wxString::Format(
        wxT("'%s'"),
        FilePickerCtrl_editTab->GetFileName().GetFullPath()
    );
    wxString cmd = ComboBoxView->GetStringSelection();
    wxString file_ext = FilePickerCtrl_editTab->GetFileName().GetExt();
    if(file_ext == "omd"){
        wxString msg_ext = wxString::Format(
            wxT("Use MSBMD to view meta-data '%s' files"),
            file_ext
        );
        wxMessageBox(msg_ext, _("File extension"));
    }
    else if(file_ext == "inc"){
        wxString msg_ext = wxString::Format(
            wxT("OpenMD Include files '%s' only can be edited"),
            file_ext
        );
        wxMessageBox(msg_ext, _("File extension"));
    }
    else if(file_ext == "frc"){
        wxString msg_ext = wxString::Format(
            wxT("OpenMD Force Field files '%s' only can be edited"),
            file_ext
        );
        wxMessageBox(msg_ext, _("File extension"));
    }
    else{
        // if(file_ext == "omd"){}
        if(cmd == "VMD"){
            wxExecute(
                wxString::Format(
                    wxT("cd $HOME")
                )
            );
            wxExecute(
                wxString::Format(
                    wxT("xterm -e %s '%s'"),
                    cmd.Lower(),
                    xyz_path
                )
            );
        } else{
            wxExecute(
                wxString::Format(
                    wxT("cd $HOME")
                )
            );
            wxExecute(
                wxString::Format(
                    wxT("%s '%s'"),
                    cmd.Lower(),
                    xyz_path
                )
            );
        }
    }
}

void XYZEditorFrame::Onbtn_saveClick(wxCommandEvent& event)
{
    wxString xyz_path =  wxString::Format(
        wxT("%s"),
        FilePickerxyz->GetPath()
    );
    txtctrl_editor->SaveFile(xyz_path);
}

void XYZEditorFrame::Onbtn_saveasClick(wxCommandEvent& event)
{
    wxString currentDocPath;
    SaveDialog->Show();
    if(SaveDialog->ShowModal() == wxID_OK){
        currentDocPath = SaveDialog->GetPath();
        txtctrl_editor->SaveFile(currentDocPath);
    }
    SaveDialog->Destroy();
}

void XYZEditorFrame::Onbtn_omdsplitClick(wxCommandEvent& event)
{
    int n_split = SpinCtrl_split->GetValue();
    wxString dump_file =  wxString::Format(
        wxT("%s"),
        FilePickerCtrl_split->GetFileName().GetFullPath()
    );
    wxString dump_path =  wxString::Format(
        wxT("%s"),
        FilePickerCtrl_split->GetFileName().GetPath()
    );
    wxString dump_name =  TextCtrl_dump_name->GetValue();
    wxArrayString outt;
    wxArrayString error;

    wxExecute(
        wxString::Format(
            wxT("omdShrink -s %i -m '%s' -o '%s/%s.dump'"),
            n_split,
            dump_file,
            dump_path,
            dump_name
        ),
        outt,
        error
    );
    if(outt.IsEmpty() || error.IsEmpty()){
        wxMessageBox("Finished without info", _("Split results"));
    }
    else{
        wxString exe_output =  wxString::Format(
            wxT("Output: %s.\nErrors: %s"),
            outt[0],
            error[0]
        );
        wxMessageBox(exe_output, _("Split results"));
    }
}
