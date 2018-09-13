#ifndef MYFRAME_HPP_INCLUDED
#define MYFRAME_HPP_INCLUDED

#include <wx/wx.h>

class MyFrame : public wxFrame {
public:
    static const int ID_EXSOVLE;
    static const int ID_FDSOVLE;
    static const int ID_FESOVLE;

    MyFrame(const wxString& title);
    void OnQuit(wxCommandEvent& event);
    void OnOpenFDSubFrame(wxCommandEvent& event);
    void OnOpenESSubFrame(wxCommandEvent& event);
};

#endif // MYFRAME_HPP_INCLUDED
