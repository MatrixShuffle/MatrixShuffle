// Copyright (C) 2026 Mykyta Polishyk
// This project is licensed under the MIT License.
// See the LICENSE file for details.

#include "ServerContructor.hpp"
#include "ServerControl.hpp"
#include "UserInterface.hpp"

ServerConstructor::ServerConstructor()  : wxDialog(wxWindow::FindWindowById(MainWindowID), ServerConstructorID, "Server constructor", wxDefaultPosition, wxSize(0, 0)){
	// Creating UI Elemets
	m_TitleTextBox = new wxTextCtrl(this, wxID_ANY, "Server title");
	m_LogFileNameTextBox = new wxTextCtrl(this, wxID_ANY, "Log file name");
	m_PortTextBox = new wxTextCtrl(this, wxID_ANY, "Server port");
	m_UseCustomVideosCheckBox = new wxCheckBox(this, wxID_ANY, "Use custom videos");
	m_ChatFilterCheckBox = new wxCheckBox(this, wxID_ANY, "Use chat filter");
	m_IsPrivateCheckBox = new wxCheckBox(this, wxID_ANY, "Private server");
	m_PasswordTextBox = new wxTextCtrl(this, wxID_ANY, "Server password");
	m_CustomVideosDirectoryTextBox = new wxTextCtrl(this, wxID_ANY, "Custom video directory");
	m_GoogleAPIKeyTextBox = new wxTextCtrl(this, wxID_ANY, "Google API Key (for random Youtube videos)");
	m_CreateButton = new wxButton(this, wxID_ANY, "Create");

	// Using sizer
	wxBoxSizer *Sizer = new wxBoxSizer(wxVERTICAL);
	Sizer->Add(m_TitleTextBox,0,wxALL,10);
	Sizer->Add(m_LogFileNameTextBox,0,wxALL,10);
	Sizer->Add(m_PortTextBox,0,wxALL,10);
	Sizer->Add(m_UseCustomVideosCheckBox,0,wxALL,10);
	Sizer->Add(m_ChatFilterCheckBox,0,wxALL,10);
	Sizer->Add(m_IsPrivateCheckBox,0,wxALL,10);
	Sizer->Add(m_PasswordTextBox,0,wxALL,10);
	Sizer->Add(m_CustomVideosDirectoryTextBox,0,wxALL,10);
	Sizer->Add(m_GoogleAPIKeyTextBox,0,wxALL,10);
	Sizer->Add(m_CreateButton,0,wxALL,10);
	SetSizerAndFit(Sizer);
	Show(true);

	ServerControl *m_SControl;
	m_SControl = new ServerControl();
}