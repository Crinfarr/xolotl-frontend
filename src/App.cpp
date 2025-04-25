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

};
void AppFrame::OnExit(wxCommandEvent& _ev) {
    Close(true);
};

bool App::OnInit() {
    AppFrame* frame = new AppFrame();
    frame->Show();
    return true;
}
