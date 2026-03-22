// Copyright (C) 2026 Mykyta Polishyk
// This project is licensed under the MIT License.
// See the LICENSE file for details.

#pragma once

#include <wx/wx.h>
#include <wx/listctrl.h>
#include <string>

class ServerControl : wxFrame{
public:
	ServerControl();
	void WriteLN(std::string Message); // Writing message into log
private:
    // UI Elements
    wxToolBar *m_Toolbar;
    wxListCtrl *m_Log;
    long LogCounter;
};