#include "ESSubFrame.hpp"
#include "function.hpp"

double function2(double x)
{
    return function1(x)*x;
}

double integration(double a,double b,double (*opfun)(double))
{
    double x[10001];
    double s=0.0;
    int i;
    for(i=0; i<=10000; i++)
        x[i]=a+i*(b-a)/10000;
    for(i=0; i<=10000; i++)
        s=s+2*opfun(x[i]);
    s=s-opfun(a)-opfun(b);
    s=s*(b-a)/2/10000;
    return s;
}

const long ESSubFrame::ID_BUTTON1 = wxNewId();

ESSubFrame::ESSubFrame(wxWindow* parent,
                       const wxString& title,
                       wxWindowID id,
                       const wxPoint& pos,
                       const wxSize& size)
{
    m_value1 = 0;
    m_value2 = 0;
    m_value3 = 0;
    Create(parent,
           wxID_ANY,
           title,
           wxDefaultPosition,
           wxDefaultSize,
           wxDEFAULT_FRAME_STYLE,
           _T("wxID_ANY"));
    Panel1 = new wxPanel(this,
                         -1,
                         wxPoint(232,208),
                         wxDefaultSize,
                         wxTAB_TRAVERSAL);
    StaticText1 = new wxStaticText(Panel1,
                                   -1,
                                   wxT("The equation is:  U''=f(x)                              f(x)=6*x^2                                              U(0)=a                                                  U(1)=b"),
                                   wxPoint(50,50),
                                   wxDefaultSize);
    StaticText2 = new wxStaticText(Panel1,
                                   -1,
                                   wxT("Please set in the Dirichlet Boundary Condition      a="),
                                   wxPoint(80,150),
                                   wxDefaultSize);
    TextCtrl1 = new wxTextCtrl(Panel1,
                               -1,
                               wxEmptyString,
                               wxPoint(450,150),
                               wxDefaultSize);

    StaticText3 = new wxStaticText(Panel1,
                                   -1,
                                   wxT("Please set in the Dirichlet Boundary Condition      b="),
                                   wxPoint(80,180),
                                   wxDefaultSize);
    TextCtrl2 = new wxTextCtrl(Panel1,
                               -1,
                               wxEmptyString,
                               wxPoint(450,180),
                               wxDefaultSize);
    StaticText4 = new wxStaticText(Panel1,
                                   -1,
                                   wxT("Please set in the x to you want to know the u:       x="),
                                   wxPoint(80,210),
                                   wxDefaultSize);
    TextCtrl3 = new wxTextCtrl(Panel1,
                               -1,
                               wxEmptyString,
                               wxPoint(450,210),
                               wxDefaultSize);
    Button1 = new wxButton(Panel1,                                                                          ID_BUTTON1,
                           wxT("Run"),
                           wxPoint(700,230),
                           wxDefaultSize);
    StaticText5 = new wxStaticText(Panel1,
                                   -1,
                                   wxT("As an EXCELLENT student, i can know the answer quickly, the answer is"),
                                   wxPoint(80,260),
                                   wxDefaultSize);
    TextCtrl4 = new wxTextCtrl(Panel1,
                               -1,
                               wxEmptyString,
                               wxPoint(450,290),
                               wxDefaultSize,
                               wxTE_READONLY);
    Connect(ID_BUTTON1,
            wxEVT_COMMAND_BUTTON_CLICKED,
            wxCommandEventHandler(ESSubFrame::OnButton1Click1));
}

ESSubFrame::~ESSubFrame() {}

void ESSubFrame::OnButton1Click1(wxCommandEvent& event)
{
    wxString stra,strb,strx,strU;
    double U;
    stra=TextCtrl1->GetValue();
    stra.ToDouble(&m_value1);
    strb=TextCtrl2->GetValue();
    strb.ToDouble(&m_value2);
    strx=TextCtrl3->GetValue();
    strx.ToDouble(&m_value3);
    U=m_value1+(m_value2-m_value1-integration(0,1,function1)
                +integration(0,1,function2))*m_value3
      +m_value3*integration(0,m_value3,function1)
      -integration(0,m_value3,function2);
    strU<<U;
    TextCtrl4->WriteText(strU);
}
