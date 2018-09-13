#include "MyFrame.hpp"
#include "FDSubFrame.hpp"
#include "ESSubFrame.hpp"

const int MyFrame::ID_EXSOVLE = wxNewId();
const int MyFrame::ID_FDSOVLE = wxNewId();
const int MyFrame::ID_FESOVLE = wxNewId();

void MyFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void MyFrame::OnOpenFDSubFrame(wxCommandEvent& event)
{
    FDSubFrame* subFrame
        = new FDSubFrame(this,
                         wxT("Finite Difference"));
    subFrame->Show(true);
}

void MyFrame::OnOpenESSubFrame(wxCommandEvent& event)
{
    ESSubFrame* subFrame
        = new ESSubFrame(this,
                        wxT("Exact Solution"));
    subFrame->Show(true);
}

MyFrame::MyFrame(const wxString& title)
    :wxFrame(NULL, wxID_ANY, title)
{
    wxMenu* sovlerMenu = new wxMenu;
    sovlerMenu->Append(wxID_EXIT, wxT("E&xit\tAlt-X"));
    sovlerMenu->Append(ID_EXSOVLE, wxT("&Exact Solution"));
    sovlerMenu->Append(ID_FDSOVLE, wxT("&Finite Difference"));
    sovlerMenu->Append(ID_FESOVLE, wxT("&Finite Element"));
    sovlerMenu->AppendSeparator();

    wxMenuBar* menuBar = new wxMenuBar;
    menuBar->Append(sovlerMenu, wxT("&Sovler"));
    SetMenuBar(menuBar);
}
