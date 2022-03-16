#ifndef MAINFRAME_H
#define MAINFRAME_H

#include "wx/frame.h"

// IDs for the controls and the menu commands
enum
{
    Minimal_Quit = wxID_EXIT,
    Minimal_About = wxID_ABOUT
};

// Define a new frame type: this is going to be our main frame
class MainFrame : public wxFrame
{
public:

    MainFrame(wxWindow* parent = (wxWindow*)NULL);

    // event handlers (these functions should _not_ be virtual)
    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

private:
    // any class wishing to process wxWidgets events must use this macro
    wxDECLARE_EVENT_TABLE();
};

#endif // !MAINFRAME_H
