// Copyright (C) 2026 Mykyta Polishyk
// This project is licensed under the MIT License.
// See the LICENSE file for details.

#pragma once

#include <wx/wx.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>

class ServerConstructor : public wxDialog{
public:
	ServerConstructor();
private:
	wxTextCtrl *m_TitleTextBox;
	wxCheckBox *m_UseCustomVideosCheckBox;
	wxCheckBox *m_IsPrivateCheckBox;
	wxCheckBox *m_ChatFilterCheckBox;
	wxTextCtrl *m_PasswordTextBox;
};

extern ServerConstructor *SC; // Global pointer