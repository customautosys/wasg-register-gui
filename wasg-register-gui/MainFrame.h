#ifndef MAINFRAME_H
#define MAINFRAME_H
#include "wxcrafter.h"
#include <wx/process.h>
#include <wx/txtstrm.h>
#include <wx/textdlg.h>
#include <wx/object.h>
#include <memory>

class MainFrame : public MainFrameBaseClass{
	public:
		MainFrame(wxWindow* parent);
		virtual ~MainFrame();
		bool retryRetrieveMode;
	protected:
		virtual void OnIdle(wxIdleEvent& event);
		virtual void OnActivate(wxActivateEvent& event);
		virtual void OnRegisterButtonClicked(wxCommandEvent& event);
		wxProcess* process;
		wxTextEntryDialog otpDialog;
		wxString output;
		wxString error;
		bool terminated;
		wxSharedPtr<wxInputStream> inputStream;
		wxSharedPtr<wxInputStream> errorStream;
		wxSharedPtr<wxTextOutputStream> outputStream;
		bool sizeBugFixed;
};

#endif // MAINFRAME_H
