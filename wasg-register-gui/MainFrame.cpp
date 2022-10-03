#include "MainFrame.h"
#include <wx/process.h>
#include <wx/msgdlg.h>
#include <wx/log.h>
#include <wx/stdpaths.h>
#include <wx/filename.h>

const wxString APP_TITLE=wxT("Wireless@SGX Linux Unofficial GUI Interface");

MainFrame::MainFrame(wxWindow* parent):
	MainFrameBaseClass(parent),
	retryRetrieveMode(false),
	sizeBugFixed(false),
	terminated(true),
	otpDialog(this,wxT("Enter OTP to continue:"),APP_TITLE,wxT(""),wxOK|wxCENTRE|wxWS_EX_VALIDATE_RECURSIVELY){
	optionsNotebook->ChangeSelection(0);
	decryptionDate->SetValue(wxInvalidDateTime);
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
	registerButton->Disable();
	otpPrompted=false;
	output->SetValue(wxT(""));
	errors->SetValue(wxT(""));
	optionsNotebook->ChangeSelection(optionsNotebook->GetPageCount()-1);
	optionsNotebook->Disable();
	wxFileName executableName(wxStandardPaths::Get().GetExecutablePath());
	wxString cmdline=executableName.GetPath()+wxT("/wasg-register.py");
	if(!isp->GetStringSelection().IsEmpty())cmdline+=wxT(" -I ")+isp->GetStringSelection().Lower();
	if(!salutation->GetValue().IsEmpty())cmdline+=wxT(" -s ")+salutation->GetValue();
	if(!name->GetValue().IsEmpty())cmdline+=wxT(" -n ")+name->GetValue();
	if(!gender->GetValue().IsEmpty())cmdline+=wxT(" -g ")+gender->GetValue();
	if(!country->GetValue().IsEmpty())cmdline+=wxT(" -c ")+country->GetValue();
	if(!email->GetValue().IsEmpty())cmdline+=wxT(" -e ")+email->GetValue();
	if(!transactionId->GetValue().IsEmpty())cmdline+=wxT(" -t ")+transactionId->GetValue();
	if(registrationPhaseOnly->GetValue())cmdline+=wxT(" -1");
	if(!otp->GetValue().IsEmpty())cmdline+=wxT(" -O ")+otp->GetValue();
	if(!successCode->GetValue().IsEmpty())cmdline+=wxT(" -S ")+successCode->GetValue();
	if(decryptionDate->GetValue().IsValid())cmdline+=wxT(" -D ")+decryptionDate->GetValue().Format(wxT("%y%m%d"));
	if(verbose->GetValue())cmdline+=wxT(" -v");
	cmdline+=wxString(retrieveModeOnly->GetValue()||retryRetrieveMode?wxT(" -r "):wxT(" "))+GetPhoneNumber()->GetValue()+wxT(" ")+GetBirthdate()->GetValue().Format(wxT("%d%m%Y"));
	process=wxProcess::Open(cmdline);
	terminated=false;
	process->Bind(wxEVT_END_PROCESS,[this](wxProcessEvent& event){
		terminated=true;
		registerButton->Enable();
		optionsNotebook->Enable();
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
		output->SetValue(output->GetValue()+c);
	}
	for(wchar_t c=0;errorStream&&errorStream->CanRead();){
		c=errorStream->GetC();
		if(c>0)errors->SetValue(errors->GetValue()+c);
		if(errors->GetValue().Contains(wxT("Server responded with error message: DOB & Mobile Number pair already exists"))&&!retryRetrieveMode){
			retryRetrieveMode=true;
			GetRegisterButton()->Enable();
			wxCommandEvent event(wxEVT_COMMAND_BUTTON_CLICKED,GetRegisterButton()->GetId());
			GetRegisterButton()->Command(event);
			return;
		}
	}
	if(terminated){
		if(!output->GetValue().IsEmpty()){
			int userIDpos=output->GetValue().find(wxT("userid = "));
			int newlinepos=output->GetValue().find(wxT("\n"),userIDpos);
			if(userIDpos>=0)userID->SetValue(output->GetValue().SubString(userIDpos+9,newlinepos-1));
			int passwordpos=output->GetValue().find(wxT("password = "));
			newlinepos=output->GetValue().find(wxT("\n"),passwordpos);
			if(passwordpos>=0)password->SetValue(output->GetValue().SubString(passwordpos+11,newlinepos-1));
		}
		return;
	}
	if(output->GetValue().Contains(wxT("Enter OTP to continue: "))&&!otpPrompted){
		otpPrompted=true;
		if(otpDialog.ShowModal()==wxID_CANCEL){
			wxProcess::Kill(process->GetPid());
			return;
		}
		(*outputStream)<<otpDialog.GetValue()<<endl;
		output->SetValue(output->GetValue()+wxT("\n"));
	}
	wxIdleEvent().RequestMore();
}