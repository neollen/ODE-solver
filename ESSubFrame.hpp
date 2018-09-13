#ifndef ESSUBFRAME_HPP_INCLUDED
#define ESSUBFRAME_HPP_INCLUDED

#include <wx/wx.h>

class ESSubFrame : public wxFrame {
public:
    ESSubFrame(wxWindow* parent,
               const wxString& title,
               wxWindowID id = wxID_ANY,
               const wxPoint& pos = wxDefaultPosition,
               const wxSize& size = wxDefaultSize);

    virtual ~ESSubFrame();
    wxPanel* Panel1;
    wxButton* Button1;
    wxStaticText* StaticText1;
    wxStaticText* StaticText2;
    wxStaticText* StaticText3;
    wxTextCtrl* TextCtrl1;
    wxTextCtrl* TextCtrl2;
    wxStaticText* StaticText4;
    wxTextCtrl* TextCtrl3;
    wxStaticText* StaticText5;
    wxTextCtrl* TextCtrl4;

    double m_value1;
    double m_value2;
    double m_value3;
protected:
    static const long ID_BUTTON1;

private:
    void OnButton1Click1(wxCommandEvent& event);
};

#endif /* ESSUBFRAME_HPP_INCLUDED */
