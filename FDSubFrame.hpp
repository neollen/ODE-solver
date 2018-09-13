#ifndef FDSUBFRAME_HPP_INCLUDED
#define FDSUBFRAME_HPP_INCLUDED

#include <wx/wx.h>

class FDSubFrame : public wxFrame {
public:
    FDSubFrame(wxWindow* parent,
               const wxString& title,
               wxWindowID id = wxID_ANY,
               const wxPoint& pos = wxDefaultPosition,
               const wxSize& size = wxDefaultSize);
    virtual ~FDSubFrame();
    wxPanel* Panel1;
    wxButton* Button1;
    wxStaticText* StaticTextf;
    wxStaticText* StaticText1;
    wxTextCtrl* TextCtrl1;
    wxStaticText* StaticText2;
    wxTextCtrl* TextCtrl2;
    wxStaticText* StaticText3;
    wxTextCtrl* TextCtrl3;
    wxStaticText* StaticText4;
    wxTextCtrl* TextCtrl4;
    wxStaticText* StaticText5;
    wxTextCtrl* TextCtrl5;
    wxStaticText* StaticText6;
    wxTextCtrl* TextCtrl6;
    wxStaticText* StaticText7;
    wxTextCtrl* TextCtrl7;
    wxStaticText* StaticText8;
    wxTextCtrl* TextCtrl8;

    double m_value1;
    double m_value2;
    double m_value3;
    long m_value4;

protected:
    static const long ID_Button1;
private:
    void OnButton1Click1(wxCommandEvent& event);
};

#endif // FDSUBFRAME_HPP_INCLUDED
