#include "MainFrame.h"
#include <wx/process.h>
#include <wx/msgdlg.h>
#include <wx/log.h>
#include <iostream>

const wxString APP_TITLE=wxT("Wireless@SGX Linux Unofficial GUI Interface");

MainFrame::MainFrame(wxWindow* parent):
	MainFrameBaseClass(parent),
	retryRetrieveMode(false),
	sizeBugFixed(false),
	terminated(true),
	otpDialog(this,wxT("Enter OTP to continue:"),APP_TITLE,wxT(""),wxOK|wxCENTRE|wxWS_EX_VALIDATE_RECURSIVELY){
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
	wxString cmdline=wxT("/home/walfin/Dokumentujo/Github/wasg-register-gui/wasg-register-gui/wasg-register.py ")+wxString(GetRetrieveModeOnly()->GetValue()||retryRetrieveMode?wxT("-r "):wxT(""))+GetPhoneNumber()->GetValue()+wxT(" ")+GetBirthdate()->GetValue().Format(wxT("%d%m%Y"));
	std::wcerr<<cmdline<<std::endl;
	process=wxProcess::Open(cmdline);
	terminated=false;
	process->Bind(wxEVT_END_PROCESS,[this](wxProcessEvent& event){
		terminated=true;
		GetRegisterButton()->Enable();
	});
	process->Redirect();
	inputStream=process->GetInputStream();
	errorStream=process->GetErrorStream();
	outputStream=new wxTextOutputStream(*process->GetOutputStream());
	retryRetrieveMode=false;
	wxIdleEvent().RequestMore();
}

void MainFrame::OnIdle(wxIdleEvent& event){
	for(wchar_t c=0;inputStream&&inputStream->CanRead();){
		c=inputStream->GetC();
		if(c<=0)continue;
		output+=c;
		std::wcerr<<c;
	}
	for(wchar_t c=0;errorStream&&errorStream->CanRead();){
		c=errorStream->GetC();
		if(c>0)error+=c;
		else if(!error.IsEmpty()){
			if(error.Contains(wxT("Server responded with error message: DOB & Mobile Number pair already exists"))){
				error.Clear();
				std::wcerr<<"Retrying"<<std::endl;
				retryRetrieveMode=true;
				GetRegisterButton()->Enable();
				wxCommandEvent event(wxEVT_COMMAND_BUTTON_CLICKED,GetRegisterButton()->GetId());
				GetRegisterButton()->Command(event);
				return;
			}
			wxMessageBox(error,APP_TITLE);
			error.Clear();
		}
		std::wcerr<<c;
	}
	if(terminated){
		if(!output.IsEmpty()){
			std::wcerr<<"Final output: "<<output<<std::endl;
			output.Clear();
			std::wcerr<<"Output now: "<<output;
		}
		return;
	}
	if(output.Contains(wxT("Enter OTP to continue: "))){
		output.Replace(wxT("Enter OTP to continue: "),wxT(""),true);
		if(otpDialog.ShowModal()==wxID_CANCEL){
			wxProcess::Kill(process->GetPid());
			return;
		}
		wxString value=otpDialog.GetValue();
		(*outputStream)<<value<<endl;
		std::wcerr<<value<<std::endl;
		wxIdleEvent().RequestMore();
		return;
	}
	wxIdleEvent().RequestMore();
}