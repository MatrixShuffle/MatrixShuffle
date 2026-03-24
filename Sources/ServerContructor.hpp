// Copyright (C) 2026 Mykyta Polishyk
// This project is licensed under the MIT License.
// See the LICENSE file for details.

#pragma once

#include <wx/wx.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/button.h>
#include <wx/sizer.h>

class ServerConstructor : public wxDialog{
public:
	ServerConstructor();
	virtual void OnButtonClicked(wxCommandEvent& Event);
private:
	// UI Widgets
	wxTextCtrl *m_TitleTextBox;
	wxTextCtrl *m_LogFileNameTextBox;
	wxTextCtrl *m_PortTextBox;
	wxCheckBox *m_UseCustomVideosCheckBox;
	wxCheckBox *m_ChatFilterCheckBox;
	wxCheckBox *m_IsPrivateCheckBox;
	wxTextCtrl *m_PasswordTextBox;
	wxTextCtrl *m_CustomVideosDirectoryTextBox;
	wxTextCtrl *m_GoogleAPIKeyTextBox;
	wxButton *m_CreateButton;
	wxButton *m_HelpButton;
	wxButton *m_ConfigureBanWordsButton;
};