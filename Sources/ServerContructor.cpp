// Copyright (C) 2026 Mykyta Polishyk
// This project is licensed under the MIT License.
// See the LICENSE file for details.

#include "ServerContructor.hpp"
#include "ServerControl.hpp"
#include "UserInterface.hpp"

ServerConstructor::ServerConstructor()  : wxDialog(wxWindow::FindWindowById(MainWindowID), ServerConstructorID, "Server constructor", wxDefaultPosition, wxSize(0, 0)){
	// Creating UI Elemets
	m_TitleTextBox = new wxTextCtrl(this, wxID_ANY, "");
	m_LogFileNameTextBox = new wxTextCtrl(this, wxID_ANY, "");
	m_PortTextBox = new wxTextCtrl(this, wxID_ANY, "");
	m_UseCustomVideosCheckBox = new wxCheckBox(this, wxID_ANY, "Use custom videos");
	m_ChatFilterCheckBox = new wxCheckBox(this, wxID_ANY, "Use chat filter");
	m_IsPrivateCheckBox = new wxCheckBox(this, wxID_ANY, "Private server");
	m_PasswordTextBox = new wxTextCtrl(this, wxID_ANY, "");
	m_CustomVideosDirectoryTextBox = new wxTextCtrl(this, wxID_ANY, "");
	m_GoogleAPIKeyTextBox = new wxTextCtrl(this, wxID_ANY, "");
	m_CreateButton = new wxButton(this, wxID_ANY, "Create");

	// Adding placeholders
	m_TitleTextBox->SetHint("Server title");
	m_LogFileNameTextBox->SetHint("Log file name");
	m_PortTextBox->SetHint("Server port");
	m_PasswordTextBox->SetHint("Server password");
	m_CustomVideosDirectoryTextBox->SetHint("Custom video directory");
	m_GoogleAPIKeyTextBox->SetHint("Google API Key (for random Youtube videos)");
	// Using sizer
	wxBoxSizer *Sizer = new wxBoxSizer(wxVERTICAL);
	Sizer->Add(m_TitleTextBox,1, wxEXPAND |wxALL,10);
	Sizer->Add(m_LogFileNameTextBox,1, wxEXPAND |wxALL,10);
	Sizer->Add(m_PortTextBox,1, wxEXPAND |wxALL,10);
	Sizer->Add(m_UseCustomVideosCheckBox,0,wxALL,10);
	Sizer->Add(m_ChatFilterCheckBox,0,wxALL,10);
	Sizer->Add(m_IsPrivateCheckBox,0,wxALL,10);
	Sizer->Add(m_PasswordTextBox,1, wxEXPAND |wxALL,10);
	Sizer->Add(m_CustomVideosDirectoryTextBox,1, wxEXPAND |wxALL,10);
	Sizer->Add(m_GoogleAPIKeyTextBox,1, wxEXPAND |wxALL,10);
	Sizer->Add(m_CreateButton,0,wxALL,10);
	SetSizerAndFit(Sizer);
	Show(true);

	ServerControl *m_SControl;
	m_SControl = new ServerControl();
}