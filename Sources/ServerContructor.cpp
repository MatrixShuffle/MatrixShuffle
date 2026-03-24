// Copyright (C) 2026 Mykyta Polishyk
// This project is licensed under the MIT License.
// See the LICENSE file for details.

#include "ServerContructor.hpp"
#include "ServerControl.hpp"
#include "UserInterface.hpp"
#include "Settings.hpp"

ServerConstructor::ServerConstructor()  : wxDialog(wxWindow::FindWindowById(MainWindowID), ServerConstructorID, "Server constructor", wxDefaultPosition, wxSize(0, 0)){
	// Creating UI Elemets
	m_TitleTextBox = new wxTextCtrl(this, wxID_ANY, "");
	m_LogFileNameTextBox = new wxTextCtrl(this, wxID_ANY, "");
	m_ChatFilterCheckBox = new wxCheckBox(this, wxID_ANY, "Use chat filter");
	m_IsPrivateCheckBox = new wxCheckBox(this, wxID_ANY, "Private server");
	m_PasswordTextBox = new wxTextCtrl(this, wxID_ANY, "");
	m_GoogleAPIKeyTextBox = new wxTextCtrl(this, wxID_ANY, "");
	m_CreateButton = new wxButton(this, BContructServerID, "Create");
	m_ConfigureBanWordsButton = new wxButton(this, BConfigureBannedWords, "Configure banned words");
	// Adding placeholders
	m_TitleTextBox->SetHint("Server title");
	m_LogFileNameTextBox->SetHint("Log file name");
	m_PasswordTextBox->SetHint("Server password");
	m_GoogleAPIKeyTextBox->SetHint("Google API Key");
	// Using sizer
	wxBoxSizer *Sizer = new wxBoxSizer(wxVERTICAL);
	Sizer->Add(m_TitleTextBox,1, wxEXPAND |wxALL,10);
	Sizer->Add(m_LogFileNameTextBox,1, wxEXPAND |wxALL,10);
	Sizer->Add(m_ChatFilterCheckBox,0,wxALL,10);
	Sizer->Add(m_IsPrivateCheckBox,0,wxALL,10);
	Sizer->Add(m_PasswordTextBox,1, wxEXPAND |wxALL,10);
	Sizer->Add(m_GoogleAPIKeyTextBox,1, wxEXPAND |wxALL,10);
	Sizer->Add(m_CreateButton,0,wxALL,10);
	Sizer->Add(m_ConfigureBanWordsButton,1, wxEXPAND |wxALL,10);
	SetSizerAndFit(Sizer);

    Bind(wxEVT_BUTTON, &ServerConstructor::OnButtonClicked, this, BContructServerID);

	Show(true);
}

void ServerConstructor::OnButtonClicked(wxCommandEvent& Event){
	switch (Event.GetId()){
        case BContructServerID:{
        	// Creating server options
        	ServerSettings OptionsBuffer;
        	OptionsBuffer.Title = m_TitleTextBox->GetValue();
        	OptionsBuffer.LogFileName = m_LogFileNameTextBox->GetValue();
        	OptionsBuffer.ChatFilter = m_ChatFilterCheckBox->GetValue();
        	OptionsBuffer.IsPrivate = m_IsPrivateCheckBox->GetValue();
        	OptionsBuffer.Password = m_PasswordTextBox->GetValue();
        	OptionsBuffer.GoogleAPIKey = m_GoogleAPIKeyTextBox->GetValue();
        	// Creating server controls, and server inside controller
			ServerControl *m_SControl;
			m_SControl = new ServerControl(OptionsBuffer);
			Close(true);
            break;
        }
    }
}