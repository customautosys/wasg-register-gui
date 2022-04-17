#include "MainFrame.h"
#include <wx/process.h>
#include <wx/textdlg.h>
#include <wx/msgdlg.h>
#include <wx/log.h>
#include <iostream>

wxDEFINE_EVENT(RE_ENABLE_REGISTER_BUTTON,wxCommandEvent);
wxDEFINE_EVENT(OUTPUT_MESSAGE,wxCommandEvent);

wxBEGIN_EVENT_TABLE(MainFrame,MainFrameBaseClass)
	EVT_COMMAND(wxID_ANY,RE_ENABLE_REGISTER_BUTTON,MainFrame::ReEnableRegisterButton)
	EVT_COMMAND(wxID_ANY,OUTPUT_MESSAGE,MainFrame::OutputMessage)
	EVT_ACTIVATE(MainFrame::OnActivate)
wxEND_EVENT_TABLE()

const wxString APP_TITLE=wxT("Wireless@SGX Linux Unofficial GUI Interface");

MainFrame::MainFrame(wxWindow* parent):
	MainFrameBaseClass(parent),
	retryRetrieveMode(false),
	sizeBugFixed(false){
}

MainFrame::~MainFrame(){
}

void MainFrame::OnActivate(wxActivateEvent& event){
	if(sizeBugFixed)return;
	wxSize size=GetSize();
	size.IncBy(1);
	SetSize(size);
	sizeBugFixed=true;
}

void MainFrame::OnRegisterButtonClicked(wxCommandEvent& event){
	GetRegisterButton()->Disable();
	registerThread=std::make_shared<RegisterThread>();
	registerThread->mainFrame=this;
	registerThread->process=wxProcess::Open(wxT("./wasg-register.py ")+wxString(GetRetrieveModeOnly()->GetValue()||retryRetrieveMode?wxT("-r "):wxT(""))+GetPhoneNumber()->GetValue()+wxT(" ")+GetBirthdate()->GetValue().Format(wxT("%d%m%Y")));
	retryRetrieveMode=false;
	registerThread->Run();
}

void MainFrame::ReEnableRegisterButton(wxCommandEvent& event){
	GetRegisterButton()->Enable();
}

void MainFrame::OutputMessage(wxCommandEvent& event){
	if(registerThread)wxMessageBox(registerThread->output,APP_TITLE);
}

wxThread::ExitCode MainFrame::RegisterThread::Entry(){
	wxCommandEvent reEnableRegisterButtonEvent(RE_ENABLE_REGISTER_BUTTON,mainFrame->GetId());
	wxCommandEvent outputMessageEvent(OUTPUT_MESSAGE,mainFrame->GetId());
	terminated=false;
	inputStream=process->GetInputStream();
	outputStream=std::make_shared<wxTextOutputStream>(*process->GetOutputStream());
	process->Bind(wxEVT_END_PROCESS,[this](wxProcessEvent& event){
		event.Skip();
		terminated=true;
	});
	while(!terminated){
		wchar_t c=inputStream->GetC();
		output+=c;
		std::cerr<<c<<std::endl;
		if(output.EndsWith(wxT("Server responded with error message: DOB & Mobile Number pair already exists"))){
			mainFrame->retryRetrieveMode=true;
			mainFrame->AddPendingEvent(reEnableRegisterButtonEvent);
			wxCommandEvent event(wxEVT_COMMAND_BUTTON_CLICKED,mainFrame->GetRegisterButton()->GetId());
			mainFrame->GetRegisterButton()->Command(event);
			return nullptr;
		}
		if(output.EndsWith(wxT("Enter OTP to continue:"))){
			wxTextEntryDialog dialog(mainFrame,wxT("Enter OTP to continue:"),APP_TITLE,wxT(""),wxOK| wxCENTRE|wxWS_EX_VALIDATE_RECURSIVELY);
			dialog.ShowModal();
			output=wxT("");
			(*outputStream)<<dialog.GetValue();
		}
	}
	mainFrame->AddPendingEvent(outputMessageEvent);
	mainFrame->AddPendingEvent(reEnableRegisterButtonEvent);
	return nullptr;
}