#include <wx/wx.h>

#ifndef TITLE
#define TITLE "App Title"
#endif

class App : public wxApp {
public:
    bool OnInit() override;
};
wxIMPLEMENT_APP(App);

class AppFrame : public wxFrame {
public:
    AppFrame();
private:
    void OnExit(wxCommandEvent& event);
};
AppFrame::AppFrame() : wxFrame(nullptr, wxID_ANY, TITLE) {
    wxBoxSizer* winbox = new wxBoxSizer(wxOrientation::wxVERTICAL);
    SetSizerAndFit(winbox);
    winbox->Add(
        new wxTextCtrl(this, wxID_ANY),
        0,
        wxEXPAND
    );
};
void AppFrame::OnExit(wxCommandEvent& _ev) {
    Close(true);
};

bool App::OnInit() {
    AppFrame* frame = new AppFrame();
    int sc_width, sc_height = 0;

    wxDisplaySize(&sc_width, &sc_height);
    frame->SetSize(sc_width/2, sc_height/2);
    frame->Show();
    frame->CenterOnScreen();
    return true;
}
