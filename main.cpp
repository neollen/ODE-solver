#include "main.hpp"
#include "MyFrame.hpp"

//DECLARE_APP(MyApp)
IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
    MyFrame* frame = new MyFrame(wxT("Poisson Solver"));
    frame->Show(true);

    frame->Connect(wxID_EXIT,
                   wxEVT_COMMAND_MENU_SELECTED,
                   wxCommandEventHandler(MyFrame::OnQuit));

    frame->Connect((MyFrame::ID_FDSOVLE),
                   wxEVT_COMMAND_MENU_SELECTED,
                   wxCommandEventHandler(MyFrame::OnOpenFDSubFrame));

    frame->Connect((MyFrame::ID_EXSOVLE),
                   wxEVT_COMMAND_MENU_SELECTED,
                   wxCommandEventHandler(MyFrame::OnOpenESSubFrame));
    return true;
}
