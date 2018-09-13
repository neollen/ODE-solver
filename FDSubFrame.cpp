#include "FDSubFrame.hpp"
#include "function.hpp"
#include <vector>
#include <Eigen/Dense>
#include <Eigen/Sparse>

const long FDSubFrame::ID_Button1= wxNewId();

FDSubFrame::FDSubFrame(wxWindow* parent,
                       const wxString& title,
                       wxWindowID id,
                       const wxPoint& pos,
                       const wxSize& size)
{
    m_value1 = 0;
    m_value2 = 0;
    m_value3 = 0;
    m_value4 = 0;

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

    StaticTextf = new wxStaticText(Panel1,
                                   -1,
                                   wxT("The equation is:  U''=f(x)                              f(x)=6*x^2                                              U(0)=a                                                  U(1)=b"),
                                   wxPoint(50,50),
                                   wxDefaultSize);

    StaticText1 = new wxStaticText(Panel1,
                                   -1,
                                   wxT("Please set in the Dirichlet Boundary Condition      a="),
                                   wxPoint(80,150),
                                   wxDefaultSize);
    TextCtrl1 = new wxTextCtrl(Panel1,
                               -1,
                               wxEmptyString,
                               wxPoint(450,150),
                               wxDefaultSize);

    StaticText2 = new wxStaticText(Panel1,
                                   -1,
                                   wxT("Please set in the Dirichlet Boundary Condition      b="),
                                   wxPoint(80,180),
                                   wxDefaultSize);
    TextCtrl2 = new wxTextCtrl(Panel1,
                               -1,
                               wxEmptyString,
                               wxPoint(450,180),
                               wxDefaultSize);
    StaticText3 = new wxStaticText(Panel1,
                                   -1,
                                   wxT("Please set in the x to you want to know the u:       x="),
                                   wxPoint(80,210),
                                   wxDefaultSize);
    TextCtrl3 = new wxTextCtrl(Panel1,
                               -1,
                               wxEmptyString,
                               wxPoint(450,210),
                               wxDefaultSize);

    StaticText4 = new wxStaticText(Panel1,
                                   -1,
                                   wxT("The size of the matrix:                                 n="),
                                   wxPoint(80,240),
                                   wxSize(23,50));
    TextCtrl4 = new wxTextCtrl(Panel1,
                               -1,
                               wxEmptyString,
                               wxPoint(450,240),
                               wxDefaultSize);

    StaticText5 = new wxStaticText(Panel1,
                                   -1,
                                   wxT("iterations:      "),
                                   wxPoint(80,270),
                                   wxSize(23,50));
    TextCtrl5 = new wxTextCtrl(Panel1,
                               -1,
                               wxEmptyString,
                               wxPoint(450,270),
                               wxDefaultSize,
                               wxTE_READONLY      );

    StaticText6 = new wxStaticText(Panel1,
                                   -1,
                                   wxT("estimated error:"),
                                   wxPoint(80,300),
                                   wxSize(23,50));
    TextCtrl6 = new wxTextCtrl(Panel1,
                               -1,
                               wxEmptyString,
                               wxPoint(450,300),
                               wxDefaultSize,
                               wxTE_READONLY);

    Button1 = new wxButton(Panel1,                                                                          ID_Button1,
                           wxT("Run"),
                           wxPoint(700,170),
                           wxDefaultSize);

    StaticText7 = new wxStaticText(Panel1,
                                   -1,
                                   wxT("U(x)=U("),
                                   wxPoint(398,330),
                                   wxSize(23,50));
    TextCtrl7 = new wxTextCtrl(Panel1,
                               -1,
                               wxEmptyString,
                               wxPoint(450,330),
                               wxSize(25,21),
                               wxTE_READONLY);
    StaticText8 = new wxStaticText(Panel1,
                                   -1,
                                   wxT(")="),
                                   wxPoint(476,330),
                                   wxSize(23,50));
    TextCtrl8 = new wxTextCtrl(Panel1,
                               -1,
                               wxEmptyString,
                               wxPoint(500,330),
                               wxDefaultSize,
                               wxTE_READONLY);

    Connect(ID_Button1,
            wxEVT_COMMAND_BUTTON_CLICKED,
            wxCommandEventHandler(FDSubFrame::OnButton1Click1));
}

FDSubFrame::~FDSubFrame() {}

void FDSubFrame::OnButton1Click1(wxCommandEvent& event)
{
    wxString stra=TextCtrl1->GetValue();
    stra.ToDouble(&m_value1);
    wxString strb=TextCtrl2->GetValue();
    strb.ToDouble(&m_value2);
    wxString strx=TextCtrl3->GetValue();
    strx.ToDouble(&m_value3);
    wxString strn=TextCtrl4->GetValue();
    strn.ToLong(&m_value4);

    wxString strm, stre, strW;
    if (int(m_value3*m_value4)==0) {
        strm<<0;
        TextCtrl5->WriteText(strm);
        TextCtrl6->WriteText("exact");
        TextCtrl7->WriteText(strx);
        strW << m_value1;
        TextCtrl8->WriteText(strW);
        return;
    } else if (int(m_value3*m_value4)==m_value4) {
        strm<<0;
        TextCtrl5->WriteText(strm);
        TextCtrl6->WriteText("exact");
        TextCtrl7->WriteText(strx);
        strW << m_value2;
        TextCtrl8->WriteText(strW);
        return;
    }

    double h=(m_value2-m_value1)/m_value4;

    Eigen::VectorXd b(m_value4-1);
    b(0)=function1(1.0/m_value4)-m_value1/(h*h);
    b(m_value4-2)=function1(1.0-1.0/m_value4)-m_value2/(h*h);

    for(int k=0; k<m_value4-3; k++) {
        b(k+1)=function1(double(k+2)/m_value4);
    }

    std::vector<Eigen::Triplet<double> > tripletList;
    std::vector<int> row,col;
    std::vector<double> value;
    row.push_back(0);
    col.push_back(0);
    value.push_back(-2/(h*h));

    for(int k=0; k<m_value4-2; k++) {
        row.push_back(k+1);
        col.push_back(k+1);
        value.push_back(-2/(h*h));
        row.push_back(k);
        col.push_back(k+1);
        value.push_back(1/(h*h));
        row.push_back(k+1);
        col.push_back(k);
        value.push_back(1/(h*h));
    }

    for(int j=0; j<row.size(); j++) {
        tripletList.push_back(Eigen::Triplet<double>(row[j],col[j],value[j]));
    }

    Eigen::SparseMatrix<double> A(m_value4-1,m_value4-1);
    A.setFromTriplets(tripletList.begin(), tripletList.end());

    Eigen::ConjugateGradient<Eigen::SparseMatrix<double> > cg;
    cg.compute(A);
    Eigen::VectorXd X(m_value4-1);
    X=cg.solve(b);
    strm<<cg.iterations();
    TextCtrl5->WriteText(strm);
    stre<<cg.error();
    TextCtrl6->WriteText(stre);
    TextCtrl7->WriteText(strx);
    strW<<X(int(m_value3*m_value4)-1);
    TextCtrl8->WriteText(strW);
}
