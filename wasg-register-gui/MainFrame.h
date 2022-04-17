#ifndef MAINFRAME_H
#define MAINFRAME_H
#include "wxcrafter.h"
#include <wx/process.h>
#include <wx/txtstrm.h>
#include <memory>

class MainFrame : public MainFrameBaseClass{
	public:
		MainFrame(wxWindow* parent);
		virtual ~MainFrame();
		bool retryRetrieveMode;
	protected:
		virtual void OnActivate(wxActivateEvent& event);
		virtual void OnRegisterButtonClicked(wxCommandEvent& event);
		virtual void ReEnableRegisterButton(wxCommandEvent& event);
		virtual void OutputMessage(wxCommandEvent& event);
		class RegisterThread:public wxThread{
			public:
				MainFrame* mainFrame;
				wxProcess* process;
				wxString output;
			protected:
				virtual void* Entry();
				bool terminated;
				wxInputStream* inputStream;
				std::shared_ptr<wxTextOutputStream> outputStream;
		};
		std::shared_ptr<RegisterThread> registerThread;
		bool sizeBugFixed;
		wxDECLARE_EVENT_TABLE();
};

#endif // MAINFRAME_H
